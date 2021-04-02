package main

import (
	"flag"
	"fmt"
	"runtime"
	"log"
	"time"
	"github.com/realjf/stress-go/server"
	"github.com/realjf/stress-go/model"
	"github.com/realjf/stress-go/cgo"
)

var (
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
	flag.StringVar(&args.Body, "data", "", "http post数据")
	flag.Parse()

	if args.Url == "" || args.ConcurrencyNum == 0 || args.RequestNum == 0 {
		flag.Usage()
		return
	}

	cgo.StartWin()
	cgo.PrintHeaderLine()
	cgo.PrintHeader()
	cgo.PrintDivider()
	cgo.PrintTd(234, 4234, 4223, 1, 3223, 234.2, 23.2, 54.2, "1234.2", "123.2")
	cgo.EndWin()

	var isDebug bool
	if args.Debug > 0 {
		isDebug = true
	}else{
		isDebug = false
	}

	request, err := model.NewRequest(args.Url, time.Second * 30, args.Headers, args.Body, isDebug)
	if err != nil {
		log.Println(err)
		return 
	}

	server.Run(request)
}
