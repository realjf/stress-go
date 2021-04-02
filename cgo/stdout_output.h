// stdout_output.h
#ifndef STDOUT_OUTPUT_H__
#define STDOUT_OUTPUT_H__
#include "ncurses.h"
#include <locale.h> // 中文乱码问题
#include <stdlib.h>

void StartWin();
void EndWin();
void PrintDivider();
void PrintHeaderLine();
void PrintHeader();
void DrawTb(double requestTimeFloat,int concurrency,int successNum,int failureNum,double qps,
	double maxTimeFloat,double minTimeFloat,double avgTime, char* receivedBytesStr, char* speedStr);


extern char* DrawTh();
extern char* DrawTd(double requestTimeFloat,int concurrency,int successNum,int failureNum,double qps,
	double maxTimeFloat,double minTimeFloat,double avgTime, char* receivedBytesStr, char* speedStr);
extern char* Divider();
extern char* HeaderLine();


#endif