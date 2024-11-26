// #############################################################################
// # File: base.c                                                              #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 23:17:02                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 23:17:23                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "base.h"

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================
bool init() {
  // 初始化ncurses，也可以使用newterm()函数
  initscr();
  // 更新屏幕
  flush();
}

void shutdown() {
  // 退出ncurses
  endwin();
}
