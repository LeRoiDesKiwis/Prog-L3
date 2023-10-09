#include <stdio.h>
#include <stdlib.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <n1> <n2>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 3)
        usage(argv[0], NULL);

    // il faut afficher la somme de argv[1] et de argv[2]
    // note : argv[1] et argv[2] sont des chaînes de caractères
    // TODO

    return EXIT_SUCCESS;
}
