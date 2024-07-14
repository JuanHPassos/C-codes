/*Implemente um programa em C que leia o nome de um arquivo de texto, e em seguida leia uma
palavra, de no maximo 10 caracteres, que sera buscada dentro do arquivo. O programa deve imprimir
quantas vezes essa palavra dentro do texto do arquivo.
Tenha em mente que a palavra pode aparecer maiuscula ou minuscula, e tambem seguida por
pontuacao, nao conte situacoes em que a palavra aparece dentro de outra palavra.*/

#include<stdio.h>
#include<stdlib.h>
/*Funcao para jogar a string para minusculo - minus*/
void minus(char *str,long int n){
    for(int i = 0; i< n; i++){
        if('A' <= str[i] && str[i] <= 'Z'){
            str[i] = str[i]+32;
        }
    }
}
/*Funcao que verifica se a palavra pode ser contada - valid*/
int valid(char c) {
    //Verifica-se se ela e uma subpalavra, caso nao seja, pode-se contar ela.
    return (!(c >= 'a' && c <= 'z'));
}

int main(){
    FILE *fp = NULL;
    char nome[10];//Nome do arquivo.
    long int tam;//Tamanho do arquivo.    
    char *arq;//Vetor que armazenara as info do arquivo.
    char repet[10];//Palavra que repete.
    char *ptr;//Ponteiro auxiliar.
    scanf("%s", &nome);
    scanf("%s", &repet);
    fp = fopen(nome, "r");//Abrir o arquivo.
    if(fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);//Colocar o ponteiro no ultimo bit.
    tam = ftell(fp) + 1;//Retorna a posicao desse bit no arquivo(tamanho do vetor) + 1(= '\0').
    rewind(fp);//Retorna ponteiro para o inicio do arquivo.
    arq = (char *) malloc((tam)*sizeof(char));
    fread(arq, sizeof(char), tam, fp);//Le o arquivo de uma vez.
    arq[tam-1] = '\0';
    fclose(fp);//Fecha o arquivo.
    minus(arq, tam);//Coloca a string para minusculo.
    minus(repet, strlen(repet)+1);//Coloca a palavra a ser contada em minusculo.
    int cont  = 0;//Contador.
    ptr = arq;//Ponteiro recebe o inicio do arquivo.
    //Enquanto existir a palavra a ser contada na string
    while ((ptr = strstr(ptr, repet)) != NULL) {
        //Verifica-se se a palavra e valida = antes dela nao ser uma letra e apos ela nao ser uma letra.
        if ((ptr == arq || valid(*(ptr - 1))) && valid(*(ptr + strlen(repet)))) {
            cont++;
        }
        ptr += strlen(repet);//Move-se o ponteiro para frente buscando por novas palavras iguais.
    }


    printf("quantidade: %d", cont);
    return 0;
}