#include "ncurses.h"
#include "color.h"



void StartColor() {
    /**
     * 初始化颜色
     */
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return;
    }
    start_color();
    init_pair(BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
}

void SetBlue() {
    attron(COLOR_PAIR(BLUE));
}

void SetRed() {
    attron(COLOR_PAIR(RED));
}

void OffBlue() {
    attroff(COLOR_PAIR(BLUE));
}

void OffRed() {
    attroff(COLOR_PAIR(RED));
}

void SetGreen() {
    attron(COLOR_PAIR(GREEN));
}

void OffGreen() {
    attroff(COLOR_PAIR(GREEN));
}

void SetYellow() {
    attron(COLOR_PAIR(YELLOW));
}

void OffYellow() {
    attroff(COLOR_PAIR(YELLOW));
}

void SetCyan() {
    attron(COLOR_PAIR(CYAN));
}

void OffCyan() {
    attroff(COLOR_PAIR(CYAN));
}

void SetMagenta() {
    attron(COLOR_PAIR(MAGENTA));
}

void OffMagenta() {
    attroff(COLOR_PAIR(MAGENTA));
}

