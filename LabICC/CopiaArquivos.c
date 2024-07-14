/*Era uma madrugada de quarta-feira, vespera de duas provas importantes.
O laboratorio de informatica estava silencioso, exceto pelo som das teclas digitadas e o zumbido dos computadores. Voce,
monitor dedicado de ICC, estava revisando seus proprios estudos quando recebe uma mensagem urgente de um aluno, Joao,
que estava em apuros com um trabalho teorico. ”Oi, Mestre!”, dizia a
mensagem de Joao. ”Estou desesperado! Preciso clonar um arquivo binario para meu trabalho de
ICC, mas nao sei como fazer isso em C. Por favor, me ajude!”. Compadecido com o desespero de
Joao, voce decide agir rapidamente para ajuda-lo.
Com toda sua experiencia em programacao, voce sabe exatamente o que fazer, decide fazer um
programa em C que tem como entrada o nome do arquivo em binario a ser clonado e deve retornar
todo o conteudo do arquivo em formato de texto na tela.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long int li;
int main(){
    FILE *fp;
    char nome[15];//Nome do arquivo.
    li tam;//Tamanho do vetor que guardara as info. do arquivo.
    char *arq;//Vetor arquivo.
    scanf("%s ", nome);//Leitura do nome do arquivo.
    fp = fopen(nome, "rb");//Abrir o arquivo a partir do nome fornecido.  
    if(fp == NULL){ 
        printf("Nao foi possivel abrir o arquivo\n"); 
        exit(1);
    }
    fseek(fp, 0, SEEK_END);//Envia o ponteiro para o ultimo bit do arquivo.
    tam = ftell(fp) + 1;//Ftell retorna o bit em que o ponteiro esta, nesse caso representa a quantidade de bits do arquivo + 1 do  '\0' da string.
    rewind(fp);//Retorna o ponteiro para o inicio.
    arq = (char *) malloc(tam*sizeof(char));//Aloca dinamicamente o vetor.
    if(arq == NULL){ 
        printf("Nao foi possivel realizar a alocacao dinamica\n"); 
        exit(1);
    }
    //Le bit a bit as informacoes do arquivo para o vetor.
    for(li i = 0; i < tam; i++){
        fread(&arq[i], sizeof(char), 1, fp);    
    }
    arq[tam-1] = '\0';
    printf("%s", arq);
    //Fechamento do arquivo.
    fclose(fp);
    //Desalocacao de memoria.
    free(arq);
    return 0;
}