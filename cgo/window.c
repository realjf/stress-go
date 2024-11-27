// #############################################################################
// # File: window.c                                                            #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 15:39:49                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 19:02:13                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "window.h"

//======================================标准窗口============================================
bool set_bg_color(int color) { return bkgd(COLOR_PAIR(color)) == OK; }

//======================================自定义窗口============================================

bool w_set_bg_color(const WINDOW *win, int color) {
  return wbkgd(win, COLOR_PAIR(color)) == OK;
}

WINDOW *new_win(int x, int y, int width, int height) {
  return newwin(height, width, y, x);
}

//======================================通用============================================

bool enable_flash() { return flash() == OK; }

bool enable_beep() { return beep() == OK; }

bool get_win_size(const WINDOW *win, int x, int y) {
  return getmaxyx(win, y, x) == OK;
}

// 重绘整个窗口
bool redraw_win(const WINDOW *win) { return touchwin(win) == OK; }

// 清理窗口
bool delete_win(const WINDOW *win) { return delwin(win) == OK; }
