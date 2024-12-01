// soft_label.h
// #############################################################################
// # File: soft_label.h                                                        #
// # Project: include                                                          #
// # Created Date: 2024/11/28 09:10:29                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:29:52                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __SOFT_LABEL_H__
#define __SOFT_LABEL_H__

#include "types.h"
#include <ncursesw/ncurses.h>

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

// 初始化软标签，必须在init函数前调用，n的值决定了软标签的数量以及如何排列在屏幕上
// n：0-8个标签2列显示，1-8个标签3列显示，2-12个标签3列显示，3-12个标签3列显示
bool init_soft_label(int n);

// 设置软标签文本和文本方向
// pos：0-左对齐，1-居中，2-右对齐
bool set_soft_label(int label_no, char *text, int pos);
// 显示软标签
bool show_soft_label();
// 移除屏幕上的软标签
bool remove_soft_label();
// 重新在屏幕上显示软标签
bool restore_soft_label();

// 设置标签颜色
bool set_soft_label_color(short color_pair_number);
// 获取标签名称
char *get_soft_label_name(int labnum);
// 强制要求更新软标签
bool touch_soft_lable();

#endif /* __SOFT_LABEL_H__ */
