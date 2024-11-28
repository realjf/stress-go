// #############################################################################
// # File: mouse.h                                                             #
// # Project: include                                                          #
// # Created Date: 2024/11/28 09:50:09                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:02:07                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <curses.h>

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

//======================================自定义窗口============================================

//======================================通用============================================
// 启用后，可以通过getch()获取输入，如果为EVENT_MOUSE事件，则可以通过get_mouse_event获取鼠标事件内容
uint32_t enable_mouse_capture(uint32_t mouse_event_mask,
                              char *old_mouse_event_mask);

bool get_mouse_event(MEVENT *event);

#endif /* __MOUSE_H__ */
