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
PROGS = shopCart findMode carLot
MAKEFLAGS = -k


all: $(PROGS)

shopCart:
	$(CC) $(CFLAGS) shopCart.cpp -o shopCart

findMode: 
	$(CC) $(CFLAGS) findMode.cpp -o findMode
	
carLot: 
	$(CC) $(CFLAGS) carLot.cpp -o carLot

clean:
	rm -f $(PROGS) *.o *~

