package main

import (
	"flag"
	"fmt"
	"runtime"

	"github.com/realjf/stress-go/cgo"
)

var (
	processingTime uint64 // 处理总时间
	requestTime    uint64 // 请求总时间
	maxTime        uint64 // 最大时长
	minTime        uint64 // 最小时长
	successNum     uint64 // 成功处理数，code为0
	failureNum     uint64 // 处理失败数，code不为0
	chanIdLen      int    // 并发数
	chanIds        = make(map[uint64]bool)

	args Args // 请求参数
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

type RequestResults struct {
	Id          string // 消息id
	ChanId      uint64 // 消息id
	Time        uint64 // 请求时间 纳秒
	IsSuccessed bool   // 是否请求成功
	ErrorCode   int    // 错误码
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
	cgo.SayHello()

	flag.Uint64Var(&args.ConcurrencyNum, "c", args.ConcurrencyNum, "并发数")
	flag.Uint64Var(&args.RequestNum, "n", args.RequestNum, "单个用户请求总数")
	flag.Uint64Var(&args.Debug, "d", args.Debug, "调试模式")
	flag.StringVar(&args.Url, "u", "", "压测地址")
	flag.StringVar(&args.Path, "p", "", "cURL文件路径")
	flag.Var(&args.Headers, "H", "自定义头部信息，如：-H 'Content-Type: application/json'")
	flag.StringVar(&args.Body, "data", "", "http post数据")
	flag.Parse()

	if args.Url == "" || args.ConcurrencyNum == 0 || args.RequestNum == 0 {
		flag.Usage()
		return
	}
}
