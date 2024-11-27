// #############################################################################
// # File: text_style.h                                                        #
// # Project: include                                                          #
// # Created Date: 2024/11/27 11:22:21                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 20:50:44                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_STYLE_H__
#define __TEXT_STYLE_H__

#include "text_attributes.h"
#include <curses.h>

//======================================标准窗口============================================
// 设置文本属性
bool std_text_attr_set(int at);
// 开启文本属性
bool std_enable_text_attr(int at);
// 关闭文本属性
bool std_disable_text_attr(int at);

//======================================自定义窗口============================================
bool w_text_attr_set(const WINDOW *win, int at);
// 开启文本属性
bool w_enable_text_attr(const WINDOW *win, int at);
// 关闭文本属性
bool w_disable_text_attr(const WINDOW *win, int at);

//======================================通用============================================

#endif /* __TEXT_STYLE_H__ */
