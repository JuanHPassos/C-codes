#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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


int BuscarJogo(int l, int r, char *jogoBuscado, char **jogos)
{
  if(l > r) return -1;

  int aux = strcmp(jogoBuscado, jogos[(l+r)/2]); 

  if (aux < 0) return BuscarJogo(l, ((l+r)/2) - 1, jogoBuscado, jogos);
  else if(aux > 0) return BuscarJogo(((l+r)/2) + 1, r, jogoBuscado, jogos);
  else return (l+r)/2; 
}

int main(void)
{
  int n;
  scanf("%d\n", &n);

  char **jogos = (char**) malloc(n*sizeof(char*));
  for(int i = 0; i < n; i++) jogos[i] = LerString();
  
  char *jogoBuscado = LerString();
  int pos = BuscarJogo(0, n - 1, jogoBuscado, jogos);

  if(pos == -1)
  {
    printf("Jogo nao encontrado");
  } else {
    printf("Jogo encontrado na posição %d", pos);
  }

  // Desalocar memória
  free(jogoBuscado);
  jogoBuscado = NULL;

  for(int i = 0; i < n; i++) 
  {
    free(jogos[i]);
    jogos[i] = NULL;
  }

  free(jogos);
  jogos = NULL;
  

  return 0;
}
