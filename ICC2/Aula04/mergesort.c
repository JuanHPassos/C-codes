//Receba um vetor de tamanho n e ordene-o.
#include<stdio.h>
#include<stdlib.h>

void conquistar(int *vet, int l, int meio, int r);
void dividir(int *vet, int l, int r);

int main(){
    int n, *vet = NULL;
    scanf("%d", &n);

    vet = (int *) malloc(sizeof(int)*n);
    if(vet == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    dividir(vet, 0, n-1);

    for(int i = 0; i<n; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}
//Função que divide o vetor até ter tamanho 1.
void dividir(int *vet, int l, int r){
    if(l<r){
        int meio = (l+r)/2;

        dividir(vet, l, meio);
        dividir(vet, meio+1, r);

        conquistar(vet, l, meio, r);

    }
}
//Função que junta as divisões do vetor, ordenando-os.
void conquistar(int *vet, int l, int meio, int r){
    int tam1 = meio-l+1;
    int tam2 = r-meio;

    int L[tam1];
    int R[tam2];

    for(int i = 0; i < tam1; i++){
        L[i] = vet[i+l];
    }

    for(int i = 0; i < tam2; i++){
        R[i] = vet[i+meio+1];
    }

    int posL = 0, posR = 0, posVet = l;

    while(posL < tam1 && posR < tam2){
        if(L[posL] < R[posR]){
            vet[posVet] = L[posL];
            posL++;
        }
        else{
            vet[posVet] = R[posR];
            posR++;
        }
        posVet++;
    }

    while(posL < tam1){
        vet[posVet] = L[posL];
        posVet++;
        posL++;
    }
    while(posR < tam2){
        vet[posVet] = R[posR];
        posVet++;
        posR++;
    }
}
