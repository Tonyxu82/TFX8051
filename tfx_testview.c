/* 8051 Firmware Test Framework
 * Copyright 2018 Lai Xu (Tony)
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject 
 * to the following conditions: 
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software. 
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE. 
 *
 * (i.e. the MIT License)
 *
 * tfx_testview.c
 * 
 */
#include "curses.h"
#include "tfx_testview.h"

WINDOW *testsuitebox = NULL, *testsuiteoutput = NULL;
WINDOW *testbox = NULL;

void build_test_view(test_suite *ts){
	//if(!ts) return;
	erase();
	WINDOW* testbox = subwin(stdscr, LINES, COLS, 0, 0);
	box(testbox,ACS_VLINE,ACS_HLINE);
	mvwaddstr(testbox, 0, COLS/3, "TFX8051 Test Framework");
	scrollok(testbox, TRUE);
}

void wipe_test_view(){
	delwin(testbox);
}

void testview_update(test_suite *ts){
	//if(!ts) return;
	char temp[256];
	sprintf(temp, "Loop\n");
	mvwprintw(testbox, 3, 3, "%s", temp);
}
