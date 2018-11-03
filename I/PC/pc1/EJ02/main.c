#include <stdio.h>
#include <stdlib.h>

void tarro(int c, int s);

int main (int argc, char **argv){
	int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  tarro(x, y);
  return 0;
}

void tarro(int c, int s){
  int a = c + s - 1;
  c = a - c;
  s = a - s;
  printf("A Carlitos le faltaron: %i\n", c);
  printf("A Sergio le faltaron: %i\n", s);
}
