/*Consiste em contar os elementos menores de um determinado numero, e guardar ele na posição apos esses menores, e necessarios dois vetores auxiliares, que guarda a quantidade de menores do numero naquela posicao, e um vetor para inserir os numeros e depois substituir o originial*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int cont_menor(int *vet,int n);

int main(){
    int n;

    scanf("%d", &n);

    int *vet = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    clock_t start, end;
    double cpu_time_ms;

    start = clock();

    int contador_trocas = cont_menor(vet, n);    

    end = clock();
    
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    // Calcular o tempo de execução em milissegundos.
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execução: %lf ms\n", cpu_time_ms);

    printf("\n Foram realizadas %d trocas.\n", contador_trocas);

    free(vet);
    vet = NULL;

    return 0;

}

// Ordena o vetor pelo metodo de contagem de menores.
int cont_menor(int *vet,int n){
    int contador_trocas = 0;
    int *x = (int*) malloc(n*sizeof(int)); // x = vetor quant_menores.
    int *b = (int*) malloc(n*sizeof(int)); // Vetor para depositar após ordernar.
    memset(x, 0, n*sizeof(int));
    // Conta elementos menores
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(vet[i] <= vet[j]){ // Para decrescente basta, trocar o menor para o maior.
                x[j]++;
            }
            else x[i]++;
        }
    }
    // Ordena em um vetor auxiliar.
    for(int i = 0; i < n; i++){
        b[x[i]] = vet[i];
        contador_trocas++; // Movimentação no vetor(troca).
    }
    // Copia para o vetor resposta.
    memcpy(vet, b, n*sizeof(int));

    free(b);
    free(x);
    b = NULL;
    x = NULL;

    return contador_trocas;
}
