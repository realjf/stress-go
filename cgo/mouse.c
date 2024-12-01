// mouse.c
// #############################################################################
// # File: mouse.c                                                             #
// # Project: cgo                                                              #
// # Created Date: 2024/11/28 09:51:36                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 14:32:08                                        #
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

bool w_mouse_pos_to_screen(NWindow *win, int *x, int *y) {
  return wmouse_trafo(win, y, x, TRUE);
}
bool w_mouse_pos_to_window(NWindow *win, int *x, int *y) {
  return wmouse_trafo(win, y, x, FALSE);
}
//======================================通用============================================

MouseMask enable_mouse_capture(MouseMask mouse_event_mask,
                               MouseMask *old_mouse_event_mask) {
  return mousemask(mouse_event_mask, old_mouse_event_mask);
}

bool get_mouse_event(MEVENT *event) { return getmouse(event) == OK; }

bool is_clicked_within_win(NWindow *win, int x, int y) {
  return wenclose(win, y, x);
}
