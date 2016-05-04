/* 8051 emulator
 * Copyright 2006 Jari Komppa
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
 * emu.c
 * Curses-based emulator front-end
 */

#ifdef _MSC_VER
#include <windows.h>
#undef MOUSE_MOVED
#else
#include <sys/time.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
#include <curses.h>
#else
#include "curses.h"
#endif
#include "emu8051.h"
#include "emulator.h"

unsigned char history[HISTORY_LINES * (128 + 64 + sizeof(int))];


// current line in the history cyclic buffers
int historyline = 0;
// last known columns and rows; for screen resize detection
int oldcols, oldrows;
// are we in single-step or run mode
int runmode = 0;
// current run speed, lower is faster
int speed = 6;

// instruction count; needed to replay history correctly
unsigned int icount = 0;

// current clock count
unsigned int clocks = 0;

// currently active view
int view = MAIN_VIEW;

// old port out values
int p0out = 0;
int p1out = 0;
int p2out = 0;
int p3out = 0;

int breakpoint = -1;

// returns time in 1ms units from Epoch - 1970-01-01 00:00:00 +0000 (UTC)
// http://man7.org/linux/man-pages/man2/time.2.html
int getTick()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_sec * 1000 + now.tv_usec / 1000;
}

void emu_sleep(int value)
{
    usleep(value * 1000);
}

int emu_sfrread(struct em8051 *aCPU, int aRegister)
{
    int outputbyte = -1;

    if (view == LOGICBOARD_VIEW)
    {
        if (aRegister == REG_P0 + 0x80)
        {
            outputbyte = p0out;
        }
        if (aRegister == REG_P1 + 0x80)
        {
            outputbyte =  p1out;
        }
        if (aRegister == REG_P2 + 0x80)
        {
            outputbyte =  p2out;
        }
        if (aRegister == REG_P3 + 0x80)
        {
            outputbyte =  p3out;
        }
    }
    else
    {
        if (aRegister == REG_P0 + 0x80)
        {
            outputbyte = p0out = emu_readvalue(aCPU, "P0 port read", p0out, 2);
        }
        if (aRegister == REG_P1 + 0x80)
        {
            outputbyte = p1out = emu_readvalue(aCPU, "P1 port read", p1out, 2);
        }
        if (aRegister == REG_P2 + 0x80)
        {
            outputbyte = p2out = emu_readvalue(aCPU, "P2 port read", p2out, 2);
        }
        if (aRegister == REG_P3 + 0x80)
        {
            outputbyte = p3out = emu_readvalue(aCPU, "P3 port read", p3out, 2);
        }
    }
    if (outputbyte != -1)
    {
        if (opt_input_outputlow == 1)
        {
            // option: output 1 even though ouput latch is 0
            return outputbyte;
        }
        if (opt_input_outputlow == 0)
        {
            // option: output 0 if output latch is 0
            return outputbyte & aCPU->mSFR[aRegister - 0x80];
        }
        // option: dump random values for output bits with
        // output latches set to 0
        return (outputbyte & aCPU->mSFR[aRegister - 0x80]) |
            (rand() & ~aCPU->mSFR[aRegister - 0x80]);
    }
    
    return aCPU->mSFR[aRegister - 0x80];

}

void setSpeed(int speed, int runmode)
{
    switch (speed)
    {
    case 7:
        slk_set(5, "+/-|.5Hz", 0);
        break;
    case 6:
        slk_set(5, "+/-|1Hz", 0);
        break;
    case 5:
        slk_set(5, "+/-|2Hz", 0);
        break;
    case 4:
        slk_set(5, "+/-|10Hz", 0);
        break;
    case 3:
        slk_set(5, "+/-|fast", 0);
        break;
    case 2:
        slk_set(5, "+/-|f+", 0);
        break;
    case 1:
        slk_set(5, "+/-|f++", 0);
        break;
    case 0:
        slk_set(5, "+/-|f*", 0);
        break;
    }

    //Runmode: Start or Step
    if (runmode == 0)
    {
        slk_set(4, "r)un", 0);
        slk_refresh();
        nocbreak();
        cbreak();
        nodelay(stdscr, FALSE);
        return;
    }
    else
    {
        slk_set(4, "r)unning", 0);
        slk_refresh();
    }

    //Speed: how many instruction per second
    if (speed < 4)
    {
        nocbreak();
        cbreak();
        nodelay(stdscr, TRUE);
    }
    else
    {
        switch(speed)
        {
        case 7:
            halfdelay(20);
            break;
        case 6:
            halfdelay(10);
            break;
        case 5:
            halfdelay(5);
            break;
        case 4:
            halfdelay(1);
            break;
        }
    }
}

//RefreshView: Update Current View
void refreshview(struct em8051 *aCPU)
{
    change_view(aCPU, view);
}

void change_view(struct em8051 *aCPU, int changeto)
{
    switch (view)
    {
    case MAIN_VIEW:
        wipe_main_view();
        break;
    case LOGICBOARD_VIEW:
        wipe_logicboard_view();
        break;
    case MEMEDITOR_VIEW:
        wipe_memeditor_view();
        break;
    case OPTIONS_VIEW:
        wipe_options_view();
        break;
    }
    view = changeto;
    switch (view)
    {
    case MAIN_VIEW:
        build_main_view(aCPU);
        break;
    case LOGICBOARD_VIEW:
        build_logicboard_view(aCPU);
        break;
    case MEMEDITOR_VIEW:
        build_memeditor_view(aCPU);
        break;
    case OPTIONS_VIEW:
        build_options_view(aCPU);
        break;
    }
}


