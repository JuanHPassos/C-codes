/*Voce e um fiscal do Tusca que sera responsavel por divulgar os resultados individuais dos atletas
num dado esporte. Para facilitar esse registro, voce desenvolvera um programa em C que te da a
colocacao dos competidores na ordem de entrada. O programa recebera como entrada o numero de
atletas (n) e, nas proximas n linhas, a pontuacao de cada atleta (1º ... nº). Com base nesses dados,
o programa deve imprimir a lista na mesma ordem em que recebeu, imprimindo o numero do atleta,
a quantidade de pontos e sua colocacao.
Por incrıvel que pareca, o numero de atletas esta contido no intervalo 1 ≤ n ≤ 100.*/

#include <stdio.h>
/*Modularizacao das funcoes*/
void sort(int n, int *p);
void org(int n, int*p);
/*Funcao para organizar o vetor em ordem crescente- sort*/
void sort(int n, int *p){
    int temp, ord;
    for(int i = 0; i< n-1; i++){
        ord = 0;
        for(int j = 0; j < n-i-1; j++){
            if(p[j] < p[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                ord = 1;}
            }
        if(ord == 0)
            break;
    }
}
/*Funcao para organizar o vetor de forma que permaneca apenas uma pontuacao igual - org*/
void org(int n, int*p){
    int temp, ord;
    //Verifico se possue elementos iguais.
    for(int i = 0; i<n-1; i++)
        if(p[i] == p[i+1])
            //Caso haja elemento igual, ando os valores a partir dessa posicao, uma casa para a esquerda.
            for(int j = i+1; j<n-1; j++)
                p[j] = p[j+1];
//obs:nota-se que no final do vetor permanece valores repetidos do ultimo elemento, porem isso nao atrapalhara na logica a ser implementada.
}
int main(){
    int x;//Variavel que guarda a quantidade de atletas.
    scanf("%d", &x);
    int v[x], n[x];//Vetor(v) guarda a ordem dos nomes conforme recebeu e o vetor(n) guardara a pontuacao dos atletas ordenada.
    for(int i = 0; i<x; i++){
        scanf("%d", &v[i]);
        n[i] = v[i];
    }
    sort(x, n);//Ordena o vetor n.
    org(x, n);//Some com valores repetidos no meio do vetor.
    for(int i = 0; i<x; i++){
        //Imprime-se o numero do atleta e os seus pontos de acordo com o primeiro vetor.
        printf("%dº Atleta, %d Pontos, ", i+1, v[i]);
        /*Para imprimir a sua classificacao, fixa-se o atleta e, procura-se em que colocacao a sua pontuacao esta, lembrando que nesse problema
        atletas com a mesma pontuacao, estao na mesma classificacao*/
        for(int j = 0; j<x; j++)
            if(v[i] == n[j]){
                printf("%dº Colocado\n", j+1);
                break;}
    }
    return 0;
}
    
    


