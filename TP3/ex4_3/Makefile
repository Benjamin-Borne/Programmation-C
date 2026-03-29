#Environment
CC=gcc
<<<<<<< HEAD
CFLAGS=-std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wformat=2 -Wundef
SRC=src
BIN=bin
TEST=tests

#Compilation
all: $(BIN)/myMain

$(BIN)/myMain: $(SRC)/myMain.c
	$(CC) $(CFLAGS) -o $(BIN)/myMain $(SRC)/myMain.c

#Tests
test: $(BIN)/CompareInt.test
	$(BIN)/CompareInt.test

$(BIN)/CompareInt.test: $(TEST)/CompareInt.test.c
	$(CC) $(CFLAGS) -o $(BIN)/CompareInt.test $(TEST)/CompareInt.test.c
=======
CFLAGS=-std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wformat=2 -Wundef -O2 -g
SRC=src
BIN=bin

SRCS=$(wildcard $(SRC)/*.c)
BINS=$(SRCS:$(SRC)/%.c=%)

#Compilation
all: $(BINS)

%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<
>>>>>>> ben

clean:
	$(RM) $(BIN)/*