/*Implemente um programa em C que leia na entrada padrao de texto um caractere e um numero
inteiro. Imprima na tela: o codigo ASCII do caractere, o caractere correspondente ao inteiro, o inteiro
em base octal e o inteiro em base hexadecimal, seguidos por uma quebra de linha.*/

#include <stdio.h>
 int main(){
    int dia, mes, ano;
    scanf("%2d", &dia);//%2d le ate dois numeros inteiros.
    scanf("%2d", &mes);
    scanf("%4d", &ano);//%4d le ate 4 numeros inteiros.
    printf("%02d/%02d/%d\n", dia, mes, ano);
    //%02 formata a saida para 2 digitos, preenchendo com zero a esquerda se necessario. 
    return 0;
}
