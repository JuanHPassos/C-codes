/*Implemente um programa em C que recebe um inteiro N e um inteiro M, que serao as dimensoes
de 2 matrizes quadradas. Seu programa deve imprimir as duas matrizes, checar se a matriz 1 e a
matriz 2 sao ou nao matrizes diagonais, e, por fim, imprimir a matriz resultante da multiplicacao de
ambas as matrizes (se possıvel) seguido por uma quebra de linha.*/

#include <stdio.h>
/*Funcao que le e printa matriz quadrada - matriz*/
int matriz(int tam, int p[][tam]){
    int d = 0;//Variavel que verifica se a matriz e diagonal.
    for(int i = 0; i<tam; i++){
        for(int j = 0; j<tam; j++){
            scanf("%d", &p[i][j]);
            printf("%d ", p[i][j]);
            if(i != j)
                if(p[i][j] != 0)
                    d = 1;//Matriz nao eh diagonal.
        }
    printf("\n");}
    return d;
}
/*Funcao principal - main*/
int main(void){
    /*n = linha e coluna da primeira matriz, m = linha e coluna da segunda matriz,
    soma = variavel que servira para realizar a multiplicacao das matrizes, d() -> 0 = diagonal, 1 = nao eh diagonal
    (1 = primeira matriz) ou (2 = segunda matriz)*/
    int n, m, soma, d1, d2;
    scanf("%d %d", &n, &m);
    int m1[n][n], m2[m][m];
    printf("Matrizes:\n");
    //Chama-se as funcoes que imprimem e leem as matrizes, alem de retornar se ela e ou nao eh diagonal.
    d1 = matriz(n, m1);
    d2 = matriz(m, m2);
    if(d1 == 0)
        printf("A matriz 1 eh diagonal\n");
    else
        printf("A matriz 1 nao eh diagonal\n");   
    if(d2 == 0)
        printf("A matriz 2 eh diagonal\n");
    else
        printf("A matriz 2 nao eh diagonal\n");   
    if(m != n)
        printf("Matrizes de tamanho incompativel\n");
    else{
        printf("Matriz multiplicada:\n");
        //Um dos jeitos de se multiplicar matrizes.
        for(int i = 0; i<n; i++){
            for(int k = 0; k<n; k++){
                for(int j = 0; j<n; j++){
                    soma += m1[i][j]*m2[j][k];}
                printf("%d ", soma);
                soma = 0;
            }
            printf("\n");
        } 
    }
    return 0;
}

