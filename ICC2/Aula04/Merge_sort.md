## Algoritmo Merge Sort

O algoritmo **Merge Sort** consiste no método de divisão e conquista para ordenar o vetor.

1. **Dividir**: O vetor é dividido em duas partes até não ser mais possível (tamanho 1).
2. Cada sub-vetor é ordenado individualmente usando o algoritmo Merge Sort.
3. **Merge**: Os vetores são juntados em ordem; tal processo ocorre até se obter o vetor original.

### Pseudo-código:

#### Função Dividir
Dado um vetor, deve-se dividir ele até os elementos serem unitários. Sendo "d" a direita do vetor, "e" a esquerda, e "m" o meio, a divisão ocorre até que **e == d**. Após isso, retorna-se dos unitários juntando os vetores separados (nova função = **juntar/conquistar**).

#### Função Conquistar
Recebe-se um array com **e**, **d**, e **m** desse vetor. Dois vetores temporários são utilizados para representar a divisão do vetor passado no parâmetro. Em seguida, o vetor original é preenchido até o tamanho de um dos vetores auxiliares ser alcançado, dando preferência aos menores valores dentre os auxiliares. Por fim, o vetor original é completado com o que sobrou dos vetores.

### Código:

```c
// Programa em C para Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Junta-se dois subarrays do vetor (arr).
// O primeiro sub_vetor é o arr[l..m]
// O segundo sub_vetor é o arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Vetores temporários para auxiliar.
    int E[n1], D[n2];

    // Copia os dados do vetor para E[] e D[]
    for (i = 0; i < n1; i++)
        E[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        D[j] = arr[m + 1 + j];

    // Junta os vetores temporários no vetor arr.
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            arr[k] = E[i];
            i++;
        } else {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    // Copia o resto dos elementos de E[], se existirem.
    while (i < n1) {
        arr[k] = E[i];
        i++;
        k++;
    }

    // Copia o resto dos elementos de D[], se existirem.
    while (j < n2) {
        arr[k] = D[j];
        j++;
        k++;
    }
}

// E é para indexar a esquerda do vetor (início)
// D é para indexar a direita do vetor (fim)
// Ordenação do subvetor de arr (Divisão)
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Divisão da primeira e segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Ordenação das mesmas
        merge(arr, l, m, r);
    }
}
```
