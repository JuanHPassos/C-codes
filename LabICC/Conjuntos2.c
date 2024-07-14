/*Implemente um programa em C que leia 2 vetores (lendo o tamanho do vetor antes), 
os vetores sao compostos por numeros inteiros(positivos e negativos) nao ordenados, 
os vetores devem ser compreendidos como conjuntos A e B.
O programa DEVE conter uma funcao que retorna o conjunto A uniao B e outra que retorne
o conjunto (A uniao B) - (A interseccao B), os vetores retornados devem ocupar somente o espaco
estritamente necessario. Em seguida, o programa deve imprimir os conjuntos como mostrado no
exemplo abaixo.*/

#include<stdio.h>
#include<stdlib.h>
void sort(int *p, int n);
/*Funcao para organizar de forma crescente o vetor - sort*/
void sort(int *p, int n){
    int temp, ord;
    for(int i = 0; i<n-1; i++){
        ord = 0;
        for(int j = 0; j<n-1-i; j++)
            if(p[j] > p[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                ord =  1;
            }
        if(ord == 0)
            break;
    }
}
/*Funcao que une os elementos do conjunto A e B e retorna o vetor uniao - uniao*/
int *uniao(int *A, int Atam, int *B, int Btam, int *ABtam){
    int *uni, inter;//Uni = vetor uniao.
    int Utam;//Tamanho do vetor uniao.
    //Se A e vazio
    if(Atam == 0){
        //E B e vazio, o vetor uniao e vazio.
        if(Btam == 0){
            *ABtam = 0;
            return NULL;
        }
        //O vetor uniao e o vetor B.
        else{
            *ABtam = Btam;
            uni = (int *) malloc(Btam*sizeof(int));
            for (int i = 0; i < Btam; i++) 
                uni[i] = B[i];
            return uni;
        }
    }  
    //Se B e vazio, o vetor uniao e o vetor A.
    else if(Btam == 0){
       *ABtam = Atam;
        uni = (int *) malloc(Atam*sizeof(int));
        for (int i = 0; i < Atam; i++) 
            uni[i] = A[i];
        return uni;
    }
    //Caso nem A e B seja vazio.
    else{
    *ABtam = 0;//Tamanho do vetor uniao.
    Utam = Atam + Btam;//Tamanho maximo do vetor uniao.
    uni = (int *) malloc((Utam)*sizeof(int));
    //Preenche-se vetor uniao com os elementos de A.
    for(int i = 0; i< Atam; i++){
        uni[i] = A[i];
        (*ABtam)++;}
    //Tamanho do vetor recebe o tamanho atual que ele ocupa.
    Utam = *ABtam;
    //Percorre-se os valores de B e adiciona os valores que ainda nao estao no vetor uniao.
    for(int i = 0; i<Btam; i++){
        inter = 0;//Variavel que verifica se ha interseccao.
        //Verifica-se se ha uniao, procurando o valor de B no vetor uniao.
        for(int j = 0; j< Utam; j++){
            if(B[i] == uni[j]){
                inter = 1;//Ha interseccao.
                break;
            }  
        } 
        //Se nao houver interseccao, adiciona-se o valor no vetor uniao.
        if(inter == 0){
            uni[*ABtam] = B[i];
            (*ABtam)++;
        }  
    }
    //Reajusto o tamanho do vetor para a quantidade de elementos presentes no vetor.
    uni = (int *) realloc(uni, *(ABtam)*sizeof(int));
    //Retorno o vetor em que esta os elementos.
    return uni;
    }
} 
/*Funcao para formar o conjunto uniao AB - interseccao AB - outinter*/
int *outinter(int *A, int Atam, int *B, int Btam, int *f2tam){
    int tam, *erase, rep = 0, *resp;//Tamanho, vetor de repetidos, quant. de elementos de interseccao e vetor resposta.
    //Se A e vazio
    if(Atam == 0){
        //E B e vazio, esse conjunto tambem eh vazio.
        if(Btam == 0){
            *f2tam = 0;
            return NULL;
        }
        //Esse conjunto e igual ao conjunto  B.
        else{
            *f2tam = Btam;
            resp = (int *) malloc(Btam*sizeof(int));
            for (int i = 0; i < Btam; i++) 
                resp[i] = B[i];
            return resp;
        }
    }
    //Se B e vazio, o conjunto e igual ao conjunto A.
    else if(Btam == 0){
       *f2tam = Atam;
        resp = (int *) malloc(Atam*sizeof(int));
        for (int i = 0; i < Atam; i++) 
            resp[i] = A[i];
        return resp;
    }
    //Caso nenhum dos conjuntos seja vazio.
    else{
    //Tamanho maximo do vetor
    tam = Atam + Btam;
    //Aloco dinamicamente o vetor resposta e o vetor de elementos da interseccao.
    resp = (int *) malloc(tam*sizeof(int));
    erase = (int *) malloc(tam*sizeof(int));
    //Comparo os dois conjuntos, guardando no vetor erase os elementos de interseccao
    for(int i = 0; i<Atam; i++){
        int inter = 0;//Variavel que verifica interseccao.
        for(int j = 0; j< Btam; j++)
            if(A[i] == B[j]){
                inter = 1;//Houve interseccao.
                erase[rep] = A[i];
                rep++;
                break;
            }
        //Se nao houver interseccao, adiciono o elemento A no vetor resposta.
        if(inter == 0){
            resp[*f2tam] = A[i];
            (*f2tam)++;
        }
    }
    //Verifico agora os elementos de B que nao sao da interseccao e os adiciono ao vetor resposta.
    for(int i = 0; i<Btam; i++){
        int fora = 0;//Variavel que verifica se e um elemento do vetor resposta.
        for(int j = 0; j<rep; j++)
            if(erase[j] == B[i]){
                fora = 1;
                break;
            }
        if(fora == 0){
            resp[*f2tam] = B[i];
            (*f2tam)++;
        }
    }
    //Liberacao de memoria.
    free(erase);
    erase = NULL;
    //Reajuste do tamanho do vetor resposta.
    resp = (int *) realloc(resp, (*f2tam)*sizeof(int));
    //Retorno do vetor.
    return resp;
    }
}

int main(){
    /*A = Vetor de A, B = Vetor de B, Atam = tamanho de A, Btam = tamanho de B
    ABtam = tamanho de AB, f2tam = tamanho do vetor uniao A e B menos interseccao A e B*/
    int *A, *B, Atam, Btam, *AB, ABtam = 0, f2tam = 0, *f2;
    
    scanf("%d", &Atam);    
    //Alocacao dinamica de A.
    A = (int*) malloc(Atam*sizeof(int));
    for(int i = 0; i<Atam; i++)
        scanf("%d", &A[i]);
    //Organizacao do vetor A em ordem crescente.
    sort(A, Atam);
    printf("conjunto A:");
    if(Atam == 0)
            printf(" vazio\n");
    else{
        for(int i = 0; i<Atam; i++)
            printf(" %d", A[i]);
        printf("\n");
    }
    scanf("%d", &Btam);
    //Alocacao dinamica do vetor B.
    B = (int*) malloc(Btam*sizeof(int));
    for(int i = 0; i<Btam; i++)
        scanf("%d", &B[i]);
    //Organizacao do vetor B em ordem crescente.
    sort(B, Btam);
    printf("conjunto B:");
    if(Btam == 0)
        printf(" vazio\n");
    else{
        for(int i = 0; i<Btam; i++)
            printf(" %d", B[i]);
        printf("\n");
    }
    //Uniao dos elementos do conjunto A e B.
    AB = uniao(A, Atam, B, Btam, &ABtam); 
    //Organiza-se o vetor uniao
    sort(AB, ABtam);
    //Imprimi-se o vetor uniao A e B.
    printf("A uniao B:");
    if(ABtam == 0)
        printf(" vazio\n");
    else{
        for(int i = 0; i<ABtam; i++)
            printf(" %d", AB[i]);
        printf("\n");
    }
    //Forma-se o conjunto uniao AB - interseccao AB.
    f2 = outinter(A, Atam, B, Btam, &f2tam);
    //Organiza-se o vetor A uniao B - A interseccao B.
    sort(f2, f2tam);
    printf("(A uniao B) - (A interseccao B):");
    if(f2tam == 0)
        printf(" vazio\n");
    else{
        for(int i = 0; i<f2tam; i++)
            printf(" %d", f2[i]);
        printf("\n");
    }
    //Liberacao de memoria.
    if(Atam != 0)
        free(A); A = NULL;
    if(Btam != 0)
        free(B); B = NULL;
    if(ABtam != NULL)
        free(AB); AB = NULL;
    if(f2tam != NULL)
        free(f2); f2 = NULL;

    return 0;
}
        
