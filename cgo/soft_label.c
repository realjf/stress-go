// soft_label.c
// #############################################################################
// # File: soft_label.c                                                        #
// # Project: cgo                                                              #
// # Created Date: 2024/11/28 09:11:07                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 22:12:23                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "soft_label.h"

//======================================标准窗口============================================

//======================================自定义窗口============================================

//======================================通用============================================
bool init_soft_label(int n) { return slk_init(n) == OK; }

bool set_soft_label(int label_no, char *text, int pos) {
  return slk_set(label_no, text, pos) == OK;
}
bool show_soft_label() { return slk_refresh() == OK; }

bool remove_soft_label() { return slk_clear() == OK; }

bool restore_soft_label() { return slk_restore() == OK; }

bool set_soft_label_color(short color_pair_number) {
  return slk_color(color_pair_number) != ERR;
}

char *get_soft_label_name(int labnum) { return slk_label(labnum); }

bool touch_soft_lable() { return slk_touch() != ERR; }
