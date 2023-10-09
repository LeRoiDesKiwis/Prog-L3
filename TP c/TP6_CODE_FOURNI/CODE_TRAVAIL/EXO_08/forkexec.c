#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

void pere(/* fd en écriture à récupérer */)
{
    printf("[père] Je suis le père %d (avant exec)\n", getpid());

    // faire un execv sur l'exécutable "ecrivain" en lui passant le file
    // descripteur en paramètre
    // note : le file descriptor doit être converti en chaîne de caractères,
    //        et vous pouvez la surdimensionner en dur.
    // TODO
    
    // si on arrive ici, il y a un pb
    perror("pb exec pere");
    assert(false);     // pour sortir "salement" du programme
}

void fils(/* fd en lecture à récupérer */)
{
    printf("    [fils] Je suis le fils %d (avant exec)\n", getpid());

    // faire un execv sur l'exécutable "lecteur" en lui passant le file
    // descripteur en paramètre
    // note : cf. ci-dessus
    // TODO
    
    // si on arrive ici, il y a un pb
    perror("pb exec fils");
    assert(false);     // pour sortir "salement" du programme
}


int main()
{
    // création du tube
    // TODO
    
    // duplication du processus
    // TODO
    
    if (true /* cas du fils */)
    {
        // fermer l'extrémité inutile
        // TODO
        // appeler la fonction "fils" avec le file descriptor restant
        // TODO

        // on n'arrive jamais ici normalement
        assert(false);
    }
    else
    {
        // fermer l'extrémité inutile
        // TODO
        // appeler la fonction "pere" avec le file descriptor restant
        // TODO
        
        // on n'arrive jamais ici normalement
        assert(false);
    }

    // on n'arrive jamais ici normalement
    printf("PB ! Fin processus %d\n", getpid());
    assert(false);

    return EXIT_SUCCESS;
}
