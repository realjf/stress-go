// #############################################################################
// # File: keyboard.h                                                          #
// # Project: include                                                          #
// # Created Date: 2024/11/27 17:08:05                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 11:48:00                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "keycode.h"
#include <curses.h>
#include <stdarg.h>
#include <stdio.h>

//======================================标准窗口============================================
// 从输入中读取一个字符
uint32_t std_get_ch();
// 从输入中读取字符串
bool std_get_str(char *str);
// 从输入中读取指定字符串
bool std_get_nstr(char *str, int length);
// 从输入中读取一个字符到指定位置
bool std_mv_get_ch(int x, int y);
// 从输入中读取指定字符串到指定位置
bool std_mv_get_str(int x, int y, char *str);
// 从输入中读取指定长度字符串到指定位置
bool std_mv_get_nstr(int x, int y, char *str, int length);
// 从输入中读取指定格式数据
bool std_scan_w(char *format, ...);
// 读取光标所在位置的字符
uint32_t std_in_ch();
// 读取光标所在位置开始到行尾的字符串
bool std_in_ch_str(char *str);

//======================================自定义窗口============================================
// 从输入中读取一个字符
uint32_t w_get_ch(const WINDOW *win);
// 从输入中读取字符串
bool w_get_str(const WINDOW *win, char *str);
// 从输入中读取指定字符串
bool w_get_nstr(const WINDOW *win, char *str, int length);
// 从输入中读取一个字符到指定位置
bool w_mv_get_ch(const WINDOW *win, int x, int y);
// 从输入中读取指定字符串到指定位置
bool w_mv_get_str(const WINDOW *win, int x, int y, char *str);
// 从输入中读取指定长度字符串到指定位置
bool w_mv_get_nstr(const WINDOW *win, int x, int y, char *str, int length);
// 从输入中读取指定格式数据
bool w_scan_w(const WINDOW *win, char *format, ...);
// 读取光标所在位置的字符
uint32_t w_in_ch(const WINDOW *win);
// 读取光标所在位置开始到行尾的字符串
bool w_in_ch_str(const WINDOW *win, char *str);

//======================================通用============================================

// 将字符放回输入缓存中
bool unget_ch(uint32_t ch);

// 清空键盘输入缓存
bool clear_input();

char *get_keyname(int ch);

#endif /* __KEYBOARD_H__ */
