// stdout_output.c

extern "C" {
    #include "stdout_output.hpp"
}

void Draw() {
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
}
