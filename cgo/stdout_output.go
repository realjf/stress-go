package cgo

/*
#include "ncurses.h"

void Draw() {
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
}
*/
import "C"

func SayHello() {
	C.Draw()
}
