#include <stdio.h>
#include <stdlib.h>

int main()
{
    // première partie du code gracieusement offerte
    int i;
    i = 99;
    printf("i = %d\n", i);
    i += 2;
    printf("i = %d\n", i);

    // todo : manipulation du contenu de i via un pointeur
    int *pi = &i;
    printf("Pointeur = %p, Zone pointée = %d\n", (void*) pi, *pi);
    *pi = *pi+2;
    printf("Pointeur = %p, Zone pointée = %d\n", (void*) pi, *pi);
    printf("i = %d\n", i);

    return EXIT_SUCCESS;
}
