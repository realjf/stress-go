// #############################################################################
// # File: stress_cgo.go                                                       #
// # Project: cgo                                                              #
// # Created Date: 2024/11/30 21:18:55                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 18:06:38                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################
package cgo

/*
#cgo CFLAGS: -std=gnu11 -Wall
#include "stress.h"
#include "character_set.h"
*/
import "C"
import "fmt"

type Win struct {
	win             *C.NWindow
	ncurses_version string

	table *Table
}

func NewWin() *Win {
	table := NewTable()
	win := &Win{
		table: table,
	}
	win.init()

	return win
}

func (w *Win) init() {
	w.ncurses_version = C.GoString(C.get_ncurses_version())
	C.init()
	w.win = C.new_win(0, 0, 100, 100)
}

func (w *Win) Show() {
	C.w_echo_str(w.win, C.CString(fmt.Sprintf("NCurses Version: %s!!", w.ncurses_version)))
	C.w_flush(w.win)
	w.table.Init(w.win, nil)
	C.w_flush(w.win)
	C.w_get_ch(w.win)
}

func (w *Win) Close() {
	C.destroy_win(w.win)
	C.shutdown()
}

type Table struct {
}

func NewTable() *Table {
	return &Table{}
}

func (t *Table) Init(win *C.NWindow, data []interface{}) {
	C.w_echo_str(win, C.CString(fmt.Sprintf("%c%c%c%c", C.CHAR_ULCORNER, C.CHAR_LINE_TOP, C.CHAR_LINE_TOP, C.CHAR_URCORNER)))
	// C.w_echo_str(win, C.CString(fmt.Sprintf("uptime")))
}
