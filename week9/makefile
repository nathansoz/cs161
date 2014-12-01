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
PROGS = geom shopCart2 carLot2
MAKEFLAGS = -k 

all: $(PROGS)

geom:
	$(CC) $(CFLAGS) geom.cpp -o geom

shopCart2: 
	$(CC) $(CFLAGS) shopCart2.cpp -o shopCart
	
carLot2: 
	$(CC) $(CFLAGS) carLot2.cpp -o carLot

clean:
	rm -f $(PROGS) *.o *~

