#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int memo[]) {
    memo[1] = 1;
    memo[2] = 2;
    int i = 3;
    while (memo[i - 1] <= n) {
        memo[i] = memo[i - 1] + memo[i - 2];
        i++;
    }
    return i;
}

void move_direita(int binario[], int i) {
    int ultimo_elemento = binario[1];

    for (int j = 2; j < i; j++) {
        binario[j - 1] = binario[j];
    }

    binario[i - 1] = ultimo_elemento;
}

void representa_binario(int binario[], int i, int x, int memo[]) {
    for (int j = i; j > 0; j--) {
        if (x >= memo[j]) {
            binario[j] = 1;
            x -= memo[j];
        } else {
            binario[j] = 0;
        }
    }
}

void calcula_milhas(int binario[], int i, int memo[]) {
    int milhas = 0;
    for (int j = i - 2; j >= 0; j--) {
        if (binario[j] == 1) {
            milhas += (binario[j] * memo[j]);
        }
    }
    printf("%d\n", milhas);
}

int main() {
    int t, x;

    scanf("%d", &t);

    int* memo = (int*)malloc(25002 * sizeof(int));

    while (t > 0) {
        scanf("%d", &x);

        int i = fibonacci(x, memo);

        int* binario = (int*)malloc(i * sizeof(int));

        representa_binario(binario, i, x, memo);
        if (i > 1) {
            move_direita(binario, i);
        }
        calcula_milhas(binario, i, memo);
        free(binario);
        t--;
    }

    free(memo);

    return 0;
}
