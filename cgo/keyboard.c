// #############################################################################
// # File: keyboard.c                                                          #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 17:09:07                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 18:50:35                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "keyboard.h"

//======================================标准窗口============================================
char get_ch() {
  // 如果getch报错，可以通过getch() == ERR进行判断
  return getch();
}

int get_str(char *str) { return getstr(str); }

int get_nstr(char *str, int length) { return getnstr(str, length); }

int scan_w(char *format, ...) {
  va_list args;
  va_start(args, format);
  int c = scanw(format, args);
  va_end(args);
  return c;
}

//======================================自定义窗口============================================
// 从输入中读取一个字符
char w_get_ch(const WINDOW *win) { return wgetch(win); }
// 从输入中读取字符串
int w_get_str(const WINDOW *win, char *str) { return wgetstr(win, str); }
// 从输入中读取指定字符串
int w_get_nstr(const WINDOW *win, char *str, int length) {
  return wgetnstr(win, str, length);
}
// 从输入中读取指定格式数据
int w_scan_w(const WINDOW *win, char *format, ...) {
  va_list args;
  va_start(args, format);
  int c = wscanw(win, format, args);
  va_end(args);
  return c;
}

//======================================通用============================================

bool unget_ch(char ch) { return ungetch(ch) == OK; }

bool clear_input() { return flushinp() == OK; }
// 关闭回显
bool disable_echo() { return noecho() == OK; }
// 回显输入
bool enable_echo() { return echo() == OK; }

// 启用或关闭输入等待
bool enable_delay(const WINDOW *win) { return nodelay(win, TRUE) == OK; }
bool disable_delay(const WINDOW *win) { return nodelay(win, FALSE) == OK; }

// 如果需要读取特殊的键盘输入值，可以通过以下方法启用或关闭，通过getch获取键盘输入值
bool enable_keypad(const WINDOW *win) { return keypad(win, TRUE) == OK; }
bool disable_keypad(const WINDOW *win) { return keypad(win, FALSE) == OK; }
