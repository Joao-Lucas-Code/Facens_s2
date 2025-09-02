#include <stdio.h>
#include <stdlib.h>
void aloca_int(float **p, int tam);
void recebe(float *p, int tam);
void imprime(float *p, int q);
void altera(float *p, int q);

int main(void)
{
  float *ptr = NULL;
  aloca_int(&ptr, 10);
  recebe(ptr, 10);
  imprime(ptr, 10);
  altera(ptr, 10);
  imprime(ptr, 10);

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

void imprime(float *p, int q)
{
  for (int i = 0; i < q; i++)
  {
    printf("\nElemento [%d]: %.2f", i, p[i]);
  }
}

void altera(float *p, int q)
{
  for (int i = 0; i < q; i++)
  {
    printf("\nDigite o novo valor para o elemento [%d]: ", i);
    scanf("%f", &p[i]);
  }
}
