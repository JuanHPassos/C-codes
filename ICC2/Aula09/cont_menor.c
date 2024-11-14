/*Consiste em contar os elementos menores de um determinado numero, e guardar ele na posição apos esses menores,
e necessarios dois vetores auxiliares, que guarda a quantidade de menores do numero naquela posicao, 
e um vetor para inserir os numeros e depois substituir o originial*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cont_menor(int *vet,int n);

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    cont_menor(vet, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;

}
// Ordena o vetor pelo metodo de contagem de menores.
void cont_menor(int *vet,int n){
    int x[n], b[n]; // x vetor quant_menores
    memset(x, 0, n*sizeof(int));
    // Conta elementos menores
    // Comparando todos os pares de elementos do vetor.
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(vet[i] <= vet[j]){ // Para decrescente basta, trocar o menor para o maior.
                x[j]++;
            }
            else x[i]++;
        }
    }
    // Ordena em um vetor auxiliar
    for(int i = 0; i < n; i++){
        b[x[i]] = vet[i];
    }
    // Copia para o vetor resposta.
    memcpy(vet, b, n*sizeof(int));
    
    // for(int i = 0; i < n; i++){
    //     vet[i] = b[i];
    // }
}
