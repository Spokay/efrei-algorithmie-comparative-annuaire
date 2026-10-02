#include <stdio.h>

#include "genere.h"
#include "hashage.h"

#define NOMBRE_ADRESSES 10000

static const char *nom_hash(const enum HashType type)
{
    switch (type)
    {
        case DJB2:
            return "djb2";
        case FNV_1A:
            return "FNV-1a";
        case SOMME_OCTETS:
            return "Somme des octets";
    }
    return "inconnue";
}

static void mesurer(const enum HashType type)
{
    int compteurs[TAILLE_TABLE] = {0};
    char email[EMAIL_MAX];
    int alveoles_occupees = 0;
    int chaine_max = 0;
    double cout_reussi = 0.0;
    double cout_echec = 0.0;

    for (int i = 0; i < NOMBRE_ADRESSES; i++)
    {
        generer_email(email, sizeof(email), i);
        const unsigned long indice = hash_email(email, type) % TAILLE_TABLE;
        compteurs[indice]++;
    }

    for (int i = 0; i < TAILLE_TABLE; i++)
    {
        const int nombre = compteurs[i];
        if (nombre > 0)
        {
            alveoles_occupees++;
        }
        if (nombre > chaine_max)
        {
            chaine_max = nombre;
        }
        cout_reussi += (double) nombre * (nombre + 1) / 2.0;
    }
    cout_reussi /= NOMBRE_ADRESSES;

    for (int i = 0; i < NOMBRE_ADRESSES; i++)
    {
        snprintf(email, sizeof(email), "absent%d@mail.com", i);
        const unsigned long indice = hash_email(email, type) % TAILLE_TABLE;
        cout_echec += compteurs[indice];
    }
    cout_echec /= NOMBRE_ADRESSES;

    printf("%-18s %5d %8d %20.2f %18.2f\n",
           nom_hash(type), alveoles_occupees, chaine_max,
           cout_reussi, cout_echec);
}

int main(void)
{
    printf("%-18s %5s %8s %20s %18s\n",
           "Fonction", "Alv.", "Max", "Comparaisons (OK)",
           "Comparaisons (echec)");
    mesurer(DJB2);
    mesurer(FNV_1A);
    mesurer(SOMME_OCTETS);
    return 0;
}
