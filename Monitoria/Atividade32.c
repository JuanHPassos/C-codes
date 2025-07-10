#include<stdio.h>

int main(void)
{
  int fibo[86];
  fibo[0] = 0;
  fibo[1] = 1;
  for(int i = 2; i < 86; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
  
  int nivel = -1;
  scanf("%d", &nivel);
  while(nivel != 0)
  {
    printf("%d\n", fibo[nivel]);
    scanf("%d", &nivel);
  }

  return 0;
}