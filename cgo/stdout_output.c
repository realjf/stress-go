// stdout_output.c
#include "stdout_output.h"

void PrintHello() {
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    initscr();
    printw("Hello World!!!");
    printw(DrawTable());
    refresh();
    getch();
    endwin();
}
