package cgo

// #cgo LDFLAGS: -lncurses
//#include "stdout_output.c"
import "C"

func SayHello() {
	C.PrintHello()
}
