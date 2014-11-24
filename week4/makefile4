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
PROGS = retFun randFun mpg size finalist secretWord
MAKEFLAGS = -k

all: $(PROGS)

retFun: 
	$(CC) $(CFLAGS) retFun.cpp -o retFun

randFun:
	$(CC) $(CFLAGS) randFun.cpp -o randFun

mpg:
	$(CC) $(CFLAGS) mpg.cpp -o mpg

size:
	$(CC) $(CFLAGS) size.cpp -o size

finalist:
	$(CC) $(CFLAGS) finalist.cpp -o finalist

secretWord:
	$(CC) $(CFLAGS) secretWord.cpp -o secretWord

clean:
	rm -f $(PROGS) *.o *~

