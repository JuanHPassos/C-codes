/*Pense em um algoritmo recursivo que converta um número decimal (base 10) para base 2*/
#include<stdio.h>
void converta(int n){
    //Se n valer 0, o número ja passou por todas as divisões por dois.(Começará o desempilhamentio)
    if(n == 0){
        return;
    }
    //Chama-se a função para chegar a ultima divisão por dois.(empilhando)
    converta(n/2);
    //Já ocorreu o empilhamento, e a memoria esta voltando ao estado original, printando os restos das divisões, que forma o numero em binario.
    printf("%d", n%2);
}

int main(void){
    int n;
    scanf("%d", &n);
    if(n == 0){
        printf("%d", 0);
    }
    else converta(n);
    return 0;
}