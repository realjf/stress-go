// stdout_output.c
#include "stdout_output.h"

void Draw() {
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
}
