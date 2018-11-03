#ifndef CAJA_H
#define CAJA_H
void ingresar_personas(cola *q, int N, const char **nombres){
    int edad, npos;
    for(int i=0; i<N; ++i){
        edad = rand()%120;
        npos = rand()%20;
        cola_insertar(q, 0, edad, nombres[npos]);
        printf("%s (edad %i) entrando a la cola\n", nombres[npos], edad); 
        cola_imprimir(q);
        printf("\n");
    }
    printf("\n\n\n");
}

int cajera_trabajo(cola *q){
    // implementar
    return 0;
}
#endif
