// screen.h
// #############################################################################
// # File: screen.h                                                            #
// # Project: include                                                          #
// # Created Date: 2024/11/29 10:08:23                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 15:04:26                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "types.h"
#include <ncursesw/ncurses.h>

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================
// 创建屏幕，结束屏幕需要调用shutdown()
NScreen *new_term(const char *name, NFile *out, NFile *in);
// 删除屏幕
void destroy_screen(NScreen *sp);
// 设置并显示新屏幕，返回旧屏幕
NScreen *show_term(NScreen *sp);
// 获取终端名称
char *get_term_name();

#endif /* __SCREEN_H__ */
