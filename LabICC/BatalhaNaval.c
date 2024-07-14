/*Escreva um programa em C, que leia um inteiro N , seguido de uma matriz N x N, que deve ser
interpretada como um tabuleiro de batalha naval, onde ”O” representa espacos vazios e ”N” navios.
Apos isso, o programa deve ler um inteiro I, seguido por I coordenadas,
cada coordenada e composta por um caractere que representa a linha e um inteiro que representa a coluna, caso haja um navio
na coordenada deve ser impresso ”acerto!” e o ”N” deve ser substituido por um ”X”, caso contrario
deve ser impresso ”erro!”. Por fim, o programa deve imprimir a matriz que representa o tabuleiro.*/

#include<stdio.h>
int main(){
    int n, c, y;//Tamanho da matriz, numero de tentativas e coordenada y.
    char x;//Coordenada x.
    scanf("%d", &n);
    char mat[n][n];
    //Preenchendo a matriz.
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf(" %c", &mat[i][j]);
    //Numero de tentativas.
    scanf(" %d", &c);
    for(int i = 0; i<c; i++){
        scanf(" %c %d", &x, &y);
        //Transformado a coordenada x(caractere) em inteiro que representa a linha.
        x = x -'A';
        //Se nessa posicao houver navio, realiza-se as especificacoes do problema.
        if(mat[x][y-1] == 'N'){
            //Nota-se que e y-1, pois a coordenada da matriz comeca no 0.
            printf("acerto!\n");
            mat[x][y-1] = 'X';}
        else
            printf("erro!\n");}
    //Impressao da matriz apos as modificacoes.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            printf("%c ", mat[i][j]);
        printf("\n");}
    return 0;
}


