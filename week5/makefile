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
PROGS = randFun refFun sortFun recFun hailstone recConvert
MAKEFLAGS = -k

all: $(PROGS)

randFun: 
	$(CC) $(CFLAGS) randFun.cpp -o randFun

refFun: 
	$(CC) $(CFLAGS) refFun.cpp -o refFun
	
sortFun: 
	$(CC) $(CFLAGS) sortFun.cpp -o sortFun

recFun: 
	$(CC) $(CFLAGS) recFun.cpp -o recFun
	
hailstone: 
	$(CC) $(CFLAGS) hailstone.cpp -o hailstone
	
recConvert: 
	$(CC) $(CFLAGS) recConvert.cpp -o recConvert

clean:
	rm -f $(PROGS) *.o *~

