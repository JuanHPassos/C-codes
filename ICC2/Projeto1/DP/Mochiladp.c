#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **alocar_matriz(int linha, int coluna);
int max(int a, int b);
int knapsack(int n, int mochila,int *valor,int *espaco);

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

    int resposta = knapsack(n, mochila, valor, espaco);

    // Marca o fim do tempo
    clock_t end = clock();
    
    printf("%d\n", resposta);

    // Calcula e imprime o tempo de execução em milissegundos
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %f ms\n", time_spent);

    
    free(valor); valor = NULL;
    free(espaco); valor = NULL;

    return 0;
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int **alocar_matriz(int linha, int coluna){
    int **matriz;
    
    //Ajustando o valor para incluir a posição n.
    linha++; coluna++;

    matriz = (int **) malloc(linha * sizeof(int*));

    matriz[0] = (int*)malloc(linha * coluna * sizeof(int));

    for(int i = 1; i < linha; i++){
        matriz[i] = matriz[0] + coluna * i;
    }

    for(int i = 0; i<linha; i++){
        for(int j = 0; j<coluna; j++){
            matriz[i][j] = 0;
        }
    }

    return matriz;
}


int knapsack(int n, int mochila,int *valor,int *espaco){
    int **dp = alocar_matriz(n, mochila);
    
    // Percorrer todos os itens.
    for(int i = 1; i <= n; i++){
        // Verificar as melhores soluções com capacidade j para o item i.
        for(int j = 0; j <= mochila; j++){
            int peso = espaco[i-1]; //Item começa do 1 e o vetor do zero.
            if(peso <= j){
                // Se couber na mochila, a melhor escolha é o maximo entre a melhor escolha do item anterior com essa capacidade ou o valor do item atual mais a melhor escolha no item anterior com essa capacidade menos o peso desse item.
                dp[i][j] = max(
                    dp[i-1][j],
                    valor[i-1] + dp[i-1][j - peso]
                );
            }
            else{
                //Se nao couber, nao se pega o item.
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int resposta = dp[n][mochila];
    
    //Evitar ponteiros selvagens(boa pratica).
    for(int i = 1; i <= n; i++){
        dp[i] = NULL;
    }

    //Desalocação de memoria.
    free(dp[0]); dp[0] = NULL;
    free(dp); dp = NULL;

    return resposta;
}
