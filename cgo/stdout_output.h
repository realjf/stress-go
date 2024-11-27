// stdout_output.h
#ifndef __STDOUT_OUTPUT_H__
#define __STDOUT_OUTPUT_H__
#include <fcntl.h>
#include <locale.h> // 中文乱码问题
#include <ncursesw/ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

void StartWin();
void EndWin();
void PrintDivider();
void PrintHeaderLine();
void PrintHeader();
void PrintVDivider();
void ReturnLine();
void PrintField(char *field);
void DrawTb(double requestTimeFloat, int concurrency, int successNum,
            int failureNum, double qps, double maxTimeFloat,
            double minTimeFloat, double avgTime, char *receivedBytesStr,
            char *speedStr);

extern char *DrawTh();
extern char *DrawTd(double requestTimeFloat, int concurrency, int successNum,
                    int failureNum, double qps, double maxTimeFloat,
                    double minTimeFloat, double avgTime, char *receivedBytesStr,
                    char *speedStr);
extern char *Divider();
extern char *HeaderLine();
extern char *VDivider();
extern char *Field();

static void finish(int sig);

#endif    /* __STDOUT_OUTPUT_H__ */
