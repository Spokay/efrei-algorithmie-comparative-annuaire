//
// Created by spokay on 10/2/26.
//

#include "annuaire.h"
#include "sequentiel.h"
#include <stdio.h>

int main(void)
{
    const char *utilisateurs[] = {
        "alice@mail.com",
        "bob@mail.com",
        "carol@mail.com",
        "david@mail.com",
        "eve@mail.com"
    };

    for (int i = 0; i < 5; i++)
    {
        seq_insert(utilisateurs[i], i + 1);
    }

    const char *recherches_reussies[] = {
        "alice@mail.com",
        "carol@mail.com",
        "eve@mail.com"
    };
    for (int i = 0; i < 3; i++)
    {
        printf("Recherche de %s : %s\n",
               recherches_reussies[i],
               seq_search(recherches_reussies[i]) ? "true" : "false");
    }

    const char *recherches_echouees[] = {
        "inconnu@mail.com",
        "frank@mail.com"
    };
    for (int i = 0; i < 2; i++)
    {
        printf("Recherche de %s : %s\n",
               recherches_echouees[i],
               seq_search(recherches_echouees[i]) ? "true" : "false");
    }

    seq_free();
    printf("Recherche dans un annuaire vide : %s\n",
           seq_search("alice@mail.com") ? "true" : "false");

    return 0;
}