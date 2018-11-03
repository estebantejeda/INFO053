#ifndef TOWER_H
#define TOWER_H

typedef struct nodo{
    char letter;
    int data;
    struct nodo *nexo;
}nodo;

void push(nodo **p, int data){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->data = data;
    n->nexo = *p;
    *p = n;
}

void impr(nodo *p){
   nodo *ptr = p;
   printf("{ ");
   while(ptr->nexo	!= NULL){
       for (int i = 0; i < ptr->data; i++) {
           printf("*");
       }
   }
   printf(" }");

#endif
