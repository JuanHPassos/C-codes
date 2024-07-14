/*Faça um programa RECURSIVO que some 2 números inteiros, NÃO negativos !!!!! Só vale com recursão.....*/
#include <stdio.h>

// Função recursiva para somar dois números inteiros não negativos
int soma(int a, int b) {
    // Caso base: se b for 0, a soma é simplesmente a
    if (b == 0) {
        return a;
    }
    // Caso recursivo: somar 1 a 'a' e subtrair 1 de 'b' até que 'b' seja 0
    else {
        return soma(a + 1, b - 1);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int resultado = soma(a, b);
    printf("%d", resultado);
    return 0;
}