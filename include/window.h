// #############################################################################
// # File: window.h                                                            #
// # Project: include                                                          #
// # Created Date: 2024/11/27 10:15:54                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 11:17:54                                        #
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
bool std_set_bg_color(int color);
// 滚动n行
bool std_scroll_n_line(int n);

// 保存屏幕内容到文件
bool std_screen_dump(const char *file);
// 加载文件内容到屏幕
bool std_screen_restore(const char *file);

void std_set_bg_attr(uint32_t a);

//======================================自定义窗口============================================

bool w_set_bg_color(const WINDOW *win, int color);
// 滚动n行
bool w_scroll_n_line(const WINDOW *win, int n);

// 保存窗口内容到文件
bool w_put_win(const WINDOW *win, FILE *file);
// 加载文件内容到新窗口
WINDOW *w_get_win(FILE *file);

void w_set_bg_attr(const WINDOW *win, uint32_t a);

//======================================通用============================================

// 创建窗口
WINDOW *new_win(int x, int y, int width, int height);

// 子窗口，共享父窗口内存数据
// 子窗口，x和y相对于屏幕的位置
WINDOW *new_subwin(const WINDOW *pwin, int x, int y, int width, int height);
// 子窗口，x和y相对于父窗口的位置
WINDOW *new_derwin(const WINDOW *pwin, int x, int y, int width, int height);
// 获取子窗口左上角在父窗口的坐标
// win是子窗口
bool get_subwin_pos(const WINDOW *subwin, int x, int y);



// 获取屏幕大小
/* y 行数， x 列数*/
bool get_win_size(const WINDOW *win, int x, int y);
// 获取窗口左上角在屏幕中的坐标
bool get_win_pos(const WINDOW *win, int x, int y);

// 重绘整个窗口
bool touch_win(const WINDOW *win);
// 重绘行，y 开始行号，n 行数
bool touch_line(const WINDOW *win, int y, int n);

//  销毁窗口(父窗口存在的话需要重绘touch和刷新flush)
bool delete_win(WINDOW *win);

// 复制窗口内容
bool overlay_win(const WINDOW *swin, const WINDOW *dwin);
// 复制窗口内容进行覆盖显示
bool overwrite_win(const WINDOW *swin, const WINDOW *dwin);
// 复制指定大小窗口内容到指定位置
// overlay如果是TRUE，等同overlay_win，如果是FALSE,等同overwrite_win
bool copy_win(const WINDOW *swin, const WINDOW *dwin, int sx, int sy, int dx,
              int dy, int width, int height, bool overlay);
// 复制整个窗口
WINDOW *dup_win(const WINDOW *win);

// 设置滚动窗口属性
bool enable_scroll(const WINDOW *win);
bool disable_scroll(const WINDOW *win);
// 手动设置滚动,每次调用向上滚动一行，仅当窗口滚动属性设置为TRUE才有效
bool scroll_a_line(const WINDOW *win);

// 移动窗口
bool move_win(const WINDOW *win, int x, int y);

// 获取终端波特率
int get_baudrate();

// 获取当前窗口背景属性
uint32_t get_current_win_attr(const WINDOW *win);

#endif    /* __WINDOW_H__ */
