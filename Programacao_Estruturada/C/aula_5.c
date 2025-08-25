#include <stdio.h>
#include <stdlib.h>

void leitura(float *p, int q);
void media(float *pa, float *pb, float *pc, int q);
void imprime(float *p, int q);

int main() {
  float n1[10], n2[10], med[10];
  int qtde;
  do {
    printf("\nQuantos elementos - max.10: ");
    scanf("%d", &qtde);
    fflush(stdin);
  } while (qtde <= 0 || qtde > 10);
  system("cls");
  printf("\nNotas da prova 1:");
  leitura(n1, qtde);

  printf("\nNotas da prova 2:");
  leitura(n2, qtde);

  media(n1, n2, med, qtde);

  printf("\nMedia:");
  imprime(med, qtde);

  printf("\n");
  system("pause");
  return 0;
}

void leitura(float *p, int q) {
  for (int i = 0; i < q; i++, p++) {
    do {
      printf("\nNotas do %i aluno: ", i+1);
      scanf("%f", p);
      fflush(stdin);
      if (*p < 0 || *p > 10) {
        printf("Nota inválida! Digite novamente.\n");
      }
    } while (*p < 0 || *p > 10);
  }
}

void media(float *pa, float *pb, float *pc, int q) {
  for (int i = 0; i < q; i++, pa++, pb++, pc++) {
    *pc = (*pa + *pb) / 2;
  } /// media
}

void imprime(float *p, int q) {
  for (int i = 0; i < q; i++, p++) {
    printf("\nElemento [%d]: %.2f", i, *p);
  } /// imprime
}