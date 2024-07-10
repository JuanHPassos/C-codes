/*Implemente um programa em C que leia na entrada padrao de texto dois inteiros a b, o programa
deve retornar o menor e o maior primos contidos no intervalo fechado [a,b], seguido por uma quebra
de linha.*/

#include <stdio.h>
#include <math.h>
int main(){
    int i, a, b, menorp, maiorp, primo;
    scanf("%d %d", &a, &b);
    //inicializo o maiorp(variavel para guardar o maior primo), com o menor numero do intervalo
    maiorp = a;
    //inicializo o menorp(variavel para guardar o menor primo), com o maior numero do intervalo
    menorp = b;
    //verficar os primos dentro do intervalo
    for( i = a; i<=b; i++){
        primo = 1;
        //verificar se o numero i e primo.
        for(int j = 2; j<=sqrt(i); j++){
            if((i%j)==0){
                primo = 0;
                break;
            }
        }  
        //se o numero i for primo, verificamos se ele e o menor ou o maior, e atualizo.  
        if(primo == 1 && i!=1){
            if(i<menorp)
               menorp = i;
            if(i>maiorp)
                maiorp = i; 
        }
    }
    //se as variaveis para guardar o maior e o menor primo continuarem iguais, sendo elas diferentes, entao nao ha primo no intervalo.
    if(menorp == b && maiorp == a && a!=b){
        printf("nenhum primo no intervalo\n");
    }
    else{
        printf("menor primo: %d\n", menorp);
        printf("maior primo: %d\n", maiorp);
    }
    return 0;
}