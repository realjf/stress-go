// stdout_output.c
#include "ncurses.h"

void PrintHello() {
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
}
