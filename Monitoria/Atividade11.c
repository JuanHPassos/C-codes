#include<stdio.h>

int main(void){
  int valorTesouro;
  scanf("%d", &valorTesouro);

  printf("Valor inicial do tesouro: %d\n", valorTesouro);

  int *mapa = &valorTesouro;

  printf("Valor do tesouro usando mapa: %d\n", *mapa);
  
  // Encontra tesouro com o mapa e adiciona 10.
  *mapa += 10;

  printf("Valor do tesouro usando mapa depois de adicionarmos 10 moedas: %d\n", *mapa);

  int **mapaDoMapa = &mapa;

  printf("Valor do tesouro usando mapa para o mapa: %d\n", **mapaDoMapa);

  // Acessa o mapa original, e com o mapa original, acessa o tesouro.
  **mapaDoMapa += 10; // Adiciona + 10 moedas ao tesouro.

  
  printf("Valor do tesouro usando mapa para o mapa depois de adicionarmos 10 moedas: %d\n", **mapaDoMapa);

  return 0;
}