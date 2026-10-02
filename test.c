//
// Created by spokay on 10/2/26.
//

#include <stdio.h>
#include <stdlib.h>

#include "annuaire.h"

int main() {
    User* u = malloc(sizeof(User));
    snprintf(u->email, EMAIL_MAX, "%s", "alice@mail.com");
    // u->email = "alice@mail.com";

    printf("Email: %s\n", u->email);

    // Question 5 : un tableau de chars ne représente pas la chaine en elle même mais un pointeur vers le premier élément,
    // on ne peux donc pas assigner ce pointeur à une chaine déjà affectée, il faut copier les caractères 1 par 1

    free(u);
    return 0;
}