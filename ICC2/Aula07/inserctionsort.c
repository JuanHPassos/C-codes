/*Inserction sort consiste em ordenar o vetor do inicio para o fim,
garantindo que sempre antes do elemento que sera inserido ja esta em ordem, 
sendo necessario apenas achar a posicao em que o elemento pertence na sequencia. 
Possui complexidade O(n^2) no pior dos casos, que ocorre quando o vetor esta ordenado de forma contrario ao que se busca.
O melhor dos casos ocorre quando o vetor ja vem ordenado, passando por ele apenas uma vez.*/

#include<stdio.h>
#include<stdlib.h>

// Modularização.
void inserctionsort(int *vet, int n);

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    inserctionsort(vet, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;

}

void inserctionsort(int *vet, int n){
    // Ordenar todos os numeros na janela.
    for(int i = 1; i < n; i++){
        // Valor a ser inserido no subvetor ordenado.
        int insercao = vet[i];
        int j = i-1; // Ultimo elemento do subvetor ordenado.
        // Procurar posicao, utilizando swap entre os numeros.
        while(j >= 0 && vet[j] > insercao){
            vet[j+1] = vet[j];
            j = j - 1;
        }
        // Posicao que foi aberta para insercao.
        vet[j+1] = insercao;
    }
}
