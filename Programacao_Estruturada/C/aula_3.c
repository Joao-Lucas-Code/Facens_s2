#include <stdio.h>

int main() {
    #define TAMANHO 10
    
    int vetor[TAMANHO];
    int i;
    int maior;

    printf("Digite os %d elementos do vetor:\n", TAMANHO);
    for (i = 0; i < TAMANHO; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];

    for (i = 1; i < TAMANHO; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    printf("\nO maior elemento digitado foi: %d\n", maior);

    return 0;
}