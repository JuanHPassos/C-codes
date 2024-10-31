#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 10000;  // Número de cartas
    int max_valor = 1000000000;    // Valor máximo para os valores das cartas

    // Inicializando o gerador de números aleatórios
    srand(time(NULL));

    // Abrir um arquivo para gravar os dados de teste
    FILE *fout = fopen("input4.in", "w");
    if (fout == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Gravar o número de cartas e a carta buscada no arquivo
    fprintf(fout, "%d\n", tamanho);

    // Gerar os valores das cartas de forma aleatória
    for (int i = 0; i < tamanho; i++) {
        int numero = rand() % max_valor;
        fprintf(fout, "%d ", numero);
    }

    // Fechar o arquivo
    fclose(fout);

    printf("Caso de teste gerado no arquivo 'input.in'.\n");

    return 0;
}
