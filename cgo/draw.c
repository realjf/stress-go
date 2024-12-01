// draw.c
// #############################################################################
// # File: draw.c                                                              #
// # Project: cgo                                                              #
// # Created Date: 2024/11/28 22:03:52                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "draw.h"

//======================================标准窗口============================================
bool std_draw_border(Char left, Char right, Char top, Char bottom, Char uleft,
                     Char uright, Char lleft, Char lright) {
  return border(left, right, top, bottom, uleft, uright, lleft, lright) == OK;
}

bool std_draw_h_line(Char ch, int width) { return hline(ch, width) == OK; }
// 绘制垂直线
bool std_draw_v_line(Char ch, int height) { return vline(ch, height) == OK; }

bool std_draw_mv_h_line(int x, int y, Char ch, int width) {
  return mvhline(y, x, ch, width) == OK;
}
bool std_draw_mv_v_line(int x, int y, Char ch, int height) {
  return mvvline(y, x, ch, height) == OK;
}

//======================================自定义窗口============================================

bool w_draw_border(NWindow *win, Char left, Char right, Char top, Char bottom,
                   Char uleft, Char uright, Char lleft, Char lright) {
  return wborder(win, left, right, top, bottom, uleft, uright, lleft, lright) ==
         OK;
}

bool w_draw_h_line(NWindow *win, Char ch, int width) {
  return whline(win, ch, width) == OK;
}
// 绘制垂直线
bool w_draw_v_line(NWindow *win, Char ch, int height) {
  return wvline(win, ch, height) == OK;
}

bool w_draw_mv_h_line(NWindow *win, int x, int y, Char ch, int width) {
  return mvwhline(win, y, x, ch, width) == OK;
}
bool w_draw_mv_v_line(NWindow *win, int x, int y, Char ch, int height) {
  return mvwvline(win, y, x, ch, height) == OK;
}

//======================================通用============================================

bool draw_box(NWindow *win, Char vertical_char, Char horizontal_char) {
  return box(win, vertical_char, horizontal_char) == OK;
}
