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

  aloca_quarto(&pq,15);
  cadastra_quarto(pq,15)
}