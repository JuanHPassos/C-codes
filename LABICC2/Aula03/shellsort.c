#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct jogo{
    char *nome;
    int rank;
}jogador;

jogador *preencher_jogadores(int n);
int maior(jogador a, jogador b);
void shellsort(jogador *selecao, int n);

int main(){
    int n;
    jogador *selecao;

    scanf("%d", &n);

    selecao = preencher_jogadores(n);

    
     // Marca o início do tempo
    clock_t start = clock();

    shellsort(selecao, n);

    // Marca o fim do tempo
    clock_t end = clock();

    // Calcula e imprime o tempo de execução em milissegundos
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %f ms\n", time_spent);

    for(int i = 0; i < n; i++){
        printf("%s %d\n", selecao[i].nome, selecao[i].rank);
    }

    for(int i = 0; i < n; i++){
        free(selecao[i].nome);
        selecao[i].nome = NULL;
    }
    free(selecao); selecao = NULL;

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

int maior(jogador a, jogador b){
    if((a.rank > b.rank) || (a.rank == b.rank && strcmp(a.nome, b.nome) < 0)){
        return 1;
    }
    return 0;
}

void shellsort(jogador *selecao, int n){
    //Dividir o vetor em janelas.
    for(int janela = n/2; janela > 0; janela /= 2){
        //Formar grupos de i até i+janela, sempre 2 a 2. 
        for(int i = janela; i < n ; i++){
            //Variavel para realizar o swap caso necessario.
            jogador troca = selecao[i];
            //Index da posição final do jogador[i] apos a troca.
            int j;
            //Troca elementos 2 a 2, até estar ordenado.
            for(j = i; j >= janela && maior(troca, selecao[j-janela]); j -= janela){
                selecao[j] = selecao[j - janela];
            }
            //Caso j tenha sido alterado, houve trocas. Sendo selecao[j] nova posicao do jogador troca.
            selecao[j] = troca;
            
        }
    }
}

