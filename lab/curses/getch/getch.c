//getch.c
//gcc getch.c -lcurses -o getch
//getch is defined in the curses.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "curses.h"


WINDOW* testbox  = NULL;
int i = 0;

void build_test_view(){
	erase();
	WINDOW* testbox = subwin(stdscr, LINES, COLS, 0, 0);
	box(testbox,ACS_VLINE,ACS_HLINE);
	mvwaddstr(testbox, 0, COLS/3, "TFX8051 Test Framework");
	scrollok(testbox, TRUE);
}

void wipe_test_view(){
	delwin(testbox);
}

void testview_update(){
	char temp[256];
	sprintf(temp, "Loop %d", i++);
	mvwprintw(testbox, 3, 3, "%s", temp);
}

int main(){
	int ch = 0;


    slk_init(1);
    initscr();

    cbreak(); // no buffering
    noecho(); // no echoing
    keypad(stdscr, TRUE); // cursors entered as single characters

    build_test_view();

	do
	{
		testview_update();
		refresh();
		sleep(1);
	}
	while ( (ch = getch()) != 'Q' );

	endwin();
	printf("Exit ...\n");
	return 0;
}