/*Voce recebe tres numeros para guardar, representados por A, B e C. No entanto, voce ainda nao
domina o uso de vetores e quer simplificar sua vida. Para facilitar a memorizacao dos tres numeros,
voce decide concatena-los em um unico valor. Voce precisa ser capaz de recuperar esses numeros
posteriormente, entao voce decide criar um padrao para armazena-los.
Voce decide armazenar os numeros de forma sequencial em um novo valor. O valor de A sera
guardado nos primeiros 2 bytes (menos significativos) da variavel que ira memorizar, B nos proximos
2 bytes e C nos 2 bytes seguintes.
Input
Voce recebera tres valores A, B e C, cada um representado por um tipo short unsigned int. Sua
tarefa e retornar a variavel que memoriza os tres numeros seguindo o algoritmo dado.
A saıda deve ser o valor resultante da concatenacao dos tres numeros, seguido de uma quebra de linha.*/

#include <stdio.h>
int main(){
   short unsigned int A, B, C;
   unsigned long long memoria = 0;
   //Ler tres numeros inteiros.
   scanf("%hu %hu %hu", &A, &B, &C);
   //Memoria recebe C.
   memoria = C;
   //Operacao bitshift(16 bits para a esquerda). 
   memoria = memoria << 16;
   //Concatena-se B.
   memoria = memoria + B;
   //Operacao bitshift(16 bits para a esquerda). 
   memoria = memoria << 16;
   //Concatena-se A.
   memoria = memoria + A;
   //Imprimi um numero unsigned long long.
   printf("%llu", memoria);
   return 0;
}
   