#include<stdio.h>
#include<stdlib.h>

// Modularização
int particao(int *vet, int l, int r);
void quicksort(int *vet,int l,int r);
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

    quicksort(vet, 0, n-1);

    for(int i = 0; i<n; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
    vet = NULL;

    return 0;
}

// Particao hoares
int particao(int *vet, int l, int r){
    int pivo = mediana(vet[l], vet[(l+r)/2], vet[r]);

    while(l < r){
        // Busca primeiro elemento a esquerda maior ou igual a pivo.
        while(vet[l] < pivo) l++;
        // Busca primeiro elemento a direita menor ou igual a pivo.
        while(vet[r] > pivo) r--;
        // Troca os elementos encontrados.
        int temp = vet[r];
        vet[r] = vet[l];
        vet[l] = temp;
        // Se eles se encontrarem, o objetivo foi cumprido.
        if(l >= r) return r;


    }
    // Retorna a posicao correta do pivo.
    return l; 

}

void quicksort(int *vet,int l,int r){

    if(l < r){
        // Busca achar a posicao correta do pivo, retorna sua posicao.
        int pivo = particao(vet, l, r);
        // Quebra o vetor em dois.
        quicksort(vet, l, pivo);
        quicksort(vet, pivo+1, r);

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
