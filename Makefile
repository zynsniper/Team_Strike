CC = gcc
CFLAGS = -Wall -I ./header
DEPS = header/team.h header/tile.h header/character.h header/SaveFunction.h header/LoadFunction.h header/MoveFunction.h

TARGET = runGame

SRCS = src/runGame.c 
OBJS = $(SRCS:src/%.c=src/%.o)    

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

test:
	./$(TARGET)           

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
