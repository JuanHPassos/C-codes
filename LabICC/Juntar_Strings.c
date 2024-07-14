/*Implemente um programa em C que leia 2 strings (A e B), de no maximo 130 caracteres, e em
seguida leia uma palavra, de no maximo 20 caracteres, que sera usada como parametro para a juncao.
O programa deve imprimir uma string composta pelos caracteres de A ate o parametro, e do parametro
ate o final de B, evitando imprimir espacos(” ”) adicionais.
Caso a string A nao possua o parametro, ela deve ser impressa completamente, ja caso a string B
nao possua o parametro, ela nao deve ser impressa.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char A[131];
    char B[131];
    char par[21];
    char *ptr;
    char ans[261] = " ";
    int pos;
    //Leitura das strings com o fgts, ou seja, elas possuem um \n no final.
    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);
    fgets(par, sizeof(par), stdin);
    //Encontrar o primeiro \n e trocar por \0.
    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';
    par[strcspn(par, "\n")] = '\0';
    //Retorna a posição do vetor(de 0 a tam) em que comeca o parametro.
    //pos = (strstr(A, par)) - A;
    ptr = (strstr(A, par));
    if(ptr != NULL){
        pos = ptr - A;
        //Se o houver mais de uma palavra, alem do parametro, retira-se o espaço.
        if(pos > 0) pos--;
    }
    else{
        //Se nao houver substring, resposta recebe a string A.
        pos = strlen(A);
    }
    // pos, aqui, representa o tam de 1 a n, logo copiara ate a posição pos-1 do vetor.
    strncpy(ans, A, pos);
    ans[pos] = '\0';
    ans[strcspn(ans, "\r")] = '\0';
    //Ponteiro para o inicio do parametro.
    ptr = strstr(B, par);
    if(ptr != NULL){
        //Avanca-se o tamanho da palavra mais o espaço, logo aponta para o inicio da prox palavra.
        ptr = ptr + strlen(par);
        if(*ptr == ' ' && pos == 0)
            ptr++;
        //Concatena a string resposta, com o resto da string B que eu quero.
        strcat(ans, ptr);}
    //Imprimi o resultado do código.
    printf("%s", ans);
    return 0;
}



    