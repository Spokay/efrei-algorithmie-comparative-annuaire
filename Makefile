CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

annuaire: annuaire.o sequentiel.o
	$(CC) $(CFLAGS) -o $@ $^

annuaire.o: annuaire.c annuaire.h sequentiel.h
sequentiel.o: sequentiel.c annuaire.h sequentiel.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: annuaire

clean:
	rm -f *.o annuaire

.PHONY: all clean