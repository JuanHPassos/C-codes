#include "gera_vetor.h"

int main () {
    int n;
    scanf ("%d",&n);
    int *v = cria_vetor(n);
    preenche_vetor_ordenado(v, n);
    imprime_vetor(v, n);
    apaga_vetor(&v);

    return EXIT_SUCCESS;
}