#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
} Produto;

void aloca(Produto **p, int tam);
void cadastrar(Produto *p);
int buscar(Produto *p, int tam, int cod_busca);
void listar(Produto *p, int tam);
void remover(Produto **p, int *tam);

int main(){
  Produto *estoque = NULL;
  int cont = 0;
  int op;
  
  do {
    // ... aqui vai todo o menu com printf e o scanf ...
    printf("\n--- CONTROLE DE ESTOQUE ---\n");
    printf("[1] Cadastrar Produto\n");
    printf("[2] Listar Produtos\n");
    printf("[3] Atualizar Estoque\n"); 
    printf("[4] Remover Produto\n");   
    printf("[5] Sair\n");             
    printf("Opcao: ");
    scanf("%i", &op);       
    
    fflush(stdin);
    
    switch(op) {
      case 1:
      // Aumenta o espaço do vetor 'estoque' para caber mais um
      aloca(&estoque, cont+1);
      // Passa o endereço da nova posição para a função cadastrar preencher
      cadastrar(estoque + cont);
      // Incrementa o nosso contador de produtos
      cont ++;
      
      break;
      
      case 2:
      printf("\n-- Listando Produtos do Estoque --\n");
      listar(estoque, cont); // Chama a função, passando o início do estoque e o total de produtos

      break;

      case 3:
    { // Usar chaves aqui é uma boa prática para criar variáveis locais ao case
        int codigo_busca;
        int indice_encontrado;
        int qtd;

        printf("\n-- Atualizando Estoque --\n");
        printf("Digite o codigo do produto: ");
        scanf("%i", &codigo_busca);
        fflush(stdin);

        indice_encontrado = buscar(estoque, cont, codigo_busca);

        if (indice_encontrado == -1) {
            printf("\nERRO: Produto com codigo %d nao encontrado!\n", codigo_busca);
        } else {
            // Se encontrou, mostre qual produto é:
            printf("\nProduto encontrado: %s\n", (estoque + indice_encontrado)->nome);
            printf("Estoque atual: %d\n", (estoque + indice_encontrado)->quantidade);
            
            printf("\nDigite a quantidade para adicionar (use negativo para remover): ");
            scanf("%i", &qtd);
            fflush(stdin);

            // Atualiza a quantidade
            (estoque + indice_encontrado)->quantidade += qtd;

            printf("\nEstoque atualizado com sucesso!\n");
            printf("Novo estoque: %d\n", (estoque + indice_encontrado)->quantidade);
        }
        break;

      case 4:
            remover(&estoque, &cont);
            break;

        case 5: 
            printf("\nSaindo do sistema...\n");
            break;

        default: 
            printf("\nERRO: Opcao invalida!\n");
            break;
    }
    break;
    }
    system("pause");
    system("cls");
    
  } while(op != 5);
  
  free(estoque); // Liberar a memória no final!
  return 0;
}


void aloca(Produto **p, int tam) {
  if ( (*p = (Produto*)realloc(*p, tam * sizeof(Produto))) == NULL) {
    printf("Erro de alocacao!");
    exit(1);
  }
}

void listar(Produto *p, int tam) {
  int i;

  // // Se tam for 0, significa que não há produtos.
    if (tam == 0) {
        printf("\nEstoque Vazio!\n");
        return; // Sai da função
    }

    // Se houver produtos, percorre o vetor
    for (i = 0; i < tam; i++) {
        printf("------------------------\n");
        printf("Codigo: %d\n", (p + i)->codigo); // Acessa o codigo do i-ésimo produto
        printf("Nome: %s\n", (p + i)->nome);
        printf("Preco: R$ %.2f\n", (p + i)->preco);
        printf("Quantidade: %d un\n", (p + i)->quantidade);
    }
    printf("------------------------\n");
}

int buscar(Produto *p, int tam, int cod_busca) {
    int i;
    for (i = 0; i < tam; i++) {
        // Verifica se o código do produto na posição 'i' é igual ao que buscamos
        if ((p + i)->codigo == cod_busca) {
            return i; // Encontrou! Retorna a posição (o índice) dele.
        }
    }
    return -1; // Percorreu tudo e não encontrou. Retorna -1.
}

void cadastrar(Produto *p) {
    static int codigo_automatico = 100;

    p->codigo = codigo_automatico;
    codigo_automatico++;

    printf("Nome do produto: ");
    gets(p->nome); 
    fflush(stdin);

    printf("Preco: ");
    scanf("%f", &p->preco);
    fflush(stdin);

    printf("Quantidade: ");
    scanf("%i", &p->quantidade);
    fflush(stdin);

    printf("\nProduto #%i - %s cadastrado!\n", p->codigo, p->nome);
}

void remover(Produto **p, int *tam) {
    int codigo_busca;
    int indice_encontrado;

    if (*tam == 0) {
        printf("\nEstoque Vazio! Nada para remover.\n");
        return;
    }

    printf("\n-- Removendo Produto --\n");
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%i", &codigo_busca);
    fflush(stdin);

    indice_encontrado = buscar(*p, *tam, codigo_busca);

    if (indice_encontrado == -1) {
        printf("\nERRO: Produto com codigo %d nao encontrado!\n", codigo_busca);
    } else {
        printf("\nProduto encontrado: %s\n", (*p + indice_encontrado)->nome);
        
        // A mágica acontece aqui:
        // Copia o último elemento para a posição do elemento a ser removido
        *(*p + indice_encontrado) = *(*p + (*tam - 1));

        // Diminui o contador ANTES de realocar
        (*tam)--;

        if (*tam == 0) {
            // Se esvaziou a lista, libera a memória e aponta pra NULL
            free(*p);
            *p = NULL;
        } else {
            // Se ainda tem itens, apenas diminui o tamanho do vetor
            aloca(p, *tam);
        }

        printf("\nProduto removido com sucesso!\n");
    }
}