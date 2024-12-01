// base.h
// #############################################################################
// # File: base.h                                                              #
// # Project: include                                                          #
// # Created Date: 2024/11/27 23:16:36                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:30:39                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __BASE_H__
#define __BASE_H__

#include "types.h"
#include <ncursesw/ncurses.h>

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

// 初始化ncurses
bool init();

// 关闭ncurses屏幕、窗口等
void shutdown();

bool is_shutdown();

// 获取版本号
const char *get_ncurses_version();

// 终端是否支持插入和删除字符
bool is_supported_ic();
// 终端是否支持插入和删除行，或影响滚动的源文本内容
bool is_supported_il();

// 判断终端是否支持颜色文本
bool is_supported_colors();
// 确认终端是否支持修改颜色属性能力（新增颜色等）
bool is_color_can_change();

#endif /* __BASE_H__ */
