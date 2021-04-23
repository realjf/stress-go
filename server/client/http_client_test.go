package client

import (
	"testing"
	"time"

	"github.com/realjf/stress-go/model"
)

func TestHttpRequest(t *testing.T) {
	newRequest, err := model.NewRequest("https://www.baidu.com", 30*time.Second, []string{}, "", false)
	if err != nil {
		t.Error(err)
	}

	resp, reqTime, err := HttpRequest(newRequest.Method, newRequest.Url, newRequest.GetBody(), newRequest.Headers, newRequest.Timeout)
	if err != nil {
		t.Error(err)
	}
	t.Error(resp, reqTime)
}
