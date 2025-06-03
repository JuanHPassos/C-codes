#include<stdio.h>

int main(){
  int mes[31];
  int maiorVenda = -1;
  for(int i = 0; i < 31; i++){
    scanf("%d", &mes[i]);
    if(mes[i] > maiorVenda) 
      maiorVenda = mes[i];
  }
    
  printf("%d\n", maiorVenda);

  int diasComMaiorVenda[31];
  for(int i = 0; i < 31; i++) 
    diasComMaiorVenda[i] = 0;

  for(int i = 0; i < 31; i++){
    if(maiorVenda == mes[i]){
      int index = 0;
      while((i+1) > diasComMaiorVenda[index] && diasComMaiorVenda[index] != 0) index++;
      for(int j = 30; j >= index; j--) diasComMaiorVenda[j] = diasComMaiorVenda[j-1];
      diasComMaiorVenda[index] = (i+1);
    }
  }

  for(int i = 0; i < 31 && diasComMaiorVenda[i] != 0; i++)
    printf("%d\n", diasComMaiorVenda[i]);

  return 0;
}