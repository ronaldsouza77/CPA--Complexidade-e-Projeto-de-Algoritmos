def fibonacci(x):
  
    fib = [1, 2]
    i = 2
    while fib[i-1] <= x:
        fib.append(fib[i-1] + fib[i-2])
        i += 1
    return fib

def representa_binario(fib,x):
    binario = []
    for num in reversed(fib):
        if num <= x:
            binario.append(1)
            x -= num
        else:
            binario.append(0)
            
    binario.pop()
    return binario[::-1]

def calcula_milhas(x):
    
    fib = fibonacci(x)
    binario = representa_binario(fib,x)
   
    milhas = 0
    tam = len(binario)
    
    for i in range(tam):
        milhas += binario[i]*fib[i]
    return milhas
    

# Ler o número de distâncias
t = int(input())

# Processar cada distância
while t > 0 :
    x = int(input())
    milhas = calcula_milhas(x)
    print(milhas)
    t -= 1
