/*Sera dado um vetor e voce deve imprimı-lo na ordem inversa, utilizando os conceitos recentementes
aprendidos em aula.
Voce nao deve usar o [i] para acessar a posicao no vetor.
Input
1 ≤ n ≤ 105*/

#include <stdio.h>
int main(){
    //Declaro variavel que indicara o tamanho que sera usado, um ponteiro para percorrer o vetor e o vetor com seu tamanho maximo.
    int n, *p, v[100001];
    scanf("%d", &n);
    //p recebe a primeira posicao do vetor.
    p = v;
    //Percorro o vetor inserindo valores em cada posicao.
    for(int i = 0; i<n; i++)
        //p e um endereco, logo nao eh necessario &.
        scanf("%d", p++);
    //decremento p porque no final do laco ele apontara para uma posicao invalida.
    p--;
    //Imprimo o vetor de tras para frente.
    for(int i = 0; i<n; i++)
        //*p = valor da posicao em que se esta sendo apontado.(obs: p = endereco da posicao apontada)
        printf("%d ", *p--);
    return 0;
}