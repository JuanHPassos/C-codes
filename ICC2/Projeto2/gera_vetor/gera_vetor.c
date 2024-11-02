#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gera_vetor.h"


int *cria_vetor (int n) {
    int *newVet = (int*)malloc(sizeof(int)*n);
    if (newVet == NULL){
        printf("Erro de alocação");
        exit(1);
    }
    return newVet;
}

void preenche_vetor (int v[], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        v[i] = rand()%100;
    }
}

void preenche_vetor_ordenado (int v[], int n) {
    srand(time(0));
    
    v[0] = rand()%100;
    for (int i = 1; i < n; i++) {
        v[i] = v[i-1] + rand()%100;
    }
}

void preenche_vetor_ordenando_inverso (int v[], int n) {
    srand(time(0));

    v[n-1] = rand()%100;
    for (int i = n-2; i >= 0; i--) {
        v[i] = v[i+1] + rand()%100;
    }
}

void imprime_vetor (int v[], int n) {
    for (int i = 0; i < n; i++) {
        if(i == 0) {
            printf("%d", v[i]);
        } else {
            printf(", %d", v[i]);
        }
        
    }
    printf("\n");
}

void apaga_vetor (int **v) {
    if (*v != NULL) {
        free(*v);
    }
}


