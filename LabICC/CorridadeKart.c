/*Em um certo dia no kartodromo de Sao Carlos ocorreram N corridas de kart, nelas os karts
partiram de um mesmo ponto inicial, com velocidades iguais ou distintas, e terminaram a corrida ap´os
um determinado tempo T.
Escreva um programa que receba como entrada a quantidade de corridas N, as velocidades iniciais
dos karts A e B e o tempo T que durou cada corrida. Seu programa deve retornar, para cada
corrida, qual kart venceu, bem como a distancia percorrida a mais que o kart perdedor.
No entanto, algumas situacoes inesperadas podem ocorrer, analise a saıda no exemplo dado para
compreende-las.
As velocidades dos karts, em quilometros por hora, sao representadas por floats.
O tempo de corrida, em horas, e do tipo inteiro.
A distancia percorrida por eles, em quilometros, deve ser representada por floats com 2 casas
decimais.*/

#include <stdio.h>
int main(){
    int N, T;
    float A, B;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%f %f %d", &A, &B, &T);
    if(T==0)
        printf("A corrida ainda nao comecou\n");
    else if(A==B && B==0)
                printf("Os dois pilotos nao querem competir\n");
    else if(A==0)
        printf("O piloto A desistiu inesperadamente\n");
    else if(B==0)
        printf("O piloto B desistiu inesperadamente\n");
    else if(T<0)
        printf("De alguma forma os pilotos voltaram no tempo\n");
    else if(A==B)
        printf("Os karts empataram, percorrendo cada %.2lfkm\n", A);
    else if(A>B)
        printf("O kart A venceu e percorreu %.2lfkm a mais que o kart B\n", T*(A-B));
    else
        printf("O kart B venceu e percorreu %.2lfkm a mais que o kart A\n", T*(B-A)); 
    }
    return 0;
}
    
