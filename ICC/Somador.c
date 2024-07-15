/*Voce recebe dois valores em binario, sua tarefa e determinar a soma desses valores em decimal.
Input
Na primeira linha, voce recebera dois valores ”N” e ”M” que descrevem o numero de bits de cada
valor que sera dado.
Na linha seguinte serao dados ”N” numeros que descrevem a representacao em binario do primeiro
valor. Cada numero sera 0 ou 1 e descrevera o valor do bit na posicao dada.
Na linha seguinte serao dados ”M” numeros que descrevem a representacao em binario do segundo
valor, com a representacao igual ao primeiro numero.
Vale ressaltar que a entrada de ambos numeros sera dada come¸cando pelo bit mais significativo.
Veja os exemplos de entrada e saıda para melhor compreensao.
A saıda deve ser seguida de uma quebra de linha.
0 ≤ N ≤ 30 e 0 ≤ M ≤ 30*/

#include <stdio.h>
int main(){
    int N, M, soma = 0, acm, pot = 1;
    //Ler tamanho dos numeros em bits.
    scanf("%d %d", &N, &M);
    //Laco para pegar os bits de um numero em binario.
    for(int i = 0; i<N; i++){
        //Ler o bit.
        scanf("%d", &acm);
        //Calcular a potencia do bit de acordo com a casa binaria.(Ex: quarto bit -> pot = 8).
        for(int j = 0; j<(N-1)-i; j++)
            pot = pot * 2;
        //Multiplicar o bit pela potencia e adiciona-lo no total da soma dos numeros.
        soma = soma + acm*pot;
        pot = 1;
    }
    //Repetir o mesmo processo para o numero M.
    for(int i = 0; i<M; i++){
        scanf("%d", &acm);
        for(int j = 0; j<(M-1)-i; j++)
            pot = pot * 2;
        soma = soma + acm*pot;
        pot = 1;
        
    }
    //Imprimir a soma desses dois numeros.
    printf("%d", soma);   
        
    return 0;    
}