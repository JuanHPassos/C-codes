/*Implemente um programa em C leia na entrada padrao de texto um numero inteiro N, representando o numero de termos da sequencia. Em seguida, imprima na tela o valor da soma da sequˆencia
representada pela formula abaixo: 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ... 1/N*/

#include <stdio.h>
int main(){
    double N, soma = 0;
    scanf("%lf", &N);
    for(int i = 1; i <= N; i++){
        if(i%2 == 0)
            soma = soma - (1.0/i);//1.0 para que a divisao tenha como resultado um float.
        else
            soma = soma + (1.0/i);
    }
    printf("%.4lf", soma); //%.4lf imprimir 4 numeros pos a virgula.
    
    return 0;
}
