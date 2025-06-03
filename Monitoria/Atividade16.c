#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n;
  scanf("%d", &n);

  char *palindromo = (char*) malloc((n+1)*sizeof(char));
  scanf(" %s", palindromo);
  palindromo[n] = '\0';

  int alf[26];
  for(int i = 0; i < 26; i++) alf[i] = 0;

  for(int i = 0; i < n; i++){
    alf[(palindromo[i]-'a')]++;
  }

  // A palavra não é mais necessária.
  free(palindromo);
  palindromo = NULL;

  // Armazena quantidade de caracteres impares
  int ehPalindromo = 0;
  for(int i = 0; i < 26 && ehPalindromo < 2; i++){
    if(alf[i]%2) ehPalindromo++;
  }

  if(ehPalindromo < 2) printf("Sim");
  else printf("Nao");

  return 0;
}