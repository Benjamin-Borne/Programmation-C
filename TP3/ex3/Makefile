CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wformat=2 -Wundef -O2 -g
SRC=src
BIN=bin

# Exclure tous les fichiers qui ne sont pas des programmes principaux
EXCLUDES=$(SRC)/AfficherHello.c
MAINS=$(filter-out $(EXCLUDES), $(wildcard $(SRC)/*.c))
BINS=$(MAINS:$(SRC)/%.c=$(BIN)/%)

all: $(BINS)

# Règle spéciale pour main (qui dépend de AfficherHello.c)
$(BIN)/main: $(SRC)/main.c $(SRC)/AfficherHello.c
	$(CC) $(CFLAGS) -o $@ $^

# Règle générique pour tous les autres programmes
$(BIN)/%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN)/*