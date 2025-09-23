
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno{
  char nome[50];
  int idade;
  int ra;
} aluno;

int main()
{
  aluno a[3];
  int idade_limite;

  // Entrada dos dados dos alunos
  for (int i = 0; i < 3; i++) {
    printf("Digite o nome do %do aluno: ", i+1);
    fgets(a[i].nome, sizeof(a[i].nome), stdin);
    a[i].nome[strcspn(a[i].nome, "\n")] = '\0'; // remove o \n
    printf("Digite a idade do %do aluno: ", i+1);
    scanf("%d", &a[i].idade);
    getchar(); // limpa o buffer

    printf("Digite o RA do %do aluno: ", i+1);
    scanf("%d", &a[i].ra);
    getchar(); // limpa o buffer
  }

  printf("\nDigite uma idade limite: ");
  scanf("%d", &idade_limite);

  printf("\nAlunos com idade menor que %d:\n", idade_limite);
  for (int i = 0; i < 3; i++) {
    if (a[i].idade < idade_limite) {
      printf("Nome: %s, Idade: %d\n", a[i].nome, a[i].idade);
    }
  }

  return 0;
}

