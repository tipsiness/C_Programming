#include <ncurses.h>

int main(int argc, char *argv[]) {
	int ch, prev;
	FILE *fp;
	int goto_prev = FALSE, y, x;

	fp = fopen(argv[1], "r");
	initscr();
	start_color();
	init_pair(1, COLOR_CYAN, 0);
	prev = EOF;
	while ((ch = fgetc(fp)) != EOF) {
		if (prev == '/' && ch == '*') {
			attron(A_BOLD);
			attron(COLOR_PAIR(1));
			goto_prev = TRUE;
		}
		if (goto_prev == TRUE) {
			getyx(stdscr, y, x);
			move(y, x - 1);
			printw("%c%c", '/', ch);
			ch = 'a';
			goto_prev = FALSE;
		} else printw("%c", ch);

		refresh();
		if (prev == '*' && ch == '/') {
			attroff(COLOR_PAIR(1));
			attroff(A_BOLD);
		}
		prev = ch;
	}
	getch();
	fclose(fp);
	endwin();

	return 0;
}
