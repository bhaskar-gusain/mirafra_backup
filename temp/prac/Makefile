.PHONY = all clean

CC = gcc

SRCS:= $(wildcard *.c)
#OBJS:= $(SRCS:%.c=%.o)
BINS:= ${SRCS:%.c=%}

all: $(BINS)

%: %.o
	$(CC) $< -o $@


%.o: %.c
	$(CC) -c $< -o $@
        	

clean:
	rm -rf $(OBJS) $(BINS)
