package cgo

//#include <stdout_output.hpp>
import "C"

func Draw() {
	C.Draw()
}
