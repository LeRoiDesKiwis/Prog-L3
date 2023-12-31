// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "exo8_comm.h"

const int MIN_SECONDES = 2;
const int MAX_SECONDES = 4;


//-----------------------------------------------------------------
// Il faut récupérer le sémaphore avec une clé générée par ftok et le
// le fichier fourni dans exo7_comm.h
// Il faut être rigoureux : le sémaphore doit déjà exister sinon
//      c'est une erreur
static int my_semget()
{
    // TODO
    return -1;
}


//-----------------------------------------------------------------
// On entre en SC et on est bloqué s'il y a trop de monde
static void entrerSC(int semId)
{
    // TODO
}

//-----------------------------------------------------------------
// On sort de la  SC
static void sortirSC(int semId)
{
    // TODO
}


//-----------------------------------------------------------------
int main()
{
    int tempsAttente;
    int semId;
    char prefixe[100];  // on surdimensionne pour se simplifier la vie (incorrect bien entendu)
    
    snprintf(prefixe, 100, "[%d] ", getpid());

    // initialisation générateur aléatoire    
    srand(getpid());

    // récupération du sémaphore
    semId = my_semget();

    // simule la 1re partie du code
    tempsAttente = MIN_SECONDES + rand() % (MAX_SECONDES - MIN_SECONDES + 1);
    printf("%sAvant : je bosse pendant %d seconde(s)\n", prefixe, tempsAttente);
    printf("%s             Zzz...\n", prefixe);
    sleep(tempsAttente);
    printf("%s             j'ai fini.\n", prefixe);

    printf("%s\n", prefixe);
    printf("%sJe tente d'entrer en SC\n", prefixe);
    
    //---SC---------------------------------------------------------------
    // entrée en SC
    entrerSC(semId);

    printf("%s    Je suis en SC\n", prefixe);
    sleep(7);
    printf("%s    Je sors de SC\n", prefixe);
    printf("%s\n", prefixe);

    // sortie de la SC
    sortirSC(semId);
    //--------------------------------------------------------------------
    
    // simule la 2me partie du code
    printf("%sJe suis sorti de SC\n", prefixe);
    
    return EXIT_SUCCESS;
}
