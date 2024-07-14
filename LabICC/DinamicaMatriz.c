/*Implemente um programa em C que recebe um inteiro N que representa a quantidade de elementos
de uma matriz, voce devera alocar uma matriz dinamicamente para receber esses n elementos, e
desenvolver funcoes para preenche-la, e depois printa-la na tela. NAO ESQUECA DE LIBERAR
MEMORIA.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void imprimi(int **p, int r);
void entrada(int **p, int r);
/*Funcao para preencher a matriz - entrada*/
void entrada(int **p, int r){
    for(int i = 0; i<r; i++)
        for(int j = 0; j<r; j++)
            scanf("%d", &p[i][j]);
            
}
/*Funcao para imprimir a matriz - imprimi*/
void imprimi(int **p, int r){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<r; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n, r;//n = quantidade elementos da matriz, r = dimensao da matriz.
    int **p;
    scanf("%d", &n);
    r = (int)sqrt(n);
    //Alocacao dinamica da matriz.
    p = (int **) malloc(r*sizeof(int*));
    for(int i = 0; i<r; i++){
        p[i] = (int*) malloc(r*sizeof(int));
    }
    //Preenchimento da matriz.
    entrada(p, r);
    //Impressao da matriz.
    imprimi(p, r);
    //Liberacao de memoria.
    for(int i = 0; i<r; i++){
        free(p[i]);
    }
    free(p);
    p = NULL;
    return 0;
}

