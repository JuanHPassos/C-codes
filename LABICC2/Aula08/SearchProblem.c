#include<stdio.h>
#include<stdlib.h>

typedef struct carta_{
    int valor;
    int index;
}carta;

void dividir(carta *vet, int l, int r);
void conquistar(carta *vet, int l, int meio, int r);

int main(){
    int quant_cartas, carta_buscada;

    scanf("%d %d", &quant_cartas, &carta_buscada);

    carta *baralhos = (carta*) malloc(quant_cartas*sizeof(carta));

    for(int i = 0; i <  quant_cartas; i++){
        scanf("%d", &baralhos[i].valor);
        baralhos[i].index = i;
    }

    dividir(baralhos, 0, quant_cartas-1);

    int l = 0, r = quant_cartas-1;

    while(l < r){
        int mid = (l+r)/2;

        if(carta_buscada <= baralhos[mid].valor)
            r = mid;
        else    
            l = mid+1;
    }

    printf("%d", baralhos[l].index + 1);

    return 0;
}

void dividir(carta *vet, int l, int r){
    if(l<r){
        int meio = (l+r)/2;

        dividir(vet, l, meio);
        dividir(vet, meio+1, r);

        conquistar(vet, l, meio, r);

    }
}

void conquistar(carta *vet, int l, int meio, int r){
    int tam1 = meio-l+1;
    int tam2 = r-meio;

    carta L[tam1];
    carta R[tam2];

    for(int i = 0; i < tam1; i++){
        L[i] = vet[i+l];
    }

    for(int i = 0; i < tam2; i++){
        R[i] = vet[i+meio+1];
    }

    int posL = 0, posR = 0, posVet = l;

    while(posL < tam1 && posR < tam2){
        if(L[posL].valor <= R[posR].valor){
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
