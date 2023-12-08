#include <stdio.h>


int merge_sort(int sequencia[], int temp[], int inicio, int fim) {

    int num_inversoes = 0;

    if (fim > inicio) {
        int meio = (inicio + fim) / 2;
        num_inversoes += merge_sort(sequencia, temp, inicio, meio);
        num_inversoes += merge_sort(sequencia, temp, meio + 1, fim);
        num_inversoes += merge(sequencia, temp, inicio, meio + 1, fim);
    }

    return num_inversoes;
}

int merge(int sequencia[], int temp[], int inicio, int meio, int fim) {

    int num_inversoes = 0;
    int i = inicio;
    int j = meio;
    int k = inicio;

    while (i <= meio - 1 && j <= fim) {
        if (sequencia[i] <= sequencia[j]) {
            temp[k++] = sequencia[i++];
        } else {
            temp[k++] = sequencia[j++];
            num_inversoes += (meio - i);
        }
    }

    while (i <= meio - 1) {
        temp[k++] = sequencia[i++];
    }

    while (j <= fim) {
        temp[k++] = sequencia[j++];
    }

    for (i = inicio; i <= fim; i++) {
        sequencia[i] = temp[i];
    }

    return num_inversoes;
}


char* determinar_vencedor(int sequencia[], int N) {

    int* temp = (int*)malloc(sizeof(int) * N);

    int num_inversoes = merge_sort(sequencia, temp, 0, N - 1);

    free(temp);

    if (num_inversoes % 2 != 0) {
        return "Marcelo";
    } else {
        return "Carlos";
    }
}

int main() {

    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        int sequencia[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sequencia[i]);
        }

        printf("%s\n", determinar_vencedor(sequencia, n));
    }

    return 0;
}
