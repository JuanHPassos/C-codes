#include<stdio.h>
#include<stdlib.h>

int main(){
  int *inteiro1 = (int*)malloc(sizeof(int)); // [inteiro] 
  int *inteiro2 = (int*)malloc(sizeof(int)); 
  
  // Ponteiro guarda endereço da variavel;
  scanf("%d %d", inteiro1, inteiro2);

  printf("%d %d\n", *inteiro1, *inteiro2);

  // A = valor inicial de inteiro1
  // B = valor inicial de inteiro2
  // C valor atual do inteiro1
  // D valor atual do inteiro2
  // C = A + B
  *inteiro1 = *inteiro1 + *inteiro2;
  // D = C - B = (A+B) - B = A
  *inteiro2 = *inteiro1 - *inteiro2;
  // D = C - D = (A+B) - A = B
  *inteiro1 = *inteiro1 - *inteiro2;

  printf("%d %d", *inteiro1, *inteiro2);

  // Desalocação de memória
  free(inteiro1);
  inteiro1 = NULL;
  free(inteiro2);
  inteiro2 = NULL;
}