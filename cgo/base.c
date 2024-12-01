// base.c
// #############################################################################
// # File: base.c                                                              #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 23:17:02                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 22:26:34                                        #
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
  return initscr() != NULL;
  // 需要更新屏幕
  // flush();
}

void shutdown() {
  // 退出ncurses
  endwin();
}

bool is_shutdown() { return isendwin(); }

const char *get_ncurses_version() { return NCURSES_VERSION; }

// 终端是否支持插入和删除字符
bool is_supported_ic() { return has_ic(); }
// 终端是否支持插入和删除行
bool is_supported_il() { return has_il(); }

bool is_supported_colors() { return has_colors(); }

bool is_color_can_change() { return can_change_color(); }
