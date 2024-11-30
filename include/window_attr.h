// #############################################################################
// # File: window_attr.h                                                       #
// # Project: include                                                          #
// # Created Date: 2024/11/30 19:55:38                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 19:58:59                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __WINDOW_ATTR_H__
#define __WINDOW_ATTR_H__

#define WIN_ATTR_SUB_WIN 0x01   // window is a subwindow
#define WIN_ATTR_ENDLINE 0X02   // window is flush-right
#define WIN_ATTR_FULLWIN 0x04   // window is full screen
#define WIN_ATTR_SCROLLWIN 0x08 // window's bottom edge is screen bottom edge
#define WIN_ATTR_ISPAD 0x10     // window is a pad
#define WIN_ATTR_HASMOVED 0x20  // cursor has moved since last refresh
#define WIN_ATTR_WRAPPED 0x40   // cursor was just wrapped

#endif /* __WINDOW_ATTR_H__ */
