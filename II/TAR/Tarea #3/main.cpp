#include <iostream>
#include <stdlib.h>
#include "Pilas.h"
#include "Colas.h"

int main(int argc, char **argv){
    if (argc != 3 || atoi(argv[1]) < 0 || atoi(argv[2]) < 0){
        cout << "Error. Debe ejecutarse como ./main n m (n,m > 0)" << endl;
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = (n/m)+m;

    Stack s, l;
    Queue q;

    for (int i = 0; i < n; i++){
        s.push(rand()%100+1);
    }
    for (int i = 0; i < m; i++){
        q.enqueue(rand()%100+1);
    }

    s.display();
    q.display();

    for (int i = 0; i <= (m+n)/k; i++){
        cout << i;
    }

}
