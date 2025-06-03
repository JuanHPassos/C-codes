#include<stdio.h>

int main(){

  int n;
  scanf("%d", &n);

  double s = 1.0;
  int fat = 2;
  double termoAtual = 1.0; 
  while(fat <= n){
    termoAtual = termoAtual/fat;
    s += (fat%2 ? -1 : 1)*(termoAtual);
    fat++;
  }

  printf("%lf", s);

  return 0;
}