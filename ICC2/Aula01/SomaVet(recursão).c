//Achar soma de forma recursiva
#include<stdio.h>
#include<stdlib.h>//Usarei dessa biblioteca a função exit() e malloc()
//Função para realizar soma do vetor - soma
int soma(int v[], int n);
int soma(int v[], int n){
    if(n == 1) return v[0];
    else{
        return v[n-1] + soma(v, n-1);
    }
}
//Função principal - Main
int main(){
    int n, *v, resp;
    scanf("%d", &n);
    //Alocação dinâmica do vetor
    v = (int*) malloc(n*sizeof(int));
    if(v == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
    //Chamada da função que vai realizar a soma do vetor.
    resp = soma(v, n);
    printf("Soma recursiva: %d", resp);
    return 0;
}