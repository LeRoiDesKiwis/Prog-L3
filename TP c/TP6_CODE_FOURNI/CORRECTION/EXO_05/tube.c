#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/wait.h>

void recepteur(int fds[2])
{
    int ret;
    
    printf("Je suis le récepteur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    ret = close(fds[1]);  // côté écriture
    assert(ret == 0);

    // on applique le protocole suivant :
    // on reçoit d'abord la taille de la chaine
    // on alloue la place nécessaire
    // on reçoit en une fois la chaîne
    char *s = NULL;
    int len;

    ret = read(fds[0], &len, sizeof(int));
    assert(ret == sizeof(int));
    s = malloc(len * sizeof(char));           // le '\0' est déjà compté dans len
    ret = read(fds[0], s, len*sizeof(char));
    assert(ret == (int) (len*sizeof(char)));
    printf("Récepteur : lecture de %d caractère(s) : \"%s\"\n", len, s);
    free(s);

    // fermeture de l'extrémité restante
    ret = close(fds[0]);
    assert(ret == 0);
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}

void envoyeur(int fds[2], const char * s)
{
    int ret;

    printf("    Je suis l'envoyeur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    ret = close(fds[0]);
    assert(ret == 0);

    // protocole : cf. fonction précédente
    int len = strlen(s) + 1;     // +1 pour le '\0'

    printf("    Envoyeur : envoi de %d caractère(s) : \"%s\"\n", len, s);
    ret = write(fds[1], &len, sizeof(int));
    assert(ret == sizeof(int));
    ret = write(fds[1], s, len*sizeof(char));
    assert(ret == (int) (len*sizeof(char)));
    
    // fermeture de l'extrémité restante
    ret = close(fds[1]);
    assert(ret == 0);

    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}


int main()
{
    // on déclare la chaîne en dur pour se concentrer sur la communication
    const char * const s = "Bonjour monde !";
    int fds[2];
    int ret;
    pid_t retFork, retWait;

    ret = pipe(fds);
    assert(ret == 0);

    // on commence par le récepteur mais c'est arbitraire
    retFork = fork();
    assert(retFork != -1);
    if (retFork == 0)
        recepteur(fds);      // on ne sort pas recepteur, inutile de faire un else

    // puis l'envoyeur
    retFork = fork();
    assert(retFork != -1);
    if (retFork == 0)
        envoyeur(fds, s);    // on ne sort pas envoyeur, inutile de faire un else
        
    // le père n'utilise pas le tube
    ret = close(fds[0]);
    assert(ret == 0);
    ret = close(fds[1]);
    assert(ret == 0);

    printf("Le père se met en attente de la fin des fils\n");
    retWait = wait(NULL);
    assert(retWait != -1);
    retWait = wait(NULL);
    assert(retWait != -1);

    printf("fin processus père %d\n", getpid());
    
    return EXIT_SUCCESS;
}
