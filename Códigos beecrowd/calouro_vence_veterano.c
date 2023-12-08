#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long merge(char **matriculas, int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int tam = fim - inicio + 1;
    char **temp = (char**) malloc(tam * sizeof(char*));
    unsigned long long count = 0;

    while (i <= meio && j <= fim) {
        if (strcmp(matriculas[i], matriculas[j]) > 0) {
            count += meio - i + 1;
            temp[k++] = matriculas[j++];
        } else {
            temp[k++] = matriculas[i++];
        }
    }

    while (i <= meio) {
        temp[k++] = matriculas[i++];
    }

    while (j <= fim) {
        temp[k++] = matriculas[j++];
    }

    for (int x = 0; x < tam; x++) {
        matriculas[inicio + x] = temp[x];
    }

    free(temp);

    return count;
}

unsigned long long merge_sort(char **matriculas, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        long long count = 0;

        count += merge_sort(matriculas, inicio, meio);
        count += merge_sort(matriculas, meio + 1, fim);
        count += merge(matriculas, inicio, meio, fim);

        return count;
    }

    return 0;
}

int main() {
    int casos;
    while(scanf("%d", &casos) != EOF){
  
        char **matriculas = (char**) malloc(casos * sizeof(char*));

        for (int i = 0; i < casos; i++) {
            matriculas[i] = (char*) malloc(11 * sizeof(char));
            scanf("%10s", matriculas[i]);
        }

        unsigned long long count = merge_sort(matriculas, 0, casos - 1);

        printf("%lld\n", count);

        for (int i = 0; i < casos; i++) {
            free(matriculas[i]);
        }

        free(matriculas);
    }
    return 0;
}
