package cgo

//#cgo CFLAGS: -I. -std=c99 -Wall
//#cgo LDFLAGS: -lncursesw
//#include "stdout_output.h"
import "C"

import (
	"fmt"
	"sort"
	"strings"
)

func SayHello() {
	C.PrintHello()
}

//export DrawTh
func DrawTh() *C.char {
	th := fmt.Sprintln()
	// 打印的时长都为毫秒 总请数
	th += fmt.Sprintln("─────┬───────┬───────┬───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────")
	th += fmt.Sprintf(" 耗时│ 并发数│ 成功数│ 失败数│   qps  │最长耗时│最短耗时│平均耗时│下载字节│字节每秒│ 错误码")
	th += fmt.Sprintln()
	// result = fmt.Sprintf("耗时(s)  │总请求数│成功数│失败数│QPS│最长耗时│最短耗时│平均耗时│错误码")
	// fmt.Println(result)
	th += fmt.Sprintln("─────┼───────┼───────┼───────┼────────┼────────┼────────┼────────┼────────┼────────┼────────")
	// cstr := C.CString(th)
	// defer C.free(unsafe.Pointer(cstr)) // 释放内存
	// strptr := (*C.char)(unsafe.Pointer(cstr))
	return C.CString(th)
}

//export DrawTd
func DrawTd(requestTimeFloat float64, concurrency int64, successNum int, failureNum int, qps int,
	maxTimeFloat float64, minTimeFloat float64, avgTime int, receivedBytesStr string, speedStr string, errorCode map[int]int) *C.char {
	// 打印的时长都为毫秒
	td := fmt.Sprintf("%4.0fs│%7d│%7d│%7d│%8.2f│%8.2f│%8.2f│%8.2f│%8s│%8s│%v",
		requestTimeFloat, concurrency, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, avgTime,
		receivedBytesStr, speedStr,
		printMap(errorCode))
	td += fmt.Sprintln()
	return C.CString(td)
}

// 输出错误码、次数 节约字符(终端一行字符大小有限)
func printMap(errCode map[int]int) (mapStr string) {
	var (
		mapArr []string
	)
	for key, value := range errCode {
		mapArr = append(mapArr, fmt.Sprintf("%d:%d", key, value))
	}
	sort.Strings(mapArr)
	mapStr = strings.Join(mapArr, ";")

	return
}
