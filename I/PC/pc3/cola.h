#ifndef COLA_H
#define COLA_H

// -----------------------------------
// definiciones de estructuras
// -----------------------------------


// estructura de nodo
typedef struct nodo{
   int key;
   int data;
   char text[100];
   struct nodo *next;
} nodo;


// estructura de cola
typedef struct cola{
    nodo *c;
    nodo *f;
    int largo;
}cola;






// -----------------------------------
// declaraciones de funciones
// -----------------------------------
void cola_imprimir(cola *q);
void cola_insertar(cola* q, int key, int data, const char *text);
nodo* cola_eliminar(cola *q);
int cola_largo(cola *q);








// -----------------------------------
// definiciones de funciones
// -----------------------------------


// crear un nodo
nodo* crear_nodo(int key, int data, const char *text){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->key = key;
    n->data = data;
    strcpy(n->text, text);
    n->next = NULL;
    return n;
}

// crear cola, la retorna como puntero
cola* crear_cola(){
    cola *q = (cola*)malloc(sizeof(cola));
    q->c = NULL;
    q->f = NULL;
    q->largo = 0;
    return q;
}

// insertar elemento en la cola (FIFO)
void cola_insertar(cola* q, int key, int data, const char *text){
    nodo *n = crear_nodo(key, data, text);
    if(q->c == NULL && q->f == NULL){
        q->c = q->f = n;
    }
    else{
        q->f->next = n;
        q->f = n;
    }
    q->largo++;
    return;
}

// imprimir cola
void cola_imprimir(cola *q){
    nodo *n = q->c;
    while(n != NULL){
        printf("(%s, %i)   ", n->text, n->data);
        n = n->next;
    }
    printf("\n");
    return;
}


// eliminar elemento de la cola (FIFO)
nodo* cola_eliminar(cola* q){
    nodo * n = q->c;
    if(q->c == q->f){
        q->c = q->f = NULL;
    }
    else{
        q->c = q->c->next;
        n->next = NULL;
    }
    q->largo--;
    return n;
}

// cantidad elementos en una cola
int cola_largo(cola *q){
    return q->largo;
}
#endif
