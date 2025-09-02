#include <stdio.h>
#include <stdlib.h>

float* aloca_float(int tam) {
    float *p = (float*) malloc(tam * sizeof(float));
    if (p == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }
    return p;
}

void recebe_valores(float *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o %d valor: ", i+1);
        scanf("%f", &vetor[i]);
    }
}

void imprime_inverso(float *vetor, int n) {
    printf("Valores em ordem inversa:\n");
    for (int i = n-1; i >= 0; i--) {
        printf("%.2f\n", vetor[i]);
    }
}

int main() {
    int n;
    printf("Quantos numeros reais? ");
    scanf("%d", &n);

    float *vetor = aloca_float(n);

    recebe_valores(vetor, n);
    imprime_inverso(vetor, n);

    free(vetor);
    return 0;
}
