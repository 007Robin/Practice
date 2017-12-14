CC	:= g++
DEBUG	:= #-g
OPT	:= #-O2
CFLAGS	:= -c -std=c++11 $(DEBUG) $(OPT)
01LinkedList: 01TestMain.o 01LinkedList.o
	$(CC) $(DEBUG) 01TestMain.o 01LinkedList.o -o 01LinkedList

01LinkedList.o: 01LinkedList.cc 01LinkedList.hh
	$(CC) $(CFLAGS) 01LinkedList.cc

01TestMain.o: 01TestMain.cc 01LinkedList.hh
	$(CC) $(CFLAGS) 01TestMain.cc

.cc.o:
	$(CC) $(CFLAGS) $<

clean:
	rm *.o *.exe
