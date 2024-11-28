// #############################################################################
// # File: control.c                                                           #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 11:02:02                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:01:17                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#include "control.h"

//======================================标准窗口============================================
bool std_flush() { return refresh() == OK; }

void std_move_cursor(int x, int y) { move(y, x); }

bool std_insert_ch_at(uint32_t ch) { return insch(ch) == OK; }
// 在光标处插入一行空白行，剩余部分往下滚动一行
bool std_insert_line() { return insertln() == OK; }

// 删除一个字符
bool std_delete_ch() { return delch() == OK; }
// 删除一行
bool std_delete_line() { return deleteln() == OK; }

bool std_clear_all() { return clear() == OK && flush(); }
bool std_erase_all() { return erase() == OK && flush(); }
// 清空光标后到屏幕底部所有内容
bool std_clear_to_bottom() { return clrtobot() == OK && flush(); }
// 清空光标后到行尾处所有内容
bool std_clear_to_eol() { return clrtoeol() == OK && flush(); }

//======================================自定义窗口============================================

bool w_flush(const WINDOW *win) { return wrefresh(win) == OK; }

void w_move_cursor(const WINDOW *win, int x, int y) { wmove(win, y, x); }

// 在光标后插入一个字符
bool w_insert_ch_at(const WINDOW *win, uint32_t ch) {
  return winsch(win, ch) == OK;
}
// 在光标处插入一行空白行，剩余部分往下滚动一行
bool w_insert_line(const WINDOW *win) { return winsertln(win) == OK; }
// 删除光标后一个字符
bool w_delete_ch(const WINDOW *win) { return wdelch(win) == OK; }
// 删除光标所在的行
bool w_delete_line(const WINDOW *win) { return wdeleteln(win) == OK; }

// 清理命令
// 清空屏幕
bool w_clear_all(const WINDOW *win) {
  return wclear(win) == OK && w_flush(win);
}
bool w_erase_all(const WINDOW *win) {
  return werase(win) == OK && w_flush(win);
}
// 清空光标后到屏幕底部所有内容
bool w_clear_to_bottom(const WINDOW *win) {
  return wclrtobot(win) == OK && w_flush(win);
}
// 清空光标后到行尾处所有内容
bool w_clear_to_eol(const WINDOW *win) {
  return wclrtoeol(win) == OK && w_flush(win);
}

//======================================通用============================================

// 暂停毫秒
void pause_ms(int ms) { napms(ms); }
// 获取光标位置，屏幕左上角为0,0
bool get_cursor_pos(const WINDOW *win, int x, int y) {
  return getyx(win, y, x) == OK;
}

bool set_cursor_mode(int n) { return curs_set(n) == OK; }
