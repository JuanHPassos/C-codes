#include<stdio.h>
#include<stdlib.h>

// Aloca string dinamicamente.
char *lerString()
{
  char buffer[100];
  fgets(buffer, 100, stdin);
  int tam = 0;
  while(buffer[tam] != '\n' && buffer[tam] != '\r' && buffer[tam] != '\0') tam++;
  // Aloca espaço para quantCaracteres + '\0'.
  char *string = (char*) malloc((tam + 1)*sizeof(char));
  string[tam] = '\0';
  // Copia caracteres do buffer para string.
  for(int i = 0; i < tam; i++) string[i] = buffer[i];
  return string;
}

int ehMinuscula(char caracter)
{
  return ('a' <= caracter && caracter <= 'z');
}

int ehMaiuscula(char caracter)
{
  return ('A' <= caracter && caracter <= 'Z');
}

void toUpperOrDownCase(char *palavra, int paraMaiuscula)
{
  // Somado ao minusculo, da maiusculo.
  // Subtraido ao maiusculo, da minusculo.
  int dif = 'A' - 'a';
  for(int i = 0; palavra[i] != '\0'; i++)
  {
    if(ehMinuscula(palavra[i]) && paraMaiuscula) palavra[i] += dif;
    else if(ehMaiuscula(palavra[i]) && !paraMaiuscula) palavra[i] -= dif;
  } 
}

int main(void)
{
  int quantMusicas;
  int paraMaiuscula;
  scanf("%d %d\n", &quantMusicas, &paraMaiuscula);

  for(int i = 0; i < quantMusicas; i++)
  {
    char *musica = lerString();
    toUpperOrDownCase(musica, paraMaiuscula);
    printf("%s\n", musica);
    free(musica);
    musica = NULL;    
  }

  return 0;
}