package golink

import (
	"github.com/realjf/stress-go/model"
	"github.com/realjf/stress-go/server/client"
)

// send 发送一次请求
func Send(request *model.Request) (bool, int, uint64, int64) {
	var (
		// startTime = time.Now()
		isSucceed     = false
		errCode       = 0
		contentLength = int64(0)
	)

	newRequest := request;
	// newRequest := request

	resp, requestTime, err := client.HttpRequest(newRequest.Method, newRequest.Url, newRequest.GetBody(), newRequest.Headers, newRequest.Timeout)
	// requestTime := uint64(heper.DiffNano(startTime))
	if err != nil {
		errCode = 1 // 请求错误
	} else {
		contentLength = resp.ContentLength

		// 验证请求是否成功
		// errCode, isSucceed = newRequest.GetVerifyHttp()(newRequest, resp)
		isSucceed = true
	}
	return isSucceed, errCode, requestTime, contentLength
}