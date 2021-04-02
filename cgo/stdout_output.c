// stdout_output.c
#include "stdout_output.h"

void StartWin() {
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    initscr();
    printw(DrawTh());
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