int main(int parc, char ** pars)
{
    int ch = 0;
    struct em8051 emu;
    int i;
    int ticked = 1;

    //Init emulator Core, a model of 8051 
    memset(&emu, 0, sizeof(emu));
    emu.mCodeMem     = malloc(65536);
    emu.mCodeMemSize = 65536;
    emu.mExtData     = malloc(65536);
    emu.mExtDataSize = 65536;
    emu.mLowerData   = malloc(128);
    emu.mUpperData   = malloc(128);
    emu.mSFR         = malloc(128);
    emu.except       = &emu_exception;
    emu.sfrread      = &emu_sfrread;
    emu.xread = NULL;
    emu.xwrite = NULL;
    reset(&emu, 1);
    
    //Load Intel format file and decode it into the code memory.
    if (load_obj(&emu, pars[i]) != 0)
    {
        printf("File '%s' load failure\n\n",pars[i]);
        return -1;
    }
    else
    {
        strcpy(filename, pars[i]);
    }


    //If we don't have ncurses, then throw out an error ad 
    //  Initialize ncurses

    slk_init(1);
    if ( (initscr()) == NULL ) {
	    fprintf(stderr, "Error initialising ncurses.\n");
	    exit(EXIT_FAILURE);
    }

    slk_set(1, "h)elp", 0);
    slk_set(2, "l)oad", 0);
    slk_set(3, "spc=step", 0);
    slk_set(4, "r)un", 0);
    slk_set(6, "v)iew", 0);
    slk_set(7, "home=rst", 0);
    slk_set(8, "s-Q)quit", 0);
    setSpeed(speed, runmode);


    //  Switch of echoing and enable keypad (for arrow keys etc)

    cbreak(); // no buffering
    noecho(); // no echoing
    keypad(stdscr, TRUE); // cursors entered as single characters

    build_main_view(&emu);

    // Loop until user hits 'shift-Q'

    do
    {
        if (LINES != oldrows ||
            COLS != oldcols)
        {
            refreshview(&emu);
        }
        switch (ch)
        {
        case KEY_F(1):
            change_view(&emu, 0);
            break;
        case KEY_F(2):
            change_view(&emu, 1);
            break;
        case 'v':
            change_view(&emu, (view + 1) % 2);
            break;
        case 'h':
            emu_help(&emu);
            break;
        case 'l':
            emu_load(&emu);
            break;
        case 'r':
            if (runmode)
            {
                runmode = 0;
                setSpeed(speed, runmode);
            }
            else
            {
                runmode = 1;
                setSpeed(speed, runmode);
            }
            break;
        case '+':
            speed--;
            if (speed < 0)
                speed = 0;
            setSpeed(speed, runmode);
            break;
        case '-':
            speed++;
            if (speed > 7)
                speed = 7;
            setSpeed(speed, runmode);
            break;
        case KEY_HOME:
            if (emu_reset(&emu))
            {
                clocks = 0;
                ticked = 1;
            }
            break;
        case KEY_END:
            clocks = 0;
            ticked = 1;
            break;
        default:
            // by default, send keys to the current view
            switch (view)
            {
            case MAIN_VIEW:
                mainview_editor_keys(&emu, ch);
                break;
            case OPTIONS_VIEW:
                options_editor_keys(&emu, ch);
                break;
            }
            break;
        }

        //Actually controller of the 8051 core, 32 is space in ASCII
        if (ch == 32 || runmode)
        {
            int targettime;
            unsigned int targetclocks;
            targetclocks = 1;
            targettime = getTick();

            if (speed == 2 && runmode)
            {
                targettime += 1;
                targetclocks += (opt_clock_hz / 12000) - 1;
            }
            if (speed < 2 && runmode)
            {
                targettime += 10;
                targetclocks += (opt_clock_hz / 1200) - 1;
            }

            do
            {
                int old_pc;
                old_pc = emu.mPC;
                if (opt_step_instruction)
                {
                    ticked = 0;
                    while (!ticked)
                    {
                        targetclocks--;
                        clocks += 12;
                        ticked = tick(&emu);
                        logicboard_tick(&emu);
                    }
                }
                else
                {
                    targetclocks--;
                    clocks += 12;
                    ticked = tick(&emu);
                    logicboard_tick(&emu);
                }

                if (emu.mPC == breakpoint)
                    emu_exception(&emu, -1);

                if (ticked)
                {
                    icount++;

                    historyline = (historyline + 1) % HISTORY_LINES;

                    memcpy(history + (historyline * (128 + 64 + sizeof(int))), emu.mSFR, 128);
                    memcpy(history + (historyline * (128 + 64 + sizeof(int))) + 128, emu.mLowerData, 64);
                    memcpy(history + (historyline * (128 + 64 + sizeof(int))) + 128 + 64, &old_pc, sizeof(int));
                }
            }
            while (targettime > getTick() && targetclocks > 0);

            while (targettime > getTick())
            {
                emu_sleep(1);
            }
        }

        switch (view)
        {
        case MAIN_VIEW:
            mainview_update(&emu);
            break;
        case LOGICBOARD_VIEW:
            logicboard_update(&emu);
            break;
        case MEMEDITOR_VIEW:
            memeditor_update(&emu);
            break;
        case OPTIONS_VIEW:
            options_update(&emu);
            break;
        }
    }
    while ( (ch = getch()) != 'Q' );

    endwin();

    return EXIT_SUCCESS;
}
