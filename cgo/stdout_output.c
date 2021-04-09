// stdout_output.c
#include "stdout_output.h"
#include "color.h"

struct termios oldt;
int lines, cols;
WINDOW *my_win;
int x, y;

void PrintDivider() {
    mvwprintw(my_win, x, y, Divider());
    x++;
    refresh();
    wrefresh(my_win);
}

void PrintVDivider() {
    y += 1;
    mvwprintw(my_win, x, y, VDivider());
    y += 1;
}

void PrintHeaderLine() {
    mvwprintw(my_win, x, y, HeaderLine());
    x++;
    refresh();
    wrefresh(my_win);
}

void PrintHeader() {
   mvwprintw(my_win, x, y, DrawTh());
   x++;
   refresh();
   wrefresh(my_win);
}

void PrintField(char* field) {
   mvwprintw(my_win, x, y, field);
   y += 8;
   refresh();
   wrefresh(my_win);
}

void ReturnLine() {
    x++;
    y = 0;
    refresh();
    wrefresh(my_win);
}

void StartWin() {
    if (!isatty(STDIN_FILENO)) {
        fprintf(stderr, "this problem should be run at a terminal\n");
        exit(1);
    }
    // save terminal setting
    if(tcgetattr(STDIN_FILENO, &oldt) < 0) {
        perror("save the terminal setting");
        exit(1);
    }
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    initscr();
    getmaxyx(stdscr, lines, cols);
    my_win = newwin(lines,cols,0,0);
    refresh(); // 刷新屏幕内容
    // box(my_win, 0, 0); // 盒子
    // int tlc, trc, blc, brc;
    // tlc = trc = blc = brc = 0;
    // wborder(my_win, 0, 0, 0, 0, tlc, trc, blc, brc); // 盒子边界
    scrollok(my_win, TRUE);
    scroll(my_win);
    x = y = 0;
    wrefresh(my_win);
    keypad(stdscr, TRUE); // 设置把收到的特殊键比如箭头,转化为ncurses定义的以KEY开头的数字宏
    cbreak(); // 设置无缓冲模式，只有newline和return才会让getch返回
    noecho(); // 设置无回显模式
    StartColor();
    clear(); // 清除窗口信息
}

void DrawTb(double requestTimeFloat,int concurrency,int successNum,int failureNum,double qps,
	double maxTimeFloat,double minTimeFloat,double avgTime, char* receivedBytesStr, char* speedStr) {
    mvwprintw(my_win, x, y, DrawTd(requestTimeFloat, concurrency, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, avgTime, receivedBytesStr, speedStr));
    refresh();
}

void EndWin() {
    getch(); // 输入一个字符
    // restore termial setting
    if(tcsetattr(STDIN_FILENO,TCSANOW, &oldt) < 0) {
        perror("restore the termial setting");
        exit(1);
    }
    delwin(my_win);
    endwin();
}
