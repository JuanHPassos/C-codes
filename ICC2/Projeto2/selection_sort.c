/*Selection sort consiste em formar um vetor ordenado da esquerda para a direita de maneira estável. O algoritmo consiste em achar o menor valor do vetor nao ordenado, que começa sendo o vetor inteiro e vai diminuindo conforme for inserindo os menores valores.
Exemplo:
7 6 9 3 5 7 5 1 - t = 0
1 6 9 3 5 7 5 7 - t = 1
1 3 9 6 5 7 5 7 - t = 2
1 3 5 6 9 7 5 7 - t = 3
1 3 5 5 9 7 6 7 - t = 4
1 3 5 5 6 7 9 7 - t = 5
1 3 5 5 6 7 9 7 - t = 6
1 3 5 5 6 7 7 9 - t = 7
1 3 5 5 6 7 7 9 - t = 8
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Modularização.
int selectionsort(int *vet, int n);

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    clock_t start, end;
    double cpu_time_ms;

    start = clock();

    int trocas = selectionsort(vet, n);

    end = clock();
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    
    // Calcular o tempo de execução em milissegundos
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execução: %lf ms\n", cpu_time_ms);

    printf("\n Foram realizadas %d trocas.\n", trocas);

    free(vet);
    vet = NULL; // Boa prática.

    return 0;
}

int selectionsort(int *vet, int n){
    int trocas = 0; // Guarda quantidade de trocas.
    for(int i = 0; i < n-1; i++){
        int menor = i; // Inicio do vetor nao ordenado.
        for(int j = i+1; j < n; j++){
            if(vet[j] < vet[menor]){
                menor = j; // Salva onde esta o menor valor.
            }
        }
        // Coloca o menor para o fim do vetor ordenado.
        if(menor != i) {
            int aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
            trocas++;
        }
    }
}
