#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct prato_{
    int prioridade;
    int tempo;
    char *prato;
}PRATO;

// Modularização
PRATO *leitura_dados(int tam);
bool menos_prioritario(PRATO prato1, PRATO prato2);
void desalocacao_memoria(PRATO **vet, int tam);
void mergesort(PRATO *vet, int l, int r);
void rearranjar_merge(PRATO *vet, int l, int meio, int r);

int main(){
    int quant_pratos;
    PRATO *pratos;
    // Quantidade de pratos;
    scanf("%d", &quant_pratos);

    pratos = leitura_dados(quant_pratos);

    mergesort(pratos, 0, quant_pratos-1);

    for(int i = 0; i < quant_pratos; i++){
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
        char leitura[52], *prato;

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
bool menos_prioritario(PRATO prato1, PRATO prato2){
    if(prato1.prioridade == prato2.prioridade)
        if(prato1.tempo > prato2.tempo) return true;
        else return false;

    else if(prato1.prioridade > prato2.prioridade) return false;
    else return true; // Prato 1 possui menos prioridade que o prato 2.
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

void mergesort(PRATO *vet, int l, int r){
    if(l<r){
        int meio = (l+r)/2;

        mergesort(vet, l, meio);
        mergesort(vet, meio+1, r);

        rearranjar_merge(vet, l, meio, r);

    }
}

void rearranjar_merge(PRATO *vet, int l, int meio, int r){
    int tam1 = meio-l+1;
    int tam2 = r-meio;

    PRATO L[tam1];
    PRATO R[tam2];

    for(int i = 0; i < tam1; i++){
        L[i] = vet[i+l];
    }

    for(int i = 0; i < tam2; i++){
        R[i] = vet[i+meio+1];
    }

    int posL = 0, posR = 0, posVet = l;

    while(posL < tam1 && posR < tam2){
        if(menos_prioritario(L[posL], R[posR])){
            vet[posVet] = L[posL];
            posL++;
        }
        else{
            vet[posVet] = R[posR];
            posR++;
        }
        posVet++;
    }

    while(posL < tam1){
        vet[posVet] = L[posL];
        posVet++;
        posL++;
    }
    while(posR < tam2){
        vet[posVet] = R[posR];
        posVet++;
        posR++;
    }
}

/*
4
7 30 fish-and-chips
1984 1 poitin
1 20 bubble-and-squeak
42 60 steak-and-ale-pie
*/
