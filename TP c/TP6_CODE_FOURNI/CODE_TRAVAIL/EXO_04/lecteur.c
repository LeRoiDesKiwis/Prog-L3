#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
// inclure les .h manquants

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

    // ouvrir avec "open" le tube en lecture (ne pas oublier le assert)
    // (note : le tube doit exister avant le lancement du programme)
    // TODO
    int tube = open(argv[1], O_RDONLY);
    assert(tube != -1);
    char c;

    while(true)
    {
        // écrire dans le tube (avec un assert)
        int ret = read(tube, &c, sizeof(char));
        assert(ret != 0);
        assert(ret == sizeof(char));
        printf("%c", c);
        // TODO
    }

    // il ne faut pas oublier qqch ici
    // TODO
    close(tube);
    return EXIT_SUCCESS;
}
