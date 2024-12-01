// draw.h
// #############################################################################
// # File: draw.h                                                              #
// # Project: include                                                          #
// # Created Date: 2024/11/28 22:03:16                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __DRAW_H__
#define __DRAW_H__

#include "types.h"
#include <ncursesw/ncurses.h>

//======================================标准窗口============================================

// 画边框
// left,right,top,bottom 边线
// uleft,uright,lleft,lright 角
bool std_draw_border(Char left, Char right, Char top, Char bottom, Char uleft,
                     Char uright, Char lleft, Char lright);

// 绘制水平线，从光标处开始绘制
// ch可以为0
bool std_draw_h_line(Char ch, int width);
// 绘制垂直线，从光标处开始绘制
bool std_draw_v_line(Char ch, int height);
// 在指定位置绘制水平线
bool std_draw_mv_h_line(int x, int y, Char ch, int width);
bool std_draw_mv_v_line(int x, int y, Char ch, int height);

//======================================自定义窗口============================================

bool w_draw_border(NWindow *win, Char left, Char right, Char top, Char bottom,
                   Char uleft, Char uright, Char lleft, Char lright);

// 绘制水平线，从光标处开始绘制
// ch可以为0
bool w_draw_h_line(NWindow *win, Char ch, int width);
// 绘制垂直线，从光标处开始绘制
bool w_draw_v_line(NWindow *win, Char ch, int height);

// 在指定位置绘制水平线
bool w_draw_mv_h_line(NWindow *win, int x, int y, Char ch, int width);
bool w_draw_mv_v_line(NWindow *win, int x, int y, Char ch, int height);

//======================================通用============================================

// 绘制box窗口边框
// vertical_char或horizontal_char为0时，使用默认字符画线
bool draw_box(NWindow *win, Char vertical_char, Char horizontal_char);

#endif /* __DRAW_H__ */
