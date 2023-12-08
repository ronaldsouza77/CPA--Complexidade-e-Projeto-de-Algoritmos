#include <stdio.h>
#include <math.h>

int quadrado_perfeito(int soma) {

    double raiz = sqrt(soma);

    if(raiz == (int)raiz) return 1;
    else return 0;
}

int coloca_bolas(int n) {

    int hastes[n];
    for (int i = 0; i < n; i++) {
        hastes[i] = 0;
    }

    int bolas = 1, bolas_colocadas = 0;
    int i;

    for (i = 0; i < n; i++) {

        if (hastes[i] == 0) {
            hastes[i] = bolas;
            bolas++;
            bolas_colocadas++;
            i = -1;

        }else if (quadrado_perfeito(hastes[i] + bolas)){
            hastes[i] = bolas;
            bolas++;
            bolas_colocadas++;
            i = -1;
            
        }else if (i == n - 1){
            break;
        }

    }
    return bolas_colocadas;
}
 
int main() {
 
    int t, n;

    scanf("%d", &t);

    while(t > 0){
        scanf("%d", &n);

        int max_bolas = coloca_bolas(n);
    
        printf("%d\n", max_bolas);

        t--;
    }

    return 0;
}