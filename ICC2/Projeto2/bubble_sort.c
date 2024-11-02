/*
Método da bolha:
Ideia, percorrer o vetor, comparando elementos com seu sucessor e ir trocando as posições, a cada ciclo, o maior elemento vai para o final, porem como são n elementos, no pior dos casos, o vetor será percorrido n vezes. O for interno, ira fazer as comparações e os swaps.

Complexidade: n^2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct quantidades_{
    int contadorTrocas;
    int contadorComparacoes;
}QUANTIDADES;


void bubbleSort(int *vet, int n, QUANTIDADES *quantidades);

int main(void){
    int n;

    scanf("%d", &n);

    int *vet = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    clock_t start, end;
    double cpu_time_ms;

    start = clock();
    
    // Calcular quantidade de trocas e comparacoes.
    QUANTIDADES quantidades;
    quantidades.contadorComparacoes = 0;
    quantidades.contadorTrocas = 0;

    // Números de trocas
    bubbleSort(vet, n, &quantidades);

    end = clock();
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    
    // Calcular o tempo de execução em milissegundos
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execucao: %lf ms\n", cpu_time_ms);

    printf("Foram realizadas: %d comparacoes e %d trocas.\n", 
           quantidades.contadorComparacoes, quantidades.contadorTrocas);

    free(vet);
    vet = NULL; // Boa prática.

    return 0;
}

// Retorna o numero de trocas
void bubbleSort(int *vet, int n, QUANTIDADES *quantidades){
    // Busca reproduzir o processo de eliminar o maior n-1 vezes.
    for(int i = 0; i < n-1; i++){
        int ord = 1;
        // Pega o maior elemento e joga para o final.
        for(int j = 0; j < n-i-1; j++){
            (quantidades->contadorComparacoes)++;
            if(vet[j] > vet[j+1]){
                // Swap de duas variaveis
                vet[j] = vet[j] + vet[j+1];
                vet[j+1] = vet[j] - vet[j+1];
                vet[j] = vet[j] - vet[j+1];
                quantidades->contadorTrocas++;
                ord = 0;
            }
        
        }
        // Verifica se o vetor ja esta ordenado
        if(ord) break; 
    }
    return;
}
