/*
 * Exercice 2.01
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_2_01.c -o exo_2_01
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"


// Écrire ici la fonction strClone
// ====== TODO ==========

int main()
{
    title_print("clone");

    // voici un ensemble de chaînes à dupliquer
    const char *essais[] =
        {
            "Tu vois, le monde se divise en deux catégories, "
                "ceux qui ont un pistolet chargé et ceux qui creusent."
                " Toi, tu creuses.",
            "aa\nbb",   // le '\n' est un caractère comme un autre
            "",         // la chaîne vide est une chaîne tout à fait légale
            "aa\0bb"    // exemple curieux : il y a un marqueur de fin en plein milieu
        };
    int nbCouples = sizeof(essais) / sizeof(*essais);

    for (int i = 0; i < nbCouples; i++)
    {
        printf("source : \"%s\"\n", essais[i]);

        // déclarer la chaîne qui va recevoir la copie, faire la copie de essais[i]
        // et l'afficher.
        // ====== TODO ==========

        // il y a sûrement quelque chose à faire ici ?
        // ====== TODO ==========

        printf("\n");
    }

    return EXIT_SUCCESS;
}
