#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

void pere(/* paramètres ! */)
{
    printf("Je suis le père %d\n", getpid());

    int a, b;

    printf("entrez deux entiers : ");
    scanf("%d %d", &a, &b);
    
    // envoyer les deux entiers au fils (toujours avec les assert)
    // TODO
    
    // récupérer le résultat envoyé par le fils et l'afficher
    // TODO
}

void fils(/* paramètres ! */)
{
    printf("    Je suis le fils %d\n", getpid());

    // récupérer les deux entiers envoyés par le père
    // TODO
    
    // calculer la somme et l'envoyer au père
    // TODO
}


int main()
{
    // créez les deux tubes :
    // - ne pas oublier les assert
    // - nommez correctement les variables pour que leurs rôles soient limpides (pas de fds1 et fds2 par exemple)
    //todo
    
    // dupliquer le processus
    // TODO

    if (true /* on est le fils */)
    {
        // fermer les extrémités des tubes inutiles
        // TODO
        
        // appeler la fonction "fils" uniquement avec les descriptors dont elle a besoin
        // TODO
        
        // fermer les extrémités restantes
        // TODO
    }
    else
    {
        // fermer les extrémités des tubes inutiles
        // TODO
        
        // appeler la fonction "pere" uniquement avec les descriptors dont elle a besoin
        // TODO
        
        // fermer les extrémités restantes
        // TODO
        
        // attendre la fin du fils
        // TODO
    }

    printf("fin processus %d\n", getpid());
    
    return EXIT_SUCCESS;
}
