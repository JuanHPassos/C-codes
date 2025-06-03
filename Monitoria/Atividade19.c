#include<stdio.h>
#include<stdlib.h>

int readInt();
double readDouble();
void printDouble(double val);

int main(){
  int qTrabalhos = readInt();
  
  double *notas = (double*) malloc(qTrabalhos*sizeof(double));
  double somatorio = 0;
  for(int i = 0; i < qTrabalhos; i++){
    notas[i] = readDouble();
    somatorio += (1.0/(notas[i] + 1.0));
  }

  printDouble((qTrabalhos/somatorio) - 1);

  free(notas);
  notas = NULL;

  return 0;
}

int readInt(){
  int aux;
  scanf("%d", &aux);
  return aux;
}
double readDouble(){
  double aux;
  scanf("%lf", &aux);
  return aux;
}

void printDouble(double val){
  printf("%.2lf", val);
}