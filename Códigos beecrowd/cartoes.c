#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b) {
     if(a > b) return a;
     else return b;
}

long long min(long long a, long long b) {
     if(a > b) return b;
     else return a;
}

long long max_pontos(int seq_cartoes[], int n) {
    long long pontuacao[n][2];
    int jogador_atual = 0;
    int jogador_anterior = 1;

    // Inicializar o caso base
    for (int i = 0; i < n - 1; ++i) {
        pontuacao[i][0] = max(seq_cartoes[i], seq_cartoes[i + 1]);
    }

    int i, j;
    long long primeiro_cartao, ultimo_cartao;

    for (int intervalo = 4; intervalo <= n; intervalo += 2) {
        jogador_anterior = jogador_atual;

        if (jogador_atual == 0) jogador_atual = 1;
        else jogador_atual = 0;

        i = 0;
        j = intervalo - 1;

        while (j < n){

            primeiro_cartao = seq_cartoes[i] + min(pontuacao[i + 1][jogador_anterior], pontuacao[i + 2][jogador_anterior]);

            ultimo_cartao = seq_cartoes[j] + min(pontuacao[i][jogador_anterior], pontuacao[i + 1][jogador_anterior]);

            pontuacao[i][jogador_atual] = max(primeiro_cartao, ultimo_cartao);

            i++;
            j++;
        }
    }

    return pontuacao[0][jogador_atual];
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
      
        int seq_cartoes[n];
      
        for (int i = 0; i < n; ++i) {
            scanf("%d", &seq_cartoes[i]);
        }

        printf("%lld\n", max_pontos(seq_cartoes, n));
    }

    return 0;
}
