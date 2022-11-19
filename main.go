package main

import (
	"flag"
	"fmt"
	"log"
	"runtime"
	"time"

	"github.com/realjf/stress-go/cgo"
	"github.com/realjf/stress-go/model"
	"github.com/realjf/stress-go/server"
)

var (
	args    Args   // 请求参数
	Version string // 版本号
)

type Array []string

func (a *Array) Set(s string) error {
	*a = append(*a, s)

	return nil
}

func (a *Array) String() string {
	return fmt.Sprint(*a)
}

type Args struct {
	ConcurrencyNum uint64 // 并发数
	RequestNum     uint64 // 请求数（单个用户）
	Debug          uint64 // 调试模式 default=0
	Url            string // 压测地址
	Path           string // curl文件路径
	Headers        Array  // 自定义头部信息
	Body           string // post数据
}

// 初始化参数
func Init() {
	args = Args{
		ConcurrencyNum: 1,
		RequestNum:     1,
		Debug:          0,
		Url:            "",
		Path:           "",
		Headers:        make([]string, 0),
		Body:           "",
	}
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	Init()
	flag.Uint64Var(&args.ConcurrencyNum, "c", args.ConcurrencyNum, "并发数")
	flag.Uint64Var(&args.RequestNum, "n", args.RequestNum, "单个用户请求总数")
	flag.Uint64Var(&args.Debug, "d", args.Debug, "调试模式")
	flag.StringVar(&args.Url, "u", "", "压测地址")
	flag.StringVar(&args.Path, "p", "", "cURL文件路径")
	flag.Var(&args.Headers, "H", "自定义头部信息，如：-H 'Content-Type: application/json'")
	flag.StringVar(&args.Body, "td", "", "http post数据")
	flag.Parse()

	if args.Url == "" || args.ConcurrencyNum == 0 || args.RequestNum == 0 {
		flag.Usage()
		return
	}

	ch := make(chan *model.RequestResults, 1000)
	endChan := make(chan bool)

	var isDebug bool
	if args.Debug > 0 {
		isDebug = true
	} else {
		isDebug = false
	}

	request, err := model.NewRequest(args.Url, time.Second*30, args.Headers, args.Body, isDebug)
	if err != nil {
		log.Println(err)
		return
	}

	go func(concurrencyNum uint64) {
		cgo.StartWin()
		cgo.PrintHeaderLine()
		cgo.PrintHeader()
		cgo.PrintDivider()
		// 时间
		var (
			processingTime uint64 // 处理总时间
			requestTime    uint64 // 请求总时间
			maxTime        uint64 // 最大时长
			minTime        uint64 // 最小时长
			successNum     uint64 // 成功处理数，code为0
			failureNum     uint64 // 处理失败数，code不为0
			receivedBytes  int64
		)
		statTime := uint64(time.Now().UnixNano())
		for {
			select {
			case td := <-ch:
				processingTime = processingTime + td.Time

				if maxTime <= td.Time {
					maxTime = td.Time
				}

				if minTime == 0 {
					minTime = td.Time
				} else if minTime > td.Time {
					minTime = td.Time
				}

				// 是否请求成功
				if td.IsSucceed == true {
					successNum = successNum + 1
				} else {
					failureNum = failureNum + 1
				}

				receivedBytes += td.ReceivedBytes

				endTime := uint64(time.Now().UnixNano())
				requestTime = endTime - statTime

				if processingTime == 0 {
					processingTime = 1
				}

				var (
					qps              float64
					averageTime      float64
					maxTimeFloat     float64
					minTimeFloat     float64
					requestTimeFloat float64
				)

				// 平均 每个协程成功数*总协程数据/总耗时 (每秒)
				if processingTime != 0 {
					qps = float64(successNum*1e9*concurrencyNum) / float64(processingTime)
				}

				// 平均时长 总耗时/总请求数/并发数 纳秒=>毫秒
				if successNum != 0 && concurrencyNum != 0 {
					averageTime = float64(processingTime) / float64(successNum*1e6)
				}

				// 纳秒=>毫秒
				maxTimeFloat = float64(maxTime) / 1e6
				minTimeFloat = float64(minTime) / 1e6
				requestTimeFloat = float64(requestTime) / 1e9

				var (
					speed int64
				)

				if requestTimeFloat > 0 {
					speed = int64(float64(receivedBytes) / requestTimeFloat)
				} else {
					speed = 0
				}
				var (
					receivedBytesStr string
					speedStr         string
				)
				// 判断获取下载字节长度是否是未知
				if receivedBytes <= 0 {
					receivedBytesStr = ""
					speedStr = ""
				} else {
					receivedBytesStr = fmt.Sprintf("%d", receivedBytes)
					speedStr = fmt.Sprintf("%d", speed)
				}

				cgo.PrintTd(requestTimeFloat, concurrencyNum, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, averageTime, receivedBytesStr, speedStr)
			case <-endChan:
				goto endTag
			}
		}
	endTag:
		close(ch)
		close(endChan)
		cgo.EndWin()
		cgo.FinishWin()
	}(args.ConcurrencyNum)

	server.Run(args.ConcurrencyNum, args.RequestNum, request, ch, endChan)
}
