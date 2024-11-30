// #############################################################################
// # File: control.h                                                           #
// # Project: include                                                          #
// # Created Date: 2024/11/27 11:01:12                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 19:52:26                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <curses.h>

//======================================标准窗口============================================
// 刷新屏幕，只刷新修改的部分
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
// 删除某个光标位置后的一个字符
bool std_mv_delete_ch(int x, int y);
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

// 开启和关闭窗口文本属性
void std_enable_text_attr();
void std_disable_text_attr();

//======================================自定义窗口============================================

// 刷新屏幕，只刷新修改的部分
bool w_flush(const WINDOW *win);
void w_move_cursor(const WINDOW *win, int x, int y);
// 在光标后插入一个字符
bool w_insert_ch_at(const WINDOW *win, uint32_t ch);
// 在光标处插入一行空白行，剩余部分往下滚动一行
bool w_insert_line(const WINDOW *win);
// 删除光标后一个字符
bool w_delete_ch(const WINDOW *win);
// 删除某个光标位置后的一个字符
bool w_mv_delete_ch(const WINDOW *win, int x, int y);
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

// 开启和关闭窗口文本属性
void w_enable_text_attr(const WINDOW *win);
void w_disable_text_attr(const WINDOW *win);

//======================================通用============================================
// 暂停
void pause_ms(int ms);
// 获取光标位置，屏幕左上角为0,0
bool get_cursor_pos(const WINDOW *win, int x, int y);
// 获取光标位置，相对于真实物理屏幕的位置
void get_cursor_real_pos(int x, int y);
// 设置光标状态
// 0-不可见模式，1-正常模式，2-非常明显模式
bool set_cursor_mode(int n);

// cbreak模式禁用行缓冲，行缓冲即输入\n后发送给ncurses程序方式
// cbreak模式禁止特殊字符捕获用于其他用途，而是直接作为程序输入值
bool enable_cbreak_mode();
bool disable_cbreak_mode();
// tenths值从1到255，单位为秒/10，即20为2秒
bool enable_cbreak_mode_with_halfdelay(int tenths);
void enable_cbreak_mode_with_timeout(int ms);

// 强制刷新全部内容
bool enable_flush_all(const WINDOW *win);
bool disable_flush_all(const WINDOW *win);

// 关闭回显
bool disable_echo();
// 启用回显
bool enable_echo();

// 启用或关闭输入等待，主要影响读取输入函数
bool enable_delay(const WINDOW *win);
bool disable_delay(const WINDOW *win);

// 如果需要读取特殊的键盘输入值，可以通过以下方法启用或关闭，通过getch获取键盘输入值
bool enable_keypad(const WINDOW *win);
bool disable_keypad(const WINDOW *win);

// 启用软插入还是硬插入
// enable表示软插入，即不会覆盖后面的数据，而是将后面数据往后移动
// disable表示硬插入，即直接覆盖后面的数据
void enable_idcok(const WINDOW *win);
void disable_idcok(const WINDOW *win);

// 闪烁屏幕
bool enable_flash();
// 蜂鸣声
bool enable_beep();

// 启用内容变更自动刷新屏幕
void enable_auto_flush(const WINDOW *win);
void disable_auto_flush(const WINDOW *win);

// UNIX将回车键生成\r\n符，而PC将回车键生成为\r
// 启用换行符模式，即将\r换行也识别为\n回车，都是代码10
bool enable_nl_mode();
// 禁用换行符模式，将\r识别为代码13，\n识别为代码10
bool disable_nl_mode();

bool reset_default_colors();

// 启用环境变量，如：LINES/COLUMNS等，需要在init()函数前调用
void enable_env_var();
void disable_env_var();

#endif /* __CONTROL_H__ */
