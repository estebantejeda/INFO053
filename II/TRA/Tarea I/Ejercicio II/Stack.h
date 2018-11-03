#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stack{
    int prio;
    int age;
    Stack *next;
}; typedef struct Stack stack;

void push(stack **T, int prio, int age);
void printList(stack *T);

void push(stack **T, int prio, int age){
    stack *p = new stack;
    p->prio = prio;
    p->age = age;
    p->next = *T;
    *T = p;

}

void printList(stack *T){
    while(T != NULL){
        cout << "Edad: " << T->age << " Prioridad: " << T->prio << endl;
        T = T->next;
    }
    cout << endl;
}
