/*Para fazer a biblioteca, é necessario armazenar os livros e eles podem ser mais que 1, ou seja, nem sempr eo vetor de livros sera do tamanho do N, logo
crio um vetor local que recebe o dado, calculo o seu tamanho e copio seu valor para a nova string alocada dinamicamente*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Funcao que verifica se o titulo eh repetido - repet*/
int repet(char **titulo,int tam,char *t, int *quant){
    for(int i = 0; i <tam; i++){
        if(!strcmp(titulo[i], t)){
            quant[i]++;
            return 1;
        }
    }
    return 0;  
}
/*Essa função serve para armazenar a entrada, alocar dinamicamente a quantidade de livros,
verificar se o livro inserido ja existe, caso nao exista, adiciona-se ele na biblioteca*/
int entrada(char ***titulo,char ***autor,int **ano, int **quant){
    int n, tam = 0, an;//Quant. de livros, Quant. de livros diferentes e ano.
    char t[110], a[60];//Variaveis temporarias para decobrir o tamanho das informacoes.
    //Leitura da quant de livros e alocacao dinamica da quant de info inserida em vetores de inteiro, string, string, string.
    scanf("%d", &n);
    *ano = (int *) malloc(n*sizeof(int));
    *quant = (int *) calloc(n, sizeof(int));
    *titulo = (char **) malloc(n*sizeof(char*));
    *autor = (char **) malloc(n*sizeof(char*));
    //Estrutura para ler todos os dados, calcular o tamanho das strings, e alocar dinamicamente o espaco necessario para guarda-las.
    for(int i = 0; i<n; i++){
        scanf(" %[^,], %[^,], %d", t, a, &an);
        if(!repet(*titulo, tam, t, *quant)){
            (*quant)[tam]++;
            (*titulo)[tam] = (char*) malloc((strlen(t)+1)*sizeof(char));//strlen(t)+1 = tamanho da string + '\0'.
            strcpy((*titulo)[tam], t);
            (*autor)[tam] = (char*) malloc((strlen(a)+1)*sizeof(char));
            strcpy((*autor)[tam], a);
            (*ano)[tam] = an;
            tam++;
        }        
    }
    //Reajuste da quantidade de informacoes para a quantidade de livros diferentes(obs:pois mesmo livro ocupa apenas um espaco no vetor).
    *ano = (int*) realloc(*ano,(tam+1)*sizeof(int));
    *quant = (int*) realloc(*quant,(tam+1)*sizeof(int));
    *titulo = (char **) realloc(*titulo, (tam+1)*sizeof(char*));
    *autor = (char **) realloc(*autor, (tam+1)*sizeof(char*));
    return tam;
}

int main(){
    char **titulo;//Vetor de strings.
    char **autor;//Vetor de strings.
    int *quant;//Vetor de inteiros.
    int *ano;//Vetor de inteiros.
    int tam;//Inteiro = quant. de Catalogos.
    tam = entrada(&titulo, &autor, &ano, &quant);
    
    printf("Catalogo de Livros:\n");
    for(int i = 0; i<tam; i++){
        if(i != 0) printf("\n");
        printf("Livro %d:\n", i+1);
        printf("Titulo: %s\n", titulo[i]);
        printf("Autor: %s\n", autor[i]);
        printf("Ano: %d\n", ano[i]);
        printf("Quantidade: %d\n", quant[i]);
    }  
    //Desalocacao de memoria.
    free(quant);  
    free(ano);  
    for(int i = 0; i<tam; i++){
        free(titulo[i]);  
        free(autor[i]);}  
    free(titulo);  
    free(autor);
    
    return 0;
}