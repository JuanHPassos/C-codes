/*Implemente um programa em C que recebe um vetor de inteiros ate receber o numero ”1”(seu
vetor nao deve armazenar o numero 1). em seguida, seu programa recebera um comando a,b ou c.
O comando ’a’deve ordenar seu vetor e imprimi-lo, o comando ’b’ deve imprimir apenas os numeros
do vetor que pertencem a sequencia de fibonacci (as entradas nao serao maiores que 2000), o comando
c devera imprimir o equivalente de cara numero do vetor como caractere, e depois imprimir o mesmo
caractere como maiusculo (ToUpper). Caso seu programa receba qualquer outro comando, deve printar
”comando inexistente”. seguidos por uma quebra de linha.*/

#include <stdio.h>
#include <ctype.h>
int main(){
    int tam, v[100000] = {0}, maior = -1 , menor = 2010, troc = 0, fibonacci[100000];
    char x;
    //Ler numeros até o valor 1.
    for(tam = 0; ; tam++){
        scanf("%d", &v[tam]);
        if(v[tam] == 1)
            break;
        if(menor > v[tam])
            menor = v[tam];
        if(maior < v[tam])
            maior = v[tam];
    }
    //Ler o comando.
    scanf(" %c", &x);
    switch(x){
        case 'a':
            printf("vetor ordenado:");
            //Ordena o vetor.
            for(int i = 0; i < tam-1; i++)
                for(int j = 0; j < tam-i-1; j++){
                    if(v[j] > v[j+1]){
                        troc = v[j];
                        v[j] = v[j+1];
                        v[j+1] = troc;}
                }        
            //Imprimir o vetor ordenado.
            for(int i = 0; i<tam; i++)
                printf("%d ", v[i]);
            break;
        
        case 'b':
            int i;
            printf("Numeros de Fibonacci:");
            //Inicio da sequencia.
            fibonacci[0] = 0;
            fibonacci[1] = 1;
            fibonacci[2] = 2;
            //Criando a sequencia de fibonnacci e guardando no vetor, até o maior numero digitado.
            for(i = 3; fibonacci[i] <= maior; i++)
                fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
            //Comparando o vetor de fibonnacci com a vetor dos numeros digitados, fixando-se um numero do vetor e percorrendo a sequencia. 
            for(int j = 0; j < tam; j++)
                for(int k = 0; k < i; k++)
                    //Caso encontre, printa-se o numero e continua o processo até o final do vetor.
                    if(fibonacci[k] == v[j])
                        printf("%d ", v[j]);
            break;    
        
        case 'c':
            printf("Vetor maiusculo:");
            for(int i = 0; i<tam; i++)
                //Toupper: minusculo -> maiusculo. Obs: o numero representa o valor do caracter na tabela ASCII.
                printf("%c ", toupper(v[i]));
            break;
        
        default:
            printf("Comando inexistente");
    }
    return 0;
}
