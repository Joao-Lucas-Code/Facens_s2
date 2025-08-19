#include <stdio.h>

int main() {
    int num[5], *p_num, d;

    p_num = num;

    printf("Lendo os elementos do array:\n");

    for (d = 0; d < 5; d++) {
        printf("Digite o %i elemento: ", d + 1);
        scanf("%i", p_num + d); 
    }

    printf("\nImprimindo os elementos do array:\n");

    for (d = 0; d < 5; d++) {
        printf("num[%i] = %i\n", d, *(p_num + d));
    }

    return 0; 
}