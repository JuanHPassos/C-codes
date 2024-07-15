/*Sera dado um numero ”N”e seu papel e retornar quantos zeros a direita o numero N! possui.
Por exemplo, caso N = 10, terıamos 10! = 3628800, assim a resposta seria 2.
Ja no caso de N = 4, terıamos 4! = 24, portanto a resposta seria 0.*/

#include <stdio.h>
int main(){
    int n, zeros = 0, i;
    scanf("%d", &n);
     /*Nota-se que o que faz os zeros aparecerem no fatorial é a multiplicação de um 5 com um 2.
       Como há geralmente mais fatores 2 do que 5 no fatorial de um número, 
       basta contar quantos fatores 5 estão presentes.
       Esse laço de repetição conta as quantidades de múltiplos de 5 no número n. */
    for (i = 5; i<=n; i = i * 5)
        zeros += (n/i);
    printf("%d\n", zeros);
    return 0;
}