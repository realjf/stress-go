// pad.h
// #############################################################################
// # File: pad.h                                                               #
// # Project: include                                                          #
// # Created Date: 2024/11/27 22:34:29                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __PAD_H__
#define __PAD_H__

#include "types.h"
#include <ncursesw/ncurses.h>
// 虚拟窗口内存
// pad不支持mvwin、scroll、scrl、subwin、wrefresh、wnoutrefresh
//======================================标准窗口============================================

// 复制pad内容到窗口进行显示
bool std_flush_pad(NWindow *pad, int pad_x, int pad_y, int scr_x, int scr_y,
                   int width, int height);

// std_flush_pad() = std_nout_pad() + std_update_pad();
bool std_nout_pad(NWindow *pad, int pad_x, int pad_y, int scr_x, int scr_y,
                  int width, int height);
// 将虚拟屏幕内容输出到终端屏幕
bool std_update_pad();

// 输出字符，需要在调用std_flush_pad()清空之后调用才能显示在屏幕上
bool std_pad_echo_ch(NWindow *pad, Char ch);

//======================================自定义窗口============================================
// 复制pad内容到窗口进行显示
bool w_flush_pad(NWindow *pad, int pad_x, int pad_y, int scr_x, int scr_y,
                 int width, int height);

//======================================通用============================================
NWindow *new_pad(int width, int height);

// 创建子pad
NWindow *new_subpad(NWindow *pad, int x, int y, int width, int height);

bool delete_pad(NWindow *pad);

#endif /* __PAD_H__ */
