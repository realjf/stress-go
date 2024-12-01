// mouse.h
// #############################################################################
// # File: mouse.h                                                             #
// # Project: include                                                          #
// # Created Date: 2024/11/28 09:50:09                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __MOUSE_H__
#define __MOUSE_H__

#include "types.h"
#include <ncursesw/ncurses.h>

// 鼠标事件
#define MOUSE_BUTTON_LEFT_CLICKED BUTTON1_CLICKED
#define MOUSE_BUTTON_LEFT_RELEASED BUTTON1_RELEASED
#define MOUSE_BUTTON_LEFT_PRESSED BUTTON1_PRESSED
#define MOUSE_BUTTON_LEFT_DOUBLE_CLICKED BUTTON1_DOUBLE_CLICKED // 双击
#define MOUSE_BUTTON_LEFT_TRIPLE_CLICKED BUTTON1_TRIPLE_CLICKED // 3连击

#define MOUSE_BUTTON_MIDDLE_CLICKED BUTTON2_CLICKED
#define MOUSE_BUTTON_MIDDLE_RELEASED BUTTON2_RELEASED
#define MOUSE_BUTTON_MIDDLE_PRESSED BUTTON2_PRESSED
#define MOUSE_BUTTON_MIDDLE_DOUBLE_CLICKED BUTTON2_DOUBLE_CLICKED // 双击
#define MOUSE_BUTTON_MIDDLE_TRIPLE_CLICKED BUTTON2_TRIPLE_CLICKED // 3连击

#define MOUSE_BUTTON_RIGHT_CLICKED BUTTON3_CLICKED
#define MOUSE_BUTTON_RIGHT_RELEASED BUTTON3_RELEASED
#define MOUSE_BUTTON_RIGHT_PRESSED BUTTON3_PRESSED
#define MOUSE_BUTTON_RIGHT_DOUBLE_CLICKED BUTTON3_DOUBLE_CLICKED // 双击
#define MOUSE_BUTTON_RIGHT_TRIPLE_CLICKED BUTTON3_TRIPLE_CLICKED // 3连击

#define EVENT_MOUSE_ALL ALL_MOUSE_EVENTS

#define EVENT_MOUSE KEY_MOUSE

//======================================标准窗口============================================

// 将窗口坐标转换为屏幕坐标
bool std_mouse_pos_to_screen(int *x, int *y);
// 将屏幕坐标转换为窗口坐标
bool std_mouse_pos_to_window(int *x, int *y);

//======================================自定义窗口============================================

// 将窗口坐标转换为屏幕坐标
bool w_mouse_pos_to_screen(NWindow *win, int *x, int *y);
// 将屏幕坐标转换为窗口坐标
bool w_mouse_pos_to_window(NWindow *win, int *x, int *y);

//======================================通用============================================
// 启用后，可以通过getch()获取输入，如果为EVENT_MOUSE事件，则可以通过get_mouse_event获取鼠标事件内容
MouseMask enable_mouse_capture(MouseMask mouse_event_mask,
                               MouseMask *old_mouse_event_mask);

bool get_mouse_event(MEVENT *event);

bool is_clicked_within_win(NWindow *win, int x, int y);

#endif /* __MOUSE_H__ */
