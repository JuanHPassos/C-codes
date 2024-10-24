/*
Método da bolha:
Ideia, percorrer o vetor, comparando elementos com seu sucessor e ir trocando as posições, a cada ciclo, o maior elemento vai para o final, porem como são n elementos, no pior dos casos, o vetor será percorrido n vezes. O for interno, ira fazer as comparações e os swaps.

Complexidade: n^2.
*/
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *vet, int n);

int main(void){
    int n, *vet;

    scanf("%d", &n);

    vet = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    bubbleSort(vet, n);
    
    for(int i = 0; i < n; i++){
        printf("%d", vet[i]);
    }

    free(vet);
    vet = NULL; // Boa prática.

    return 0;
}

void bubbleSort(int *vet, int n){
    // Busca reproduzir o processo de eliminar o maior n-1 vezes.
    for(int i = 0; i < n-1; i++){
        int ord = 1;
        // Pega o maior elemento e joga para o final.
        for(int j = 0; j < n-i-1; j++){
            
            if(vet[j] > vet[j+1]){
                // Swap de duas variaveis
                vet[j] = vet[j] + vet[j+1];
                vet[j+1] = vet[j] - vet[j+1];
                vet[j] = vet[j] - vet[j+1];
                ord = 0;
            }
        
        }
        // Verifica se o vetor ja esta ordenado
        if(ord) break; 
    }
}
