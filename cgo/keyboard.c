// #############################################################################
// # File: keyboard.c                                                          #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 17:09:07                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 00:03:49                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "keyboard.h"

//======================================标准窗口============================================
uint32_t std_get_ch() {
  // 如果getch报错，可以通过getch() == ERR进行判断
  return getch();
}

bool std_get_str(char *str) { return getstr(str) == OK; }

bool std_get_nstr(char *str, int length) { return getnstr(str, length) == OK; }

bool std_mv_get_ch(int x, int y) { return mvgetch(y, x) == OK; }
// 从输入中读取指定字符串到指定位置
bool std_mv_get_str(int x, int y, char *str) {
  return mvgetstr(y, x, str) == OK;
}
// 从输入中读取指定长度字符串到指定位置
bool std_mv_get_nstr(int x, int y, char *str, int length) {
  return mvgetnstr(y, x, str, length) == OK;
}

bool std_scan_w(char *format, ...) {
  va_list args;
  va_start(args, format);
  int c = scanw(format, args);
  va_end(args);
  return c == OK;
}

uint32_t std_in_ch() { return inch(); }

bool std_in_ch_str(char *str) { return inchstr(str) == OK; }

//======================================自定义窗口============================================
// 从输入中读取一个字符
uint32_t w_get_ch(const WINDOW *win) { return wgetch(win); }
// 从输入中读取字符串
bool w_get_str(const WINDOW *win, char *str) { return wgetstr(win, str) == OK; }
// 从输入中读取指定字符串
bool w_get_nstr(const WINDOW *win, char *str, int length) {
  return wgetnstr(win, str, length) == OK;
}
// 从输入中读取一个字符到指定位置
bool w_mv_get_ch(const WINDOW *win, int x, int y) {
  return mvwgetch(win, y, x) == OK;
}
// 从输入中读取指定字符串到指定位置
bool w_mv_get_str(const WINDOW *win, int x, int y, char *str) {
  return mvwgetstr(win, y, x, str) == OK;
}
// 从输入中读取指定长度字符串到指定位置
bool w_mv_get_nstr(const WINDOW *win, int x, int y, char *str, int length) {
  return mvwgetnstr(win, y, x, str, length) == OK;
}

// 从输入中读取指定格式数据
bool w_scan_w(const WINDOW *win, char *format, ...) {
  va_list args;
  va_start(args, format);
  int c = wscanw(win, format, args);
  va_end(args);
  return c == OK;
}

uint32_t w_in_ch(const WINDOW *win) { return winch(win); }

bool w_in_ch_str(const WINDOW *win, char *str) {
  return winchstr(win, str) == OK;
}

//======================================通用============================================

bool unget_ch(uint32_t ch) { return ungetch(ch) == OK; }

bool clear_input() { return flushinp() == OK; }

bool has_key(int keycode) { return has_key(keycode); }

char *get_keyname(int ch) { return keyname(ch); }

char *get_control_code_name(uint32_t c) { return unctrl(c); }
