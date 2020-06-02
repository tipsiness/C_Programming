#include <ncurses.h>

int main() {
	int c;
	MEVENT event;

	initscr();
	noecho();
	cbreak();

	keypad(stdscr, TRUE);

	attron(A_REVERSE);
	mvprintw(LINES-2, 0, "Click on Exit to quit");
	refresh();
	attroff(A_REVERSE);

	mousemask(ALL_MOUSE_EVENTS|REPORT_MOUSE_POSITION, NULL);

	//printf("\033[?1003h\n");
	printf("\033[?1002h\n");

	while (1) {
		c = wgetch(stdscr);
		switch (c) {
			case KEY_MOUSE:
				if (getmouse(&event) == OK) {
					mvprintw(0, 0, "mouse");
					if (event.bstate & BUTTON1_PRESSED) {
						mvprintw(30, 2, "left button");
					}
				}
		}
	}

	endwin();
	return 0;
}


