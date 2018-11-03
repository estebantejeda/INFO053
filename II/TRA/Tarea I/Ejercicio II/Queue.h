#include <iostream>
#include <stdlib.h>

using namespace std;

struct Queue{
    int prio;
    int age;
    Queue *next;
}; typedef struct Queue queue;

void enqueue(queue **T, int prio, int age);
void enqueueRight(queue **T, int prio, int age);
void printList(queue *T);
void removeNodo(queue **Q, int prio);

void enqueue(queue **T, int prio, int age){
    queue *p = new queue;
    p->prio = prio;
    p->age = age;
    p->next = *T;
    *T = p;
}

void enqueueRight(queue **T, int prio, int age){
    queue *p = new queue;
    p->prio = prio;
    p->age = age;
    p->next = NULL;
    if(*T == nullptr){
        *T = p;
    }
    else{
        queue *q = *T;
        while(q->next != nullptr){
            q = q->next;
        }
        q->next = p;
    }

}

void dequeue(queue **Q1, queue **Q2, queue **Q3){
    queue *p = *Q1;
    queue *q = *Q1;
    queue *r = *Q1;
    queue *s = *Q1;
    queue *t = *Q1;
    queue *u = *Q1;

    while(p != nullptr){
        if(p->prio == 3){
            enqueue(Q3, 3, p->age);
            removeNodo(Q1, 3);
        }
        p = p->next;
    }

    while(q != nullptr){
        if(q->prio == 2 && q->age <= 15){
            enqueue(Q2, 2, q->age);
        }
        q = q->next;
    }

    while(r != nullptr){
        if(r->prio == 2 && r->age >= 75){
            enqueue(Q2, 2, r->age);
        }
        r = r->next;
    }

    while(s != nullptr){
        if(s->prio == 2 && (s->age >= 60 && s->age < 75) ){
            enqueue(Q2, 2, s->age);
        }
        s = s->next;
    }

    while(t != nullptr){
        if(t->prio == 2 && (t->age > 15 && t->age < 60) ){
            enqueue(Q2, 2, t->age);
        }
        t = t->next;
    }

    while(u != nullptr){
        removeNodo(Q1, 2);
        u = u->next;
    }

}

void removeNodo(queue **Q, int prio){
    queue *p = *Q;
    if(p->prio == prio){
        *Q = (*Q)->next;
        delete p;
    }
    else{
        while((p->next)->prio != prio){
            p = p->next;
        }
        queue *q = p->next;
        p->next = q->next;
        delete q;
    }
}

void printList(queue *T){
    while(T != NULL){
        cout << "Edad: " << T->age << " Prioridad: " << T->prio << endl;
        T = T->next;
    }
    cout << endl;
}
