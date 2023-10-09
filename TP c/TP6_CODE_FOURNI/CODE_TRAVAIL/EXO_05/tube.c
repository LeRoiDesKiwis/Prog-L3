#include <stdio.h>
#include <stdlib.h>
// inclure les .h nécessaires
#include <sys/types.h>
#include <unistd.h>

void recepteur(int fds[2])
{
    printf("Je suis le récepteur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    // TODO (ne pas oublier les assert)

    // on applique le protocole suivant :
    // on reçoit d'abord la taille de la chaine
    // on alloue la place nécessaire
    // on reçoit en une fois la chaîne
    // attention aux fuites mémoire
    // TODO
    
    // fermeture de l'extrémité restante
    // TODO
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}

void envoyeur(int fds[2], const char * s)
{
    printf("    Je suis l'envoyeur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    // TODO

    // protocole : cf. fonction précédente
    // TODO
    
    // fermeture de l'extrémité restante
    // TODO
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}


int main()
{
    // on déclare la chaîne en dur pour se concentrer sur la communication
    const char * const s = "Bonjour monde !";

    // création du tube
    // TODO

    // on commence par le récepteur mais c'est arbitraire
    // donc fork et dans le fils on appelle recepteur
    // TODO
    
    // puis l'envoyeur
    // donc fork et dans le fils on appelle envoyeur
    // TODO
        
    // le père n'utilise pas le tube
    // TODO

    printf("Le père se met en attente de la fin des fils\n");
    // TODO

    printf("fin processus père %d\n", getpid());
    
    return EXIT_SUCCESS;
}
