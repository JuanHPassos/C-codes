#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define FILENAME "numeros"
#define FILEEXTENCIONBIN ".bin"
typedef struct Lista_t{
    int *numeros;
    int tamanho;
} lista_t;
//Estrutura para armezenar tempo de execução.
typedef struct {
    clock_t start;
    clock_t end;
}   Timer;

void start_timer(Timer *timer);
double stop_timer(Timer *timer);
int obterNumeroDigitos(int tamanho);
char* gerarNomeArquivo(int tamanho);
char *escreverListaArquivoBinario(lista_t lista);
void imprimeLista(lista_t lista);
void imprimeTempodeExecucao(double tempo);

int main(){
    lista_t lista;
    Timer timer;
    srand(time(NULL));

    printf("Quantos elementos na lista?\n");
    scanf("%d", &lista.tamanho);

    lista.numeros = (int*)malloc(lista.tamanho*sizeof(int));
    start_timer(&timer);
    for(int i = 0; i<lista.tamanho; i++){
        lista.numeros[i] = rand();
    }
    imprimeTempodeExecucao(stop_timer(&timer));//Devolve um double.
    imprimeLista(lista);
    escreverListaArquivoBinario(lista);
    
    free(lista.numeros);

    return 0;
}

//Inicializa o timer.
void start_timer(Timer *timer){
    timer->start = clock();
}
//Encerra o timer.
double stop_timer(Timer *timer){
    timer->end = clock();
    return ((double) (timer->end - timer->start))/ CLOCKS_PER_SEC;
}

int obterNumeroDigitos(int tamanho){
    if(tamanho == 0) return 1;

    int digitos = 0;
    while(tamanho > 0){
        tamanho = tamanho/10;
        digitos++;
    }
    return digitos;
}

char* gerarNomeArquivo(int tamanho){
    char *nomeArquivo;
    int numeroDigitos = obterNumeroDigitos(tamanho);
    char *digitosString = (char*)malloc(numeroDigitos * sizeof(char));

    nomeArquivo = (char*)malloc(strlen(FILENAME) + numeroDigitos + strlen(FILEEXTENCIONBIN));
    sprintf(digitosString, "%d", tamanho);
    strcpy(nomeArquivo, FILENAME);
    strcat(nomeArquivo, digitosString);
    strcat(nomeArquivo, FILEEXTENCIONBIN);
    free(digitosString);
    return nomeArquivo;
}


char *escreverListaArquivoBinario(lista_t lista){
    FILE *arquivo;

    char *nomeArquivo = gerarNomeArquivo(lista.tamanho);
    arquivo = fopen(nomeArquivo, "wb");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    fwrite(lista.numeros, sizeof(int), lista.tamanho, arquivo);
    fclose(arquivo);

    return nomeArquivo;

}


void imprimeLista(lista_t lista){
    for(int i = 0; i<lista.tamanho; i++){
        printf("%d\n", lista.numeros[i]);
    }
}

void imprimeTempodeExecucao(double tempo){
    printf("Tempo de execucao: %lf", tempo);
}
