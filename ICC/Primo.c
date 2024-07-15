/*Serao dadas Q perguntas, em cada uma sera dado um valor N e voce deve retornar para cada uma
se o valor N e primo ou nao.
Input
1 ≤ Q ≤ 106
2 ≤ N ≤ 1500000*/

#include <stdio.h>
int main(){
    int q, n;
    //Ler numero de casos testes(pergutas).
    scanf("%d", &q);
    //Laco para realizar o processo de verificacao de primo q vezes.
    for(int i = 0; i<q; i++){
        //Verificacao para ver se e primo.(0 = nao eh primo).
        int primo = 1;
        //Leio o numero.
        scanf("%d", &n);
        //Verifico se os numero ate mais ou menos a sua raiz quadrada sao seus divisores(apos isso o numero nao tem mais divisores.)
        for(int j = 2; j*j<= n; j++){
            if(n%j == 0){
                //Se tiver divisores, entao nao eh primo.
                primo = 0;
                printf("Nao\n");
                break;}
        }   
        //Caso nao tenha nenhum divisor, ele eh primo.     
        if(primo == 1)
            printf("Sim\n");
    }
    return 0;    
}
