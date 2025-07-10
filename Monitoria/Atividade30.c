#include <stdio.h>
#include <stdlib.h>

typedef struct _pair
{
  int f; int s;
} PAIR;

int valid(int n, int m, int i, int j, char **grid)
{
  return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#');
}

int run(int n, int m, int i, int j, char **grid) 
{ 

  if (grid[i][j] == 'P') return 1;  
  
  char original = grid[i][j];
  grid[i][j] = '#';  
  int achou = 0;

  if (valid(n, m, i + 1, j, grid)) achou = run(n, m, i + 1, j, grid);
  if (!achou && valid(n, m, i - 1, j, grid)) achou = run(n, m, i - 1, j, grid);
  if (!achou && valid(n, m, i, j + 1, grid)) achou = run(n, m, i, j + 1, grid);
  if (!achou && valid(n, m, i, j - 1, grid)) achou = run(n, m, i, j - 1, grid);

  grid[i][j] = original;
  
  return achou;
}

int solve(int n, int m, char **matriz)
{
  PAIR pair; pair.f = -1; pair.s = -1; 
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    if(matriz[i][j] =='J') { pair.f = i; pair.s = j; break; }
  
  // Caso não encontre J.
  if(pair.f == -1) return 0;
  return run(n, m, pair.f, pair.s, matriz);
}

int main(void)
{
  int n, m;
  scanf("%d %d", &n, &m);

  // Aloca matriz dinamicamente
  char **matriz = (char**) malloc(n*sizeof(char*));
  char *linha = (char*) malloc(n*(m + 1)*sizeof(char));
  
  // Salva as linhas na matriz.
  for(int i = 0; i < n; i++) matriz[i] = linha + (m + 1)*i;

  // Ler entrada
  for(int i = 0; i < n; i++) scanf(" %s", matriz[i]);
  // for(int i = 0; i < n; i++) printf("%s\n", matriz[i]);
  
  int encontrou = solve(n, m, matriz);
  if(encontrou) printf("Sim\n");
  else printf("Nao\n");

  free(matriz);
  matriz = NULL;
  free(linha);
  linha = NULL;

  return 0;
}