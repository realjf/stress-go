// #############################################################################
// # File: draw.h                                                              #
// # Project: include                                                          #
// # Created Date: 2024/11/28 22:03:16                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:10:43                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __DRAW_H__
#define __DRAW_H__

#include <curses.h>

//======================================标准窗口============================================

// 画边框
// left,right,top,bottom 边线
// uleft,uright,lleft,lright 角
bool std_draw_border(uint32_t left, uint32_t right, uint32_t top,
                     uint32_t bottom, uint32_t uleft, uint32_t uright,
                     uint32_t lleft, uint32_t lright);

// 绘制水平线，从光标处开始绘制
// ch可以为0
bool std_draw_h_line(uint32_t ch, int width);
// 绘制垂直线，从光标处开始绘制
bool std_draw_v_line(uint32_t ch, int height);

//======================================自定义窗口============================================

bool w_draw_border(const WINDOW *win, uint32_t left, uint32_t right,
                   uint32_t top, uint32_t bottom, uint32_t uleft,
                   uint32_t uright, uint32_t lleft, uint32_t lright);

// 绘制水平线，从光标处开始绘制
// ch可以为0
bool w_draw_h_line(const WINDOW *win, uint32_t ch, int width);
// 绘制垂直线，从光标处开始绘制
bool w_draw_v_line(const WINDOW *win, uint32_t ch, int height);

//======================================通用============================================

// 绘制box窗口边框
// vertical_char或horizontal_char为0时，使用默认字符画线
bool draw_box(const WINDOW *win, uint32_t vertical_char,
              uint32_t horizontal_char);

#endif /* __DRAW_H__ */
