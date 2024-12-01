// text_style.h
// #############################################################################
// # File: text_style.h                                                        #
// # Project: include                                                          #
// # Created Date: 2024/11/27 11:22:21                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_STYLE_H__
#define __TEXT_STYLE_H__

#include "text_attributes.h"
#include "types.h"
#include <ncursesw/ncurses.h>

//======================================标准窗口============================================
// 设置文本属性
bool std_text_attr_set(int at);
// 开启文本属性
bool std_enable_text_attr(int at);
// 关闭文本属性
bool std_disable_text_attr(int at);

// 修改已有文本属性
// n代表修改多少个字符，-1表示光标后所有字符
// color代表一个color_pair数值
bool std_change_text_attr(int n, Attr attr, short color, const void *opts);
bool std_mv_change_text_attr(int x, int y, int n, Attr attr, short color,
                             const void *opts);

//======================================自定义窗口============================================
bool w_text_attr_set(NWindow *win, int at);
// 开启文本属性
bool w_enable_text_attr(NWindow *win, int at);
// 关闭文本属性
bool w_disable_text_attr(NWindow *win, int at);

// 修改已有文本属性
// n代表修改多少个字符，-1表示光标后所有字符
// color代表一个color_pair数值
bool w_change_text_attr(NWindow *win, int n, Attr attr, short color,
                        const void *opts);
bool w_mv_change_text_attr(NWindow *win, int x, int y, int n, Attr attr,
                           short color, const void *opts);
//======================================通用============================================

#endif /* __TEXT_STYLE_H__ */
