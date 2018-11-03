#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tower.h"

int main(int argc, char **argv) {
	if ((argc != 5) || (atoi(argv[2])==atoi(argv[3]))){
		printf("ejecutar como ./prog N O D M \n");
        exit(EXIT_FAILURE);
	}

    //Asignación de Variables de Usuario

    int N = atoi(argv[1]);
    int O = atoi(argv[2]);
	int D = atoi(argv[3]);
    int M = atoi(argv[4]);

    //Creación de Torres

    nodo *A = NULL;
    nodo *B = NULL;
    nodo *C = NULL;

    //Asignación de

    for (int i = 1; i <= N; i++) {
        push(&A, i);
    }

#endif


}
