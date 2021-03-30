package main

import (
	"log"
	"net/http"
	"runtime"
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
)

type RequestResults struct {
	Id          string // 消息id
	ChanId      uint64 // 消息id
	Time        uint64 // 请求时间 纳秒
	IsSuccessed bool   // 是否请求成功
	ErrorCode   int    // 错误码
}

const (
	httpPort = "8888"
)

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU() - 1)

	hello := func(w http.ResponseWriter, r *http.Request) {
		data := "Hello, stress-go!\n"
		w.Header().Add("Server", "golang")
		w.Write([]byte(data))

		return
	}

	http.HandleFunc("/", hello)
	err := http.ListenAndServe(":"+httpPort, nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
