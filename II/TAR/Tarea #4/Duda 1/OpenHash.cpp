#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 50

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

void insertInT(nodo **T, int m, int val);
bool removeFromT(nodo **T, int m, int val);
void printT(nodo **T, int m);

// creamos una Tabla de Hash largo m y le ingresamos n nodos aleatorios
int main(int argc, char **argv){
	if(argc != 3){
		cout << "Execution Error! call: ./openHashT <n> <m>" << endl;
		exit(EXIT_FAILURE);
	}

	int i, val, val2, n, m;
	n = atoi(argv[1]);
	m = atoi(argv[2]);

	nodo **T = new nodo*[m];		// tabla de tamaño m
	for (i=0; i<m; i++)
		T[i] = NULL;

	// ingresamos n items...
	for (i=0; i<n; i++){
		val = rand()%MAX;
		insertInT(T, m, val);
		printT(T, m);
	}

	// eliminamos e ingresamos n items...
	for (i=0; i<n; i++){
		val = rand()%MAX;
		if(removeFromT(T, m, val)){
			val2 = rand()%MAX;
			cout << "Se elimina " << val << " y se inserta " << val2 << endl;
			insertInT(T, m, val2);
			printT(T, m);
		}else
			cout << "nodo con val=" << val << " No existe!" << endl;
	}

	cout << "## Fin del programa ##" << endl;

	return EXIT_SUCCESS;
}

// inserta un nudo con valor val en la lista correspondiente a su clave
void insertInT(nodo **T, int m, int val){
	int key = val%m;

	nodo *nuevo = new nodo;
	nuevo->val = val;
	nuevo->next = nullptr;

	nodo *p = T[key];

	if(p == nullptr){
		p = nuevo;
	}
	else{
		while(p->next != nullptr){
			p = p->next;
		}
		p->next = nuevo;
	}

}

bool removeFromT(nodo **T, int m, int val){
	nodo *p, *q;
	int key = val%m;

	if (T[key] == nullptr)
		return false;

	if (T[key]->val == val){		// esta an inicio de la lista T[key] ?
		q = T[key];
		T[key] = T[key]->next;
		delete q;
	}else{
		p = T[key];
		while (p->next != nullptr && p->next->val != val)
			p = p->next;

		if (p->next != nullptr && p->next->val == val){
			q = p->next;
			p->next = p->next->next;
			delete q;
		}else
			return false;
	}

	return true;
}


void printT(nodo **T, int m){
	int i;
	nodo *p;

	for (i=0; i<m; i++){
		if (T[i] != nullptr){
			cout << "T[" << i << "] = ";
			p = T[i];
			while (p != nullptr){
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
	cout << "---------" << endl;
}
