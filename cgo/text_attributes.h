// text_attributes.h
// #############################################################################
// # File: text_attributes.h                                                   #
// # Project: include                                                          #
// # Created Date: 2024/11/27 13:37:48                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:29:40                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __TEXT_ATTRIBUTES_H__
#define __TEXT_ATTRIBUTES_H__

#include <ncursesw/ncurses.h>

/*  多个属性可以通过 | 竖线组合 */
// 使用备选字符集显示文本
#define ATTR_ALTCHARSET A_ALTCHARSET
// 闪烁文本
#define ATTR_BLINK A_BLINK
// 亮、粗、浓厚文本
#define ATTR_BOLD A_BOLD
// 暗淡的文本（不如普通文本明亮）
#define ATTR_DIM A_DIM
// 隐藏文本
#define ATTR_INVIS A_INVIS
// 正常文本
#define ATTR_NORMAL A_NORMAL
// 反转文本
#define ATTR_REVERSE A_REVERSE
//
#define ATTR_STANDOUT A_STANDOUT
// 下划线文本
#define ATTR_UNDERLINE A_UNDERLINE
// 保护文本，避免被覆盖
#define ATTR_PROTECT A_PROTECT

// 其他不太常用的属性
#define ATTR_HORIZONTAL A_HORIZONTAL
#define ATTR_LEFT A_LEFT
#define ATTR_LOW A_LOW
#define ATTR_RIGHT A_RIGHT
#define ATTR_TOP A_TOP
// 未实现这个属性
// #define ATTR_VERTICAL A_VERTICAL

#endif    /* __TEXT_ATTRIBUTES_H__ */
