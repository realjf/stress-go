// #############################################################################
// # File: control.c                                                           #
// # Project: cgo                                                              #
// # Created Date: 2024/11/27 11:02:02                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 19:51:36                                        #
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
// 删除某个光标位置后的一个字符
bool std_mv_delete_ch(int x, int y) { return mvdelch(y, x) == OK; }
// 删除一行
bool std_delete_line() { return deleteln() == OK; }

bool std_clear_all() { return clear() == OK && flush(); }
bool std_erase_all() { return erase() == OK && flush(); }
// 清空光标后到屏幕底部所有内容
bool std_clear_to_bottom() { return clrtobot() == OK && flush(); }
// 清空光标后到行尾处所有内容
bool std_clear_to_eol() { return clrtoeol() == OK && flush(); }

void std_enable_text_attr() { standout(); }
void std_disable_text_attr() { standend(); }

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
// 删除某个光标位置后的一个字符
bool w_mv_delete_ch(const WINDOW *win, int x, int y) {
  return mvwdelch(win, y, x) == OK;
}
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

void w_enable_text_attr(const WINDOW *win) { wstandout(win); }
void w_disable_text_attr(const WINDOW *win) { wstandend(win); }

//======================================通用============================================

// 暂停毫秒
void pause_ms(int ms) { napms(ms); }
// 获取光标位置，屏幕左上角为0,0
bool get_cursor_pos(const WINDOW *win, int x, int y) {
  return getyx(win, y, x) == OK;
}

void get_cursor_real_pos(int x, int y) { getsyx(y, x); }

bool set_cursor_mode(int n) { return curs_set(n) == OK; }

bool enable_cbreak_mode() { return cbreak() == OK; }
bool disable_cbreak_mode() { return nocbreak() == OK; }

bool enable_cbreak_mode_with_halfdelay(int tenths) {
  return halfdelay(tenths) == OK;
}
void enable_cbreak_mode_with_timeout(int ms) { timeout(ms); }

bool enable_flush_all(const WINDOW *win) { return clearok(win, TRUE) == OK; }
bool disable_flush_all(const WINDOW *win) { return clearok(win, FALSE) == OK; }

// 关闭回显
bool disable_echo() { return noecho() == OK; }
// 回显输入
bool enable_echo() { return echo() == OK; }

// 启用或关闭输入等待
bool enable_delay(const WINDOW *win) { return nodelay(win, TRUE) == OK; }
bool disable_delay(const WINDOW *win) { return nodelay(win, FALSE) == OK; }

// 如果需要读取特殊的键盘输入值，可以通过以下方法启用或关闭，通过getch获取键盘输入值
bool enable_keypad(const WINDOW *win) { return keypad(win, TRUE) == OK; }
bool disable_keypad(const WINDOW *win) { return keypad(win, FALSE) == OK; }

void enable_idcok(const WINDOW *win) { idcok(win, TRUE); }
void disable_idcok(const WINDOW *win) { idcok(win, FALSE); }

bool enable_flash() { return flash() == OK; }

bool enable_beep() { return beep() == OK; }

void enable_auto_flush(const WINDOW *win) { immedok(win, TRUE); }
void disable_auto_flush(const WINDOW *win) { immedok(win, FALSE); }

bool enable_nl_mode() { return nl() == OK; }
bool disable_nl_mode() { return nonl() == OK; }

bool reset_default_colors() { return use_default_colors() == OK; }

void enable_env_var() { use_env(TRUE); }
void disable_env_var() { use_env(FALSE); }
