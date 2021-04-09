#include "ncurses.h"
#include "color.h"

extern WINDOW *scrwin;
extern WINDOW *boxwin;

void StartColor() {
    /**
     * 初始化颜色
     */
    if (has_colors() == FALSE) {
        delwin(scrwin);
        delwin(boxwin);
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
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
    // init_color(COLOR_BLUE, 30, 144, 255);
}

void SetBlue() {
    wattron(scrwin, COLOR_PAIR(BLUE));
}

void SetRed() {
    wattron(scrwin,COLOR_PAIR(RED));
}

void OffBlue() {
    wattroff(scrwin, COLOR_PAIR(BLUE));
}

void OffRed() {
    wattroff(scrwin, COLOR_PAIR(RED));
}

void SetGreen() {
    wattron(scrwin, COLOR_PAIR(GREEN));
}

void OffGreen() {
    wattroff(scrwin, COLOR_PAIR(GREEN));
}

void SetYellow() {
    wattron(scrwin, COLOR_PAIR(YELLOW));
}

void OffYellow() {
    wattroff(scrwin, COLOR_PAIR(YELLOW));
}

void SetCyan() {
    wattron(scrwin, COLOR_PAIR(CYAN));
}

void OffCyan() {
    wattroff(scrwin, COLOR_PAIR(CYAN));
}

void SetMagenta() {
    wattron(scrwin, COLOR_PAIR(MAGENTA));
}

void OffMagenta() {
    wattroff(scrwin, COLOR_PAIR(MAGENTA));
}

void SetWhite() {
    wattron(scrwin,COLOR_PAIR(WHITE));
}

void OffWhite() {
    wattroff(scrwin, COLOR_PAIR(WHITE));
}