package client

import (
	"net/http"
	"crypto/tls"
	"io"
	"time"
	"log"
	"github.com/realjf/stress-go/helper"
)

func NewHttpClient(timeout time.Duration) *http.Client {
	// 跳过证书验证
	tr := &http.Transport{
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	}

	client := &http.Client{
		Transport: tr,
		Timeout:   timeout,
	}

	return client
}

func HttpRequest(method, url string, body io.Reader, headers map[string]string, timeout time.Duration) (resp *http.Response, requestTime uint64,err error) {
	client := NewHttpClient(timeout)
	req, err := http.NewRequest(method, url, body)
	if err != nil {
		return
	}
	req.Close = true
	// 在req中设置Host，解决在header中设置Host不生效问题
	if _, ok := headers["Host"]; ok {
		req.Host = headers["Host"]
	}
	// 设置默认为utf-8编码
	if _, ok := headers["Content-Type"]; !ok {
		if headers == nil {
			headers = make(map[string]string)
		}
		headers["Content-Type"] = "application/x-www-form-urlencoded; charset=utf-8"
	}

	for key, value := range headers {
		req.Header.Set(key, value)
	}

	startTime := time.Now()
	resp, err = client.Do(req)
	requestTime = uint64(helper.DiffNano(startTime))
	if err != nil {
		log.Println("请求失败:", err)

		return
	}

	return
}