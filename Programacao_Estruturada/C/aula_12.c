# include <stdlib.h>
# include <stdio.h>

int main(){
  int *vetor = NULL;
  int i;

  // alocar espaço para 5 inteiros
  vetor = (int*)malloc(5 * sizeof(int));
  if (vetor == NULL) {
    printf("Erro ao alocar memoria!\n");
    return 1; // sair com erro
  }

  // leitura dos 5 numeros
  printf("Digite 5 numeros inteiros:\n");
  for (i = 0; i < 5; i++) {
    printf("Digite o valor %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  // exibir os numeros lidos
  printf("Os numeros digitados foram:\n");
  for (i = 0; i < 5; i++) {
    printf("%d ", vetor[i]);
  }

  // liberar a memoria alocada
  free(vetor);

  return 0;
}