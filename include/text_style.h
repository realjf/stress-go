// #############################################################################
// # File: text_style.h                                                        #
// # Project: include                                                          #
// # Created Date: 2024/11/27 11:22:21                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 18:16:00                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_STYLE_H__
#define __TEXT_STYLE_H__

#include "text_attributes.h"
#include <curses.h>

// 设置文本属性
bool text_attr_set(int at);
// 开启文本属性
bool enable_text_attr(int at);
// 关闭文本属性
bool disable_text_attr(int at);

#endif /* __TEXT_STYLE_H__ */
