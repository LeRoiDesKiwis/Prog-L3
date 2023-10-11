#include <stdio.h>
#include <stdlib.h>
// inclure les .h nécessaires
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

void recepteur(int fds[2])
{
    printf("Je suis le récepteur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    // TODO (ne pas oublier les assert)
    int ret = close(fds[1]);
    assert(ret == 0);

    // on applique le protocole suivant :
    // on reçoit d'abord la taille de la chaine
    // on alloue la place nécessaire
    // on reçoit en une fois la chaîne
    // attention aux fuites mémoire
    // TODO
    int len;
    char *s;
    read(fds[0], &len, sizeof(int));
    printf("Received %d size\n", len);
    s = malloc(sizeof(char)*len);
    ret = read(fds[0], s, sizeof(char)*len);
    assert(ret == (int)(sizeof(char)*len));
    
    printf("%s\n", s);
    free(s);

    // fermeture de l'extrémité restante
    // TODO
    close(fds[0]);
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}

void envoyeur(int fds[2], const char * s)
{
    printf("    Je suis l'envoyeur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    // TODO
    int ret = close(fds[0]);
    // protocole : cf. fonction précédente
    // TODO
    assert(ret == 0);
    int len = strlen(s)+1;

    write(fds[1], &len, sizeof(int));
    write(fds[1], s, len*sizeof(char));
    // fermeture de l'extrémité restante
    // TODO
    printf("Sended %s (size %d)\n", s, len);
    close(fds[1]);
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}


int main()
{
    // on déclare la chaîne en dur pour se concentrer sur la communication
    const char * const s = "Bonjour monde !";

    // création du tube
    // TODO
    int fds[2];
    pipe(fds);

    // on commence par le récepteur mais c'est arbitraire
    // donc fork et dans le fils on appelle recepteur
    // TODO
    if(fork() == 0) recepteur(fds);
    
    // puis l'envoyeur
    // donc fork et dans le fils on appelle envoyeur
    // TODO
    if(fork() == 0) envoyeur(fds, s);
        
    // le père n'utilise pas le tube
    // TODO
    close(fds[0]);
    close(fds[1]);
    printf("Le père se met en attente de la fin des fils\n");
    // TODO
    wait(NULL);

    printf("fin processus père %d\n", getpid());
    
    return EXIT_SUCCESS;
}
