//Cálculo do MDC recursivo.
#include<stdio.h>
//Modularização da função MDC.
int MDC(int p, int q, int d);
/*Função para calcular o máximo divisor comum entre 2 numeros - MDC*/
int MDC(int p, int q, int d){
    //Se p for zero, o maximo divisor entre os dois é q.
    if(p == 0) return q;
    //Se q for zero, o maximo divisor entre os dois é p.
    if(q == 0) return p;
    //Se p e q forem divisiveis, d é o MDC.
    if(p%d == 0 && q%d == 0) return d;
    //Caso contrario, decrementa-se 1 de d.
    else return MDC(p, q, d-1);
}
/*Função principal - Main*/
int main(){
    int p, q, resp;
    scanf("%d %d", &p, &q);
    //d recebe o menor valor dos dois numeros. 
    int d = (p < q) ? p : q;
    resp = MDC(p , q, d);
    printf("%d", resp);
    return 0;
}