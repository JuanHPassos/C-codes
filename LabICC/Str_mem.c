/*Implemente um programa em C que leia na entrada padrao de texto uma string com espacos de
no maximo 26 caracteres, o programa deve printar na tela caractere por caractere, seguido por uma
quebra de linha.*/

#include <stdio.h>
int main(){
    char ch[27];//26 espacos de acordo com a especificacao + o '\0'.
    char *p; 
    scanf("%[^\n]s", ch);
    p = ch;//ch é um ponteiro estatico, pois ch guarda o endereco de memoria da primeira posicao do vetor.
    for(p = ch; *p != '\0'; p++)
        printf("%c\n", *p);
    return 0;
}