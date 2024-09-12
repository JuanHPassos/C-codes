#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct par{
    float razao;
    int index;
}pair;

int max(float a, float b);
void dividir(pair *vet, int l, int r);
void conquistar(pair *vet, int l, int meio, int r);
int knapsack(int n, int mochila, int *espaco,int *valor);

int main(){
    int n, mochila, *valor, *espaco;

    scanf("%d %d", &n, &mochila);
    
    valor = (int*) malloc(n * sizeof(int));
    espaco = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        espaco[i] = a;
    }

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        valor[i] = a;
    }

     // Marca o início do tempo
    clock_t start = clock();

    int resposta = knapsack(n, mochila, espaco, valor);

    // Marca o fim do tempo
    clock_t end = clock();
    
    printf("%d\n", resposta);

    // Calcula e imprime o tempo de execução em milissegundos
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução: %f ms\n", time_spent);

    
    free(valor); valor = NULL;
    free(espaco); valor = NULL;

    return 0;
}

int max(float a, float b){
    if(a > b) return a;
    else return b;
}

void dividir(pair *vet, int l, int r){
    if(l<r){
        int meio = (l+r)/2;

        dividir(vet, l, meio);
        dividir(vet, meio+1, r);

        conquistar(vet, l, meio, r);

    }
}

void conquistar(pair *vet, int l, int meio, int r){
    int tam1 = meio-l+1;
    int tam2 = r-meio;

    pair L[tam1];
    pair R[tam2];

    for(int i = 0; i < tam1; i++){
        L[i] = vet[i+l];
    }

    for(int i = 0; i < tam2; i++){
        R[i] = vet[i+meio+1];
    }

    int posL = 0, posR = 0, posVet = l;

    while(posL < tam1 && posR < tam2){
        if(L[posL].razao < R[posR].razao){
            vet[posVet] = L[posL];
            posL++;
        }
        else{
            vet[posVet] = R[posR];
            posR++;
        }
        posVet++;
    }

    while(posL < tam1){
        vet[posVet] = L[posL];
        posVet++;
        posL++;
    }
    while(posR < tam2){
        vet[posVet] = R[posR];
        posVet++;
        posR++;
    }
}

int knapsack(int n, int mochila, int *espaco,int *valor){
    pair *razao;

    razao = (pair *) malloc(n * sizeof(pair));

    for(int i = 0; i < n; i++){
        razao[i].index = i;
        razao[i].razao = (float)(valor[i])/espaco[i];
    }
    //Ordenar o vetor(n log n) com base na razao. 
    dividir(razao, 0, n-1);

    int resposta = 0;
    //Comecar do maior para o menor.
    for(int i = n-1; i >= 0; i--){
        int item = razao[i].index;
        if(espaco[item] <= mochila){
            resposta += valor[item];
            mochila -= espaco[item];
        }
        if(mochila == 0) break;
    }

    free(razao); razao = NULL;

    return resposta;
}


