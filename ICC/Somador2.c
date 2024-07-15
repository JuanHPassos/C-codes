/*Na primeira linha, voce recebera dois valores ”N”e ”M” que descrevem o numero de bits de cada
valor que sera dado.
Na linha seguinte serao dados ”N” numeros que descrevem a representacao em binario do primeiro
valor. Cada numero sera 0 ou 1 e descrevera o valor do bit na posicao dada.
Na linha seguinte serao dados ”M” numeros que descrevem a representacao em binario do segundo
valor, com a representacao igual ao primeiro n´umero.
Vale ressaltar que a entrada de ambos n´umeros sera dada come¸cando pelo bit mais significativo.
Veja os exemplos de entrada e saıda para melhor compreensao.
A saıda deve ser seguida de uma quebra de linha.
Para esse exercıcio voce deve utilizar vetor.
ATENC¸AO: Voce NAO deve usar o operador ”[]” para acessar a posicao de um vetor, por exemplo,
nao faca: v[i].
0 ≤ N ≤ 30 e 0 ≤ M ≤ 30*/

#include <stdio.h>
/*Funcao que calcula potencia - pow*/
int pow(int base, int exp){
    int pot = 1;
    for(int i = 0; i < exp; i++){
        pot *= base;
    }
    return pot;
}
/*Funcao principal - main*/
int main(){
    int N, M, v[70], *p, num1 = 0, num2 = 0;//Declaro vetor de 70 espacos que comporta o numero maximo dos dois numeros em bits.
    p = v;//p recebe o endereco da primeira posicao de v.
    scanf("%d %d", &N, &M);
    //Calcula o valor do numero 1 em decimal.
    for(int i = 0; i<N; i++){
        scanf("%d", p);
        num1 += (*p)*pow(2, N-1-i);
        p++;
    }    
    //Calcula o valor do numero 2 em decimal.
    for(int i = 0; i<M; i++){
        scanf("%d", p);
        num2 += (*p)*pow(2, M-1-i);
        p++;
    }
    //Imprime a soma dos dois numeros.
    printf("%d", num1+num2);
    return 0;
}