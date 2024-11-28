// #############################################################################
// # File: mouse.c                                                             #
// # Project: cgo                                                              #
// # Created Date: 2024/11/28 09:51:36                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 11:03:53                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "mouse.h"

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

uint32_t enable_mouse_capture(uint32_t mouse_event_mask,
                              uint32_t *old_mouse_event_mask) {
  return mousemask(mouse_event_mask, old_mouse_event_mask);
}

bool get_mouse_event(MEVENT *event) { return getmouse(event) == OK; }
