#ifndef NODE_H
#define NODE_H

#define MAXELEM 10

typedef struct nodo{
    int nelem;
    int pos;
    int array[MAXELEM];
} nodo;

nodo* crear_nodo(){
    //printf("x = %i asasa1\n", x); fflush(stdout);
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    //printf("x = %i asasa2\n", x); fflush(stdout);
    aux->nelem = 0;
    aux->pos = 0;

    for(int i=0; i<MAXELEM; ++i){
        aux->array[i] = -1;
    }
}

#endif
