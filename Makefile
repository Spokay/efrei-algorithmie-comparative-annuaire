CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

annuaire: annuaire.o hashage.o
	$(CC) $(CFLAGS) -o $@ $^

annuaire.o: annuaire.c annuaire.h hashage.h
hashage.o: hashage.c annuaire.h hashage.h
genere.o: genere.c annuaire.h
test.o: test.c annuaire.h sequentiel.h hashage.h
distribution.o: distribution.c annuaire.h hashage.h genere.h


test: test.o sequentiel.o hashage.o
	$(CC) $(CFLAGS) -o $@ $^


distribution: distribution.o hashage.o genere.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: annuaire test distribution

clean:
	rm -f *.o annuaire test distribution

.PHONY: all clean