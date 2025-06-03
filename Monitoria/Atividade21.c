#include<stdio.h>
#include<stdlib.h>

char *lerString(int n)
{
  char *string = (char*) malloc((n + 1)*sizeof(char));
  scanf("%s", string);
  return string;
}

float calculaNota(int quantPerg, char *gabarito, char *respsAluno)
{
  int respsCertas = 0; 
  for(int i = 0; i < quantPerg; i++)
    if(gabarito[i] == respsAluno[i]) respsCertas++;
    
  return ((respsCertas/(float) quantPerg) * 10.0);
}


int main()
{
  int quantPerg, quantAlunos; 
  scanf("%d %d", &quantPerg, &quantAlunos);
  char *gabarito = lerString(quantPerg);

  for(int i = 0; i < quantAlunos; i++)
  {
    char *respsAluno = lerString(quantPerg);
    float nota = calculaNota(quantPerg, gabarito, respsAluno);
    printf("%.2f\n", nota);
    // Desalocar memória utilizada
    free(respsAluno);
    respsAluno = NULL;
  }

  return 0;
}