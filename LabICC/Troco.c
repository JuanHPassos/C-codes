/*Dona Lucineia e dona de um mercadinho no centro de Sao Carlos e, como gostaria de nao precisar
usar calculadora para dar o troco dos clientes, ela chamou VOCE para desenvolver um programa em
C que ira fornece-la o troco em notas e moedas rapidamente. Com isso, seu programa ira receber
uma entrada de um valor inteiro em reais e determinar a quantidade mınima de notas e moedas
necessarias para representar esse valor.*/

#include <stdio.h>
int main(){
    int valor, a, b, c, d, e, f, g, h;
    scanf("%d", &valor);
    a = valor/200;
    valor = valor%200;
    b = valor/100;
    valor = valor%100;
    c = valor/50;
    valor = valor%50;
    d = valor/20;
    valor = valor%20;
    e = valor/10;
    valor = valor%10;
    f = valor/5;
    valor = valor%5;
    g = valor/2;
    valor = valor%2;
    h = valor/1;
    valor = valor%1;
    printf("%d nota(s) de R$ 200\n", a);
    printf("%d nota(s) de R$ 100\n", b);
    printf("%d nota(s) de R$ 50\n", c);
    printf("%d nota(s) de R$ 20\n", d);
    printf("%d nota(s) de R$ 10\n", e);
    printf("%d nota(s) de R$ 5\n", f);
    printf("%d nota(s) de R$ 2\n", g);
    printf("%d moeda(s) de R$ 1\n", h);
    return 0;
}
    /*Solucao com vetor e estrutura de repetição:
    int valor, troco[8];
    int notas[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    scanf("%d", &valor);
    for(int i = 0; i<8; i++){
        troco[i] = valor/notas[i];
        valor = valor%notas[i];
    }
    for(int i = 0; i<7; i++){
        printf("%d nota(s) de R$ %d\n", troco[i], notas[i]);
    }
    printf("%d moeda(s) de R$ 1\n", troco[7]);
    return 0;
}*/


