#include "Pilha.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct jogo{
    char *nome;
    int rank;
}jogador;

jogador *preencher_jogadores(int n);
int min(jogador a, jogador b);
PILHA *metodo(jogador *selecao, int n);

int main(){
    int n;
    jogador *selecao;
    PILHA *pilha;

    scanf("%d", &n);

    selecao = preencher_jogadores(n);

    //  // Marca o início do tempo
    // clock_t start = clock();

    pilha = metodo(selecao, n);

    // // Marca o fim do tempo
    // clock_t end = clock();

    for(int i = 0; i < n; i++){
        ITEM *jogador = pilha_desempilhar(pilha);
        
        char *nome = (char*) item_get_dados(jogador);
        int rank = item_get_chave(jogador);
        
        printf("%s %d\n", nome, rank);

        free(nome); nome = NULL;
        item_apagar(&jogador);
    }

    // // Calcula e imprime o tempo de execução em milissegundos
    // double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    // printf("Tempo de execução: %f ms\n", time_spent);

    free(selecao); selecao = NULL;
    pilha_apagar(&pilha); 
    
    return 0;
}


jogador *preencher_jogadores(int n){
    jogador *selecao;
    char nome[52];

    selecao = (jogador*) malloc(n * sizeof(jogador));

    for(int i = 0; i < n; i++){
        int rank;
        
        scanf("%s %d", nome, &rank);

        selecao[i].nome = (char*) malloc((strlen(nome)+1)*sizeof(char));

        strcpy(selecao[i].nome, nome);

        selecao[i].rank = rank;
    }

    return selecao;
}


int min(jogador a, jogador b){
    if((a.rank > b.rank) || (a.rank == b.rank && strcmp(a.nome, b.nome) < 0)){
        return 1;
    }
    return 0;
}

PILHA *metodo(jogador *selecao, int n){
    PILHA *pilha = pilha_criar();

    for(int i = 0; i < n; i++){
        jogador menor = selecao[n-1];            
        int index = n-1;
        for(int j = i; j < n; j++){
            if(min(menor, selecao[j])){
                menor = selecao[j];
                index = j;
            }
        }
        menor = selecao[i];
        selecao[i] = selecao[index];
        selecao[index] = menor;

        pilha_empilhar(pilha, item_criar(selecao[i].rank, selecao[i].nome));
    }

    return pilha;
}
