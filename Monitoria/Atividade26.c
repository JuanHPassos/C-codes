#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
  int dia;
  int mes;
  int ano;
}DATA;

typedef struct hora{
  int hora;
  int min;
  int seg;
}HORA;

typedef struct atividade{
  DATA data;
  HORA hora;
  char *desc_ativ;
}ATIVIDADE;

typedef struct agenda{
  ATIVIDADE *atividade;
}AGENDA;


char *LerString()
{
  // Ler entrada
  char buffer[256];
  scanf(" %[^\n]", buffer);
  // Alocar espaço para armazenar conteudo
  int tamString = strlen(buffer);
  char *string = (char*) malloc(sizeof(char)*(tamString + 1));
  // Copiar conteudo no espalo alocado
  strcpy(string, buffer);
  string[tamString] = '\0';
  // Retornar endereço
  return string;
}

int main()
{
  int quantAtiv;
  scanf("%d", &quantAtiv);

  AGENDA agenda;
  agenda.atividade = (ATIVIDADE*) malloc(sizeof(ATIVIDADE)*quantAtiv);
  
  for(int i = 0; i < quantAtiv; i++)
  {
    scanf("%d", &agenda.atividade[i].data.dia);
    scanf("%d", &agenda.atividade[i].data.mes);
    scanf("%d", &agenda.atividade[i].data.ano);
    scanf("%d", &agenda.atividade[i].hora.hora);
    scanf("%d", &agenda.atividade[i].hora.min);
    scanf("%d", &agenda.atividade[i].hora.seg);
    agenda.atividade[i].desc_ativ = LerString();
  }

  for(int i = 0; i < quantAtiv; i++)
  {
    printf("%02d/%02d/%02d - %02d:%02d:%02d\n", agenda.atividade[i].data.dia,
                                                agenda.atividade[i].data.mes,
                                                agenda.atividade[i].data.ano,
                                                agenda.atividade[i].hora.hora,
                                                agenda.atividade[i].hora.min,
                                                agenda.atividade[i].hora.seg);
    printf("%s\n", agenda.atividade[i].desc_ativ);
  }

  for(int i = 0; i < quantAtiv; i++)
  {
    free(agenda.atividade[i].desc_ativ);
    agenda.atividade[i].desc_ativ = NULL;
  }

  free(agenda.atividade);
  agenda.atividade = NULL;

  return 0;
}