/*Torre de Hanoi !!! O 'jogo' torre de Hanoi consiste de 3 varetas (A, B e C), 
sendo que existem N discos perfurados em ordem de tamanho (o maior sempre sobre o menor) na vareta A. 
Seu objetivo é transferir todos os discos de A para B, usando a vareta C como auxiliar... 
O disco do topo é o disco 1, o segundo disco, 2.. e assim sucessivamente... Escreva um programa recursivo que faz isso.. 
Observe a saída do programa formatar a sua saída !!!*/

#include <stdio.h>

void moverDiscos(int n, char origem, char destino, char auxiliar) {
    // Caso base: mover um disco
    if (n == 1) {
        printf("Move disco 1 da pilha %c para a pilha %c\n", origem, destino);
        return;
    }

    // Passo 1: Mover n-1 discos da origem para a auxiliar, usando destino como auxiliar
    moverDiscos(n - 1, origem, auxiliar, destino);

    // Passo 2: Mover o disco n da origem para o destino
    printf("Move disco %d da pilha %c para a pilha %c\n", n, origem, destino);

    // Passo 3: Mover os n-1 discos da auxiliar para o destino, usando origem como auxiliar
    moverDiscos(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;

    // Le o número de discos
    scanf("%d", &n);

    // Chama a função para mover os discos
    moverDiscos(n, 'A', 'C', 'B');

    return 0;
}
