#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodeList{
    int val;
    nodeList *next;
}; typedef struct nodeList nodo;

void push(nodo **T, int val);
void randomPush(nodo **T);
void printList(nodo *T);
void removeList(nodo **T);
float mediaList(nodo *T);
void appendList(nodo **T_1, nodo *T_2);
void addPrevVal(nodo *T);
void insertList(nodo **T_1, nodo *T_2);

void push(nodo **T, int val){
    nodo *p = new nodo;
    p->val = val;
    p->next = *T;
    *T = p;
}

void randomPush(nodo **T){
    nodo *p = new nodo;
    p->val = rand()%100+1;
    p->next = *T;
    *T = p;
}

void printList(nodo *T){
    while(T != NULL){
        cout << T->val << " ";
        T = T->next;
    }
    cout << endl;
}

void removeList(nodo **T){
    while (*T != NULL){
        nodo *p = *T;
        *T = (*T)->next;
        delete p;
    }
}

float mediaList(nodo *T){
    int k = 0;
    float x = 0;
    while(T != NULL){
        x = x + T->val;
        k++;
        T = T->next;
    }
    x = x/k;
    return x;
}

void appendList(nodo **T_1, nodo *T_2){
    nodo *p = *T_1;
    while(p->next != NULL){
        p = p->next;
    }
    while(T_2 != NULL){
        nodo *q = new nodo;
        q->val = T_2->val;
        p->next = q;
        p = q;
        T_2 = T_2->next;
    }
}

void addPrevVal(nodo *T){
    int k = 0;
    while(T != NULL){
        T->val = T->val + k;
        k = T->val;
        T = T->next;
    }
}

void insertList(nodo **T_1, nodo *T_2){
    nodo *p = *T_1;
    while(T_2 != NULL){
        if(T_2->val < (*T_1)->val){
            nodo *q = new nodo;
            q->val = T_2->val;
            q->next = *T_1;
            *T_1 = q;
            T_2 = T_2->next;
            p = *T_1;
        }
        else if(p->next != NULL && T_2->val <= (p->next)->val){
            nodo *q = new nodo;
            q->val = T_2->val;
            q->next = p->next;
            p->next = q;
            T_2 = T_2->next;
            p = p->next;
        }
        else if(p->next == NULL){
            nodo *q = new nodo;
            q->val = T_2->val;
            p->next = q;
            p = q;
            T_2 = T_2->next;
            q->next = NULL; //¿? DUDA
        }
        else{
            p = p->next;
        }
    }
}
