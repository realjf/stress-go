// stdout_output.c
#include "stdout_output.h"
#include "color.h"

void PrintDivider() {
    printw(Divider());
}

void PrintHeaderLine() {
    printw(HeaderLine());
}

void PrintHeader() {
   printw(DrawTh());
}

void StartWin() {
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
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
