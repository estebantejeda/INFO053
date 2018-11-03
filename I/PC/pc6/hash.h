#ifndef HASH_H
#define HASH_H

// universal hashing
int h2(int x){
    return ((a*x + b) % p) % L;
}

int esprimo(int n){
    int i,root;
    if (n%2 == 0 || n%3 == 0)
        return 0;

    root = (int)sqrt(n);
    for (i=5; i<=root; i+=6){
        if (n%i == 0)
           return 0;
    }
    for (i=7; i<=root; i+=6){
        if (n%i == 0)
           return 0;
    }
    return 1;
}

int mprimo(int m){
    int i = m;
    while( !esprimo(i) ){
        ++i;
    }
    return i;
}

void gen_hashfunc(int m, int *a, int *b, int *p){
    // get prime greater than M
    *p = mprimo(m);
    *a = (rand() % *p) + 1;
    *b = rand() % *p;
}

void ht_print(nodo **ht, int m){
   for(int i=0; i<m; ++i){
        nodo *aux = ht[i];
        printf("ht[%i] -> [", i);
        for(int i=0; i<MAXELEM; ++i){
            if(aux->array[i] == -1){
                printf("%2s  ", "  ");
            }
            else{
                printf("%2i  ", aux->array[i]);
            }
        }
        printf("]\n");
    }
}





// ejercicio (1)
int ht_insertar(nodo **ht, int x, int (*h)(int)){
    int index = h2(x);
    nodo *a = ht[index];
    if (a->pos == 0){
        a->array[a->nelem] = x;
        a->nelem = a->nelem + 1;
        if(a->nelem == MAXELEM){
            a->pos = 1;
        }
    }
    else{
        a->pos = 0;
        a->nelem = 0;
    }

}


// ejercicio (2)
int ht_eliminar(nodo **ht, int x, int (*h)(int)){
    int index = h2(x);
    nodo *a = ht[index];
    int i = 0;
    while(i <= MAXELEM && a->array[i] != x){
        i++;
    }
    if (i <= MAXELEM){
        int aux = a->array[i];
        a->array[i] = a->array[a->nelem-1];
        a->array[a->nelem-1] = aux;
        a->nelem = a->nelem-1;
        a->array[a->nelem] = -1;
    }
}

#endif
