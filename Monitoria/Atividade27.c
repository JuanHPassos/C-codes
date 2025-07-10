#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _discente
{
  char *nome;
  int nusp;
  char* assunto;
}DISCENTE;

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
  int quantDiscentes;
  scanf("%d", &quantDiscentes);

  DISCENTE *discente = (DISCENTE*) malloc(sizeof(DISCENTE)*quantDiscentes);
  if(discente == NULL)
  {
    printf("Erro ao alocar dinamicamente.\n");
    exit(1);
  } 

  for(int i = 0; i < quantDiscentes; i++)
  {
    discente[i].nome = LerString();
    scanf("%d", &discente[i].nusp);
    discente[i].assunto = LerString();
  }

  int inscricoesExtras;
  scanf("%d", &inscricoesExtras);

  quantDiscentes += inscricoesExtras;
  discente = (DISCENTE*) realloc(discente, quantDiscentes*sizeof(DISCENTE));

  for(int i = quantDiscentes - inscricoesExtras; i < quantDiscentes; i++)
  {
    discente[i].nome = LerString();
    scanf("%d", &discente[i].nusp);
    discente[i].assunto = LerString();
  }

  for(int i = 0; i < quantDiscentes; i++)
  {
    printf("Discente %d:\n", i + 1);
    printf("Nome: %s\n", discente[i].nome);
    printf("Número USP: %d\n", discente[i].nusp);
    printf("Assunto: %s\n\n", discente[i].assunto);
  }

  for(int i = 0; i < quantDiscentes; i++)
  {
    free(discente[i].nome);
    discente[i].nome = NULL;
    free(discente[i].assunto);
    discente[i].assunto = NULL;
  }

  free(discente);
  discente = NULL;

  return 0;
}