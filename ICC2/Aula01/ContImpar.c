/*Implementar uma função recursiva que conta todos os 
números ímpares de um arranjo*/
#include<stdio.h>
#include<stdlib.h>
/*Função para contar impares - contar_impar*/
int contar_impar(int v[], int n){
    //Dado um vetor de tamanho 1, esse unico valor é impar se há resto na sua divisão por 2.
    if(n == 1) return v[0]%2;
    //Caso contrário, pega-se o ultimo numero do vetor e adiciona um na contagem se ele for impar, e chama a função para o proximo a esquerda.
    return v[n-1]%2 + contar_impar(v, n-1);
}
//Função principal - Main
int main(void){
    int n, *v, resp;
    scanf("%d", &n);
    //Alocação dinâmica do vetor
    v = (int*) malloc(n*sizeof(int));
    if(v == NULL){
        printf("Erro ao alocar memória.");
        exit(1);
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
    //Chamada da função para contar os numeros impares existentes no vetor.
    resp = contar_impar(v, n);
    printf("%d", resp);
    
    return 0;
}