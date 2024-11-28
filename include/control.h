// #############################################################################
// # File: control.h                                                           #
// # Project: include                                                          #
// # Created Date: 2024/11/27 11:01:12                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/28 22:01:17                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <curses.h>

//======================================标准窗口============================================
// 刷新屏幕
bool std_flush();
// 移动光标,从0开始
/* row 对应y轴， col 对应 x轴 */
void std_move_cursor(int x, int y);

// 在光标后插入一个字符
bool std_insert_ch_at(uint32_t ch);
// 在光标处插入一行空白行，剩余部分往下滚动一行
bool std_insert_line();
// 删除光标后一个字符
bool std_delete_ch();
// 删除光标所在的行
bool std_delete_line();

// 清理命令
// 清空屏幕
bool std_clear_all();
bool std_erase_all();
// 清空光标后到屏幕底部所有内容
bool std_clear_to_bottom();
// 清空光标后到行尾处所有内容
bool std_clear_to_eol();

//======================================自定义窗口============================================

bool w_flush(const WINDOW *win);
void w_move_cursor(const WINDOW *win, int x, int y);
// 在光标后插入一个字符
bool w_insert_ch_at(const WINDOW *win, uint32_t ch);
// 在光标处插入一行空白行，剩余部分往下滚动一行
bool w_insert_line(const WINDOW *win);
// 删除光标后一个字符
bool w_delete_ch(const WINDOW *win);
// 删除光标所在的行
bool w_delete_line(const WINDOW *win);

// 清理命令
// 清空屏幕
bool w_clear_all(const WINDOW *win);
bool w_erase_all(const WINDOW *win);
// 清空光标后到屏幕底部所有内容
bool w_clear_to_bottom(const WINDOW *win);
// 清空光标后到行尾处所有内容
bool w_clear_to_eol(const WINDOW *win);

//======================================通用============================================
// 暂停
void pause_ms(int ms);
// 获取光标位置，屏幕左上角为0,0
bool get_cursor_pos(const WINDOW *win, int x, int y);
// 设置光标状态
// 0-不可见模式，1-正常模式，2-非常明显模式
bool set_cursor_mode(int n);

#endif /* __CONTROL_H__ */
