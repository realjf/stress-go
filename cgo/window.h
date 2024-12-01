// window.h
// #############################################################################
// # File: window.h                                                            #
// # Project: include                                                          #
// # Created Date: 2024/11/27 10:15:54                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 15:05:01                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "types.h"
#include "window_attr.h"
#include <ncursesw/ncurses.h>

//======================================标准窗口============================================
// 标准窗口
#define STANDARD_NScreen stdscr

// 设置窗口背景色
/* 支持特殊用法，如 set_bg_color(COLOR_PAIR(1) | '.') */
bool std_set_bg_color(int color);
// 滚动n行
bool std_scroll_n_line(int n);

// 保存屏幕内容到文件
bool std_screen_dump(const char *file);
// 加载文件内容到屏幕
bool std_screen_restore(const char *file);

void std_set_bg_attr(Char a);

// 设置滚动区域
bool std_set_scroll_region(int from_line, int to_line);

//======================================自定义窗口============================================

bool w_set_bg_color(NWindow *win, int color);
// 滚动n行
bool w_scroll_n_line(NWindow *win, int n);

// 保存窗口内容到文件
bool w_put_win(NWindow *win, NFile *file);
// 加载文件内容到新窗口
NWindow *w_get_win(NFile *file);

void w_set_bg_attr(NWindow *win, Char a);

// 设置滚动区域
bool w_set_scroll_region(NWindow *win, int from_line, int to_line);

//======================================通用============================================

// 创建窗口
NWindow *new_win(int x, int y, int width, int height);

// 子窗口，共享父窗口内存数据
// 子窗口，x和y相对于屏幕的位置
NWindow *new_subwin(NWindow *pwin, int x, int y, int width, int height);
// 子窗口，x和y相对于父窗口的位置
NWindow *new_derwin(NWindow *pwin, int x, int y, int width, int height);
// 获取子窗口左上角在父窗口的坐标
// win是子窗口
bool get_subwin_pos(NWindow *subwin, int x, int y);

// 获取屏幕大小
/* y 行数， x 列数*/
bool get_win_size(NWindow *win, int x, int y);
// 获取窗口左上角在屏幕中的坐标
bool get_win_pos(NWindow *win, int x, int y);

// 重绘整个窗口
bool touch_win(NWindow *win);
// 重绘行，y 开始行号，n 行数
bool touch_line(NWindow *win, int y, int n);

//  销毁窗口(父窗口存在的话需要重绘touch和刷新flush)
bool destroy_win(NWindow *win);

// 复制窗口内容
bool overlay_win(NWindow *swin, NWindow *dwin);
// 复制窗口内容进行覆盖显示
bool overwrite_win(NWindow *swin, NWindow *dwin);
// 复制指定大小窗口内容到指定位置
// overlay如果是TRUE，等同overlay_win，如果是FALSE,等同overwrite_win
bool copy_win(NWindow *swin, NWindow *dwin, int sx, int sy, int dx, int dy,
              int width, int height, bool overlay);
// 复制整个窗口
NWindow *dup_win(NWindow *win);

// 设置滚动窗口属性
bool enable_scroll(NWindow *win);
bool disable_scroll(NWindow *win);
// 手动设置滚动,每次调用向上滚动一行，仅当窗口滚动属性设置为TRUE才有效
bool scroll_a_line(NWindow *win);

// 移动窗口
bool move_win(NWindow *win, int x, int y);

// 获取终端波特率
int get_baudrate();

// 获取当前窗口背景属性
Char get_current_win_attr(NWindow *win);

// 重绘窗口
bool redraw_win(NWindow *win);

// 设置是否同步更新子窗口
bool enable_sync_subwin(NWindow *win);
bool disable_sync_subwin(NWindow *win);

#endif    /* __WINDOW_H__ */
