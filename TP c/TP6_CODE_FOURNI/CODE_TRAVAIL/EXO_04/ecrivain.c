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

    printf("%s", argv[1]);
    int tube = open(argv[1], O_WRONLY);
    assert(tube != -1);

    printf("Le tube est ouvert en écriture\n");

    printf("Saisissez des caractères. '!' pour terminer\n");

    while(true)
    {
        char c = getchar();
        if (c == '!')
            break;
        // écrire dans le tube (avec un assert)
        int ret = write(tube, &c, sizeof(char));
        assert(ret != 0);
        assert(ret == sizeof(char));
        // TODO
    }

    // il ne faut pas oublier qqch ici
    // TODO
    close(tube);
    
    return EXIT_SUCCESS;
}
