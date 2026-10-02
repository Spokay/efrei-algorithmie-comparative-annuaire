#ifndef GENERE_H
#define GENERE_H
#include <stddef.h>
#include "annuaire.h"

/* ecrit "user<i>@mail.com" dans buf */
void generer_email(char *buf, size_t taille, int i);
#endif
