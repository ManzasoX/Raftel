CC=gcc
CFLAGS= -g -Wall -ansi -pedantic

all: final

final: command.o game.o game_loop.o graphic_engine.o screen.o space.o GameReader.o object.o player.o die.o set.o
	$(CC) $(CFLAGS) command.o game.o game_loop.o graphic_engine.o screen.o space.o GameReader.o object.o player.o die.o set.o -o final

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

game.o: game.c game.h types.h GameReader.h space.h set.h
	$(CC) $(CFLAGS) -c game.c

game_loop.o: game_loop.c graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h screen.h
	$(CC) $(CFLAGS) -c graphic_engine.c

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c screen.c

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c space.c

GameReader.o: GameReader.c GameReader.h game.h
	$(CC) $(CFLAGS) -c GameReader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c player.c

die.o: die.c die.h types.h
	$(CC) $(CFLAGS) -c die.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

clean:
	rm -f *.o
