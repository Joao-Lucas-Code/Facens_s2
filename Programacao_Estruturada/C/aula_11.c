#include <stdlib.h>
#include <stdio.h>

void muda(int *p) {
  *p = 50;
}

int main() {
  int x = 20;
  printf("Valor de x antes da mudanca: %d\n", x);
  muda(&x);
  printf("Valor de x depois da mudanca: %d\n", x);
  return 0;
}