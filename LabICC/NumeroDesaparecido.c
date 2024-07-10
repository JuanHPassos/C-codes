/*Em um certo dia voce se depara com uma lista muito interessante de numeros entre 1,2,. . . ,N na
qual, apos muita observacao, voce percebe que ha exatamente um numero faltando, isso e, nao esta presente.
Tendo em vista sua curiosidade inata, voce se pergunta qual sera o numero que esta faltando. Seu
dever e desenvolver um programa em C para descobrir qual e esse numero.*/

#include <stdio.h>
/*Funcao para ordernar o vetor - sort*/
void sort(int n, int *p){
    int ord;//Variavel de controle para saber se o vetor ja esta ordenado.
    //N-1, pois há um valor faltando.
    for(int i = 0; i< n-1; i++){
        ord = 0;//Simboliza vetor ordenado.
        for(int j = 0; j < n-i-2; j++){
            if(p[j] > p[j+1]){
                //Swap com 2 variaveis.
                p[j] = p[j] + p[j+1];
                p[j+1] = p[j] - p[j+1];
                p[j] = p[j] - p[j+1];
                //Houve ordenacao.
                ord = 1;}
            }
        //Se o vetor ja estiver ordenado, encerra a ordenacao.
        if(ord == 0)
            break;
    }
    return;
}
/*Funcao para identificar o numero desaparecido - num*/
int num(int n, int *p){
    //Parametros: tamanho do vetor e ponteiro para o inicio do vetor.
    for(int i = 1; i <= n; i++){
        //Caso o numero que o ponteiro aponte nao seja o numero que deveria(*p != i), retorna-se esse numero, pois ele é o que esta faltando.
        if( *p != i )
            //Como sempre haverá, um numero faltando, a funcao sempre encerrara nesse return.
            return i;
        //Caso contrario, move-se o ponteiro para a proxima casa.
        p++;
    }
}
/*Funcao principal - main*/
int main(){
    int n;//Tamanho do vetor que sera preenchido por numeros.
    scanf("%d", &n);
    int v[n];
    //Preenchimento do vetor que tera um numero faltando.
    for(int i = 0; i<n-1; i++)
        scanf("%d", &v[i]);
    //Ordenacao do vetor.
    sort(n, v);
    printf("Numero desaparecido: %d", num(n, v));
    return 0;
}