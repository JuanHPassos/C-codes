/*Implemente um programa em C que leia na entrada padrao de texto dois numeros e execute as 4
principais operacoes da calculadora (Adicao, Subtracao, Multiplicacao e Divisao). Imprima na tela o
resultado das operacoes. Nota: no caso da divisao, lembre-se que esta pode ser inteira ou racional.
A divisao inteira de 4/3 e 1, enquanto a divisao racional e 1.3333333.*/

#include <stdio.h>
int main(){
    int i, j;

    scanf("%d %d", &i, &j);//Leitura de dois numeros inteiros.
    printf("Soma: %d\n", i+j);
    printf("Subtracao: %d\n", i-j );
    printf("Multiplicacao: %d\n", i*j);
    printf("Divisao Inteira: %d\n", i/j);
    printf("Divisao Racional: %.3f\n", ((float) i)/j);
    //Cast do numero inteiro i para float, e necessario para que a divisao tenha como resultado um numero float.

    return 0;
}
