/*Voce encontrou um conjunto de arquivos binarios do mestre Rafito dinamite. Esses arquivos
possuem conselhos valiosos. porem o arquivo foi invadido com uma palavra invasora. Voce decide
fazer um programa para limpar esse arquivo, o programa recebera a palavra invasora, seguida pelo
nome do arquivo de entrada, que serao no formato binn.bin, onde estara o texto a ser lido, e devera
imprimir o texto sem a palavra invasora.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long int li;
int main(){
    FILE *fp;
    char inv[30];//Palavra invasora.
    char nome[30];//Nome do arquivo.
    char *arq;//Vetor que guardara info do arquivo.
    li tam;//Tamanho do vetor.
    char *ptr;//Ponteiro auxiliar.
    int cort;//Tamanho do vetor que sera "cortado".

    scanf("%s %s", inv, nome);
    fp = fopen(nome, "a+");//Abre-se o arquivo com a ponteiro no final.
    rewind(fp);//Volta ele para o inicio.
    if(fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);//Coloca o ponteiro no ultimo bit do arquivo.
    tam = ftell(fp);//Retorna que bit e esse, representando o tamanho do arquivo.
    arq = (char *) malloc((tam+1)*sizeof(char));//Aloca dinamicamente o vetor que contera as informacoes do arquivo.
    rewind(fp);//Retorna o ponteiro para o inicio.
    fread(arq, sizeof(char), tam, fp);//Le o arquivo de uma vez e armazena no vetor.
    arq[tam] = '\0';
    ptr = strstr(arq, inv);//Ponteiro aponta para o inicio da palavra invasora.
    cort = strlen(inv);//Tamanho que se deseja sumir partindo do ponteiro.
    while(*(ptr+cort) == ' '){
        cort++;//Caso haja espaco apos, busca-se tira-lo.
    }
    //Busca-se eliminar de ptr ate ptr+cort.
    memmove(ptr, ptr+cort, strlen(ptr+cort)+1);
    printf("%s\n", arq);

    return 0;

}