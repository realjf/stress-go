// window.c
// #############################################################################
// # File: window.c                                                            #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 15:39:49                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:51:18                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "window.h"

//======================================标准窗口============================================
bool std_set_bg_color(int color) { return bkgd(COLOR_PAIR(color)) == OK; }

// 滚动n行
bool std_scroll_n_line(int n) { return scrl(n) == OK; }

// 保存屏幕内容到文件
bool std_screen_dump(const char *file) { return scr_dump(file) == OK; }
// 加载文件内容到屏幕
bool std_screen_restore(const char *file) { return scr_restore(file) == OK; }

void std_set_bg_attr(Char a) { bkgdset(a); }

// 设置滚动区域
bool std_set_scroll_region(int from_line, int to_line) {
  return setscrreg(from_line, to_line) == OK;
}

//======================================自定义窗口============================================

bool w_set_bg_color(NWindow *win, int color) {
  return wbkgd(win, COLOR_PAIR(color)) == OK;
}

// 滚动n行
bool w_scroll_n_line(NWindow *win, int n) { return wscrl(win, n) == OK; }

// 保存窗口内容到文件
bool w_put_win(NWindow *win, NFile *file) { return putwin(win, file) == OK; }
// 加载文件内容到窗口
NWindow *w_get_win(NFile *file) { return getwin(file); }

void w_set_bg_attr(NWindow *win, Char a) { wbkgdset(win, a); }

// 设置滚动区域
bool w_set_scroll_region(NWindow *win, int from_line, int to_line) {
  return wsetscrreg(win, from_line, to_line) == OK;
}

//======================================通用============================================

NWindow *new_win(int x, int y, int width, int height) {
  return newwin(height, width, y, x);
}

// 子窗口，x和y相对于屏幕的位置
NWindow *new_subwin(NWindow *pwin, int x, int y, int width, int height) {
  return subwin(pwin, height, width, y, x);
}
// 子窗口，x和y相对于父窗口的位置
NWindow *new_derwin(NWindow *pwin, int x, int y, int width, int height) {
  return derwin(pwin, height, width, y, x);
}

bool get_subwin_pos(NWindow *win, int x, int y) {
  return getparyx(win, y, x) == OK;
}

bool get_win_size(NWindow *win, int x, int y) {
  return getmaxyx(win, y, x) == OK;
}

bool get_win_pos(NWindow *win, int x, int y) {
  return getbegyx(win, y, x) == OK;
}

// 重绘整个窗口
bool touch_win(NWindow *win) { return touchwin(win) == OK; }
// 重绘一行
bool touch_line(NWindow *win, int y, int n) {
  return touchline(win, y, n) == OK;
}

// 清理窗口
bool destroy_win(NWindow *win) { return delwin(win) == OK; }

// 复制窗口内容
bool overlay_win(NWindow *swin, NWindow *dwin) {
  return overlay(swin, dwin) == OK;
}
// 复制窗口内容进行覆盖显示
bool overwrite_win(NWindow *swin, NWindow *dwin) {
  return overwrite(swin, dwin) == OK;
}
// 复制指定大小窗口内容到指定位置
// overlay如果是TRUE，等同overlay_win，如果是FALSE,等同overwrite_win
bool copy_win(NWindow *swin, NWindow *dwin, int sx, int sy, int dx, int dy,
              int width, int height, bool overlay) {
  return copywin(swin, dwin, sy, sx, dy, dx, height, width, overlay) == OK;
}

// 复制整个窗口
NWindow *dup_win(NWindow *win) { return dupwin(win); }

bool enable_scroll(NWindow *win) { return scrollok(win, TRUE) == OK; }
bool disable_scroll(NWindow *win) { return scrollok(win, FALSE) == OK; }

// 手动设置滚动,每次调用向上滚动一行，仅当窗口滚动属性设置为TRUE才有效
bool scroll_a_line(NWindow *win) { return scroll(win) == OK; }

// 移动窗口
bool move_win(NWindow *win, int x, int y) { return mvwin(win, y, x) == OK; }

int get_baudrate() { return baudrate(); }

Char get_current_win_attr(NWindow *win) { return getbkgd(win); }

bool redraw_win(NWindow *win) { return redrawwin(win) != ERR; }

bool enable_sync_subwin(NWindow *win) { return syncok(win, TRUE) == OK; }
bool disable_sync_subwin(NWindow *win) { return syncok(win, FALSE) == OK; }
