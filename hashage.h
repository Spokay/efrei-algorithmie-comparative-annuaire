//
// Created by spokay on 10/2/26.
//

#ifndef ALGORITHMIE_COMPARATIVE_HASH_TABLE_H
#define ALGORITHMIE_COMPARATIVE_HASH_TABLE_H

#define TAILLE_TABLE 1024
#include "annuaire.h"

typedef struct Node {
    char email[EMAIL_MAX];
    int id;
    struct Node *next;
} Node;

unsigned long hash_email(const char* email);

void hash_insert(const char *email, int id);
bool hash_search(const char *email);

void hash_free(void);

#endif //ALGORITHMIE_COMPARATIVE_HASH_TABLE_H
