#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>

int main()
{
    int a, b;
    char *sommeArgv[4];
    char atxt[1000];     // on surdimensionne pour ne pas allonger le code
    char btxt[1000];     // et pour se concentrer sur le exec (mais c'est incorrect)
    
    printf("entrez a et b : ");
    scanf("%d %d", &a, &b);

    // execv prend un tableau de chaînes, dont conversion obligatoire
    // notons que le programme cible va les retransformer en entiers
    sprintf(atxt, "%d", a);
    sprintf(btxt, "%d", b);

    sommeArgv[0] = "somme";
    sommeArgv[1] = atxt;
    sommeArgv[2] = btxt;
    sommeArgv[3] = NULL;

    int ret = execv(sommeArgv[0], sommeArgv);

    // si on est là, ret vaut obligatoirement -1
    printf("retour de exec : %d (normalement -1)\n", ret);
    perror("Problème exec");
    assert(false);    // juste pour qu'on ne sorte pas du programme avec un succès

    // note : le code ci-après n'est jamais exécuté si le exec est ok

    return EXIT_SUCCESS;
}
