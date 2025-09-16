#include <stdlib.h>
#include <stdio.h>

int main() {
  int x = 10;
  int* p = &x;
  printf("Valor de x: %d\n", *p);
  return 0;
}