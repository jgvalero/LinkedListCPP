OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

linkedlist: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o linkedlist

main.o:
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o linkedlist