#include <stdlib.h>
#include <stdio.h>

void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);
void media(int *p, int tam);

int main(){
  int *vetor = NULL;
  int qtd = 0;
  char op;

  do {
    aloca(&vetor, qtd + 1);

    leitura(vetor + qtd);

    qtd++;

    printf("Deseja continuar? (s/n): ");
    scanf(" %c", &op);
  } while (op == 's');

  printf("Os numeros digitados foram:\n");
  mostra(vetor, qtd);
  printf("A media dos numeros digitados e: ");
  media(vetor, qtd);

  free(vetor);
  return 0;
}

void aloca(int **p, int tam){
  *p = (int*)realloc(*p, tam * sizeof(int));
  if(*p == NULL){
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }
}

void leitura(int *p){
  printf("Digite um numero: ");
  scanf("%d", p);
}

void mostra(int *p, int tam){
  for(int i = 0; i < tam; i++){
    printf("%d ", p[i]);
  }
  printf("\n");
}

void media(int *p, int tam){
  float soma = 0;
  for(int i = 0; i < tam; i++){
    soma += p[i];
  }
  printf("%.2f\n", soma/tam);
}