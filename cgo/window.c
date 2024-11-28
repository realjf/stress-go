// #############################################################################
// # File: window.c                                                            #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 15:39:49                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:04:58                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "window.h"

//======================================标准窗口============================================
bool std_set_bg_color(int color) { return bkgd(COLOR_PAIR(color)) == OK; }

// 滚动n行
bool std_scroll_n_line(int n) { return scrl(n) == OK; }

//======================================自定义窗口============================================

bool w_set_bg_color(const WINDOW *win, int color) {
  return wbkgd(win, COLOR_PAIR(color)) == OK;
}

// 滚动n行
bool w_scroll_n_line(const WINDOW *win, int n) { return wscrl(win, n) == OK; }

bool w_draw_border(const WINDOW *win, uint32_t left, uint32_t right,
                   uint32_t top, uint32_t bottom, uint32_t uleft,
                   uint32_t uright, uint32_t lleft, uint32_t lright) {
  return wborder(win, left, right, top, bottom, uleft, uright, lleft, lright) ==
         OK;
}

//======================================通用============================================

WINDOW *new_win(int x, int y, int width, int height) {
  return newwin(height, width, y, x);
}

// 子窗口，x和y相对于屏幕的位置
WINDOW *new_subwin(const WINDOW *pwin, int x, int y, int width, int height) {
  return subwin(pwin, height, width, y, x);
}
// 子窗口，x和y相对于父窗口的位置
WINDOW *new_derwin(const WINDOW *pwin, int x, int y, int width, int height) {
  return derwin(pwin, height, width, y, x);
}

bool enable_flash() { return flash() == OK; }

bool enable_beep() { return beep() == OK; }

bool get_win_size(const WINDOW *win, int x, int y) {
  return getmaxyx(win, y, x) == OK;
}

// 重绘整个窗口
bool touch_win(const WINDOW *win) { return touchwin(win) == OK; }
// 重绘一行
bool touch_line(const WINDOW *win, int y, int n) {
  return touchline(win, y, n) == OK;
}

// 清理窗口
bool delete_win(const WINDOW *win) { return delwin(win) == OK; }

// 复制窗口内容
bool overlay_win(const WINDOW *swin, const WINDOW *dwin) {
  return overlay(swin, dwin) == OK;
}
// 复制窗口内容进行覆盖显示
bool overwrite_win(const WINDOW *swin, const WINDOW *dwin) {
  return overwrite(swin, dwin) == OK;
}
// 复制指定大小窗口内容到指定位置
// overlay如果是TRUE，等同overlay_win，如果是FALSE,等同overwrite_win
bool copy_win(const WINDOW *swin, const WINDOW *dwin, int sx, int sy, int dx,
              int dy, int width, int height, bool overlay) {
  return copywin(swin, dwin, sy, sx, dy, dx, height, width, overlay) == OK;
}

// 复制整个窗口
WINDOW *dup_win(const WINDOW *win) { return dupwin(win); }

bool enable_scroll(const WINDOW *win) { return scrollok(win, TRUE) == OK; }
bool disable_scroll(const WINDOW *win) { return scrollok(win, FALSE) == OK; }

// 手动设置滚动,每次调用向上滚动一行，仅当窗口滚动属性设置为TRUE才有效
bool scroll_a_line(const WINDOW *win) { return scroll(win) == OK; }

// 移动窗口
bool move_win(const WINDOW *win, int x, int y) {
  return mvwin(win, y, x) == OK;
}
