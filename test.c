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

    free(u);
    return 0;
}