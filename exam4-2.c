#include <ncurses.h>
#include <string.h>

int main() {
	char mesg[] = "Enter a string: ";
	char str[80];
	int row, col;

	initscr();
	start_color();
	init_pair(1, COLOR_CYAN, 0);
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col-strlen(mesg))/2, "%s", mesg);

	getstr(str);
	attron(COLOR_PAIR(1)|A_BOLD|A_ITALIC);
	mvprintw(LINES - 2, 0, "You Entered: %s", str);
	attroff(COLOR_PAIR(1)|A_BOLD|A_ITALIC);
	getch();
	endwin();

	return 0;
}
