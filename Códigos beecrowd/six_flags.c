#include <stdio.h>

int pontuacao_pd(int n, int duracao[], int pontuacao[], int t) {
    int c[n + 1][t + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        c[i][0] = 0;
    }

    for (j = 0; j <= t; j++) {
        c[0][j] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= t; j++) {

            if (duracao[i - 1] > j) {               
                c[i][j] = c[i - 1][j];

            } else {
                int max_repeticoes = j / duracao[i - 1];
                int maior_pontuacao = 0;
                int pontuacao_atual;

                for (int r = 0; r <= max_repeticoes; r++) {

                    pontuacao_atual = r * pontuacao[i - 1] + c[i - 1][j - r * duracao[i - 1]];

                    if (pontuacao_atual > maior_pontuacao) maior_pontuacao = pontuacao_atual;

                }

                c[i][j] = maior_pontuacao;
            }
        }
    }
    return c[n][t];
}

int main() {
    int instancia = 1;
    int n, t;

    while (scanf("%d %d", &n, &t)) {

        if (n == 0 && t == 0) {
            break;
        }

        int duracao[n], pontuacao[n];

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &duracao[i], &pontuacao[i]);
        }

        printf("Instancia %d\n", instancia);
        printf("%d\n\n",pontuacao_pd(n, duracao, pontuacao, t));

        instancia++;
    }

    return 0;
}
