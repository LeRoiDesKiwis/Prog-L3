#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>

int main()
{
    char *lsArgv[4];
    lsArgv[0] = "/bin/ls";     // la première case est la commande
    lsArgv[1] = "-l";
    lsArgv[2] = "-h";
    lsArgv[3] = NULL;          // ne pas oublier le marqueur de fin

    int ret = execv(lsArgv[0], lsArgv);

    // si on est là, ret vaut obligatoirement -1
    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");
    assert(false);    // juste pour qu'on ne sorte pas du programme avec un succès
    
    return EXIT_SUCCESS;
}
