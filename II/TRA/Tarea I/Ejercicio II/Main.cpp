#include <iostream>
#include <cstdlib>
#include "Queue.h"
#include "Stack.h"
#define M 90

using namespace std;

int main(int argc, char **argv){
    if (argc != 2 || atoi(argv[1]) < 0){
        cout << "Error. Debe ejecutarse como ./main n (n > 0)" << endl;
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    queue *Q1 = NULL;
    queue *Q2 = NULL;
    queue *Q3 = NULL;
    stack *P1 = NULL;
    stack *P2 = NULL;
    stack *P3 = NULL;
    stack *P4 = NULL;
    stack *P5 = NULL;
    stack *P6 = NULL;

    for (int i = 0; i < n; i++){
        enqueue(&Q1, rand()%3+1, rand()%M+1);
    }

    cout << "Cola Original" << endl;
    printList(Q1);

    dequeue(&Q1, &Q2, &Q3);

    cout << "Cola Prioridad 2" << endl;
    printList(Q2);
    cout << "Cola Prioridad 3" << endl;
    printList(Q3);

    queue *p = Q1;
    while(p != nullptr){
        switch (p->age <15) {
            case 1:
                push(&P1, 2, p->age);
                break;
        }
        switch (p->age >= 15 && p->age < 30) {
            case 1:
                push(&P2, 2, p->age);
                break;
        }
        switch (p->age >= 30 && p->age < 45) {
            case 1:
                push(&P3, 2, p->age);
                break;
        }
        switch (p->age >= 45 && p->age < 60) {
            case 1:
                push(&P4, 2, p->age);
                break;
        }
        switch (p->age >= 60 && p->age < 75) {
            case 1:
                push(&P5, 2, p->age);
                break;
        }
        switch (p->age >=75) {
            case 1:
                push(&P6, 2, p->age);
                break;
        }
        p = p->next;
    }

    cout << "Pila de Prioridad 1" << endl;
    printList(P1);
    cout << "Pila de Prioridad 2" << endl;
    printList(P2);
    cout << "Pila de Prioridad 3" << endl;
    printList(P3);
    cout << "Pila de Prioridad 4" << endl;
    printList(P4);
    cout << "Pila de Prioridad 5" << endl;
    printList(P5);
    cout << "Pila de Prioridad 6" << endl;
    printList(P6);

}
