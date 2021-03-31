// stdout_output.c
#include "stdout_output.h"

void PrintHello() {
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
}
