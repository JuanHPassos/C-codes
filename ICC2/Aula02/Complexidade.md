# Algoritmo

Conjunto de instruções que devem ser seguidas para solucionar um determinado problema.

## Exemplo

**Fibonacci recursivo vs iterativo:** Apesar da versão recursiva estar correta, ela não termina para valores de n grandes, então o algoritmo correto seria a versão iterativa.

## Recursos de um algoritmo

É importante determinar os recursos necessários para sua execução:

- **Tempo**
- **Memória**

Obs: É preferível priorizar o tempo, haja vista que um tempo de processamento de 1 ano é inviável.

### Fatores que determinam a relação entre tempo e memória:

1. **Características da máquina:**
   - Quantidade de memória.
2. **Linguagem de programação:**
   - Compilada vs interpretada
   - Alto vs baixo nível
3. **Implementação**
4. **Quantidade de dados processados**

Logo, começou-se a procurar formas de analisar algoritmos sem hardware, linguagem de programação e habilidade do programador. Assim, pode-se estimar a eficiência de um algoritmo em função do tamanho do problema. Em geral, assume-se que "n" é o tamanho do problema, ou número de elementos que serão processados.

## Exemplos de Algoritmos

Por exemplo, dada a soma e produto de duas matrizes NxN:

**Soma:**
```plaintext
para i = 1, ..., n faça
    para j = 1, ..., n faça
        c[i][j] = a[i][j] + b[i][j]
```
**Multiplicativo:**
```plaintext
para i = 1, ..., n faça
    para j = 1, ..., n faça
        c[i][j] = 0
        para k = 1, ..., n faça
            c[i][j] = c[i][j] + a[i][k] * b[k][j]
```
Logo, o número total de passos corresponde ao número total de operações. Dessa forma, a complexidade do algoritmo de soma de duas matrizes quadradas é **n²** e o do produto das mesmas tem complexidade **n³**.

**Melhor algoritmo** requer menos operações sobre a entrada, pois é o mais rápido (Eficiente).

Deve-se preocupar com a eficiência de algoritmos quando o tamanho de **n** for grande. Ou seja, o que será analisado é o comportamento assintótico das funções, e não serão consideradas constantes aditivas ou multiplicativas na expressão matemática obtida.

Por exemplo, valores com complexidade **3n** serão aproximados para **n**. Além disso, como o interesse são de valores assintóticos, funções como **n²+n** serão reduzidas a **n²**. Assim como **6n³+4n-9** será transformado em **n³**.

## Definição

A eficiência assintótica de um algoritmo descreve a eficiência relativa dele quando **n** se torna grande. Compara-se dois algoritmos, determinando-se as taxas de crescimento entre ambos. O algoritmo com menor taxa de crescimento rodará mais rápido quando o tamanho do problema for grande.

As complexidades têm por objetivo avaliar a eficiência de tempo ou espaço. O termo complexidade será empregado para a complexidade de pior caso na maioria das vezes.

# Notações
- "Big oh", "oh", "na ordem de": Diz-se que f é O(h), escrevendo-se f = O(h), quando existir uma constante c > 0 e um valor inteiro n_inicial, tal que:

**n > n_inicial -> f(n) <= c*h(n)**

Ou seja, a função **h** atua como limitante superior para valores assintóticos da função **f**.

## Exemplos de notação O

- f = n² - 1 → f = O(n²).
- f = n² - 1 → f = O(n³).
- f = 403 → f = O(1).
- f = 5 + 2log(n) + 3log²(n) → f = O(log²(n)). (Limitante superior mais próxima)
- f = 5 + 2log(n) + 3log²(n) → f = O(n). (Também limitante superior, porém mais distante)
- f = 5 * 2^n + 5 * n¹⁰ → f = O(2^n).

## Manipulação de expressões com notação O

- O(g+h) = O(g) + O(h).
- O(k * g) = k * O(g) = O(g).

### Exemplo de manipulação:
```plaintext
f = 5 + 2log(n) + 3log²(n)
O(5 + 2log(n) + 3log²(n)) = O(5) + O(2log(n)) + O(3log²(n)) 
= 5*O(1) + 2*O(log(n)) + 3*O(log²(n)) = O(1) + O(log(n)) + O(log²(n))
= O(log²(n)), haja vista que essa função cresce mais rápido entre as 3, e portanto essa é a limitante superior. Observa-se que O(log²(n)) está contido em O(n), então "n", apesar de distante, também é uma limitante superior dessa expressão.
```
## Complexidade do Procedimento Recursivo

Número total de chamadas vezes a complexidade de execução de cada chamada isolada. Por exemplo, o fatorial tem complexidade **O(n)**, já para o problema da torre de Hanoi, a complexidade é **O(2^n)**, pois para a execução ocorrem duas chamadas.

## Notação Theta (θ)

A notação **θ** é utilizada para exprimir limites superiores justos. Diz-se que **f** é **θ(g)** quando **f = O(g)** e **g = O(f)**. Por exemplo, se **f = n² - 1**, **g = n²** e **h = n³**, então **f = O(g)**, **f = O(h)**, **g = O(f)**, mas **h** não é **O(f)**. Consequentemente, **f** é **θ(g)**, mas **f** não é **θ(h)**.

## Notação Ômega (Ω)

A notação **Ω** é útil para descrever limites inferiores assintóticos. **f = Ω(h)**, quando existir uma constante **c > 0** e um valor inteiro **n_inicial**, tal que:

```plaintext
n > n_inicial -> f(n) >= c*h(n).
```

Por exemplo, se **f = n² - 1**, então são válidas as igualdades **f = Ω(n²)**, **f = Ω(n)** e **f = Ω(1)**, mas não vale **f = Ω(n³)**.

## Algoritmos Ótimos

Seja **P** um problema no qual um limite inferior para **P** é uma função **l**, tal que a complexidade de pior caso que resolva **P** é **Ω(l)**. Ou seja, qualquer algoritmo que resolva **P** executa no mínimo **Ω(l)** passos. Logo, se existir um caso em que um algoritmo **A** tenha complexidade **O(l)**, então **A** é denominado algoritmo ótimo para **P**.

Logo, conclui-se que um **algoritmo ótimo** é aquele que apresenta a menor complexidade dentre todos os possíveis algoritmos para resolver o problema.

**Importante:** O limite superior garante que o tempo de execução não excederá uma certa função de **n**. (Tempo máximo - **Complexidade máxima**) O limite inferior garante que o tempo de execução não será menor que uma certa função de **n**. (Tempo mínimo - **Complexidade mínima**)
