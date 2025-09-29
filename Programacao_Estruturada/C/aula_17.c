// Exercicio Feito pela professora Andreia com 
#include <stdlib.h>
#include <stdio.h>

struct cliente{
  char nome[30];
  int conta;
  float saldo;
};

void cadastro(struct cliente *p);
int busca(struct cliente *p, int tam);
void movimenta(struct cliente *p, int op);

int main(){
  struct cliente cli[10], *pcli;
  int cont=0, op, pos;
  pcli = cli;
  do{
    system("cls");
    printf("\n[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\nOPCAO:");
      scanf("%i", &op);
      fflush(stdin);
      switch (op)
      {
        case 1: if(cont<10)
          {
            cadastro(pcli+cont);
            cont++;
          }// If
        else
          printf("\nLimite de clientes atingido\n");
          break;
      case 2:
      case 3: pos=busca(pcli, cont);
        if(pos>=0)
        {
          movimenta(pcli+pos, op);
        }// If
        else
          printf("\nConta nao encontrada\n");
        system("pause");
        break;
      } // Switch
  } while(op != 4);
} // Main 

void cadastro(struct cliente *p)
{
  static int n=1000;
  printf("\nNome: ");
  gets(p->nome);
  fflush(stdin);
  p->conta=n;
  n+=100;
  p->saldo=0;
  printf("\nConta: %i", p->conta);
  system("pause");
}// Cadastro


int busca (struct cliente *p, int tam)
{
  int conta_procurada, i;
  
  printf("\nDigite o numero da conta: ");
  scanf("%d", &conta_procurada);
  fflush(stdin);
  
  for(i = 0; i < tam; i++) {
    if(p[i].conta == conta_procurada) {
      return i; // Retorna a posição do cliente encontrado
    }
  }
  
  return -1; // Retorna -1 se não encontrar a conta
}// Busca
void movimenta(struct cliente *p, int op)
{
  float valor;
  printf("\nNome: %s\nSaldo: %.2f\n\n",p->nome,p->saldo);
  if(op==2)
    printf("\nValor a ser depositado: ");
  else
    printf("\nValor a ser retirado: ");
  scanf("%f", &valor);
  fflush(stdin);
  if(op==2)
    p->saldo+=valor;
  else
    p->saldo-=valor;

  printf("\nSaldo atualizado: %.2f\n\n",p->saldo);
}// Movimenta 