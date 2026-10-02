#include <stdio.h>
#include "genere.h"
void generer_email(char *buf, const size_t taille, const int i) {
    snprintf(buf, taille, "user%d@mail.com", i);
}