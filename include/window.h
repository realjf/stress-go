// #############################################################################
// # File: window.h                                                            #
// # Project: include                                                          #
// # Created Date: 2024/11/27 10:15:54                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 19:01:54                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <curses.h>

//======================================标准窗口============================================
// 标准窗口
#define STANDARD_SCREEN stdscr

// 设置窗口背景色
/* 支持特殊用法，如 set_bg_color(COLOR_PAIR(1) | '.') */
bool set_bg_color(int color);

//======================================自定义窗口============================================

bool w_set_bg_color(const WINDOW *win, int color);
// 创建窗口
WINDOW *new_win(int x, int y, int width, int height);

//======================================通用============================================

// 闪烁屏幕
bool enable_flash();
// 蜂鸣声
bool enable_beep();

// 获取屏幕大小
/* y 行数， x 列数*/
bool get_win_size(const WINDOW *win, int x, int y);

// 重绘整个窗口
bool redraw_win(const WINDOW *win);

// 清理窗口
bool delete_win(const WINDOW *win);

#endif /* __WINDOW_H__ */
