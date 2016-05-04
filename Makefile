#sudo apt-get install libncurses5 libncurses5-dev

HEADERS = emu8051.h  emulator.h
OBJ = core.o disasm.o opcodes.o tfx_testview.o tfx_test.o tfx_list.o tfx.o 

CC = gcc
CCPP = g++
CFLAGS = -g -Wall -Wextra

%.o: %.c $(HEADERS)
	$(CC) $(CLFLAGS)-c -o $@ $< $(CFLAGS)

tfx: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o tfx -lcurses

clean:
	-rm -rf *.o tfx
