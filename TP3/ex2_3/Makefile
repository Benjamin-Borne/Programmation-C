#Environment
CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wformat=2 -Wundef -O2 -g
SRC=src
BIN=bin

SRCS=$(wildcard $(SRC)/*.c)
BINS=$(SRCS:$(SRC)/%.c=%)

#Compilation
all: $(BINS)

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

clean:
<<<<<<< HEAD
	$(RM) $(BIN)/*
=======
	$(RM) $(BIN)/*


>>>>>>> ben
