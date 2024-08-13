/*Achar o maior número de um vetor de forma recursiva*/
#include<stdio.h>
#include<stdlib.h>//Para poder usar o exit(), malloc().
/*Função recursiva para achar o maior valor - maior*/
int maior(int v[], int n){
    //Se tiver tamanho 1, o maior valor e o elemento 0.
    if(n==1)
        return v[0];
    //Caso contrario
    else{
        //Busca-se o ultimo elemento do vetor
        int aux = maior(v, n-1);
        //E na volta das funções, é comparado os valores, e retorna-se o maior.
        if(aux > v[n-1])
            return aux;
        else
            return v[n-1];
    }
}
int main(){
    //Tamanho do vetor, vetor, resposta.
    int n, *v, resp;
    scanf("%d", &n);
    //Alocação dinamica do vetor de tamanho n.
    v = (int*) malloc(n*sizeof(int));
    if(v == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    //Leitura do vetor.
    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
    //Chama-se a função para encontrar o maior valor de maneira recursiva.
    resp = maior(v, n);
    printf("Maior: %d", resp);
    return 0;
}