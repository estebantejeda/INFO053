#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodeDoubleList{
    int val;
    nodeDoubleList *next;
    nodeDoubleList *prev;
}; typedef struct nodeDoubleList nodoD;

void push(nodoD **T, int val);
void randomPush(nodoD **T);
void printList(nodoD *T);
void printReversed(nodoD *T);
void removeList(nodoD **T);
float mediaList(nodoD *T);
void appendList(nodoD **T_1, nodoD *T_2);
void addPrevVal(nodoD *T);
void insertList(nodoD **T_1, nodoD *T_2);

void push(nodoD **T, int val){
    if(*T == NULL){
        nodoD *p = new nodoD;
        p->val = val;
        p->next = *T;
        p->prev = *T;
        *T = p;
    }
    else{
        nodoD *p = new nodoD;
        p->val = val;
        p->next = *T;
        (*T)->prev = p;
        *T = p;
    }
}

void randomPush(nodoD **T){
    if(*T == NULL){
        nodoD *p = new nodoD;
        p->val = rand()%100+1;
        p->next = *T;
        p->prev = *T;
        *T = p;
    }
    else{
        nodoD *p = new nodoD;
        p->val = rand()%100+1;
        p->next = *T;
        (*T)->prev = p;
        *T = p;
    }
}

void printList(nodoD *T){
    while(T != NULL){
        cout << T->val << " ";
        T = T->next;
    }
    cout << endl;
}

void printReversed(nodoD *T){
    nodoD *p = T;
    while(p->next != NULL){
        p = p->next;
    }
    while(p != NULL){
        cin.get();
        cout << p->val << " ";
        p = p->prev;
    }
}

void removeList(nodoD **T){
    while (*T != NULL){
        cin.get();
        cout << (*T)->val;
        nodoD *p = *T;
        *T = (*T)->next;
        delete p;
    }
}

float mediaList(nodoD *T){
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

void appendList(nodoD **T_1, nodoD *T_2){
    nodoD *p = *T_1;
    while(p->next != NULL){
        p = p->next;
    }
    while(T_2 != NULL){
        nodoD *q = new nodoD;
        q->val = T_2->val;
        p->next = q;
        q->prev = p;
        p = q;
        T_2 = T_2->next;
    }
}

void addPrevVal(nodoD *T){
    int k = 0;
    while(T != NULL){
        T->val = T->val + k;
        k = T->val;
        T = T->next;
    }
}

void insertList(nodoD **T_1, nodoD *T_2){
    nodoD *p = *T_1;
    while(T_2 != NULL){
        if(T_2->val < (*T_1)->val){
            nodoD *q = new nodoD;
            q->val = T_2->val;
            q->next = *T_1;
            (*T_1)->prev = q;
            *T_1 = q;
            T_2 = T_2->next;
            p = *T_1;
        }
        else if(p->next != NULL && T_2->val <= (p->next)->val){
            nodoD *q = new nodoD;
            q->val = T_2->val;
            q->next = p->next;
            (q->next)->prev = q;
            q->prev = p;
            p->next = q;
            T_2 = T_2->next;
            p = p->next;
        }
        else if(p->next == NULL){
            nodoD *q = new nodoD;
            q->val = T_2->val;
            p->next = q;
            q->prev = p;
            p = q;
            T_2 = T_2->next;
            q->next = NULL;
        }
        else{
            p = p->next;
        }
    }
}
