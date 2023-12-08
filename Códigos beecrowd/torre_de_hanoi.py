import math


def quadrado_perfeito(soma) :
     print("Soma=",soma)
     raiz = math.isqrt(soma)
     print("Raiz=",raiz)
     
     return raiz * raiz == soma
     
     
def coloca_bolas(n):
     print("cheguei no coloca bolas")
     
     hastes =  [[] for _ in range(n)]
     bolas = 1
     bolas_colocadas = 0
     
     for haste in hastes:
         # tamanho = len(haste)
          if len(haste) == 0 :
               print("entrei no if 1")
               haste.append(bolas)
               bolas += 1
               bolas_colocadas += 1
          if len(haste) >= 1 :
               print("entrei no else")  
               if quadrado_perfeito(haste[-1] + bolas):
                    print("entrei no if 1 do quadrado perfeito")
                    haste.append(bolas)
                    bolas += 1
                    bolas_colocadas += 1
                    
          print("bolas=",bolas,"bolas_colocadas=",bolas_colocadas)
          print("vetor",haste)
        
     for i in hastes :    
          print(i)  
     return bolas_colocadas;
               

# num de casos teste
t = int(input())

while t > 0 :
    
     n = int(input())
    
     max_bolas = coloca_bolas(n)
     
     print(max_bolas)
    
     t -= 1