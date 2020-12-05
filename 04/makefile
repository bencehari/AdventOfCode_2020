CC = gcc
CFLAGS = -Wall -g -o0
MAIN = 04

SRCS = \
	main.c

OBJS = $(SRCS:.c=.o)

all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	$(MAKE) clean

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o
