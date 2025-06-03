#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float quadrado (float num){
  return num*num;
}

float calculaDist(int n, float *xPontos, float *yPontos){
  float distancia = 0;
  for(int i = 0; i < n - 1; i++){
    distancia += sqrt(quadrado(xPontos[i + 1] - xPontos[i]) + quadrado(yPontos[i + 1] - yPontos[i]));   
  }
  return distancia;
}

int main(){
  int n;
  float *x, *y;
  scanf("%d", &n);

  x = (float*) malloc(n*sizeof(float));
  y = (float*) malloc(n*sizeof(float));
  
  for(int i = 0; i < n; i++){
    scanf("%f %f", &x[i], &y[i]);
  }

  float resp = calculaDist(n, x, y);
  printf("%.4f", resp);

  free(x);
  x = NULL;
  free(y);
  y = NULL;

}