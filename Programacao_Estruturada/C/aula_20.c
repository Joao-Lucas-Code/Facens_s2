#include <stdio.h>
#include <stdlib.h>

typedef struct quarto{
  int num; // numero do quarto
  char categoria; // [S]olteiro / [F]amiliar
  char status; // [L]ivre/ [O]cupado
}quarto;

typedef struct hospede{
  int quarto; // número do quarto
  char nome[80];
  int acompanhante; // quantidade de acompanhantes 
  char categoria; // [S]olteiro / [F]amiliar
  int dias; // tempo de permanência
}hospede;

/* protótipos (evitam declarações implícitas) */
void aloca_quarto(quarto **q, int tam);
void cadastra_quarto(quarto *q, int tam);

int main(void)
{
  quarto *pq = NULL;
  hospede *ph = NULL;
  int cont = 0, op, pos;

  aloca_quarto(&pq, 15); /* o &pq é a chamada por referência */
  cadastra_quarto(pq, 15);

  /* liberar memória antes de sair */
  free(pq);
  return 0;
}

void aloca_quarto(quarto **q, int tam)
{
  /* realloc com ponteiro NULL funciona como malloc */
  *q = (quarto*) realloc(*q, (size_t) (tam * sizeof(quarto)));
  if (*q == NULL) {
    fprintf(stderr, "Erro ao alocar memoria!\n");
    exit(1);
  }
}

void cadastra_quarto(quarto *q, int tam)
{
  int i;
  for(i=0; i<tam; i++, q++)
  {
    q->num = i+1; // -> acessa um campo
    /* status é um char, use literal de caractere */
    q->status = 'L';
    if (i<5)
      q->categoria = 'S';
    else
      q->categoria = 'F';
  }
}