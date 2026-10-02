//
// Created by spokay on 10/2/26.
//

#include "hashage.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Node *table[TAILLE_TABLE] = { NULL };

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


void hash_insert(const char *email, const int id) {
    const unsigned long i = hachage(email) % TAILLE_TABLE;
    Node *n = malloc(sizeof(Node));
    if (n == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    snprintf(n->email, EMAIL_MAX, "%s", email);
    n->id = id;
    n->next = table[i];
    table[i] = n;
}

bool hash_search(const char *email) {
    const unsigned long i = hachage(email) % TAILLE_TABLE;
    for (const Node *n = table[i]; n != NULL; n = n->next)
        if (strcmp(n->email, email) == 0)
            return true;
    return false;
}

void hash_free(void) {
    for (int i = 0; i < TAILLE_TABLE; i++) {
        Node *n = table[i];
        while (n != NULL) {
            Node *suiv = n->next;
            free(n);
            n = suiv;
        }
        table[i] = NULL;
    }
}