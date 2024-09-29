#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct prato_{
    int prioridade;
    int tempo;
    char *prato;
}PRATO;

PRATO *leitura_dados(int tam);
void bubbleSort(PRATO *vet, int n);
bool compara_pratos(PRATO prato1, PRATO prato2);
void desalocacao_memoria(PRATO **vet, int tam);

int main(){
    int quant_pratos;
    PRATO *pratos;
    // Quantidade de pratos;
    scanf("%d", &quant_pratos);

    pratos = leitura_dados(quant_pratos);

    bubbleSort(pratos, quant_pratos);

    for(int i = quant_pratos - 1; i >= 0; i--){
        printf("%s\n", pratos[i].prato);
    }

    desalocacao_memoria(&pratos, quant_pratos);

    return(0);
}

// Funcao que le os dados e aloca espaço necessario, sem desperdicio de memoria.
PRATO *leitura_dados(int tam){
    PRATO *pratos = (PRATO*) malloc(tam*sizeof(PRATO));
    if(pratos == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i = 0; i < tam; i++){
        int prioridade, tempo;
        char leitura[51], *prato;

        scanf("%d %d %s", &prioridade, &tempo, leitura);

        pratos[i].prioridade = prioridade;
        pratos[i].tempo = tempo;
        // Guarda-se exatamente o espaço necessário para guardar nome.
        prato = (char*) malloc((strlen(leitura) + 1)*sizeof(char));
        strcpy(prato, leitura);
        pratos[i].prato = prato;
    }

    return pratos;
}

// Função que analisa se o prato1 tem menos prioridade que o prato2.
bool compara_pratos(PRATO prato1, PRATO prato2){
    if(prato1.prioridade == prato2.prioridade)
        if(prato1.tempo > prato2.tempo) return true;
        else return false;

    else if(prato1.prioridade > prato2.prioridade) return false;
    else return true; // Prato 1 possui menos prioridade que o prato 2.
}

// Função de ordenação (implementada de forma descrescente para struct PRATO).
void bubbleSort(PRATO *vet, int n){
    // Busca reproduzir o processo de eliminar o maior n-1 vezes.
    for(int i = 0; i < n-1; i++){
        int ord = 1;
        // Pega o maior elemento e joga para o final.
        for(int j = 0; j < n-i-1; j++){
            
            if(compara_pratos(vet[j], vet[j+1])){
                PRATO troca; // Variavel auxiliar para ordenar os pratos.
                troca = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = troca;
                ord = 0;
            }
        
        }
        // Verifica se o vetor ja esta ordenado
        if(ord) break; 
    }
}

// Libera memoria armazenada, tanto do campo prato da struct, quanto do vetor do tipo PRATO.
void desalocacao_memoria(PRATO **vet, int tam){
    if(*vet == NULL) return;
    for(int i = 0; i < tam; i++){
        free((*vet)[i].prato);
        (*vet)[i].prato = NULL; // Boa prática
    }
    free(*vet); 
    *vet = NULL;

    return;
}

/*
Caso teste:
4
7 30 fish-and-chips
1984 1 poitin
1 20 bubble-and-squeak
42 60 steak-and-ale-pie
 */
