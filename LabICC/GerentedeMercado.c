/*Voce e um gerente de supermercado encarregado de administrar a entrada e saıda de produtos
do estoque. Para automatizar esse processo, voce desenvolvera um programa em C que registra as
transacoes diarias. O programa recebera como entrada o numero de produtos negociados no dia. Para
cada produto, o programa registrara o preco de compra, o preco de venda, a quantidade adquirida
e a quantidade vendida. Com base nesses dados, o programa deve calcular o lucro total do dia e
determinar o ındice do produto que gerou a maior receita junto a sua propria receita.*/

#include <stdio.h>
int main(){
    /*n = (numero de produtos negociados no dia), qadq = (quantidade adquirida), qvend = (quantidade vendida),
    indice = (ındice do produto que gerou a maior receita), pcompra = (preco de compra), pvenda = (preco de venda),
    lucro = (faturamento), prejuizo = (gastos), maior = (maior receita). */    
    int n, qadq, qvend, indice;
    float pcompra, pvenda, lucro, prejuizo, maior;
    //Ler quantidade de produtos.
    scanf("%d", &n);
    if(n == 0){
        printf("Sem atividades registradas hoje");
        return 0;
    }
    //Ler os dados de cada negociação e calcular o lucro e o prejuizo de cada item.
    for(int i = 1; i<=n; i++){
        scanf("%f %f %d %d", &pcompra, &pvenda, &qadq, &qvend);
        //Caso haja lucro e esse lucro seja maior que o lucro disponibilizado por um item anterior, guarda-se seu indice e receita.
        if(pvenda*qvend-pcompra*qadq > maior){
            maior = pvenda*qvend-pcompra*qadq;
            indice = i;
        }
        //Faturamento adquirido pelo item "i".
        lucro += pvenda*qvend;
        //Gasto adquirido pelo item "i".
        prejuizo += pcompra*qadq;
    }
    //Caso o faturamento diario seja maior que o gasto diario, imprimi-se o lucro.
    if(lucro > prejuizo)
        printf("lucro: %.2f\n", lucro-prejuizo);
    //Caso contrario, imprimi-se o prejuizo gerado.
    else 
        printf("prejuizo: %.2f\n", prejuizo-lucro);
    //Imprimi-se o indice do produto que gerou maior lucro e a sua respectiva receita.
    printf("produto: %d lucro relativo: %.2f", indice, maior);
    
    return 0;
}