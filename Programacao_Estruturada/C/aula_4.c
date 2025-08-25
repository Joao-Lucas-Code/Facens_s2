
#include <stdio.h>
#include <stdlib.h>

void leitura(int *p, int q);
void resultante(int *pa, int *pb, int *pc, int q);
void imprime(int *p, int q);

int main() {
  int a[10], b[10], c[10], qtde;
  do {
    printf("\nQuantos elementos da matriz - max.10: ");
    scanf("%d", &qtde);
    fflush(stdin);
  } while (qtde <= 0 || qtde > 10);
  system("cls");
  printf("\nLeitura do vetor A:");
  leitura(a, qtde);

  printf("\nLeitura do vetor B:");
  leitura(b, qtde);

  resultante(a, b, c, qtde);

  printf("\nVetor resultante C:");
  imprime(c, qtde);

  system("pause");
  return 0;
} // main

void leitura(int *p,int q) {
  for (int i = 0; i < q; i++, p++) {
    printf("\nElemento [%d]: ", i);
    scanf("%d", p);
    fflush(stdin);
  } /// for
}

void resultante(int *pa, int *pb, int *pc, int q) {
  int i;
  for (i = 0; i < q; i++, pa++, pb++, pc++) {
    *pc = *pa + *pb;
  } // resultante
}

void imprime(int *p, int q) {
  int i;
  for (i = 0; i < q; i++, p++) {
    printf("\nElemento [%d]: %d", i, *p);
  } /// imprime
}
