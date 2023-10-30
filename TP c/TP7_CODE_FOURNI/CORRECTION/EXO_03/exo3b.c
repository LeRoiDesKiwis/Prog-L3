// pour des problèmes de compilation
#define _XOPEN_SOURCE

#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    // ici il faut déclarer un sémaphore (en mode IPC_PRIVATE) de deux cases
    // avec les droits 0641
    // et donc on ne le détruit pas

    int semId;

    // le IPC_CREAT|IPC_EXCL n'est pas utile avec IPC_PRIVATE mais c'est plus clair
    //       IPC_CREAT : on veut créer un sémaphore
    //       IPC_EXCL : déclenche une erreur si le sémaphore existe déjà (impossible avec IPC_PRIVATE)
    //       0641 : : rw-r----x
    semId = semget(IPC_PRIVATE, 2, IPC_CREAT | IPC_EXCL | 0641);
    // et surtout on n'oublie pas les assert
    assert(semId != -1);
    
    // oubli volontaire et assumé de destruction (bien entendu c'est incorrect)
    
    return EXIT_SUCCESS;
}
