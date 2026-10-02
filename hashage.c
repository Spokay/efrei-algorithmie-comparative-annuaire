//
// Created by spokay on 10/2/26.
//

#include "hashage.h"


static unsigned long hachage(const char *email) {
    unsigned long h = 5381;
    int c;
    while ((c = (unsigned char)*email++))
        h = (h * 33) + c;
    return h;
}

unsigned long hash_email(const char* email) {
    return hachage(email) % TAILLE_TABLE;
}
