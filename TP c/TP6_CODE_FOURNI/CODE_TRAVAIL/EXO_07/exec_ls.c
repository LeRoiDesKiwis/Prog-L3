#include <stdio.h>
#include <stdlib.h>
// des .h à inclure
// TODO

int main()
{
    // construire le tableau d'arguments à passer dans le execv
    // donc les arguments de "ls" sont "-l" et "-h"
    // spoil/rappel : il faut un tableau de 4 cases
    // TODO

    // appeler execv avec "/bin/ls"
    // TODO
    
    // si on est là, execv a obligatoirement renvoyé -1
    perror("Problème exec");
    
    return EXIT_SUCCESS;
}
