/*A funcao Swap e um conceito comum em programacao e refere-se a uma operacao que troca os
valores de duas variaveis entre si. Sabendo disso, a logica por tras da funcao e simples: ela armazena
temporariamente o valor de uma das variaveis em uma variavel temporaria, atribui o valor da segunda
variavel a primeira e, em seguida, atribui o valor temporario a segunda variavel. Isso resulta na troca
efetiva dos valores entre as duas variaveis. Porem, e possıvel realizar essa troca utilizando ponteiros
e, devido a tematica da aula, voce ira desenvolver esse novo metodo, trocando o conteudo das variaveis
pelos ponteiros que sinalizam os respectivos conteudos nelas. Note que o procedimento e o mesmo
para ambos os casos, o que muda sera a declaracao de ponteiros extras para efetuar as trocas entre
eles.*/

#include <stdio.h>
int main(){
    int num1, num2, troca1, *p, *q;
    scanf("%d %d", &num1, &num2);
    p = &num1;
    q = &num2;
    troca1 = *p;
    *p = *q;
    *q = troca1;
    
    printf("%d %d", num1, num2);
    return 0;
}
/*Curiosidade: Swap com apenas 2 variaveis
#include <stdio.h>
int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    A = A + B;
    B = A - B;
    A = A - B;
    printf("%d %d", A, B);
    return 0; 
}*/