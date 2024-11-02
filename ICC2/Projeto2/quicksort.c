#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Modularização
int particao(int *vet, int l, int r, int *contadorTrocas);
void quicksort(int *vet,int l,int r, int *contadorTrocas);
int mediana(int a, int b, int c);

int main(){
    int n, *vet = NULL;
    scanf("%d", &n);

    vet = (int *) malloc(sizeof(int)*n);
    if(vet == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    clock_t start, end;
    double cpu_time_ms;

    start = clock();

    int contadorTrocas = 0;
    quicksort(vet, 0, n-1, &contadorTrocas);

    end = clock();

    for(int i = 0; i<n; i++){
        printf("%d ", vet[i]);
    }

    // Calcular o tempo de execução em milissegundos
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execução: %lf ms\n", cpu_time_ms);

    printf("\n Foram realizadas %d trocas.\n", contadorTrocas);

    free(vet);
    vet = NULL;

    return 0;
}

// Particao hoares
int particao(int *vet, int l, int r, int *contadorTrocas){
    // int pivo = mediana(vet[l], vet[(l+r)/2], vet[r]);
    int pivo = vet[r];
    while(l < r){
        // Busca primeiro elemento a esquerda maior ou igual a pivo.
        while(vet[l] < pivo) l++;
        // Busca primeiro elemento a direita menor ou igual a pivo.
        while(vet[r] > pivo) r--;
       
       if(l >= r) return r;
        // Se l e r ainda não se cruzaram, trocamos os elementos.
        // Troca os elementos encontrados.
       int temp = vet[r];
       vet[r] = vet[l];
       vet[l] = temp;
       (*contadorTrocas)++; // Incrementa o contador de trocas
    }
    // Retorna a posicao correta do pivo.
    return r; 

}

void quicksort(int *vet,int l,int r, int *contadorTrocas){

    if(l < r){
        // Busca achar a posicao correta do pivo, retorna sua posicao.
        int pivo = particao(vet, l, r, contadorTrocas);
        // Quebra o vetor em dois.
        quicksort(vet, l, pivo - 1, contadorTrocas);
        quicksort(vet, pivo + 1, r, contadorTrocas);

    }
}
// Encontra o pivo.
int mediana(int a, int b, int c) {
    if ((a > b) == (a < c)) {
        return a;
    } else if ((b > a) == (b < c)) {
        return b;
    } else {
        return c;
    }
}
