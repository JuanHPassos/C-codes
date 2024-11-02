#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct quantidades_{
    int contadorTrocas;
    int contadorComparacoes;
}QUANTIDADES;

// Moduçarização
int getMax(int arr[], int n);
void countSort(int *arr, int n, int exp, QUANTIDADES *quantidades);

// Função utilitária para obter o valor máximo em arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Função para realizar o Counting Sort em arr[]
// de acordo com o dígito representado por exp
void countSort(int *arr, int n, int exp, QUANTIDADES *quantidades) {
    int *output = (int*) malloc(n*sizeof(int)); // Array de saída
    int *count = (int*) calloc(10, sizeof(int)); // Inicializa o array de contagem como 0

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Modifica count[i] para que ele contenha a posição real deste dígito
    // em output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[],
    // para que arr[] agora contenha números ordenados
    // de acordo com o dígito atual
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
        (quantidades->contadorTrocas)++; // Conta "trocas"(movimentação no array)
    }
}

// Função principal para ordenar arr[] de tamanho n usando Radix Sort
void radixSort(int *arr, int n, int *contador) {
  
    // Encontra o número máximo para saber
    // o número de dígitos
    int m = getMax(arr, n); 

    // Realiza o Counting Sort para cada dígito
    // exp é 10^i onde i é o número do dígito atual
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp, contador);
}

// Código principal
int main() {
    int n, *vet = NULL, contador = 0;
    scanf("%d", &n);

    vet = (int *) malloc(sizeof(int)*n);
    if(vet == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    clock_t start, end;
    double cpu_time_ms;

    start = clock();

    // Calcular quantidade de trocas e comparacoes.
    QUANTIDADES quantidades;
    quantidades.contadorComparacoes = 0;
    quantidades.contadorTrocas = 0;

    radixSort(vet, n, &quantidades);

    end = clock();
    
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    // Calcular o tempo de execução em milissegundos
    cpu_time_ms = ((double) (end - start)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\nTempo de execução: %lf ms\n", cpu_time_ms);

    printf("\n Foram realizadas: %d comparacoes e %d trocas.\n", 
           quantidades.contadorComparacoes, quantidades.contadorTrocas);

    free(vet);
    vet = NULL;

    return 0;
}
