#include<stdio.h>

void swap(int *a, int *b);

int main(void){
  int canal1, canal2;
  scanf("%d %d", &canal1, &canal2);
  int *controle1 = &canal1, *controle2 = &canal2;
  swap(controle1, controle2);
  printf("%d %d", *controle1, *controle2);
}

void swap(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
  return;
}