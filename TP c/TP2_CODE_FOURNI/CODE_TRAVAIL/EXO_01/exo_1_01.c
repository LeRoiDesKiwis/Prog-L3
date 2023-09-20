/*
 * Exercice 1.01
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_01.c -o exo_1_01
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
    char c = 'A';
    char *s1 = "chien";
    char s2[] = "chiot";
    char t[] = {'c', 'h', 'o', 'u', 'x'};
    // ====== TODO ==========
    // ====== faites un dessin  représentant l'état de la mémoire.

    //| A | c | h | i | e | n | \0 | c | h | i | o | t | \0 | c | h | o | u | x

    // ------------------------------------------------------------
    // Affichage des 4 variables
    printf("Affichage des 4 variables\n");
    printf("%c %s %s\n", c, s1, s2);
    for(int i = 0; i < 5; i++){
        printf("%c", t[i]);
    }

    // ------------------------------------------------------------
    // Utilisation de strlen
    printf("\nstrlen or not strlen, this is the question\n");
    // ====== TODO ==========

    //strlen : fonctionne en détectant le \0 à la fin d'un string, ne peut donc pas fonctionner sur un tableau de caractère ou un seul caractère.

    printf("%d\n", (int)strlen(&c)); //un seul caractère donc ça marche pas
    printf("%d\n", (int)strlen(s1));
    printf("%d\n", (int)strlen(s2));
    printf("%d\n", (int)strlen(t)); //faux : \0 n'existe pas donc il bug

    // ------------------------------------------------------------
    // Quelle est la différence en s1 et s2 ?
    printf("différence entre s1 et s2\n");

    //Différence entre s1 et s2 : s1 est read-only et pas s2

    // explications
    // ====== TODO ==========

    // Modifier la 4me lettre de s1
    // ====== TODO ==========

    // Modifier la 4me lettre de s2
    // ====== TODO ==========

    // ------------------------------------------------------------
    // Combien de cases
    // ====== TODO ==========
    //taille+1 (pour le \0)

    // ------------------------------------------------------------
    // Remplacer la 3me lettre (le 'i') de s2 par '\0'
    printf("longueur vs. nombre de cases\n");
    // ====== TODO ==========
    //le nombre de cases c'est la longueur +1 (\0)

    // ------------------------------------------------------------
    // peut-on appeler strlen sur une chaîne littérale ?
    printf("strlen sur une chaîne littérale\n");
    // ====== TODO ==========
    //oui on peut pas la modifier mais on peut toujours la lire

    printf("\n");

    return EXIT_SUCCESS;
}