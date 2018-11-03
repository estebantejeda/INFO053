#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#define M 5
using namespace std;

int posAprox(int x, int n);
bool isXinA(int *A, int n, int x, int *pos, int *c);
bool bbXinA(int *A, int n, int x, int *pos, int *c);

int main(int argc, char **argv){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}

	//Crear y Declarar Variables

	int x = atoi(argv[1]);
	int n = rand()%100+1;
	int inc = rand()%M;
	int *A = new int[n-1];
	int *p, *q;
	int *r, *s;

	//Rellenar Array con Números Aleatorios

	A[0] = 0;
	for(int i = 0; i < n-1; i++){
		A[i+1] = A[i] + inc;
	}

	//Realizar Experimento

	isXinA(A, n, x, p, r);
	bbXinA(A, n, x, q, s);

}

int posAprox(int x, int n){
	int i = 2*x/M;
	return i;
}

bool isXinA(int *A, int n, int x, int *pos, int *c){
	int cont=0;
	int i = posAprox(x, M);

	if (A[i] == x){
		*pos = i;
		*c=1;
		return true;
	}
	if (A[i] > x){
		i--;
		cont++;
		while (i>=0 && A[i] > x){
			i--;
			cont++;
		}
		if (i>=0 && A[i] == x){
			*pos = i;
			*c = cont;
			return true;
		}
	}
	else{
		i++;
		cont++;
		while(i<=0 && A[i] < x){
			i++;
			cont++;
		}
		if(i>=0 && A[i] == x){
			*pos = i;
			*c = cont;
			return true;
		}
	}
	return false;
}

bool bbXinA(int *A, int n, int x, int *pos, int *c){
	int cont = 0;
	int i = posAprox(x, M);

	while (A != NULL){
		if (A[i] == x){
			cont++;
			*c = cont;
			*pos = i;
			return true;
		}
		if (x < A[i]){
			cont++;
			i--;
		}
		else{
			cont++;
			i++;
		}
	*c = cont;
	return false;
	}
}
