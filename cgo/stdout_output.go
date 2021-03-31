package cgo

/**
void Draw();
*/
import "C"

func Draw() {
	C.Draw()
}
