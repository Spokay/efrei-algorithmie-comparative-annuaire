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

    for (int i = 0; i < 5; i++)
    {
        printf("%s -> %lu\n", adresses[i], hash_email(adresses[i]));
    }

    printf("alice@mail.com, trois appels : %lu, %lu, %lu\n",
           hash_email("alice@mail.com"),
           hash_email("alice@mail.com"),
           hash_email("alice@mail.com"));

    printf("user1@mail.com -> %lu\n", hash_email("user1@mail.com"));
    printf("user2@mail.com -> %lu\n", hash_email("user2@mail.com"));

    return 0;
}