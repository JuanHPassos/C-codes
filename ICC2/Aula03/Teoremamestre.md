# Teorema mestre
Ferramenta para analisar complexidade de algoritmos recursivos, com certo formato específico.

T(n) = aT($\frac{n}{b}$) + O($n^d$)

Sendo:
 - `a` representa o número de subproblemas gerados na divisão(filhos).
 - `b` indica o fator de redução do problema(por quanto o tamanho do problema é dividido).
 - $n^d$  é o custo da combinação das soluções dos subproblemas(o termo não-recursivo).
  
O método mestre divide a análise em três casos, comparando o crescimento da parte recursiva T(n) com o custo da parte não-recursiva O($n^d$):
   
  1. Caso 1: Se a > $b^d$, a parte recursiva dormina, e T(n) = O($n^{\log_b a}$).
  2. Caso 2: Se a = $b^d$, ambos os termos têm a mesma ordem de crescimento, e T(n) = O($n^d\log_2 n$). Obs: em alguns sites, o n está elevado a log a na base b, resultado da igualdade.
  3. Caso 3: Se a < $b^d$, a parte não-recursiva domina, e T(n) = O($n^d$).

