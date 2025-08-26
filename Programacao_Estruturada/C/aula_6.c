/* Exercico que pega os dias que querem registrar
 Encontra a maior temperatura 
 depois a média das temperaturas
 por fim, as temperaturas abaixo da média */

#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void leitura(float *p, int q);
void maior(float *p, int q);
void media(float *p, int q);
void menor_que_media(float *p, int q);

int main() {
  float temp[31];
  int qtde;
  do {
    printf("\nQuantos dias quer calcular a temperatura - max.31: ");
    scanf("%d", &qtde);
    fflush(stdin); 
  } while (qtde <= 0 || qtde > 31);
  system("cls");
  leitura(temp, qtde);
  maior(temp, qtde);
  media(temp, qtde);
  menor_que_media(temp, qtde);
  return 0;
}

void leitura(float *p, int q) {
  for (int i = 0; i < q; i++) {
    printf("\nTemperatura do dia [%d]: ", i);
    scanf("%f", &p[i]);
    fflush(stdin); 
  }
}

void maior(float *p, int q) {
  float maior = p[0];
  for (int i = 1; i < q; i++) {
    if (p[i] > maior) {
      maior = p[i];
    }
  }
  printf("\nMaior temperatura: %.2f", maior);
}

void media(float *p, int q) {
  float soma = 0;
  for (int i = 0; i < q; i++) {
    soma += p[i];
  }
  printf("\nMedia das temperaturas: %.2f", soma / q);
}

void menor_que_media(float *p, int q) {
  float soma = 0;
  for (int i = 0; i < q; i++) {
    soma += p[i];
  }
  float media = soma / q;
  printf("\nTemperaturas abaixo da media (%.2f):", media);
  for (int i = 0; i < q; i++) {
    if (p[i] < media) {
      printf(" %.2f", p[i]);
    }
  }
}