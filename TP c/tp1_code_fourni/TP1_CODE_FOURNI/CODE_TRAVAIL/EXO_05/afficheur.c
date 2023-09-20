#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("yo\n");
    fprintf(stdin, "yo\n");
    fprintf(stderr, "erreur\n");

    int yomec;
    scanf("%d", &yomec);
    printf("%d", yomec);
    
}