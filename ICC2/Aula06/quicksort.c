#include<stdio.h>
#include<stdlib.h>
// Particao hoares
int particao(int *vet, int l, int r){
    int pivo = vet[(l+r)/2];

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

    return 0;
}
