package model

import (
	"fmt"
	"io"
	"strings"
	"time"
)

// 请求结果
type Request struct {
	Url     string            // Url
	Method  string            // 方法 GET/POST
	Headers map[string]string // Headers
	Body    string            // body
	Timeout time.Duration     // 请求超时时间
	Debug   bool              // 是否开启Debug模式
}

func (r *Request) GetBody() (body io.Reader) {
	body = strings.NewReader(r.Body)

	return
}

func NewRequest(url string, timeout time.Duration, reqHeaders []string, reqBody string, debug bool) (request *Request, err error) {
	// 解析url
	var (
		method  = "GET"
		headers = make(map[string]string)
		body    string
	)

	if reqBody != "" {
		method = "POST"
		body = reqBody

		headers["Content-Type"] = "application/x-www-form-urlencoded; charset=utf-8"
	}

	for _, v := range reqHeaders {
		getHeaderValue(v, headers)
	}

	request = &Request{
		Url:     url,
		Method:  method,
		Body:    body,
		Headers: headers,
		Timeout: timeout,
		Debug:   debug,
	}

	return
}

func getHeaderValue(v string, headers map[string]string) {
	index := strings.Index(v, ":")
	if index < 0 {
		return
	}

	vIndex := index + 1
	if len(v) >= vIndex {
		value := strings.TrimPrefix(v[vIndex:], " ")

		if _, ok := headers[v[:index]]; ok {
			headers[v[:index]] = fmt.Sprintf("%s; %s", headers[v[:index]], value)
		} else {
			headers[v[:index]] = value
		}
	}
}

// 请求结果
type RequestResults struct {
	Time          uint64 // 请求时间 纳秒
	IsSucceed     bool   // 是否请求成功
	ErrCode       int    // 错误码
	ReceivedBytes int64
}
