#!/usr/bin/make -f

CFLAGS=-Wall -ansi -pedantic -g
LDFLAGS=
EXEC=calcul
BIN=bin/calc.o bin/main.o
SRC=*.c
HEAD=mesTypes.h

BINS=$(sort $(BIN))

all: $(EXEC)

sokoban: $(BIN)
	$(CC) -o bin/$@ $(BIN) $(LDFLAGS)

$(BINS): bin/%.o: src/%.c
	$(CC) -c $< $(CFLAGS) -o $@