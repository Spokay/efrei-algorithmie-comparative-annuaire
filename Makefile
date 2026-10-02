CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

annuaire: annuaire.o hashage.o
	$(CC) $(CFLAGS) -o $@ $^

annuaire.o: annuaire.c annuaire.h hashage.h
hashage.o: hashage.c annuaire.h hashage.h
test.o: test.c annuaire.h sequentiel.h hashage.h

test: test.o sequentiel.o hashage.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: annuaire test

clean:
	rm -f *.o annuaire test

.PHONY: all clean