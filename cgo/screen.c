// #############################################################################
// # File: screen.c                                                            #
// # Project: cgo                                                              #
// # Created Date: 2024/11/29 10:11:09                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 23:49:29                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "screen.h"

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================

SCREEN *new_term(const char *name, FILE *out, FILE *in) {
  return newterm(name, out, in);
}
void delete_screen(SCREEN *sp) { delscreen(sp); }

SCREEN *show_term(SCREEN *sp) { return set_term(sp); }

char *get_term_name() { return termname(); }