/*Voce deve apenas ler um valor N e imprimi-lo seguido de uma quebra de linha.
Entrada
0 ≤ n ≤ 18446744073709551615*/

#include <stdio.h>
int main(){
    unsigned long n;
    scanf("%lu", &n);
    printf("%lu\n", n);
    return 0;
}