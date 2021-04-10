package golink

import (
	"sync"

	"github.com/realjf/stress-go/model"
	"github.com/realjf/stress-go/server/client"
)

// send 发送一次请求
func Send(request *model.Request, requestNum uint64, wg sync.WaitGroup, ch chan<- *model.RequestResults) {

	defer func() {
		wg.Done()
	}()

	var (
		// startTime = time.Now()
		isSucceed     = false
		errCode       = 0
		contentLength = int64(0)
		requestTime   = uint64(0)
	)

	newRequest := request
	// newRequest := request

	var i uint64
	for i = 0; i < requestNum; i++ {
		resp, reqTime, err := client.HttpRequest(newRequest.Method, newRequest.Url, newRequest.GetBody(), newRequest.Headers, newRequest.Timeout)
		// requestTime := uint64(heper.DiffNano(startTime))
		if err != nil {
			errCode = 1 // 请求错误
		} else {
			contentLength += resp.ContentLength

			// 验证请求是否成功
			// errCode, isSucceed = newRequest.GetVerifyHttp()(newRequest, resp)
			isSucceed = true
		}

		requestTime = requestTime + reqTime

		requestResults := &model.RequestResults{
			Time:          requestTime,
			IsSucceed:     isSucceed,
			ErrCode:       errCode,
			ReceivedBytes: contentLength,
		}

		ch <- requestResults
	}

	return
}
