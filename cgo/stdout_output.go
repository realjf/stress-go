package cgo

//#cgo CFLAGS: -I. -std=c99 -Wall
//#cgo LDFLAGS: -lncurses
//#include "stdout_output.h"
//#include <stdlib.h>
import "C"

import (
	"fmt"
	"unsafe"
)

func SayHello() {
	C.PrintHello()
}


//export DrawTable
func DrawTable() *C.char {
	th := "\n"
	// 打印的时长都为毫秒 总请数
	th += "─────┬───────┬───────┬───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────"
	th += "\n"
	th += fmt.Sprintf(" 耗时│ 并发数│ 成功数│ 失败数│   qps  │最长耗时│最短耗时│平均耗时│下载字节│字节每秒│ 错误码")
	th += "\n"
	// result = fmt.Sprintf("耗时(s)  │总请求数│成功数│失败数│QPS│最长耗时│最短耗时│平均耗时│错误码")
	// fmt.Println(result)
	th += "─────┼───────┼───────┼───────┼────────┼────────┼────────┼────────┼────────┼────────┼────────"
	th += "\n"
	cstr := C.CString(th)
	defer C.free(unsafe.Pointer(cstr)) // 释放内存
    strptr := (*C.char)(unsafe.Pointer(cstr))
	return strptr
}

