/*
Método da bolha:
Ideia, percorrer o vetor, comparando elementos com seu sucessor e ir trocando as posições, a cada ciclo, o maior elemento vai para o final, porem como são n elementos, no pior dos casos, o vetor será percorrido n vezes. O for interno, ira fazer as comparações e os swaps.

Complexidade: n^2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bubbleSort(int *vet, int n);

int main(void){
    int n, *vet;

    scanf("%d", &n);

    vet = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    clock_t start, end;
    double cpu_time_ms;

    start = clock();
    
    // Números de trocas
    int trocas = bubbleSort(vet, n);

    end = clock();
    
    for(int i = 0; i < n; i++){
        printf("%d", vet[i]);
    }

    
    // Calcular o tempo de execução em milissegundos
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execução: %lf ms\n", cpu_time_ms);

    printf("\n Foram realizadas %d trocas.\n", trocas);



    free(vet);
    vet = NULL; // Boa prática.

    return 0;
}
// Retorna o numero de trocas
int bubbleSort(int *vet, int n){
    int trocas = 0;
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
                trocas++;
                ord = 0;
            }
        
        }
        // Verifica se o vetor ja esta ordenado
        if(ord) break; 
    }
    return trocas;
}
