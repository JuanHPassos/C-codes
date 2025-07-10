#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define INCREMENTO 50

typedef struct _pessoa
{
  char nome[50];
  int telefone;
  char cidade[50];
} PESSOA;

typedef struct _registro
{
  PESSOA *lista;
  int quantPessoas;
  int espaco;
} REGISTRO;

// Prototipação
void ADD(PESSOA novaPessoa, REGISTRO *registro);
REGISTRO SELECT(FILE *arquivo);
PESSOA _lerLinha(FILE *arquivo);
void ADD(PESSOA novaPessoa, REGISTRO *registro);

// Busca registros do arquivo para a memória
REGISTRO SELECT(FILE *arquivo)
{
  REGISTRO registro;
  registro.espaco = INCREMENTO;
  registro.lista = (PESSOA*) malloc(sizeof(PESSOA)*registro.espaco);
  registro.quantPessoas = 0;
  
  
  while (TRUE) 
  {
    PESSOA novaPessoa = _lerLinha(arquivo);
    if (novaPessoa.telefone == -1) break;
    
    ADD(novaPessoa, &registro);
  }

  return registro;
}

PESSOA _lerLinha(FILE *arquivo)
{
  PESSOA p;
  // Inicializa campos
  p.nome[0] = '\0';
  p.telefone = -1;
  p.cidade[0] = '\0';

  // Verifica se foi lido
  fscanf(arquivo, "%[^,], %d, %[^\n]\n", p.nome, &p.telefone, p.cidade);

  return p;
}

void ADD(PESSOA novaPessoa, REGISTRO *registro)
{
  registro->quantPessoas += 1;
  
  if(registro->quantPessoas >= registro->espaco)
  {
    registro->espaco += INCREMENTO; 
    registro->lista = (PESSOA*) realloc(registro->lista, (registro->espaco)*sizeof(PESSOA));
  }

  registro->lista[registro->quantPessoas - 1] = novaPessoa;
  return;
}

void DEL(REGISTRO * registro, int index)
{
  if(index >= registro->quantPessoas || index < 0) return;

  for (int i = index; i < registro->quantPessoas - 1; i++) 
    registro->lista[i] = registro->lista[i + 1]; 

  registro->quantPessoas--;
  return;
}

int main(void)
{
  char nomeArquivo[50];
  scanf("%s", nomeArquivo);

  
  FILE *fp = fopen(nomeArquivo, "r");
  if(fp == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  // Ler dados do arquovo.txt
  REGISTRO registro = SELECT(fp);

  fclose(fp);
  fp = NULL;

  char buffer[10];
  while (scanf(" %[^ ] ", buffer) > 0) {
    if (strcmp(buffer, "ADD") == 0) 
    {
      PESSOA novaPessoa = _lerLinha(stdin);
      ADD(novaPessoa, &registro);
    } 
    else if (strcmp(buffer, "DEL") == 0) 
    {
      int index;
      scanf(" %d", &index);
      DEL(&registro, index);
    }
  }

  for (int i = 0; i < registro.quantPessoas; i++) 
    printf("%s, %08d, %s\n", registro.lista[i].nome, 
                            registro.lista[i].telefone, 
                            registro.lista[i].cidade);

  free(registro.lista);
  registro.lista = NULL;
  
  return 0;
}