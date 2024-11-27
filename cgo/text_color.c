// #############################################################################
// # File: text_color.c                                                        #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 15:05:58                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 20:57:13                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "text_color.h"

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

bool is_supported_colors() { return has_colors(); }

bool enable_color() { return start_color() == OK; }

bool is_color_can_change() { return can_change_color(); }

bool new_color(short new_color_number, short r, short g, short b) {
  return init_color(new_color_number, r, g, b) == OK;
}

bool new_color_pair(short pair, short f, short b) {
  return init_pair(pair, f, b) == OK;
}
