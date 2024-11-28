// #############################################################################
// # File: draw.c                                                              #
// # Project: cgo                                                              #
// # Created Date: 2024/11/28 22:03:52                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:11:09                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "draw.h"

//======================================标准窗口============================================
bool std_draw_border(uint32_t left, uint32_t right, uint32_t top,
                     uint32_t bottom, uint32_t uleft, uint32_t uright,
                     uint32_t lleft, uint32_t lright) {
  return border(left, right, top, bottom, uleft, uright, lleft, lright) == OK;
}

bool std_draw_h_line(uint32_t ch, int width) { return hline(ch, width) == OK; }
// 绘制垂直线
bool std_draw_v_line(uint32_t ch, int height) {
  return vline(ch, height) == OK;
}

//======================================自定义窗口============================================

bool w_draw_border(const WINDOW *win, uint32_t left, uint32_t right,
                   uint32_t top, uint32_t bottom, uint32_t uleft,
                   uint32_t uright, uint32_t lleft, uint32_t lright) {
  return wborder(win, left, right, top, bottom, uleft, uright, lleft, lright) ==
         OK;
}

bool w_draw_h_line(const WINDOW *win, uint32_t ch, int width) {
  return whline(win, ch, width) == OK;
}
// 绘制垂直线
bool w_draw_v_line(const WINDOW *win, uint32_t ch, int height) {
  return wvline(win, ch, height) == OK;
}

//======================================通用============================================

bool draw_box(const WINDOW *win, uint32_t vertical_char,
              uint32_t horizontal_char) {
  return box(win, vertical_char, horizontal_char) == OK;
}
