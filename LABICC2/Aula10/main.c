#include "hash.h"

#include<stdio.h>
#include<stdlib.h>

// Modularização.
int achar_sequencia(hash_t *hash, int chave);

int main(void){
    int tamanho;

    scanf("%d", &tamanho);

    int *vetor = (int*) malloc(tamanho*sizeof(int));
    hash_t *hashmap = hash_criar(tamanho);

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
        hash_inserir(hashmap, vetor[i]);
    } 

    int maior_seq = 0;

    for(int i = 0; i < tamanho; i++){
        // Guarde possivel maior sequencial.
        int aux = achar_sequencia(hashmap, vetor[i]);
        if(maior_seq < aux){
            maior_seq = aux;
        }
    }

    printf("%d", maior_seq);

    // Desalocação de memória.
    // hash_apagar(&hashmap);
    free(vetor);
    vetor = NULL;

    return 0;
}

int achar_sequencia(hash_t *hash, int chave){
    // Verificar se é o primeiro da sequencia.
    if(hash_busca(hash, chave-1))
        return -1; // Elemento neutro.
    else{
        int seq = 0; // Guarda tamanho sequencia.
        do{
            chave++; // Checar se existe sucessor.
            seq++; // Aumenta 1 elemento na sequencia.
        }while(hash_busca(hash, chave));
        return seq;
    }
}