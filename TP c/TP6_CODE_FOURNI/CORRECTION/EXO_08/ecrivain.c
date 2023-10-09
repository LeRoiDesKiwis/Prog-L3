#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/wait.h>

static void usage(const char *exeName, const char *message)
{
    fprintf(stderr, "usage : %s <fd>\n", exeName);
    if (message != NULL)
        fprintf(stderr, "message : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        usage(argv[0], NULL);

    printf("[père] Je suis le père %d (après exec)\n", getpid());

    int a, b;
    int fd = atoi(argv[1]);
    int ret;

    printf("[père] Entrez deux entiers : ");
    scanf("%d %d", &a, &b);
    ret = write(fd, &a, sizeof(int));
    assert(ret == sizeof(int));
    ret = write(fd, &b, sizeof(int));
    assert(ret == sizeof(int));

    close(fd);

    // on peut envisager un wait ici
    pid_t retWait = wait(NULL);
    assert(retWait != -1);
    printf("père] mon fils %d a terminé\n", retWait);

    return EXIT_SUCCESS;
}
