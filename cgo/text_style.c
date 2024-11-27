// #############################################################################
// # File: text_style.c                                                        #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 12:36:49                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/27 18:16:17                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "text_style.h"

bool text_attr_set(int at) { return attrset(at) == OK; }
bool enable_text_attr(int at) { return attron(at) == OK; }
bool disable_text_attr(int at) { return attroff(at) == OK; }
