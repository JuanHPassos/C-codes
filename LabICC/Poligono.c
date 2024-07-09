/*Implemente um programa em C que leia na entrada padrao de texto um inteiro n e um double l.
O programa deve imprimir na tela a area de um polıgono regular com n lados de tamanho l, seguidos
por uma quebra de linha.
Utilize a biblioteca math.h neste exercıcio.
Defina π = 3.14159265358979323846*/

#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846
int main(){
     int n;
     double l, area;
     scanf("%d %lf", &n, &l);
     area = n*(l*l)/(4*(tan(pi/n)));//formula obtida atraves de substituicoes.
     printf("%lf\n", area);
     return 0;
}