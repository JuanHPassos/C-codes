/*Implemente um programa em C que leia na entrada padrao de texto quatro inteiros a b c d, que
representeam lados consecutivos de um quadrilatero. Assumindo que todos os angulos sao retos, a
saıda deve determinar se o quadrilatero e um quadrado ou so um retangulo qualquer, seguido por uma
quebra de linha.*/

#include <stdio.h>
int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a==0 || b==0 || c==0 || d==0)//Se algum dos lados for 0, nao temos um poligono.
        printf("nenhum!\n");
    else if (a==b && c==d && a==c)
        printf("quadrado!\n");
    else if(a==c && b==d)
        printf("retangulo!\n");
    else
        printf("nenhum!\n");
    return 0;
}