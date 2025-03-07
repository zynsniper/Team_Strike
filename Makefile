CC = gcc
CFLAGS = -Wall -I.
DEPS = team.h tile.h character.h SaveFunction.h

TARGET = runGame

SRCS = runGame.c 
OBJS = $(SRCS:.c=.o)    

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

test:
	./$(TARGET)           

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
