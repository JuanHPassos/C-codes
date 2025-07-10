#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *LerString(void)
{
  // Ler entrada
  char buffer[256];
  scanf(" %[^\n]", buffer);
  // Alocar espaço para armazenar conteudo
  int tamString = strlen(buffer);
  char *string = (char*) malloc(sizeof(char)*(tamString + 1));
  if(string == NULL)
  {
    printf("Erro ao alocar dinamicamente.\n");
    exit(1);
  }
  // Copiar conteudo no espalo alocado
  strcpy(string, buffer);
  string[tamString] = '\0';
  // Retornar endereço
  return string;
}

int main(void)
{
  char *menor = LerString();
  char *maior = LerString();

  if(strlen(menor) > strlen(maior))
  {
    char *aux = maior;
    maior = menor;
    menor = aux;
  }

  int tamanho = 0;
  int bytePrex = -1;
  for(int i = 0; i < strlen(maior); i++)
  {
    int tam = 0;
    for(int j = 0; j < strlen(menor); j++)
    {
      if(maior[i + j] == menor[j]) tam++;
      else break;
    }

    if(tam > tamanho)
    {
      tamanho = tam;
      bytePrex = i;
    }
  }

  if(tamanho == 0) printf("%d", tamanho);
  else
  {
    printf("%d ", tamanho);
    for(int i = 0; i < tamanho; i++) printf("%c", maior[bytePrex+i]);
  }

  free(maior);
  free(menor);

  return 0;
}