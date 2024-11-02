#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct quantidades_ {
    int contadorTrocas;
    int contadorComparacoes;
}QUANTIDADES;

void merge(int *vet, int l, int meio, int r, QUANTIDADES *contador);
void mergesort(int *vet, int l, int r, QUANTIDADES *contador);

int main(){
    int n, *vet = NULL;
    QUANTIDADES contador;
    contador.contadorComparacoes = contador.contadorTrocas = 0;

    scanf("%d", &n);

    vet = (int *) malloc(sizeof(int)*n);
    if(vet == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    clock_t start, end;
    double cpu_time_ms;

    start = clock();

    mergesort(vet, 0, n-1, &contador);

    end = clock();
    
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    // Calcular o tempo de execução em milissegundos
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execução: %lf ms\n", cpu_time_ms);

    printf("\n Foram realizadas %d trocas e %d comparações.\n", 
                contador.contadorTrocas, contador.contadorComparacoes);

    free(vet);
    vet = NULL;

    return 0;
}

void mergesort(int *vet, int l, int r, QUANTIDADES *contador){
    if(l<r){
        int meio = (l+r)/2;

        mergesort(vet, l, meio, contador);
        mergesort(vet, meio+1, r, contador);

        merge(vet, l, meio, r, contador);

    }
}

void merge(int *vet, int l, int meio, int r, QUANTIDADES *contador){
    int tam1 = meio-l+1;
    int tam2 = r-meio;

    int *L = (int*) malloc(tam1*sizeof(int));
    int *R = (int*) malloc(tam2*sizeof(int));

    for(int i = 0; i < tam1; i++){
        L[i] = vet[i+l];
    }

    for(int i = 0; i < tam2; i++){
        R[i] = vet[i+meio+1];
    }

    int posL = 0, posR = 0, posVet = l;

    while(posL < tam1 && posR < tam2){
        (*contador).contadorComparacoes++;
        if(L[posL] <= R[posR]){
            vet[posVet] = L[posL];
            posL++;
        }
        else{
            vet[posVet] = R[posR];
            posR++;
            (*contador).contadorTrocas++;
        }
        posVet++;
    }

    while(posL < tam1){
        vet[posVet] = L[posL];
        posVet++;
        posL++;
    }
    while(posR < tam2){
        vet[posVet] = R[posR];
        posVet++;
        posR++;
    }

    free(L);
    free(R);
    L = NULL;
    R = NULL;

}
