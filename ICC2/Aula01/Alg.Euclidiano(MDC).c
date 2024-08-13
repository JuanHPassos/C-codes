/*Calculo do MDC pelo algortimo de euclides*/
#include<stdio.h>

int MDC(int p, int q){
    if(q == 0) return p;//Caso base.
    //Aproximação da condição de parada.
    //OBS: funciona pois o MDC de (p, q) é igual ao MDC de (q, p%q).
    else return MDC(q, p%q);
}
/*Função principal - Main*/
int main(){
    int p, q, resp;
    scanf("%d %d", &p, &q);
    resp = MDC(p, q);
    printf("%d", resp);

    return 0;
}