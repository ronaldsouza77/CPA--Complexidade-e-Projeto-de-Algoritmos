#include <stdio.h>
#include <string.h>

void merge(char nomes[][21], int inicio, int meio, int fim, int k) {
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;

    char nomes_esquerda[tamanho_esquerda][21];
    char nomes_direita[tamanho_direita][21];

    // Copia os nomes para os arrays auxiliares
    for (int i = 0; i < tamanho_esquerda; i++) {
        strcpy(nomes_esquerda[i], nomes[inicio + i]);
    }
    for (int j = 0; j < tamanho_direita; j++) {
        strcpy(nomes_direita[j], nomes[meio + 1 + j]);
    }

    int i = 0, j = 0, posicao = inicio;

    // Combina as duas metades, considerando o número máximo de trocas permitidas
    while (i < tamanho_esquerda && j < tamanho_direita) {
        if (strcmp(nomes_esquerda[i], nomes_direita[j]) <= 0) {
            strcpy(nomes[posicao], nomes_esquerda[i]);
            i++;
        } else {
            strcpy(nomes[posicao], nomes_direita[j]);
            j++;
            k--;
        }
        posicao++;

        // Verifica se o número máximo de trocas foi atingido
        if (k == 0) {
            break;
        }
    }

    // Copia os elementos restantes da metade esquerda
    while (i < tamanho_esquerda) {
        strcpy(nomes[posicao], nomes_esquerda[i]);
        i++;
        posicao++;
    }

    // Copia os elementos restantes da metade direita
    while (j < tamanho_direita) {
        strcpy(nomes[posicao], nomes_direita[j]);
        j++;
        posicao++;
    }
}

void mergeSort(char nomes[][21], int inicio, int fim, int k) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a metade esquerda
        mergeSort(nomes, inicio, meio, k);

        // Ordena a metade direita
        mergeSort(nomes, meio + 1, fim, k);

        // Combina as duas metades ordenadas
        merge(nomes, inicio, meio, fim, k);
    }
}

int main() {
    int instancia = 1;
    int n, k;
    char nomes[100][21];

    while (1) {
        scanf("%d %d", &n, &k);

        if (n == 0 && k == 0) {
            break;
        }

        // Leitura dos nomes
        for (int i = 0; i < n; i++) {
            scanf("%s", nomes[i]);
        }

        // Ordena os nomes usando o merge sort modificado
        if (k > 0 && n > 1) mergeSort(nomes, 0, n - 1, k);

        // Impressão da saída
        printf("Instancia %d\n", instancia);
        for (int i = 0; i < n; i++) {
            printf("%s ", nomes[i]);
        }
        printf("\n\n");

        instancia++;
    }

    return 0;
}