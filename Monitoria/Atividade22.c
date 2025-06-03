#include<stdio.h>
#include<stdlib.h>

#define NAIPE 4
#define VALORES 13

// Tabelas de referência
const char* valores_str[VALORES] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const char* naipes_str[NAIPE] = {"Copas", "Ouros", "Paus", "Espadas"};

int valorToIndice(char valor)
{
  switch (valor) 
  {
    case 'A': return 0;
    case '2': return 1;
    case '3': return 2;
    case '4': return 3;
    case '5': return 4;
    case '6': return 5;
    case '7': return 6;
    case '8': return 7;
    case '9': return 8;
    case '1': return 9;
    case 'J': return 10;
    case 'Q': return 11;
    case 'K': return 12;
    default: return -1;
  }
}

int naipeToIndice(char naipe)
{
  switch (naipe) 
  {
    case 'C': return 0;
    case 'O': return 1;
    case 'P': return 2;
    case 'E': return 3;
    default: return -1;
  }
}

int main()
{
  // 4 naipes(linhas) e 13 valores(colunas)
  // Ordem das linhas : C O P E
  // Ordem colunas: A, 2... K
  int cartas[4][13] = {0};
  int quantCartas;
  scanf("%d", &quantCartas);

  for(int i = 0; i < quantCartas; i++)
  {
    char buffer[4];
    scanf("%s", buffer);
    int indiceValor = valorToIndice(buffer[0]);
    int indiceNaipe;
    if(buffer[0] == '1') indiceNaipe = naipeToIndice(buffer[2]);
    else indiceNaipe = naipeToIndice(buffer[1]);
    
    if(indiceNaipe != -1 && indiceValor != -1)
      cartas[indiceNaipe][indiceValor]++;
  }

  // Impressão da tabela de frequências
  for (int i = 0; i < NAIPE; i++) {
    printf("Naipe: %s\n", naipes_str[i]);
    for (int j = 0; j < VALORES; j++) {
      printf("%s: %d\n", valores_str[j], cartas[i][j]);
    }
  }

  return 0;
}