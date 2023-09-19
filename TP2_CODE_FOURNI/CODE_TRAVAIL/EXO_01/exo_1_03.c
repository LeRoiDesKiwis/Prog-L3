/*
 * Exercice 1.03
 * compilation :
 *   $ alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'
 *   $ mygcc title.c exo_1_03.c -o exo_1_03
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>      // pour accéder aux fonctions sur les chaînes

#include "title.h"

// Écrire ici la fonction isPalin
// ====== TODO ==========
bool isPalin(const char* s){

    int len = strlen(s);

    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

// Écrire ici la fonction isPalinTab
// ====== TODO ==========

bool isPalinTab(const char s[], int size){

    for(int i = 0; i < size/2; i++){
        if(s[i] != s[size-i-1]) return false;
    }
    return true;
}

int main()
{
    // ------------------------------------------------------------
    title_print("iPalin");
    // appeler isPalin avec les deux chaînes :
    // - "esope reste ici et se repose" : ce n'est pas un palindrome
    // - "esoperesteicietserepose" : c'est un palindrome
    // Pour info voici d'autres palindromes :
    // - "etlamarinevaveniramalte"
    // - "eluparcettecrapule",
    // - "02022020" i.e. le 2 février 2020
    // - "engagelejeuquejelegagne"
    // ====== TODO ==========
    printf("%d %d\n", isPalin("etlamarinevaveniramalte"), isPalin("unephrasealeatoireetlonguejsppourquoielleestaussilonguecettephrase"));
    
    // ------------------------------------------------------------
    title_print("iPalinTab");
    // appeler isPalinTab avec un tableau qui n'est pas un palindrome (par
    // exemple 'b','a','t','e','a','u') puis avec un palindrome (par
    // exemple 'k','a','y','a','k')
    // ====== TODO ==========

    char s[] = {'b', 'a', 't', 'e', 'a', 'u'};
    char s1[] = {'k', 'a', 'y', 'a', 'k'};
    printf("%d %d\n", isPalinTab(s, 6), isPalinTab(s1, 5));

    printf("\n");

    return EXIT_SUCCESS;
}
