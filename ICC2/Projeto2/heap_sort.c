/*
Heap sort é uma técnica de ordenação baseada em comparação baseada na Estrutura de Dados de Heap Binário. Pode ser visto como uma otimização sobre o tipo de seleção, onde primeiro encontramos o elemento max (ou min) e o trocamos pelo último (ou primeiro). Repetimos o mesmo processo para os elementos restantes. No Heap Sort, usamos o Heap binário para que possamos encontrar e mover rapidamente o elemento max (In O(Log n) em vez de O(n)) e, portanto, atingir a complexidade de tempo O(n Log n).

Heap maxima deve ter uma ordem especifica:
16 14 10 9 3 8 7 2 4 1

Arvore maxima:(A minima colocaria os menores em cima)

                16
            14      10
         8     7  9    3
       2  4  1    

Nessa implementação trabalha-se com vetor:
Da forma, filhos do nó k:
filho esquerdo = 2k + 1
filho da direita = 2k + 2

pai do nó = (k-1)/2

Folhas de n/2 em diante

Raiz sempre estara na posição zero
Contruir heap maximo, trocando a raiz - maior elemento - da ultima posicao, diminuindo o tamanho da heap.
Rearranjar o heap maximo, se necessario
Repetir processor n-1 vezes

Dado o vetor = {4, 10, 3, 5, 1}
                4
            10      3
        5       1

Agora, arruma-se o vetor para representar uma arvore maxima
vetor = {10, 5, 3, 4, 1} 
Agora elimina-se o a raiz, jogando para o final do vetor(swap(v[0], v[n-1]))
vetor = {1, 5, 3, 4} (10)
            1
        5       3
    4

heap maxima = {5, 4, 3, 1}
vetor = {1, 3, 4} (5)(10)
            1
        4       3

heap maxima = {4, 1, 3}
vetor = {3, 1} (4)(5)(10)
        3
    1
heap maxima = {3, 1}
vetor = {1} (3)(4)(5)(10)
        1
heap maxima = {1}
vetor (1)(3)(4)(5)(10)
*/


#include<stdio.h>
#include<stdlib.h>

// Modularização.
void swap(int *i, int *j);
void rearranjar_heap(int *vet, int i, int tam_heap);
void heapsort(int *vet, int n);

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    heapsort(vet, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    free(vet);
    vet = NULL; // Evita ponteiro selvagem.

    return 0;
}


void swap(int *i, int *j){
    int aux = *i;
    *i = *j;
    *j = aux; 
}

void rearranjar_heap(int *vet, int i, int tam_heap){
    int esq, dir, maior;

    esq = 2*i + 1;
    dir = 2*i + 2;
    maior = i;

    if(esq < tam_heap && vet[esq] > vet[maior])
        maior = esq;
    
    if(dir < tam_heap && vet[dir] > vet[maior])
        maior = dir;

    if(maior != i){
        
        swap(&vet[maior], &vet[i]);

        rearranjar_heap(vet, maior, tam_heap);

    }
}

void heapsort(int *vet, int n){
    int i;
    // Começa em (n/2) - 1, pois a partir disso, são representadas as folhas das arvore binaria.
    for(i = (n / 2) - 1; i >= 0; i--){
        rearranjar_heap(vet, i, n);
    }

    
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {

        swap(&vet[0], &vet[i]);

        rearranjar_heap(vet, 0, i);
    }
}
