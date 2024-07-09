/*Implemente um programa em C que leia na entrada padrao de texto dois numeros inteiros, seu
programa devera realizar os seguintes testes:
1) Se n1 e maior que n2 E n1 menos n2 e divisıvel por 3.
2) Se n2 e maior que n1 E n1 + n2 e maior que 400.
3) Se n1 e igual a n2 E n1 e ımpar.
Se qualquer um desses testes for verdadeiro, imprima n1 + n2, se nao, seu programa deve imprimir
”Nenhuma condicao foi satisfeita” seguidos por uma quebra de linha.*/

#include <stdio.h>
int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if ( (n1>n2 && (n1-n2)%3==0)||(n2>n1 && n1+n2>400)||(n1==n2 && n1%2==1))//Verificação.
        printf("%d", n1+n2);
    else
        printf("Nenhuma condicao foi satisfeita\n");
    return 0;
}