// #############################################################################
// # File: text_style.c                                                        #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 12:36:49                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 20:50:22                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "text_style.h"

//======================================标准窗口============================================
bool std_text_attr_set(int at) { return attrset(at) == OK; }
bool std_enable_text_attr(int at) { return attron(at) == OK; }
bool std_disable_text_attr(int at) { return attroff(at) == OK; }

//======================================自定义窗口============================================
bool w_text_attr_set(const WINDOW *win, int at) {
  return wattrset(win, at) == OK;
}
bool w_enable_text_attr(const WINDOW *win, int at) {
  return wattron(win, at) == OK;
}
bool w_disable_text_attr(const WINDOW *win, int at) {
  return wattroff(win, at) == OK;
}

//======================================通用============================================
