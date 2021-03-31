// stdout_output.h
#ifndef STDOUT_OUTPUT_H__
#define STDOUT_OUTPUT_H__
#include "ncurses.h"
#include <locale.h> // 中文乱码问题

void PrintHello();
extern char* DrawTable();

#endif