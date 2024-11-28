// #############################################################################
// # File: base.h                                                              #
// # Project: include                                                          #
// # Created Date: 2024/11/27 23:16:36                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 21:34:44                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __BASE_H__
#define __BASE_H__

#include <curses.h>

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

// 初始化ncurses
bool init();

// 关闭ncurses
void shutdown();


#endif    /* __BASE_H__ */
