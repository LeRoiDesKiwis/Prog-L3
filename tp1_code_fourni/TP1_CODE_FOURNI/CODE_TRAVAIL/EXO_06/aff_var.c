#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* env[])
{
	printf("%d arguments\n", argc);
	for(int i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}
	
	printf("\n====\n");
	
	for(int i = 0; env[i] != NULL ; i++){
		printf("%s\n", env[i]);
	}
    
    return EXIT_SUCCESS;
}
