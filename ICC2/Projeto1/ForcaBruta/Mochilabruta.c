#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a, int b);

int bruta(int n,int mochila,int *valor,int *espaco);

int main(){
    int n, mochila, *valor, *espaco;

    scanf("%d %d", &n, &mochila);
    
    valor = (int*) malloc(n * sizeof(int));
    espaco = (int*) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        espaco[i] = a;
    }

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        valor[i] = a;
    }

    // Marca o início do tempo
    clock_t start = clock();

    int resposta = bruta(n, mochila, valor, espaco);

    // Marca o fim do tempo
    clock_t end = clock();

    printf("%d\n", resposta);

    // Calcula e imprime o tempo de execução em milissegundos
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %f ms\n", time_spent);

    //Desalocação de memoria e boa pratica ao evitar ponteiros selvagens.
    free(valor); valor = NULL;
    free(espaco); espaco = NULL;

    return 0;
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int bruta(int n,int mochila,int *valor,int *espaco){
    if(n == 0 || mochila == 0) return 0;
    
    if(mochila < espaco[n-1]) return bruta(n-1, mochila, valor, espaco);
    
    else return max(
        bruta(n-1, mochila, valor, espaco),
        valor[n-1] + bruta(n-1, mochila - espaco[n-1], valor, espaco));
}