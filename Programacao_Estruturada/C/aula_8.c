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

int main() {
    int n;
    printf("Quantos números reais? ");
    scanf("%d", &n);

    float *vetor = aloca_float(n);

    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i+1);
        scanf("%f", &vetor[i]);
    }

    printf("Valores em ordem inversa:\n");
    for (int i = n-1; i >= 0; i--) {
        printf("%.2f\n", vetor[i]);
    }

    free(vetor);
    return 0;
}