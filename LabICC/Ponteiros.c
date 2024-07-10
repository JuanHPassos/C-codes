/*Implemente um programa em C que leia o valor de uma variavel, depois crie um ponteiro (*p)
para receber o endereco dessa variavel. Em seguida, acrescente em 10 o valor da variavel atraves do
ponteiro (NAO use variavel +=10). Apos isso, crie um ponteiro para ponteiro (**p) que receba o
endereco do ponteiro *p, e acrescente mais 10 ao valor da variavel usando o ponteiro para ponteiro.
Por fim, seu programa deve: Imprimir o valor inicial da variavel, imprimir o valor da variavel
apontada pelo ponteiro antes e depois do incremento, e o valor do ponteiro para ponteiro antes e
depois do incremento. Por fim imprima o valor final da variavel seguido por uma quebra de linha.*/

#include <stdio.h>
int main(){
    int x, *p, **q;
    scanf("%d", &x);
    printf("Valor inicial da variavel: %d\n", x);
    p = &x;
    printf("Valor do ponteiro antes do incremento: %d\n", *p);
    *p = *p + 10;
    printf("Valor do ponteiro depois do incremento: %d\n", *p);
    q = &p;
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **q);
    **q = **q + 10;
    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **q);
    printf("Valor final da variavel: %d\n", x);
    
    return 0;
}