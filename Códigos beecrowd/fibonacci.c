#include <stdio.h>

//variável para contar o num de chamadas recursivas
int calls;

// recursão
int fibonacci(int n) {
    calls++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    //lendo o número de casos teste
    int casos_teste;
    scanf("%d", &casos_teste);

    while (casos_teste--) {
        int n;
        scanf("%d", &n);
        calls = 0;
        int result = fibonacci(n);
        printf("fib(%d) = %d calls = %d\n", n, calls - 1, result);
    }

    return 0;
}