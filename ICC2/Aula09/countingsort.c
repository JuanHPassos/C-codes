/*Conta-se o numero de vezes que cada elemento ocorre no arranjo, ou seja,
se há k elementos, o elementos analisado sera inserido no espaço k+1.
Pega-se o maior elemento do vetor, e cria-se um vetor auxiliar que vai guardar a quantidade do numero nele,
ou seja, faz-se um estoque desses numeros, que serão inseridos no vetor original
Esse algoritmo é maior eficiente pois nao há comparação entre os elementos,
pois se faz um estoque, varrendo os vetores e permitindo uma complexidade O(n).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void coutingsort(int *vet,int n);

int main(){
    int n, *vet;
    scanf("%d", &n);
    vet = (int*) malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    coutingsort(vet, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;

}

// Ordena o vetor pelo metodo de contagem de menores.
void coutingsort(int *vet,int n){
    // Procura maior elemento do vetor.
    int maior = -1;
    for(int i = 0; i < n; i++){
        if(vet[i] > maior) maior = vet[i];
    }
    // Aloca um estoque para os numeros.
    int x[maior+1];
    memset(x, 0, (maior+1)*sizeof(int));
    // Preenche o estoque.
    for(int i = 0; i < n; i++){
        x[vet[i]]++;
    }

    // Ajusta para o vetor original
    int j = 0; // Index para percorrer o vetor original
    // Percorre ate o maior elemento.
    for(int i = 0; i < maior + 1; i++){
        // Descarrega o estoque(maximo O(n) durante todo o for).
        while(x[i] > 0){
            vet[j++] = i;
            x[i]--;
        }
    }
    // Complexidade desse for, é O(maior + 1 + n), pois percorre o vetor maior + 1,
    // e descarrega no maximo n elementos durante todo o for.
}
