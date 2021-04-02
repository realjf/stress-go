// stdout_output.c
#include "stdout_output.h"

#define TB 1
#define TH 2
#define TD 3

void StartWin() {
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    initscr();
    start_color();
    init_pair(TB, COLOR_WHITE, COLOR_BLACK);
    init_pair(TH, COLOR_RED, COLOR_BLACK);
    init_pair(TD, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(TH));
    printw(DrawTh());
    attron(COLOR_PAIR(TH));
}

void DrawTb(double requestTimeFloat,int concurrency,int successNum,int failureNum,double qps,
	double maxTimeFloat,double minTimeFloat,double avgTime, char* receivedBytesStr, char* speedStr) {
    attron(COLOR_PAIR(TD));
    printw(DrawTd(requestTimeFloat, concurrency, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, avgTime, receivedBytesStr, speedStr));
    attron(COLOR_PAIR(TD));
    refresh();
}

void EndWin() {
    getch();
    endwin();
}
