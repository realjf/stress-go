// #############################################################################
// # File: text_color.c                                                        #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 15:05:58                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 11:06:21                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "text_color.h"

//======================================标准窗口============================================

bool std_set_text_color(short color_pair_number, void *opts) {
  return color_set(color_pair_number, opts) == OK;
}

//======================================自定义窗口============================================

bool w_set_text_color(const WINDOW *win, short color_pair_number, void *opts) {
  return wcolor_set(win, color_pair_number, opts) == OK;
}
//======================================通用============================================

bool enable_color() { return start_color() == OK; }


bool new_color(short new_color_number, short r, short g, short b) {
  return init_color(new_color_number, r, g, b) == OK;
}

bool new_color_pair(short pair, short f, short b) {
  return init_pair(pair, f, b) == OK;
}

bool extract_rgb_from_color(short color, short *r, short *g, short *b) {
  return color_content(color, r, g, b) == OK;
}
