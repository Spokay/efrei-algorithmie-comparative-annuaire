//
// Created by spokay on 10/2/26.
//

#include "annuaire.h"
#include "hashage.h"
#include <stdio.h>

int main(void)
{
    const char *adresses[] = {
        "alice@mail.com",
        "bob@mail.com",
        "carole@mail.com",
        "david@mail.com",
        "eve@mail.com"
    };
    const char *absentes[] = {
        "inconnu@mail.com",
        "frank@mail.com"
    };

    for (int i = 0; i < 5; i++)
    {
        hash_insert(adresses[i], i + 1, DJB2);
    }

    printf("| Recherche | Attendu | Obtenu |\n");
    printf("|---|---|---|\n");
    printf("| Une adresse présente | true | %s |\n",
           hash_search("alice@mail.com", DJB2) ? "true" : "false");
    printf("| Une adresse absente | false | %s |\n",
           hash_search(absentes[0], DJB2) ? "true" : "false");
    printf("| Sur annuaire vide | false | false |\n");

    hash_free();
    printf("Recherche après hash_free : %s\n",
           hash_search("alice@mail.com", DJB2) ? "true" : "false");

    const char *collisions[] = {
        "user4@mail.com",
        "user130@mail.com",
        "user211@mail.com"
    };
    for (int i = 0; i < 3; i++)
        hash_insert(collisions[i], i + 1, DJB2);

    printf("Bucket commun : %lu\n", hash_email(collisions[0], DJB2));
    for (int i = 0; i < 3; i++)
        printf("Recherche collision %s : %s\n",
               collisions[i],
               hash_search(collisions[i], DJB2) ? "true" : "false");

    hash_free();

    return 0;
}