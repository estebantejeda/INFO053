#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"
#include "caja.h"

int main(int argc, char **argv) {
    if(argc != 2){
        fprintf(stderr, "ejecutar como ./prog N\n");
        exit(EXIT_FAILURE);
    }
    // N personas
    int N = atoi(argv[1]);
    // crear una instancia de cola
    const char *nombres[20] = {"Carlitos", "Yannet", "Rolando", "Pat", "Wei", "Macedonio", "Chuck", "Alex", "Evaristo", "Tito",
                                "Bartolo", "Verito", "Gato", "Chamyto", "Jorge", "Alvaro", "Alicia", "Rodrigo", "Modesto", "Panchito"};

    cola *q = crear_cola();
    srand(13);
    printf("Comenzando:\n");
    ingresar_personas(q, N, nombres);
    while(cola_largo(q) != 0){
        printf("Presione [enter] para iniciar trabajo de cajera....");
        getchar();
        //en cada instante, la cajera atiene una cantidad equivalente a 100 anios en edad.
        int p = cajera_trabajo(q);
        printf("Cajera Atiende %i personas\n", p);
        cola_imprimir(q);
        printf("\n\n\n");


        //en cada instante, entra un nuevo grupo N de personas.
        printf("Ingresan %i personas\n", N);
        ingresar_personas(q, N, nombres);
    }
    cola_imprimir(q);
    return EXIT_SUCCESS;	
}
