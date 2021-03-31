// stdout_output.c
#include "stdout_output.h"

void PrintHello() {
    setlocale(LC_ALL,"");
    initscr();
    printw("Hello World!!!");
    printw(DrawTable());
    refresh();
    getch();
    endwin();
}
