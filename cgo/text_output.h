// text_output.h
// #############################################################################
// # File: text_output.h                                                       #
// # Project: include                                                          #
// # Created Date: 2024/11/27 10:44:12                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_OUTPUT_H__
#define __TEXT_OUTPUT_H__

#include "types.h"
#include <ncursesw/ncurses.h>
#include <stdarg.h>

//======================================标准窗口输出============================================

/* 输出字符 */
void std_echo(Char ch);
// 输出单个字符，性能好
void std_echo_ch(Char ch);
// 输出字符串
void std_echo_str(char *str);
// 格式化输出
void std_echo_fmt(char *format, ...);

// 在屏幕指定位置输出
void std_echo_at(int y, int x, Char ch);
void std_echo_str_at(int y, int x, char *str);
void std_echo_fmt_at(int y, int x, char *format, ...);

bool std_vprintw(const char *fmt, ...);

//======================================自定义窗口输出============================================
void w_echo(NWindow *win, Char ch);
void w_echo_ch(NWindow *win, Char ch);
void w_echo_str(NWindow *win, char *str);
void w_echo_fmt(NWindow *win, char *format, ...);

void w_echo_at(NWindow *win, int y, int x, Char ch);
void w_echo_str_at(NWindow *win, int y, int x, char *str);
void w_echo_fmt_at(NWindow *win, int y, int x, char *format, ...);

bool w_vprintw(NWindow *win, const char *fmt, ...);

//======================================通用============================================

#endif /* __TEXT_OUTPUT_H__ */
