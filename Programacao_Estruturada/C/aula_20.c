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
}

int main{
  quarto *pq=NULL;
  hospede *ph=NULL;
  int cont=0,op,pos;

  aloca_quarto(&pq,15); // o &pq é a famosa chamada por referencia
  cadastra_quarto(pq,15)
}

void aloca_quarto(quarto **q, int tam)
{
  if((*q = (quarto*)realloc(*q, tam*sizeof(quarto))) == NULL)
  exit(1);
}

void cadastra_quarto(quarto *q, int tam)
{
  int i;
  for(i=0; i<tam; i++, q++)
  {
    q->num = i+1 // -> acessa um campo
    q->status = "L";
    if (i<5)
      q->categoria = 'S';
    else
      q->categoria = 'F';
  }
}