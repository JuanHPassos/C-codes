#include<stdio.h>
#include<stdlib.h>

void bubblesort(int n, int *vet){
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n -1 - i; j++){
      if(vet[j] > vet[j+1]){
        int aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux; 
      }
    }
  }
}

int main(){
  int n; 
  scanf("%d", &n);

  int *vet = (int*) malloc(n*sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d", &vet[i]);
  }

  bubblesort(n, vet);

  for(int i = 0; i < n; i++){
    printf("%d ", vet[i]);
  }

  return 0;
}