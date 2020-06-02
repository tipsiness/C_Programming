#include <ncurses.h>

int main() {
	int ch, prev;
	FILE *fp;
	int goto_prev = FALSE, y, x;

	initscr();
	prev = EOF;
	while ((ch = fgetc(fp)) != EOF) {
		if (prev == '/' && ch == '*') {
			attron(A_BOLD);
			goto_prev = TRUE;
		}
		if (goto_prev == TRUE) {
			getyx(stdstr, y, x);
			move(y, x - 1);
			printw("%c%c", '/', ch);
			ch = 'a';
			goto_prev = FALSE;
		} else printw("%c", ch);

		refresh();
		if (prev == '*' && ch == '/') 
			attroff(A_BOLD);
		prev = ch;
	}
	getch();
	endwin();

	return 0;
}
