/*
O algortimo de ordenação shellshort consiste na divisão do vetor em janelas formando subvetores com determinados elementos 
(escolhidos da forma i+k*janela, com i representando a quantidade de subvetores, e k iterações,
que garante que cada vetor tenha apenas 1 elemento da janela). 
Tais subvetores são ordenados 2 a 2, e no final do ciclo dessa janela, inicialmente valendo tamanho do vetor dividido por 2,
garante que os valores estarão em posições mais próximas da ordenação. Esse ciclo se repete até a janela possuir tamanho 1,
no qual ocorre a última ordenação caso necessária. No pior dos casos a complexidade é O(n²). 
No entanto, se o vetor vier ordenado, a janela irá se dividir log n vezes, e cada janela chegará ao vetor apenas uma vez. 
Logo no melhor dos casos a complexidade é 𝛀(n logn). 
Portanto, é valido afirmarmos que o shellsort será, em média, mais eficiente que o selection sort.
Interessante notar também que o fato de essa implementação não utilizar um TAD também contribui para que ela seja mais rápida.
*/

#include<stdio.h>
#include<stdlib.h>

void shellsort(int *vet, int n);

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    shellsort(vet, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;


}

void shellsort(int *vet, int n){
    //Dividir o vetor em janelas.
    for(int janela = n/2; janela > 0; janela /= 2){
        //Formar grupos de i até i+janela, sempre 2 a 2. 
        for(int i = janela; i < n ; i++){
            //Variavel para realizar o swap caso necessario.
            int troca = vet[i];
            //Index da posição final do vet[i] apos a troca.
            int j;
            //Troca elementos 2 a 2, até estar ordenado.
            for(j = i; j >= janela && troca < vet[j-janela]; j -= janela){
                vet[j] = vet[j - janela];
            }
            //Caso j tenha sido alterado, houve trocas. Sendo vet[j] nova posicao do numero troca.
            vet[j] = troca;
        }
    }
}


