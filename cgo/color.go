package cgo

//#cgo CFLAGS: -I. -std=c99 -Wall
//#cgo LDFLAGS: -lncursesw
//#include "color.h"
import "C"

// 开启颜色功能
func StartColor() {
	C.StartColor()
}

func SetBlue() {
	C.SetBlue()
}

func SetRed() {
	C.SetRed()
}

func OffBlue() {
	C.OffBlue()
}

func OffRed() {
	C.OffRed()
}

func SetGreen() {
	C.SetGreen()
}

func OffGreen() {
	C.OffGreen()
}

func SetYellow() {
	C.SetYellow()
}

func OffYellow() {
	C.OffYellow()
}

// 青色
func SetCyan() {
	C.SetCyan()
}

func OffCyan() {
	C.OffCyan()
}
// 品红色
func SetMagenta() {
	C.SetMagenta()
}

func OffMagenta() {
	C.OffMagenta()
}