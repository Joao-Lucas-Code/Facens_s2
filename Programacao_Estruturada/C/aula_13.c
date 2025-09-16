#include <stdlib.h>
#include <stdio.h>

int main() {
  int *vetor = NULL;
  int qtd = 0; // quantidade de numeros a serem lidos
  char op;

  do {
    // aumenta o vetor em 1 posição
    vetor = (int*)realloc(vetor, (qtd + 1) * sizeof(int));
    if (vetor == NULL) {
      printf("Erro ao alocar memoria!\n");
      return 1; // sair com erro
    }

    // ler o novo numero
    printf("Digite o valor: ");
    scanf("%i", &vetor[qtd]);
    
    qtd++;

    // perguntar se deseja continuar
    printf("Deseja continuar? (s/n): ");
    scanf(" %c", &op);
  } while (op == 's');

  // exibir os numeros lidos
  printf("Os numeros digitados foram:\n");
  for (int i = 0; i < qtd; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  // liberar a memoria alocada
  free(vetor);

  return 0;
}