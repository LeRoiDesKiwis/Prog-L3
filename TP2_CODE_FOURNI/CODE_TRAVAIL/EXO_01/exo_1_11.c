/*
 * Exercice 1.11
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_11.c -o exo_1_11
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

int main()
{
    // ------------------------------------------------------------
    title_print("strstr : utilisation");

    // voici un ensemble de chaînes à comparer
    const char *essais[][2] =
        {
            { "Il fait beau et chaud", "beau" },
            { "Il fait beau et chaud", " " },
            { "Il fait beau et chaud", "i" },
            { "Il fait beau et chaud", "au" },
            { "Il fait beau et chaud", "au " },
            { "Il fait beau et chaud", "aud" },
            { "Il fait beau et chaud", "froid" },
            { "Il fait beau et chaud", "x" }
        };
    int nbCouples = sizeof(essais) / sizeof(*essais);

    for (int i = 0; i < nbCouples; i++)
    {
        // Indiquer si essais[i][1] est une sous-chaîne de essais[i][0]
        // ====== TODO ==========

        // Plus compliqué : si essais[i][1] est une sous-chaîne de essais[i][0], indiquer
        // à quelle position se trouve cette sous-chaîne
        // ====== TODO ==========
    }

    // à étudier le problème de l'encodage

    printf("\n");

    return EXIT_SUCCESS;
}
