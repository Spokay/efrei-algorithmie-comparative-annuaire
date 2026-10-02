//
// Created by spokay on 10/2/26.
//

#include "annuaire.h"
#include "sequentiel.h"
#include <stdio.h>

int main(void)
{
    char email[EMAIL_MAX];

    for (int id = 1; id <= 40; id++)
    {
        snprintf(email, sizeof(email), "utilisateur%02d@mail.com", id);
        seq_insert(email, id);
    }

    seq_free();
    return 0;
}