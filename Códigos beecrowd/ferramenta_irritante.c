#include <stdio.h>

void leitura_pixels(int n, int m, char** pixels, char** imagem) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &pixels[i][j]);
            imagem[i][j] = '0';
        }
    }
}

int  verifica_imagem(int n, int m, char** pixels, char** imagem){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pixels[i][j] != imagem[i][j]) {
                return -1;
            }
        }
    }
    return 0;
}

int percorre_imagem(int n, int m, int r, int c, char** pixels, char** imagem) {
    int operacoes = 0;

    for (int i = 0; i <= n - r; i++) {
        for (int j = 0; j <= m - c; j++) {
            if (pixels[i][j] != imagem[i][j]) {
                operacoes++;

                for (int k = i; k < i + r; k++) {
                    for (int l = j; l < j + c; l++) {
                        imagem[k][l] = '1' - imagem[k][l] + '0';
                    }
                }
            }
        }
    }

    if(verifica_imagem(n,m,pixels,imagem) == -1) return -1;
    else return operacoes;
}

int main() {
     int n, m, r, c;

    while (scanf("%d %d %d %d", &n, &m, &r, &c)) {

        if (n == 0 && m == 0 && r == 0 && c == 0) {
            break; 
        }

        char** pixels = (char**)malloc(n * sizeof(char*));
        char** imagem = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            pixels[i] = (char*)malloc(m * sizeof(char));
            imagem[i] = (char*)malloc(m * sizeof(char));
        }

        leitura_pixels(n, m, pixels, imagem);

        printf("%d\n",percorre_imagem(n, m, r, c, pixels, imagem));

        for (int i = 0; i < n; i++) {
            free(pixels[i]);
            free(imagem[i]);
        }
        free(pixels);
        free(imagem);
       
    }
    return 0;
}