// #############################################################################
// # File: keyboard.h                                                          #
// # Project: include                                                          #
// # Created Date: 2024/11/27 17:08:05                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 18:48:30                                        #
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
char get_ch();
// 从输入中读取字符串
int get_str(char *str);
// 从输入中读取指定字符串
int get_nstr(char *str, int length);
// 从输入中读取指定格式数据
int scan_w(char *format, ...);

//======================================自定义窗口============================================
// 从输入中读取一个字符
char w_get_ch(const WINDOW *win);
// 从输入中读取字符串
int w_get_str(const WINDOW *win, char *str);
// 从输入中读取指定字符串
int w_get_nstr(const WINDOW *win, char *str, int length);
// 从输入中读取指定格式数据
int w_scan_w(const WINDOW *win, char *format, ...);

//======================================通用============================================

// 将字符放回输入缓存中
bool unget_ch(char ch);

// 清空键盘输入缓存
bool clear_input();
// 关闭回显
bool disable_echo();
// 启用回显
bool enable_echo();

// 启用或关闭输入等待
bool enable_delay(const WINDOW *win);
bool disable_delay(const WINDOW *win);

// 如果需要读取特殊的键盘输入值，可以通过以下方法启用或关闭，通过getch获取键盘输入值
bool enable_keypad(const WINDOW *win);
bool disable_keypad(const WINDOW *win);

#endif /* __KEYBOARD_H__ */
