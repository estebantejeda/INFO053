#include <iostream>
#include <cstdlib>
#include "nodeDoubleList.h"

using namespace std;

int main(int argc, char **argv){
    if (argc != 3 || atoi(argv[1]) < 0 || atoi(argv[2]) < 0){
        cout << "Error. Debe ejecutarse como ./main n m (n,m > 0)" << endl;
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    nodoD *l_1 = NULL;
    nodoD *l_2 = NULL;

//Ejercicio 1

    cout << "\n#### GENERANDO ESTRUCTURA DE DATOS CON NÚMEROS ALEATOREOS ####\n" << endl;

    for (int i = 0; i < n; i++){
        randomPush(&l_1);
    }
    for (int i = 0; i < m; i++){
        randomPush(&l_2);
    }

    cout << "Lista 1: ";
    printList(l_1);
    cout << "Lista 2: ";
    printList(l_2);

//Ejercicio 2

    cout << "\n#### CALCULANDO LA MEDIA DE LAS RESPECTIVAS LISTAS ####\n" << endl;

    cout << "Media de Lista 1: " << mediaList(l_1) << endl;
    cout << "Media de Lista 2: " << mediaList(l_2) << endl;

//Ejercicio 3

    cout << "\n#### AÑADIENDO LA LISTA 2 AL FINAL DE LA LISTA 1 ####\n" << endl;

    appendList(&l_1, l_2);
    cout << "Nueva Lista 1: ";
    printList(l_1);

//Ejercicio 4

    cout << "\n#### REALIZANDO UNA SUMA ACUMULATIVA EN LA LISTA 2 ####\n" << endl;

    addPrevVal(l_2);
    cout << "Nueva Lista 2: ";
    printList(l_2);

//Ejercicio 5

    cout << "\n#### INSERTANDO EN LA LISTA 1 TODOS LOS NODOS DE LA LISTA 2 DE MANERA ASCENDENTE ####\n" << endl;

    removeList(&l_1);
    removeList(&l_2);

    for(int i = n; i > 0; i--){
        push(&l_1, (i+3));
    }
    for(int i = m; i > 0; i--){
        push(&l_2, (i+1)*3);
    }

    cout << "Lista 1: ";
    printList(l_1);
    cout << "Lista 2: ";
    printList(l_2);
    printReversed(l_2);
    /*
    cout << "Nueva Lista 1: ";
    insertList(&l_1, l_2);
    printList(l_1);
    printReversed(l_1);*/
}
