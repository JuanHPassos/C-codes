/*Dado o algoritmo abaixo, confira se esta correto e, depois, faca um codigo em C que implemente
exatamente o que e feito, sem pular etapas, lendo e declarando todas as variaveis escritas no algoritmo.
Algoritmo:
INICIO
inteiro : case
caracter : 1 nome , 2 nome , char
leia ( case )
leia (1 nome )
leia (2 nome )
leia ( char )
inteiro : resposta
resposta <- case
escreva ("a resposta eh ")
escreva ( resposta )
FIM*/

#include <stdio.h>
int main(){
    int caso;
    char nome1, nome2, ch;
    scanf("%d", &caso);
    scanf("%c", &nome1);
    scanf("%c", &nome2);
    scanf("%c", &ch);
    
    int resposta;
    resposta = caso;
    
    printf("a resposta eh %d", caso);
    return 0;
}