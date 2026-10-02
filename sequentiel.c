#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequentiel.h"

#include "annuaire.h"

static User *annuaire = NULL;
static int taille = 0;
static int capacite = 0;
static int count = 0;

void seq_insert(const char *email, const int id)
{
    if (taille == capacite)
    {
        int nouvelle;
        if (capacite == 0)
        {
            nouvelle = 16;
        }
        else
        {
            nouvelle = capacite * 2;
        }
        User *tmp = realloc(
            annuaire,
        (size_t)nouvelle * sizeof(User)
        );
        count++;
        if (tmp == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        annuaire = tmp;
        capacite = nouvelle;
    }
    snprintf(
    annuaire[taille].email,
    EMAIL_MAX,
    "%s",
    email
    );
    annuaire[taille].id = id;
    taille++;
    printf("taille = %d\n", taille);
    printf("capacite = %d\n", capacite);
    printf("count = %d\n", count);
}
void seq_free(void)
{
    free(annuaire);
    taille = 0;
    capacite = 0;
}

bool seq_search(const char *email) {
    for (int i = 0; i < taille; i++)
        if (strcmp(annuaire[i].email, email) == 0)
            return true;
    return false;
}