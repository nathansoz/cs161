#
#  $RCSfile$
#  $Revision$
#  $Author$ Sharon Davis
#  $Date$  10/2/2013
#  $Log$
#

CC = g++
DEBUG = -g
CFLAGS = $(DEBUG) 
#CFLAGS += -Wall
PROGS = firelaws arcade arcade2 numGuess 
SRCS = firelaws.cpp arcade.cpp arcade2.cpp numGuess.cpp 
OBJS = firelaws.o arcade.o arcade2.o numGuess.o 
#HEADERS = 

all: $(PROGS)

firelaws: $(OBJS)
	$(CC) $(CFLAGS) -o firelaws firelaws.o

firelaws.o: $(SRCS)
	$(CC) $(CFLAGS) -c firelaws.cpp

arcade: $(OBJS)
	$(CC) $(CFLAGS) -o arcade arcade.o

arcade.o: $(SRCS)
	$(CC) $(CFLAGS) -c arcade.cpp
	
arcade2: $(OBJS)
	$(CC) $(CFLAGS) -o arcade2 arcade2.o

arcade2.o: $(SRCS)
	$(CC) $(CFLAGS) -c arcade2.cpp

numGuess: $(OBJS)
	$(CC) $(CFLAGS) -o numGuess numGuess.o

numGuess.o: $(SRCS)
	$(CC) $(CFLAGS) -c numGuess.cpp


clean:
	rm -f $(PROGS) *.o *~

