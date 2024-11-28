// #############################################################################
// # File: text_output.h                                                       #
// # Project: include                                                          #
// # Created Date: 2024/11/27 10:44:12                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:02:07                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_OUTPUT_H__
#define __TEXT_OUTPUT_H__

#include <curses.h>
#include <stdarg.h>
#include <stdio.h>

//======================================标准窗口输出============================================

/* 输出字符 */
void std_echo(uint32_t ch);
// 输出字符串
void std_echo_str(char *str);
// 格式化输出
void std_echo_fmt(char *format, ...);

// 在屏幕指定位置输出
void std_echo_at(int y, int x, uint32_t ch);
void std_echo_str_at(int y, int x, char *str);
void std_echo_fmt_at(int y, int x, char *format, ...);

//======================================自定义窗口输出============================================
void w_echo(const WINDOW *win, uint32_t ch);
void w_echo_str(const WINDOW *win, char *str);
void w_echo_fmt(const WINDOW *win, char *format, ...);

void w_echo_at(const WINDOW *win, int y, int x, uint32_t ch);
void w_echo_str_at(const WINDOW *win, int y, int x, char *str);
void w_echo_fmt_at(const WINDOW *win, int y, int x, char *format, ...);

//======================================通用============================================

#endif /* __TEXT_OUTPUT_H__ */
