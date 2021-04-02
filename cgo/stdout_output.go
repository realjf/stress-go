package cgo

//#cgo CFLAGS: -I. -std=c99 -Wall
//#cgo LDFLAGS: -lncursesw
//#include "stdout_output.h"
//#include "color.h"
import "C"

import (
	"fmt"
	"sort"
	"strings"
)

func StartWin() {
	C.StartWin()
}

func EndWin() {
	C.EndWin()
}

func DrawTableLine() {
	C.DrawTb(C.double(132.2), C.int(4134), C.int(323), C.int(433), C.double(1334), C.double(43.23), C.double(3.2), C.double(32.2), C.CString("4342"), C.CString("2343"))
}

func PrintHeaderLine() {
	SetWhite()
	C.PrintHeaderLine()
	OffWhite()
}

func PrintDivider() {
	SetWhite()
	C.PrintDivider()
	OffWhite()
}

//export Divider
func Divider() *C.char {
	return C.CString(fmt.Sprintln("───────┼───────┼───────┼───────┼────────┼────────┼────────┼────────┼────────┼────────┼────────"))
}

//export HeaderLine
func HeaderLine() *C.char {
	return C.CString(fmt.Sprintln("───────┬───────┬───────┬───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────"))
}

// 打印表头
func PrintHeader() {
	// C.PrintHeader()
	PrintField(" 耗时")
	PrintVDivider()
	PrintField(" 并发数")
	PrintVDivider()
	PrintField(" 成功数")
	PrintVDivider()
	PrintField(" 失败数")
	PrintVDivider()
	PrintField("   qps  ")
	PrintVDivider()
	PrintField("最长耗时")
	PrintVDivider()
	PrintField("最短耗时")
	PrintVDivider()
	PrintField("平均耗时")
	PrintVDivider()
	PrintField("下载字节")
	PrintVDivider()
	PrintField("字节每秒")
	PrintVDivider()
	PrintField(" 错误码")

	PrintField("\n")
}

func PrintTd(requestTimeFloat float64, concurrency int, successNum int, failureNum int, qps float64,
	maxTimeFloat float64, minTimeFloat float64, avgTime float64, receivedBytesStr string, speedStr string) {
	PrintField(fmt.Sprintf("%4.2fs", requestTimeFloat))
	PrintVDivider()
	PrintField(fmt.Sprintf("%7d", concurrency))
	PrintVDivider()
	PrintField(fmt.Sprintf("%7d", successNum))
	PrintVDivider()
	PrintField(fmt.Sprintf("%7d", failureNum))
	PrintVDivider()
	PrintField(fmt.Sprintf("%8.2f", qps))
	PrintVDivider()
	PrintField(fmt.Sprintf("%8.2f", maxTimeFloat))
	PrintVDivider()
	PrintField(fmt.Sprintf("%8.2f", minTimeFloat))
	PrintVDivider()
	PrintField(fmt.Sprintf("%8.2f", avgTime))
	PrintVDivider()
	PrintField(fmt.Sprintf("%8s", receivedBytesStr))
	PrintVDivider()
	PrintField(fmt.Sprintf("%8s", speedStr))
	PrintVDivider()
	PrintField(" 错误码")

	PrintField("\n")
}

func PrintVDivider() {
	SetWhite()
	C.PrintVDivider()
	OffWhite()
}

//export VDivider
func VDivider() *C.char {
	return C.CString(fmt.Sprint("│"))
}

func PrintField(field string) {
	// 设置颜色
	var color FieldColor = Yellow
	switch color {
	case Blue:
		SetBlue()
	case Red:
		SetRed()
	case Green:
		SetGreen()
	case Yellow:
		SetYellow()
	case Cyan:
		SetCyan()
	case Magenta:
		SetMagenta()
	default:
		SetBlue()
	}
	C.PrintField(C.CString(field))
	switch color {
	case Blue:
		OffBlue()
	case Red:
		OffRed()
	case Green:
		OffGreen()
	case Yellow:
		OffYellow()
	case Cyan:
		OffCyan()
	case Magenta:
		OffMagenta()
	default:
		OffBlue()
	}
}

func Field(field string) *C.char {
	return C.CString(field)
}

//export DrawTh
func DrawTh() *C.char {
	// 打印的时长都为毫秒 总请数
	th := fmt.Sprintf(" 耗时│ 并发数│ 成功数│ 失败数│   qps  │最长耗时│最短耗时│平均耗时│下载字节│字节每秒│ 错误码")
	th += fmt.Sprintln()
	// cstr := C.CString(th)
	// defer C.free(unsafe.Pointer(cstr)) // 释放内存
	// strptr := (*C.char)(unsafe.Pointer(cstr))
	return C.CString(th)
}

//export DrawTd
func DrawTd(requestTimeFloat C.double, concurrency C.int, successNum C.int, failureNum C.int, qps C.double,
	maxTimeFloat C.double, minTimeFloat C.double, avgTime C.double, receivedBytesStr *C.char, speedStr *C.char) *C.char {
	// 打印的时长都为毫秒
	td := fmt.Sprintf("%4.0fs│%7d│%7d│%7d│%8.2f│%8.2f│%8.2f│%8.2f│%8s│%8s│%v",
		requestTimeFloat, concurrency, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, avgTime,
		C.GoString(receivedBytesStr), C.GoString(speedStr))
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
