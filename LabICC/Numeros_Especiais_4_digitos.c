/*Qualquer numero natural de quatro algarismos pode ser dividido em duas dezenas formadas pelos
seus dois primeiros e dois ultimos dıgitos. Exemplos:
• 1297 = 12 e 97
• 5314 = 53 e 14
Escreva um programa que analise todos os numeros de 4 dıgitos e escreva na tela os numeros
cuja raiz quadrada seja a soma das dezenas formadas pela separacao acima. Exemplo: √9801 = 98+01*/

#include <stdio.h>
#include <math.h>
int main(){
    for(int i =1000; i<=9999; i++)
        if(sqrt(i) == (i/100)+(i%100))
            printf("%d\n", i);
    return 0;
    }