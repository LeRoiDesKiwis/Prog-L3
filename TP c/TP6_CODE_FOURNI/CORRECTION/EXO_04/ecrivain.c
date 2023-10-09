#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
// inclure les .h manquants
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <nom tube>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    int fd;
    int ret;
    
    // ouvrir avec "open" le tube en écriture (ne pas oublier le assert)
    // (note : le tube doit exister avant le lancement du programme)
    // TODO
    fd = open(argv[1], O_WRONLY);
    assert(fd != -1);

    printf("Le tube est ouvert en écriture\n");

    printf("Saisissez des caractères. '!' pour terminer\n");

    while(true)
    {
        char c = getchar();
        if (c == '!')
            break;
        // écrire dans le tube (avec un assert)
        // TODO
        ret = write(fd, &c, sizeof(char));
        assert(ret != -1);               // vérifie qu'il n'y a pas d'erreur (cf. aussi fonction perror")
        assert(ret == sizeof(char));     // vérifie que le bon nombre d'octets a été lu
    }

    // il ne faut pas oublier qqch ici
    // TODO
    ret = close(fd);
    assert(ret == 0);   // ou "!= -1"

    return EXIT_SUCCESS;
}
