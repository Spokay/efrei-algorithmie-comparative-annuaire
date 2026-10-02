#include <stdio.h>

#include "hashage.h"
#include "sequentiel.h"

static int tests_total = 0;
static int tests_reussis = 0;

static void verifier(const char *titre, bool obtenu, bool attendu)
{
    tests_total++;
    if (obtenu == attendu)
    {
        tests_reussis++;
        printf("[OK] %s\n", titre);
    }
    else
    {
        printf("[ECHEC] %s\n", titre);
    }
}

int main(void)
{
    const char *utilisateurs[] = {
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

    verifier("annuaire sequentiel vide",
             seq_search("alice@mail.com"), false);
    verifier("table de hachage vide",
             hash_search("alice@mail.com", DJB2), false);

    for (int i = 0; i < 5; i++)
    {
        seq_insert(utilisateurs[i], i + 1);
        hash_insert(utilisateurs[i], i + 1, DJB2);
    }

    for (int i = 0; i < 5; i++)
    {
        char titre_seq[64];
        char titre_hash[64];
        snprintf(titre_seq, sizeof(titre_seq),
                 "sequentiel trouve %s", utilisateurs[i]);
        snprintf(titre_hash, sizeof(titre_hash),
                 "hachage trouve %s", utilisateurs[i]);
        verifier(titre_seq, seq_search(utilisateurs[i]), true);
        verifier(titre_hash, hash_search(utilisateurs[i], DJB2), true);
    }

    for (int i = 0; i < 2; i++)
    {
        char titre_seq[64];
        char titre_hash[64];
        snprintf(titre_seq, sizeof(titre_seq),
                 "sequentiel absent %s", absentes[i]);
        snprintf(titre_hash, sizeof(titre_hash),
                 "hachage absent %s", absentes[i]);
        verifier(titre_seq, seq_search(absentes[i]), false);
        verifier(titre_hash, hash_search(absentes[i], DJB2), false);
    }

    verifier("sequentiel respecte la casse",
             seq_search("Alice@mail.com"), false);
    verifier("hachage respecte la casse",
             hash_search("Alice@mail.com", DJB2), false);

    seq_free();
    hash_free();

    printf("Compte final : %d/%d tests reussis\n",
           tests_reussis, tests_total);
    return tests_reussis == tests_total ? 0 : 1;
}