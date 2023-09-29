/*
 * Exercice 1.02
 * compilation :
 *   $ make 1_2_exercice
 */

#include <stdio.h>
#include <stdlib.h>

// Donc à part montrer la différence entre déclaration
// et définition, ce code est n'importe quoi

// déclarer afficheN
// ====== TODO (en fait c'est cadeau) ==========
void afficheN(int n, const char *msg);  // déclaration

void afficheN(int n, const char *msg);  // déclaration

// définir afficheN
// ====== TODO ==========
void afficheN(int n, const char *msg){
    for(int i = 0; i < n; i++){
        printf(msg);
    }
}

// déclarer afficheN
// ====== TODO ==========
void afficheN(int n, const char *msg);  // déclaration

int main()
{
    // déclarer afficheN
    // ====== TODO ==========
    void afficheN(int n, const char *msg);  // déclaration

    // appeler afficheN pour afficher 3 fois "Bonjour"
    // ====== TODO ==========
    afficheN(3, "Bonjour")
    
    return EXIT_SUCCESS;
}
