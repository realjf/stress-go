// stdout_output.c
#include "stdout_output.h"
#include "color.h"

void PrintDivider() {
    printw(Divider());
}

void PrintVDivider() {
    printw(VDivider());
}

void PrintHeaderLine() {
    printw(HeaderLine());
}

void PrintHeader() {
   printw(DrawTh());
}

void PrintField(char* field) {
    printw(field);
}

void StartWin() {
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    initscr();
    keypad(stdscr, TRUE); // 设置把收到的特殊键比如箭头,转化为ncurses定义的以KEY开头的数字宏
    cbreak(); // 设置无buff模式，只有newline和return才会让getch返回
    noecho(); // 设置无回显模式
    StartColor();
    clear();
}

void DrawTb(double requestTimeFloat,int concurrency,int successNum,int failureNum,double qps,
	double maxTimeFloat,double minTimeFloat,double avgTime, char* receivedBytesStr, char* speedStr) {
    printw(DrawTd(requestTimeFloat, concurrency, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, avgTime, receivedBytesStr, speedStr));
    refresh();
}

void EndWin() {
    getch();
    endwin();
}
