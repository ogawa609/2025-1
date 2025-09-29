#include <stdio.h>

int main() {
    int N;
    float soma = 0;
    float media;
    int maior;
    int i = 0;
    int primeiro = 1; // Flag para o primeiro número

    do {
        scanf("%d", &N);

        if (N == 0) {
            break;
        }

        // Atualiza maior na primeira entrada
        if (primeiro) {
            maior = N;
            primeiro = 0;
        }

        soma = soma + N;
        i++;
        media = soma / i;

        if (N > maior) {
            maior = N;
        }

        printf("%d %.6f\n", maior, media);
    } while (1);

    return 0;
}