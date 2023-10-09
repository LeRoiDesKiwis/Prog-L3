#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>

int main()
{
    char *lsArgv[4];
    lsArgv[0] = "liste_arguments";
    lsArgv[1] = "tart";
    lsArgv[2] = "empion";
    lsArgv[3] = NULL;

    int ret = execv(lsArgv[0], lsArgv);

    // si on est là, ret vaut obligatoirement -1
    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");
    assert(false);    // juste pour qu'on ne sorte pas du programme avec un succès
 
    return EXIT_SUCCESS;
}
