#
#  $RCSfile$
#  $Revision$
#  $Author$ Sharon Davis & Shoshana Abrass
#  $Date$  10/6/2014
#  $Log$
#

CC = g++
DEBUG = -g
CFLAGS = $(DEBUG) 
PROGS = sameSum symArrays ticTacToe
MAKEFLAGS = -k

all: $(PROGS)

sameSum: 
	$(CC) $(CFLAGS) sameSum.cpp -o sameSum

symArrays: 
	$(CC) $(CFLAGS) symArrays.cpp -o symArrays
	
ticTacToe: 
	$(CC) $(CFLAGS) ticTacToe.cpp -o ticTacToe

clean:
	rm -f $(PROGS) *.o *~

