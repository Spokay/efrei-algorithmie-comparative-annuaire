CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

annuaire: annuaire.o hashage.o
	$(CC) $(CFLAGS) -o $@ $^

annuaire.o: annuaire.c annuaire.h hashage.h
hashage.o: hashage.c annuaire.h hashage.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: annuaire

clean:
	rm -f *.o annuaire

.PHONY: all clean