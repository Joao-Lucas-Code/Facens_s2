#include <stdio.h>
#include <stdlib.h>
void aloca_int(float **p, int tam);
void recebe(float *p, int tam);
int main(void)
{
  float *ptr = NULL;
  aloca_int(&ptr, 10);
  recebe(ptr, 10);

  return 0;
}
void recebe(float *p, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("\nDigite o valor para o elemento %d: ", i);
    scanf("%f", &p[i]);
  }
}

void aloca_int(float **p, int tam)
{
  if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
  {
    printf("Erro na alocacao!");
    exit(1);
  }
  printf("\nFuncao aloca - endereco = %p", *p);
}
