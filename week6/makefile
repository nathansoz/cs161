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
PROGS = evenOdd stringMix grades randFun2 arrayAdd wordShift
MAKEFLAGS = -k

all: $(PROGS)

evenOdd:
	$(CC) $(CFLAGS) evenOdd.cpp -o evenOdd

stringMix: 
	$(CC) $(CFLAGS) stringMix.cpp -o stringMix
	
grades: 
	$(CC) $(CFLAGS) grades.cpp -o grades

randFun2: 
	$(CC) $(CFLAGS) randFun2.cpp -o randFun2
	
arrayAdd: 
	$(CC) $(CFLAGS) arrayAdd.cpp -o arrayAdd
	
wordShift: 
	$(CC) $(CFLAGS) wordShift.cpp -o wordShift

clean:
	rm -f $(PROGS) *.o *~

