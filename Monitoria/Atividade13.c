#include<stdio.h>

int **selecCartao(int **livro1, int **livro2,int **livro3, int livro){
  switch (livro)
  {
  case 1:
    return livro1;
    break;
  case 2:
    return livro2;
    break;
  case 3:
    return livro3;
    break;
  
  default:
    return NULL;
    break;
  } 
}

int main(void){
  int livro1, livro2, livro3;
  scanf("%d %d %d", &livro1, &livro2, &livro3);

  int *pLivro1 = &livro1, 
      *pLivro2 = &livro2,
      *pLivro3 = &livro3;
  
  for(int i = 1; i<=3; i++){
    int op;
    scanf("%d", &op);

    int **cartaoAtual = selecCartao(&pLivro1, &pLivro2, &pLivro3, i);
    
    switch (op)
    {
      case -1:
        *cartaoAtual = NULL;
        break;
      case 0:
        (**cartaoAtual)++;
        break;
      default:{
        int **trocaCartao = selecCartao(&pLivro1, &pLivro2, &pLivro3, op);
        int *aux = *cartaoAtual;
        *cartaoAtual = *trocaCartao;
        *trocaCartao = aux;
        break;
      }
    }
  }

  if(!pLivro1) printf("cartao1 -> Livro fora da estante\n");
  else printf("cartao1 -> %d\n", *pLivro1);
  
  if(!pLivro2) printf("cartao2 -> Livro fora da estante\n");
  else printf("cartao2 -> %d\n", *pLivro2);
  
  if(!pLivro3) printf("cartao3 -> Livro fora da estante\n");
  else printf("cartao3 -> %d\n", *pLivro3);

  return 0;
}