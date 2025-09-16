#include <stdlib.h>
#include <stdio.h>

// prototipo da função
void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);

int main() {
  int *vetor = NULL;
  int qtd = 0; // quantidade de numeros a serem lidos
  char op;

  do {
    // realoca para mais 1 posição
    aloca(&vetor, qtd + 1);

    leitura(vetor + qtd); // ler o novo numero

    qtd++;

    // perguntar se deseja continuar
    printf("Deseja continuar? (s/n): ");
    scanf(" %c", &op);
  } while (op == 's');

  printf("Os numeros digitados foram:\n");
  mostra(vetor, qtd);

  free(vetor);
  return 0;
}

// funcao para alocar/realoar memoria
void aloca(int **p, int tam) {
  *p = (int*)realloc(*p, tam * sizeof(int));
  if (*p == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1); // sair com erro
  }
}

// funcao para ler um numero
void leitura(int *p) {
  printf("Digite o valor: ");
  scanf("%i", p);
}

// funcao para mostrar os numeros
void mostra(int *p, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}