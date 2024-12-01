// pad.c
// #############################################################################
// # File: pad.c                                                               #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 22:37:45                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "pad.h"

//======================================标准窗口============================================
// 复制pad内容到窗口进行显示
bool std_flush_pad(NWindow *pad, int pad_x, int pad_y, int scr_x, int scr_y,
                   int width, int height) {
  return prefresh(pad, pad_y, pad_x, scr_y, scr_x, height, width) == OK;
}

// prefresh() = pnoutrefresh() + doupdate();
bool std_nout_pad(NWindow *pad, int pad_x, int pad_y, int scr_x, int scr_y,
                  int width, int height) {
  return pnoutrefresh(pad, pad_y, pad_x, scr_y, scr_x, height, width) == OK;
}

bool std_update_pad() { return doupdate() == OK; }

// 输出字符
bool std_pad_echo_ch(NWindow *pad, Char ch) { return pechochar(pad, ch) == OK; }

//======================================自定义窗口============================================
// 复制pad内容到窗口进行显示
bool w_flush_pad(NWindow *pad, int pad_x, int pad_y, int scr_x, int scr_y,
                 int width, int height) {
  return prefresh(pad, pad_y, pad_x, scr_y, scr_x, height, width) == OK;
}

//======================================通用============================================
NWindow *new_pad(int width, int height) { return newpad(height, width); }

NWindow *new_subpad(NWindow *pad, int x, int y, int width, int height) {
  return subpad(pad, height, width, y, x);
}

bool delete_pad(NWindow *pad) { return delwin(pad) == OK; }
