package cgo

//#cgo CFLAGS: -I. -std=c99 -Wall
//#cgo LDFLAGS: -lncursesw
//#include "color.h"
import "C"

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

