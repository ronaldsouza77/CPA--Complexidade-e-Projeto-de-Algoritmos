"""
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

# Leitura do número de casos de teste
num_testes = int(input())

# Processamento dos casos de teste
for i in range(num_testes):
    caso_teste = int(input())
    fib = fibonacci(caso_teste)
    calls = 2 * fib - 2
    print(f"fib({caso_teste}) = {calls} calls = {fib}")


# Recursão
def fibonacci(n):
    if n == 0:
        return 0, 0
    elif n == 1:
        return 1, 0
    else:
        a, calls_a = fibonacci(n - 1)
        b, calls_b = fibonacci(n - 2)
        calls = calls_a + calls_b + 2
        return a + b, calls

# número de casos de teste
num_testes = int(input())

# Processamento dos casos de teste
for _ in range(num_testes):
    x = int(input())
    result, calls = fibonacci(x)
    print(f"fib({x}) = {calls} calls = {result}")
"""
def fibonacci(n):
    fib_values = [0, 1]  # Lista para armazenar os valores de Fibonacci

    for i in range(2, n + 1):
        fib_values.append(fib_values[i - 1] + fib_values[i - 2])

    return fib_values[n], 2 * n

# número de casos de teste
num_testes = int(input())

# Processando os casos de teste
for _ in range(num_testes):
    x = int(input())
    result, calls = fibonacci(x)
    print(f"fib({x}) = {calls} calls = {result}")
