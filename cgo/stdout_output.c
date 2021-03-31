// stdout_output.c
#include <ncurses.h>

void Draw()
{
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
}
