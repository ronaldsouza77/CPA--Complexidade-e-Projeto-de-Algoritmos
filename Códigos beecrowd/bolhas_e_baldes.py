while True:
    n, *seq = map(int, input().split())
    if n == 0:
        break
    
    inversoes = 0
    for i in range(n):
        for j in range(i + 1, n):
            if seq[j] < seq[i]:
                inversoes += 1

    if inversoes % 2 == 0:
        print("Carlos")
    else:
        print("Marcelo")
