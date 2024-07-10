/*Implemente um programa em C que recebe um inteiro n, seguido de n palavras. Voce deve
implementar uma funcao que cheque se cada palavra e ou nao um palindromo, e imprimir na saıda da
maneira demonstrada a seguir seguido por uma quebra de linha.*/

#include <stdio.h>
//Modularização das funcoes.
int tam(char *str);
int palin(char *str);
/*Funcao para calcular o tamanho das palavras - tam*/
int tam(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){}
    return i-1;
}
/*Funcao que verifica se a palavra e um palindromo - palin*/
int palin(char *str){ 
    //Se a ultima letra é igual a primeira, a segunda igual penultima e assim por diante, a palavra eh um palindromo.
    for(int i  = 0; i<(tam(str)+1)/2 ; i++)
        if(str[i] != str[tam(str)-i])//Se forem diferentes, encerra a funcao retornando 0(nao eh palindromo).
            return 0;
    return 1;//Eh um palindromo.
}
int main(void){
    int n; //Variavel para guardar a quantidade de palavras.
    char str[100010];//String que guardara uma palavra de cada vez.(Até palavras de no máximo 100010 de tamanho).
    scanf("%d", &n);//Le a quantidade de palavras.
    for(int i = 0; i<n; i++){
        //Le uma palavra.
        scanf("%s", &str);
        //Verifica se a palavra eh um palindromo.
        if(palin(str))
            printf("%s eh um palindromo\n", str);
        else
            printf("%s nao eh um palindromo\n", str);
    }
    return 0;
}

