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
PROGS = strings name randNum loop randNum2
MAKEFLAGS = -k

all: $(PROGS)

strings: $(OBJS)
	$(CC) $(CFLAGS) strings.cpp -o strings

name: $(OBJS)
	$(CC) $(CFLAGS) name.cpp -o name
	
randNum: 
	$(CC) $(CFLAGS) randNum.cpp -o randNum

loop: 
	$(CC) $(CFLAGS) loop.cpp -o loop
	
randNum2: 
	$(CC) $(CFLAGS) randNum2.cpp -o randNum2

clean:
	rm -f $(PROGS) *.o *~

