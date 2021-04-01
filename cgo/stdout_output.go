package cgo

//#cgo CFLAGS: -I. -std=c99 -Wall
//#cgo LDFLAGS: -lncursesw
//#include "stdout_output.h"
//#include <stdlib.h>
import "C"

import (
	"fmt"
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
func DrawTd(totalTime int, concurrency int, success int, failure int, qps int, maxTime int, minTime int, avgTime int, downloadByte int, byteSecond int, errorCode int) *C.char {
	td := fmt.Sprintf("| |")
	td += fmt.Sprintln()
	return C.CString(td)
}
