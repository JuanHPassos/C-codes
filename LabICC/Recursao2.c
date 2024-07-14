/*Faça um programa que gere TODAS as palavras (de 'a' --- 'z' - minúsculas) de M caracteres.

A entrada é o valor de M. A saída, todas as palavras.. 1 por linha !!!!*/

#include <stdio.h>
#include <stdlib.h>
//Modularizacao das funcoes.
void gerarPalavras(char *prefixo, int m, int nivel);
void gerarTodasPalavras(int m);
void gerarPalavras(char *prefixo, int m, int nivel) {
    if (nivel == m) {
        // Quando atingimos o comprimento desejado, imprimimos a palavra gerada
        printf("%s\n", prefixo);
        return;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        // Adiciona a letra atual ao prefixo e chama recursivamente para o próximo nível
        prefixo[nivel] = c;
        gerarPalavras(prefixo, m, nivel + 1);
        /*nota-se que quando atinge o tamanho da palavra, troca-se a letra pela proxima, ou seja, apos printar aa(...), ele volta por recursão
        para esse for na ultima letra, e adiciona ate bater o z, após isso, volta-se para a penultima chamada(por exemplo, m=2, o primeiro "a", vira b),
        e inicia-se o ciclo novamente a partir dessa letra(m=2, ba...bz).*/
    }
}

void gerarTodasPalavras(int m) {
    // Aloca memória para armazenar a palavra de comprimento M + 1 (para o caractere nulo)
    char *prefixo = (char *)malloc((m + 1) * sizeof(char));
    if (prefixo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    // Adiciona o caractere nulo ao final da string
    prefixo[m] = '\0';

    // Inicia a geração de palavras
    gerarPalavras(prefixo, m, 0);

    // Libera a memória alocada
    free(prefixo);
}

int main() {
    int m;

    // Le o comprimento da palavra
    scanf("%d", &m);

    // Gera todas as palavras de comprimento M
    gerarTodasPalavras(m);

    return 0;
}
