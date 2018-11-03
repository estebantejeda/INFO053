#include <stdio.h>
#include <stdlib.h>

int realizarSuma(int x);

int main (int argc, char **argv){
	if (atoi(argv[1]) > 1000 || atoi(argv[1]) < -1000){
		printf("Error, no se puede ingresar un numero mayor a 1000 digitos\n");
		exit(EXIT_FAILURE);
	}
	int x = atoi(argv[1]);
	int a = realizarSuma(x);
	printf("%i\n", a);
	return 0;
}

int realizarSuma(int x){
  int a = 0;
	if(x > 0){
		while(x > 0){
	    a = a + x;
	    x--;
	  }
	}
	else{
		while(x < 2){
			a = a + x;
			x++;
			}
		}
		return a;
}
