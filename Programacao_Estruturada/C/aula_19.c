// treino das funções 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
} Produto;

void buscar(Produto *p, int tam, int cod_busca);
void listar(Produto *p, int tam);

int main(){
  
}

void buscar(Produto *p, int tam, int cod_busca) {
  int i;
  for (i = 0, i < tam; i++) {
    if ((p + 1)->codigo == cod_busca)
    return i;
  }
  return 1;
}

