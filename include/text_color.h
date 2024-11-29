// #############################################################################
// # File: text_color.h                                                        #
// # Project: include                                                          #
// # Created Date: 2024/11/27 15:05:38                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 11:06:09                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_COLOR_H__
#define __TEXT_COLOR_H__

#include <curses.h>

#define BLACK 1
#define RED 2
#define BLUE 3
#define YELLOW 4
#define GREEN 5
#define CYAN 6    // 青色
#define MAGENTA 7 // 品红色
#define WHITE 8
#define DODGERBLUE 9 // 天蓝色

// curses内置的颜色数值
#define COLOUR_BLACK COLOR_BLACK     // 0 黑色
#define COLOUR_RED COLOR_RED         // 1 红色
#define COLOUR_GREEN COLOR_GREEN     // 2 绿色
#define COLOUR_YELLOW COLOR_YELLOW   // 3 黄色
#define COLOUR_BLUE COLOR_BLUE       // 4 蓝色
#define COLOUR_MAGENTA COLOR_MAGENTA // 5 品红色
#define COLOUR_CYAN COLOR_CYAN       // 6 青色
#define COLOUR_WHITE COLOR_WHITE     // 7 白色
/* 后面可以自定义颜色值 */
// #define COLOUR_XXX 8
//...

//======================================标准窗口============================================
// 同时设置文本的前景色和背景色
bool std_set_text_color(short color_pair_number, void *opts);

//======================================自定义窗口============================================
bool w_set_text_color(const WINDOW *win, short color_pair_number, void *opts);

//======================================通用============================================
// 开启终端颜色支持
bool enable_color();

// 设置新颜色
bool new_color(short new_color_number, short r, short g, short b);

// 创建颜色对（前景色+背景色）
// pair的值可以自定义
bool new_color_pair(short pair, short f, short b);
// 从一个颜色值中提取rgb值
bool extract_rgb_from_color(short color, short *r, short *g, short *b);

#endif    /* __TEXT_COLOR_H__ */
