#include <ncurses.h>
#include "game.h"
#include "mydefinitions.h"

using namespace std;

int main()
{

    initscr();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    noecho();
    refresh();

    attron(A_BOLD);
    mvprintw(LINES/2-2, COLS/2-12, "Welcome to the Snake game");
    mvprintw(LINES/2, COLS/2-11, "Press Enter to continue");
    mvprintw(LINES/2+2, COLS/2-12, "Press any other key to exit");

    int ch;
    ch = getch();
    if(ch == 10) //10 is "Enter"
    {
        game g(70);
        g.play();
    }
    else
    {
        clear();
        refresh();
    }
    attroff(A_BOLD);
    endwin();
}
