#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto{
  int num; // numero do quarto
  char categoria; // [S]olteiro / [F]amiliar
  char status; // [L]ivre/ [O]cupado
}quarto;

typedef struct hospede{
  int quarto; // número do quarto (-1 se vaga no vetor)
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
int busca_hospede(hospede *h, int tam, int quarto_val);
int busca_quarto(quarto *q, int qq, char cat);

int main(void)
{
  quarto *pq = NULL;
  hospede *ph = NULL;
  int cont = 0, op = 0, pos;

  aloca_quarto(&pq, 15); /* o &pq é a chamada por referência */
  cadastra_quarto(pq, 15);

  do{
    system("cls");
    printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospedes\n[5]Fim\nOpcao:");
    scanf("%i", &op);
    fflush(stdin);
    switch(op)
    {
      case 1: // Check-in
        /* Procure na lista de hospedes por uma posição livre (quarto == -1) */
        pos = busca_hospede(ph, cont, -1); 
        if(pos == -1)
        {
          aloca_hospede(&ph, cont + 1);
          pos = cont;
          cont++;
        }
        cadastra_hospede(ph + pos, pq, 15);
        break;

      case 2: /* Check-out (a implementar) */
        printf("Funcao Check-out nao implementada ainda.\n");
        system("pause");
        break;

      case 3: /* Mostra quartos */
        for (int i = 0; i < 15; i++)
          printf("Quarto %d - Categoria %c - Status %c\n", pq[i].num, pq[i].categoria, pq[i].status);
        system("pause");
        break;

      case 4: /* Mostra hospedes */
        for (int i = 0; i < cont; i++)
        {
          if (ph[i].quarto != -1)
            printf("Nome: %s, Quarto: %d, Dias: %d\n", ph[i].nome, ph[i].quarto, ph[i].dias);
        }
        system("pause");
        break;

      case 5:
        break;

      default:
        printf("Opcao invalida!\n");
        system("pause");
    }//switch
  }while(op!=5);

  /* liberar memória antes de sair */
  free(pq);
  free(ph);
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
    q->status = 'L'; // todos livres no cadastro
    if (i<5)
      q->categoria = 'S';
    else
      q->categoria = 'F';
  }
}

void aloca_hospede(hospede **h, int tam)
{
  *h = (hospede*) realloc(*h, (size_t) (tam * sizeof(hospede)));
  if (*h == NULL) {
    fprintf(stderr, "Erro ao alocar memoria para hospedes!\n");
    exit(1);
  }
  /* inicializa os novos elementos (marca quarto como -1) */
  for (int i = 0; i < tam; i++)
    (*h)[i].quarto = -1;
}

void cadastra_hospede(hospede *h, quarto *q, int qq)
{
  char buffer[120];
  printf("\nNome: ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  strncpy(h->nome, buffer, sizeof(h->nome)-1);
  h->nome[sizeof(h->nome)-1] = '\0';

  do{
    printf("\nQtde de acompanhantes - max.3: ");
    scanf("%i",&h->acompanhante);
    fflush(stdin);
  }while(h->acompanhante<0 || h->acompanhante>3);

  if(h->acompanhante==0)
    h->categoria='S';
  else
    h->categoria='F';

  printf("\nQuantidade de dias: ");
  scanf("%i", &h->dias);
  fflush(stdin);

  /* procura um quarto disponível da categoria */
  int quarto_num = busca_quarto(q, qq, h->categoria);
  if (quarto_num == -1) {
    printf("\nNao ha quartos disponiveis para essa categoria.\n");
    h->quarto = -1;
  } else {
    h->quarto = quarto_num;
    printf("\nHospede alocado no quarto %d\n", quarto_num);
  }
}

int busca_hospede(hospede *h, int tam, int quarto_val)
{
  if (h == NULL || tam <= 0) return -1;
  for (int i = 0; i < tam; i++) {
    if (h[i].quarto == quarto_val)
      return i;
  }
  return -1;
}

int busca_quarto(quarto *q, int qq, char cat)
{
    int i;
    for(i=0; i<qq; i++, q++) // Usa qq como limite e q para navegar
    {
        if(q->categoria == cat && q->status == 'L') // Categoria bate? Status é Livre?
        {
            q->status = 'O';      // Se sim, MUDA o status para Ocupado!
            return q->num;        // E RETORNA o número do quarto.
        }
    }
    return -1; // Se o loop terminar e não achar nada, retorna -1.
}