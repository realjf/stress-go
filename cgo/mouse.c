// #############################################################################
// # File: mouse.c                                                             #
// # Project: cgo                                                              #
// # Created Date: 2024/11/28 09:51:36                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 19:54:17                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "mouse.h"

//======================================标准窗口============================================
bool std_mouse_pos_to_screen(int *x, int *y) { return mouse_trafo(y, x, TRUE); }
bool std_mouse_pos_to_window(int *x, int *y) {
  return mouse_trafo(y, x, FALSE);
}

//======================================自定义窗口============================================

bool w_mouse_pos_to_screen(const WINDOW *win, int *x, int *y) {
  return wmouse_trafo(win, y, x, TRUE);
}
bool w_mouse_pos_to_window(const WINDOW *win, int *x, int *y) {
  return wmouse_trafo(win, y, x, FALSE);
}
//======================================通用============================================

uint32_t enable_mouse_capture(uint32_t mouse_event_mask,
                              char *old_mouse_event_mask) {
  return mousemask(mouse_event_mask, old_mouse_event_mask);
}

bool get_mouse_event(MEVENT *event) { return getmouse(event) == OK; }

bool is_clicked_within_win(const WINDOW *win, int x, int y) {
  return wenclose(win, y, x);
}
