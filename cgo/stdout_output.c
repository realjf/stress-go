// stdout_output.c
#include "stdout_output.h"
#include "color.h"

struct termios oldt;
int lines, cols;
WINDOW *scrwin, *boxwin;
int x, y;

void PrintDivider() {
    mvwprintw(scrwin, x, y, Divider());
    x++;
    refresh();
    wrefresh(scrwin);
}

void PrintVDivider() {
    y += 1;
    mvwprintw(scrwin, x, y, VDivider());
    y += 1;
}

void PrintHeaderLine() {
    mvwprintw(scrwin, x, y, HeaderLine());
    x++;
    refresh();
    wrefresh(scrwin);
}

void PrintHeader() {
   mvwprintw(scrwin, x, y, DrawTh());
   x++;
   refresh();
   wrefresh(scrwin);
}

void PrintField(char* field) {
   mvwprintw(scrwin, x, y, field);
   y += 8;
   refresh();
   wrefresh(scrwin);
}

void ReturnLine() {
    y = 0;
    x++;
    if(x >= lines){
        wclear(scrwin);
        x = 1;
        wscrl(scrwin, 1); // 滚动一行
    }
    refresh();
    wrefresh(scrwin);
    usleep(30000);
}

void StartWin() {
    if (!isatty(STDIN_FILENO)) {
        fprintf(stderr, "this problem should be run at a terminal\n");
        exit(1);
    }
    // save terminal setting
    if(tcgetattr(STDIN_FILENO, &oldt) < 0) {
        perror("save the terminal setting");
        exit(1);
    }
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"C-UTF-8");
    (void)signal(SIGINT, finish);
    initscr();
    cbreak(); // 设置无缓冲模式，只有newline和return才会让getch返回
    noecho(); // 设置无回显模式
    nonl(); 
    clear(); // 清除窗口信息
    getmaxyx(stdscr, lines, cols);
    scrwin = newwin(lines-1,cols-1,1,1);
    // boxwin = newwin(lines, cols, 0, 0);
    scrollok(scrwin, TRUE); // 开启视窗卷动功能
    keypad(scrwin, TRUE); // 设置把收到的特殊键比如箭头,转化为ncurses定义的以KEY开头的数字宏
    
    // box(boxwin, '|', '-'); // 盒子
    refresh(); // 刷新屏幕内容
    // wrefresh(boxwin);
    // int tlc, trc, blc, brc;
    // tlc = trc = blc = brc = 0;
    // wborder(scrwin, 0, 0, 0, 0, tlc, trc, blc, brc); // 盒子边界
    
    // scroll(scrwin);
    x = y = 0;
    StartColor();

}

void DrawTb(double requestTimeFloat,int concurrency,int successNum,int failureNum,double qps,
	double maxTimeFloat,double minTimeFloat,double avgTime, char* receivedBytesStr, char* speedStr) {
    mvwprintw(scrwin, x, y, DrawTd(requestTimeFloat, concurrency, successNum, failureNum, qps, maxTimeFloat, minTimeFloat, avgTime, receivedBytesStr, speedStr));
    refresh();
}

void EndWin() {
    getch(); // 输入一个字符
    // restore termial setting
    if(tcsetattr(STDIN_FILENO,TCSANOW, &oldt) < 0) {
        perror("restore the termial setting");
        exit(1);
    }
    delwin(scrwin);
    delwin(boxwin);
    endwin();
}

static void finish(int sig) {
    delwin(scrwin);
    delwin(boxwin);
    endwin();
    exit(0);
}