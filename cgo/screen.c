// screen.c
// #############################################################################
// # File: screen.c                                                            #
// # Project: cgo                                                              #
// # Created Date: 2024/11/29 10:11:09                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/12/01 15:04:33                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "screen.h"

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

NScreen *new_term(const char *name, NFile *out, NFile *in) {
  return newterm(name, out, in);
}
void destroy_screen(NScreen *sp) { delscreen(sp); }

NScreen *show_term(NScreen *sp) { return set_term(sp); }

char *get_term_name() { return termname(); }
