# Quick-sort

Esse método de ordenação baseia-se no método de divisão e conquista, escolhendo um elemento como pivô e dividindo o vetor entre antes e depois do pivô, colocando o pivô na posição correta.

## Como o algoritmo funciona?

1. Escolher pivô.
2. Dividir o vetor em volta dele e garantir que elementos à esquerda sempre serão menores que os elementos à direita. A esquerda e a direita não devem ser ordenados individualmente.
3. Chama-se recursivamente para as duas partições, esquerda e direita.
4. A recursão acaba quando há apenas um elemento.

### Escolha do pivô:
A solução ideal é escolher o meio do vetor, pois assim se encontra uma média de tempo.

## Algoritmo de partição:

A complexidade das partições costuma ser O(n).

### 1. Naive partition:
Cria-se uma cópia do vetor. Primeiro coloca-se todos os menores elementos e depois todos os maiores. Depois copia-se o vetor temporário para o vetor original. Esse método requer espaço extra de n.

### 2. Lomuto partition:
O algoritmo mais simples. Escolhe-se o pivô, normalmente o maior, e percorre-se o vetor, colocando os menores no início.  
Exemplo:

| Vetor | Instante (j) | Operação | i (-1) |
|-------|--------------|----------|--------|
| 10 80 30 90 40 50 70 | 0 | Trocou 10 por 10 | 0 |
| 10 80 30 90 40 50 70 | 1 | 80 é maior | 0 |
| 10 30 80 90 40 50 70 | 2 | Trocou 80 por 30 | 1 |
| 10 30 80 90 40 50 70 | 3 | 90 é maior | 1 |
| 10 30 40 90 80 50 70 | 4 | Troca 40 por 80 | 2 |
| 10 30 40 50 80 90 70 | 5 | Troca 50 por 90 | 3 |

Coloca-se o 70 no meio, `swap(&arr[i + 1], &arr[high])`:

10 30 40 50 70 80 90

Retorna-se a posição do 70 = i+1, divide-se em duas metades, menor que i+1 e maior que i+1.

### 3. Hoare’s Partition:
Jeito mais rápido. Percorre-se o vetor pela esquerda e direita, até achar um elemento à esquerda maior que o pivô e um à direita menor que o pivô, trocando suas posições.

| Vetor                | Descrição                     |
|----------------------|-------------------------------|
| 10 80 30 70 40 50 90 | Pivô seria o 70               |
| 10 50 30 70 40 80 90 | Primeira troca: 50 e 80       |
| 10 50 30 40 70 80 90 | Última troca: 40 e 70         |

## Complexidade:

### Melhor caso:
Ocorre quando o pivô escolhido é um elemento com valor médio no vetor, dividindo-o em duas metades. O(n log n).

**Por quê?**  
T(n) = 2T(n/2) + O(n). Cada nível terá custo de O(n) e a árvore terá log n na base 2 níveis.

### Pior caso:
Ocorre quando o valor escolhido é o menor ou o maior do vetor, não conseguindo dividir o vetor em duas metades. Assim:  
T(n) = T(n-1) + O(n). Dessa forma, serão n níveis com custo n. Logo, O(n²).

