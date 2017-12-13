# Makefile gameScores

GCC_FLAGS = -Wall
all: gameScores

gameTest.o	: gameTest.c
	gcc $(GCC_FLAGS) -c gameTest.c

score.o	: score.c
	gcc $(GCC_FLAGS) -c score.c

game.o	: game.c
	gcc $(GCC_FLAGS) -c game.c

gameScores : gameTest.o score.o game.o
	gcc $(GCC_FLAGS) gameTest.o score.o game.o -o gameScores

clean	:
	rm -f game.o score.o gameTest.o gameScores
