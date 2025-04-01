CC = gcc
CFLAGS = -Wall -I ./header
DEPS = header/generate_team.h header/generate_team.h header/tile.h header/character.h header/save_function.h header/load_function.h header/move_function.h header/map_function.h header/bot_logic.h header/palace.h header/defender.h

TARGET = run_game 

SRCS = src/run_game.c src/generate_team.c src/load_function.c src/save_function.c src/map_function.c src/move_function.c src/bot_logic.c src/palace.c src/defender
OBJS = $(SRCS:src/%.c=src/%.o)    

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm

clean:
	rm -f $(OBJS) $(TARGET)

test:
	./$(TARGET)           

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)