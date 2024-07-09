/*Implemente um programa em C que leia na entrada padrao de texto um numero inteiro n. Suponha
que existam 3 vetores 1 de tamanho n, um formado por chars, outro por ints e outro por doubles.
O programa deve imprimir na tela o espaco ocupado (em bytes) por cada um dos vetores, seguidos
por uma quebra de linha.*/

#include <stdio.h>
int main(){
    long unsigned n;
    scanf("%lu", &n);
    printf("char: %lu\n", n*sizeof(char));//tamanho que o vetor ocupa, é o tipo vezes o tamanho n.
    printf("int: %lu\n", n*sizeof(int));
    printf("double: %lu\n", n*sizeof(double));
    
    return 0;
    
}