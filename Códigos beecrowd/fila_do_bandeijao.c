#include <stdio.h>
#include <stdlib.h>

void ordena(int* distancias, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (distancias[j] < distancias[j + 1]) {
                int temp = distancias[j];
                distancias[j] = distancias[j + 1];
                distancias[j + 1] = temp;
            }
        }
    }
}

int calcula_distancias(int* posicoes, int n, int k) {
    int* distancias = (int*)malloc(n * sizeof(int));
    distancias[0] = 0;

    for (int i = 1; i < n; i++) {
        distancias[i] = posicoes[i] - posicoes[i - 1];
    }

    int soma_das_distancias = 0;

    ordena(distancias, n);

    for (int i = k - 1; i < n; i++) {
        soma_das_distancias += distancias[i];
    }

    free(distancias);

    return soma_das_distancias;
}

int main() {
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF) {
        int* posicoes = (int*)malloc(n * sizeof(int));

        posicoes[0] = 0;

        for (int i = 1; i < n; i++) {
            scanf("%d", &posicoes[i]);
        }

        printf("%d\n", calcula_distancias(posicoes, n, k));

        free(posicoes);
    }

    return 0;
}
