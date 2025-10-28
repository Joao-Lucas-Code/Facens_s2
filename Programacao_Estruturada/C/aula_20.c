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
void aloca_hospede(hospede **h, int tam);
void cadastra_hospede(hospede *h, quarto *q, int qq);
int busca_hospede(hospede *h, int tam);

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

  do{
    system("cls");
    printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospedes\n[5]Fim\nOpcao:");
    scanf("%i", &op);
    fflush(stdin);
    switch(op)
    {
      case 1: // Check=in
      // Procure na lista de hospedes se alguem cujo quarto é -1 (DEU CHECK-OUT)
      pos = busca_hospede(ph, cont, -1); 
        if(pos == -1)
        {
          aloca_hospede(&ph, cont + 1);
          pos = cont;
          cont++;
        }
        cadastra_hospede(ph + pos, pq, 15)
      break;
    }//switch
  }while(op!=5);
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
    q->status = 'L'; // todos livres no cadastro
    if (i<5)
      q->categoria = 'S';
    else
      q->categoria = 'F';
  }
}

void cadastra_hospede(hospede *h, quarto *q, int qq)
{
    printf("\nNome: ");
    gets(h->nome);
    fflush(stdin);
    do{
        printf("\nQtde de acompanhantes - max.3: ");
        scanf("%i",&h->acompanhante);
        fflush(stdin);
    }while(h->acompanhante<0 || h->acompanhante>3);

    if(h->acompanhante==0)
        h->categoria='S';
    else
        h->categoria='F';
    // ...
}

void cadastra_hospede(hospede *h, quarto *q, int qq)
{
  printf("\nNome: ");
  gets(h->nome);
  fflush(stdin);
  do{
    printf("\nQtde de acompanhantes - max.3: ");
        scanf("%i",&h->acompanhante);
        fflush(stdin);
  }while(h->acompanhante<0 || h->acompanhante>3);

  if(h->acompanhante==0)
    h->categoria='S';
  else
    h->categoria='F';
}