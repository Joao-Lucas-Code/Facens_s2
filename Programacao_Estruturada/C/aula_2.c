#include <stdio.h>
#include <ctype.h>

int main() {
    int num[5];
    int *p_num;
    int d;
    char continuar;

    while (1) {
        p_num = num;

        printf("Lendo os 5 elementos do array:\n");

        for (d = 0; d < 5; d++) {
            printf("Digite o %iº elemento: ", d + 1);
            scanf("%i", p_num + d);
        }

        printf("\nImprimindo os elementos do array:\n");

        for (d = 0; d < 5; d++) {
            printf("num[%i] = %i\n", d, *(p_num + d));
        }

        printf("\nDeseja continuar? (S/N): ");
        scanf(" %c", &continuar);

        if (toupper(continuar) == 'N') {
            break;
        }
    }

    printf("\nPrograma finalizado.\n");

    return 0;
}