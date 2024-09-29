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
int particao(PRATO *vet, int l, int r);
void quicksort(PRATO *vet,int l,int r);
PRATO find_pivo(PRATO *vet, int l, int r);

int main(){
    int quant_pratos;
    PRATO *pratos;
    // Quantidade de pratos;
    scanf("%d", &quant_pratos);

    pratos = leitura_dados(quant_pratos);

    quicksort(pratos, 0, quant_pratos-1);

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

// Conquista
int particao(PRATO *vet, int l, int r){
    PRATO pivo = vet[(l+r)/2];
    // PRATO pivo = find_pivo(vet, l, r); // Implemetação achando mediana.

    while(l < r){
        // Busca primeiro elemento a esquerda menos prioritario ou igual ao pivo.
        while(menos_prioritario(pivo, vet[l])) l++;
        // Busca primeiro elemento a direita mais prioritario ou igual ao pivo.
        while(menos_prioritario(vet[r], pivo)) r--;
        // Troca os elementos encontrados.
        PRATO temp = vet[r];
        vet[r] = vet[l];
        vet[l] = temp;

        if(l >= r) return r;
    }
    return r;
}

// Divisão
void quicksort(PRATO *vet,int l,int r){

    if(l < r){
        // Busca achar a posicao correta do pivo, retorna sua posicao.
        int pivo = particao(vet, l, r);
        // Quebra o vetor em dois.
        quicksort(vet, l, pivo);
        quicksort(vet, pivo+1, r);

    }
}
/*
// Mediana
PRATO find_pivo(PRATO *vet, int l, int r){
    PRATO pivo[3]; // 3 candidatos a pivo, escolhe-se o meio deles.
    pivo[0] = vet[l];
    pivo[1] = vet[(l+r)/2];
    pivo[2] = vet[r];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2-i; j++){
            if(menos_prioritario(vet[j], vet[j+1])){
                    PRATO troca; // Variavel auxiliar para ordenar os pratos.
                    troca = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = troca;
            }
        }
    }

    return pivo[1];
}
*/