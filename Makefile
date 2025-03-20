CC = gcc
CFLAGS = -Wall -I ./header
DEPS = header/team.h header/tile.h header/character.h header/SaveFunction.h header/LoadFunction.h header/MoveFunction.h header/MapFunction.h

TARGET = runGame

SRCS = src/run_game.c src/generate_character.c src/load_function.c src/save_function.c src/map_function.c src/move_function.c
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
