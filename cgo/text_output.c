// #############################################################################
// # File: text_output.c                                                       #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 10:54:30                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 18:52:05                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "text_output.h"

//======================================标准窗口输出============================================
void echo(char ch) {
  // 输出字符
  addch(ch);
}

void echo_str(char *str) {
  // 输出字符串
  addstr(str);
}

void echo_fmt(char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  printw(format, args);
  va_end(args);
}

void echo_at(int y, int x, char ch) { mvaddch(y, x, ch); }

void echo_str_at(int y, int x, char *str) { mvaddstr(y, x, str); }

void echo_fmt_at(int y, int x, char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  mvprintw(y, x, format, args);
  va_end(args);
}

//======================================自定义窗口输出============================================

void w_echo(const WINDOW *win, char ch) { waddch(win, ch); }
void w_echo_str(const WINDOW *win, char *str) { waddstr(win, str); }
void w_echo_fmt(const WINDOW *win, char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  wprintw(win, format, args);
  va_end(args);
}

void w_echo_at(const WINDOW *win, int y, int x, char ch) {
  mvwaddch(win, y, x, ch);
}
void w_echo_str_at(const WINDOW *win, int y, int x, char *str) {
  mvwaddstr(win, y, x, str);
}
void w_echo_fmt_at(const WINDOW *win, int y, int x, char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  mvwprintw(win, y, x, format, args);
  va_end(args);
}

//======================================通用============================================
