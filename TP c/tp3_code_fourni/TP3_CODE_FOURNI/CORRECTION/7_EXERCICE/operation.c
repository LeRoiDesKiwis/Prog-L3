#include "operation.h"

// variable globale : définition et initialisation
int dummy = 14;

// compte le nombre d'opérations
// static pour être locale au fichier et être sûr que l'utilisateur ne la modifie pas (private en fait)
static int nbOperations = 0;

int plus(int a, int b)
{
    nbOperations ++;
    return a + b;
}

int moins(int a, int b)
{
    nbOperations ++;
    return a - b;
}

// ce qui revient à avoir un getter et pas de setter
int getNbOperations()
{
    return nbOperations;
}
