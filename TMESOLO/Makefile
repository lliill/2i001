# Makefile gameScores

GCC_FLAGS = -Wall
all: gameScores mainTabScores game

gameTest.o	: gameTest.c
	gcc $(GCC_FLAGS) -c gameTest.c

score.o	: score.c
	gcc $(GCC_FLAGS) -c score.c

game.o	: game.c
	gcc $(GCC_FLAGS) -c game.c

game : game.o score.o
	gcc $(GCC_FLAGS) game.o score.o gameTest.o -o game

gameScores : gameTest.o score.o game.o
	gcc $(GCC_FLAGS) gameTest.o score.o game.o -o gameScores

mainTabScores.o : mainTabScores.c
	gcc $(GCC_FLAGS) -c mainTabScores.c

mainTabScores :  score.o gameTest.o mainTabScores.o 
	gcc -Wall score.o gameTest.o mainTabScores.o -o mainTabScores

clean	:
	rm -f game.o score.o gameTest.o mainTabScores.o gameScores mainTabScores game
