/*Implemente um programa em C que leia na entrada padrao de texto uma data desformatada
composta de dia, mes e ano. Imprima na tela a data formatada da seguinte maneira: dd/dd/dddd,
seguida por uma quebra de linha.*/

#include <stdio.h>
int main(){
    char ch;
    int i;

    scanf("%c %d", &ch,&i);
    printf("numero correspondente: %d\n", ch);//Numero do caractere "ch" na tabela ASCII.
    printf("caracter correspondente: %c\n", i);//Caracter que possui o numero "i" na tabela ASCII.
    printf("octal: %o\n", i);//Representação desse numero em octal( %o ).
    printf("hexadecimal: %x\n", i);//Representação desse numero em hexadecimal( %x ).
    return 0;
    }
