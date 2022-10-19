CC = gcc
FLAGS = -Wall

TARGET = TicTacToe
DEP = ../library/functions.h
OBJ = ../TicTacToe/main.o ../library/functions.o

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c $(DEP)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clear

clear:
	-rm $(OBJ)
	-rm $(TARGET)
