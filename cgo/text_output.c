// #############################################################################
// # File: text_output.c                                                       #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 10:54:30                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 22:38:39                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "text_output.h"

//======================================标准窗口输出============================================
void std_echo(uint32_t ch) {
  // 输出字符
  addch(ch);
}

void std_echo_ch(uint32_t ch) { echochar(ch); }

void std_echo_str(char *str) {
  // 输出字符串
  addstr(str);
}

void std_echo_fmt(char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  printw(format, args);
  va_end(args);
}

void std_echo_at(int y, int x, uint32_t ch) { mvaddch(y, x, ch); }

void std_echo_str_at(int y, int x, char *str) { mvaddstr(y, x, str); }

void std_echo_fmt_at(int y, int x, char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  mvprintw(y, x, format, args);
  va_end(args);
}

bool std_vprintw(const char *fmt, ...) {
  va_list args;
  int a = vw_printw(stdscr, fmt, args);
  va_end(args);
  return a == OK;
}

//======================================自定义窗口输出============================================

void w_echo(const WINDOW *win, uint32_t ch) { waddch(win, ch); }
void w_echo_ch(const WINDOW *win, uint32_t ch) { wechochar(win, ch); }
void w_echo_str(const WINDOW *win, char *str) { waddstr(win, str); }
void w_echo_fmt(const WINDOW *win, char *format, ...) {
  // 定义va_list变量
  va_list args;
  // 初始化args
  va_start(args, format);
  wprintw(win, format, args);
  va_end(args);
}

void w_echo_at(const WINDOW *win, int y, int x, uint32_t ch) {
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

bool w_vprintw(const WINDOW *win, const char *fmt, ...) {
  va_list args;
  int a = vw_printw(win, fmt, args);
  va_end(args);
  return a == OK;
}

//======================================通用============================================
