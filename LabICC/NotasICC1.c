/*Voce terminou a disciplinas de Lab de ICC 1 e os monitores pediram um ultimo trabalho que
consiste em calcular alguns dados do desempenho da turma toda. Se voce acertar, ganhara um sonho
de valsa extra, alem daqueles ja prometidos pelo professor.
E dada uma matriz de N linhas e M colunas que representam, respectivamente, a quantidade de
alunos e exercıcios resolvidos durante todo o semestre. Importante: 1 ≤ N ≤ 100 e 1 ≤ M ≤ 25.
Seu trabalho e calcular e imprimir para cada aluno: a) a media simples m b) o conceito. Se
m ≥ 5.0, “Aprovado”, caso contrario “Reprovado”. E para cada exercıcio, voce devera calcular e
imprimir a nota media obtida pelos alunos, em ordem decrescente.
Nota: programas com funcoes sao, via de regra, melhores e mais reaproveitaveis. Use funcoes, por
exemplo para ordenar, para imprimir a nota dos alunos e para imprimir a media dos exercıcios.*/

#include<stdio.h>
//Modularizacao das funcoes.
void sort(int tam, float v[tam]);
void nota(int n, int m, float mat[][m]);
void media(int n, int m, float mat[][m]);
/*Funcao para o calculo das notas/medias dos alunos - nota*/
void nota(int n, int m, float mat[][m]){
    float soma = 0.0;
    //Soma-se a linha(= soma das notas) e dividi-se pelas colunas quant. colunas(= n. de exercicios).
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            soma += mat[i][j]; 
        printf("Media do aluno %d = %.2f : ", i+1, soma/m);
        if(soma/m >= 5.0)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
        soma = 0.0;
    }
    printf("\n");
}
/*Funcao para a ordenacao crescente do vetor - sort*/
void sort(int tam, float v[tam]){
    float temp; 
    int ord;//Variavel para saber se o vetor ja esta ordenado(ord == 0 -> ordenado).
    for(int i = 0; i<tam-1; i++){
        ord = 0;
        for(int j = 0; j<tam-1-i; j++){
            //Swap de 3 variaveis.
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                ord = 1;}
            }
        if(ord == 0)//Se ord valer 0, nao ocorreu nenhum Swap, logo ele ja esta ordenado.
            break;
    }    
}
/*Funcao para calcular a media dos exericios - media*/
void media(int n, int m, float mat[][m]){
    float media[m];
    //Inicializa-se o vetor com 0.
    for(int i = 0; i<m; i++)
        media[i] = 0.0;
    //Fixa-se a coluna e percorre as linhas, para calcular a media do exercicio.
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++)
            media[j] += mat[i][j];
        media[j] = media[j]/n;}
    //Organizacao das media do menor para o maior.
    sort(m, media);
    //Impressao das medias do maior para o menor.
    for(int i = m-1; i>=0; i--)
        printf("%.2f ", media[i]);
}

int main(){
    int n, m; //Quantidade de alunos e exercicios resolvidos durante o semestre.
    scanf("%d %d", &n, &m);
    float mat[n][m];
    //Leitura das notas.
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%f", &mat[i][j]);
    //Calculo das notas/medias dos alunos.
    nota(n, m, mat);
    //Calculo das medias das notas de cada exercicio.
    media(n, m, mat);

    return 0;       
}