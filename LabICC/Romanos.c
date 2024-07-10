/*Vanuza, professora de matematica, esta ensinando aos seus alunos algarismos romanos, vendo a
dificuldade de seus alunos ela desenvolveu uma tabela para converter numeros indo-arabicos para
algarismos romanos, contudo nao houve uma mudanca significativa. Pensando nisso, ela lembrou que
os alunos estao inertes em um mundo digital, por isso, decidiu fazer um programa em C que traduza os
numeros para algarismo romano. Sua funcao e ajudar a professora Vanuza a solucionar seu problema,
desenvolva um programa em C que crie possua uma funcao inteiroParaRomano e realize a correta
traducao.
A primeira entrada do exercıcio e o tamanho do vetor de numeros que sera lido seguido por seus
valores, o maior valor que pode ser passado e 3999*/

#include <stdio.h>
//Solucao com if e else.
/*void inteiroParaRomano(int n){
    while(n != 0){
        if(n >= 1000){
            printf("M");
            n = n-1000;}
        else if(n >= 900){
            printf("CM");
            n = n-900;}
        else if( n >= 500 ){
            printf("D");
            n = n-500;}
        else if( n >= 400 ){
            printf("CD");
            n = n-400;}
        else if( n >= 100 ){
            printf("C");
            n = n-100;}
        else if( n >= 90 ){
            printf("XC");
            n = n-90;}
        else if( n >= 50 ){
            printf("L");
            n = n-50;}
        else if( n >= 40 ){
            printf("XL");
            n = n-40;}
        else if( n >= 10 ){
            printf("X");
            n = n-10;}
        else if( n >= 9 ){
            printf("IX");
            n = n-9;}
        else if( n >= 5 ){
            printf("V");
            n = n-5;}
        else if( n >= 4 ){
            printf("IV");
            n = n-4;}
        else if( n >= 1 ){
            printf("I");
            n = n-1;}
    }
}*/
//Solucao usando vetores:
/*Funcao que transforma o numero inteiro para romano - inteiroParaRomano*/
void inteiroParaRomano(int n){
    int inteiro[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    /*Vetor de strings.(O compilador reconhece o tamanho e preenche, um jeito equivalente é romano[][3], sendo obrigatorio preencher
    a segunda indexição, que define o tamanho maximo de colunas, ex de uma linha "XC\0".*/
    char *romano[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for(int i = 0; i < 13; i++){
        //Enquanto n for maior ou igual que o inteiro[i], ele é representado pela string romano[i].
        while(n >= inteiro[i]){
            printf("%s", romano[i]);
            //Subtrai de n o valor printado anteriormente, pois esse valor ja foi representado.
            n -= inteiro[i];
        }
    }
}
int main(){
    int x, n;
    //Le a quantidade de numeros que serao inseridos.
    scanf("%d", &x);
    for(int i = 0; i<x; i++){
        scanf("%d", &n);
        inteiroParaRomano(n);
        printf("\n");
    }
    return 0;
    
}
