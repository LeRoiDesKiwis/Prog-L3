/*
 * Exercice 1.04
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_04.c -o exo_1_04
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction mirror
// ====== TODO ==========

void mirror(char* s){

    int size = strlen(s);

    for(int i = 0; i < size/2; i++){
        char a = s[i];
        s[i] = s[size-i-1];
        s[size-i-1] = a;
    }

}


int main()
{
    title_print("mirror");

    char s[] = "il fait beau !";  // "char *" est incorrect ! Pourquoi ?
                                  // Parce qu'on va modifier la chaine

    printf("Voici la chaîne avant retournement : \"%s\" (%ld)\n", s, strlen(s));
    // appeler ici la fonction mirror
    // ====== TODO ==========
    mirror(s);
    printf("Voici la chaîne après retournement : \"%s\" (%ld)\n", s, strlen(s));
    
    printf("\n");

    return EXIT_SUCCESS;
}
