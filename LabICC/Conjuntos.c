/*Implemente um programa em C que leia 2 vetores (lendo o tamanho do vetor antes) de no maximo
10 inteiros, os vetores devem ser compreendidos como conjuntos a e b, o programa deve imprimir na
tela o conjunto interseccao a b e o conjunto a-b, seguido por uma quebra de linha.*/

#include <stdio.h>
int main(){
    int a[10], b[10], m, n, vazio = 1;
    //Tamanho de a.
    scanf("%d", &m);
    //Leitura de a.
    for(int i = 0; i<m; i++)
        scanf("%d", &a[i]);
    //Tamanho de b.
    scanf("%d", &n);
    //Leitura de b.
    for(int i = 0; i<n; i++)
        scanf("%d", &b[i]);
    
    printf("intersecao:");
    //Fixa-se um numero em a e percorro b para achar um igual, caso esteja la, printo a interseccao.
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
            //Nota-se que nao existe break nesse if, pois o problema nao especifica se pode repeticao de numeros nos conjuntos.
            if( a[i] == b[j]){
                vazio = 0;
                printf(" %d", a[i]);
            }
    //Se nao entrar nenhuma vez no if, e porque nao ha interseccao.
    if(vazio == 1)
        printf(" vazio");
    vazio = 1;
    printf("\na - b:");
    //Fixa-se um numero de a e percorro b, se o numero de a nao estiver em b, eu printo ele.
    for(int i = 0; i<m; i++){
        int x = 1;
        for(int j = 0; j<n; j++)
            if( a[i] == b[j])
                x = 0; //Se x = 0, há interseção.
        if(x == 1){
            vazio = 0;
            printf(" %d", a[i]);}
    }
    if(vazio == 1)
        printf(" vazio");
    return 0;
}
                