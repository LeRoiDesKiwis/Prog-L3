/*
 * Exercice 1.02
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_02.c -o exo_1_02
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"


int main()
{
    // ------------------------------------------------------------
    // les déclarations de l'énoncé
    const char *s1 = "chien";
    char s2[] = "chiot";

    // ------------------------------------------------------------
    title_print("Modification de s1");
    printf("s1 avant : %s\n", s1);
    s1 = "cheval";
    printf("s1 après : %s\n", s1);
    // Explication
    // ====== TODO ==========

    // ------------------------------------------------------------
    title_print("Modification de s2 ou *s2");
    // s2 = "rat";
    // Explication
    // ====== TODO ==========
    // code pour réaffecter la chaîne
    // ====== TODO ==========
  
    // ------------------------------------------------------------
    title_print("Modification de s2 ou *s2 (suite)");
    // s2 = "cheval";
    // Explication
    // ====== TODO ==========
    // strcpy(s2, "cheval");
    // Expliquez pourquoi c'est incorrect
    // ====== TODO ==========

    printf("\n");

    return EXIT_SUCCESS;
}
