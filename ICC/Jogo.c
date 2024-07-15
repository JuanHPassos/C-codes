/*Isa é ligeiramente competitiva e está jogando com seu amigo, Bruno, um jogo de tabuleiro. 
Esse jogo possui regras e uma maneira de jogar bem diferente. 
Bruno irá colocar peças em algumas posições e Isa deve decidir em quais posições irá colocar as suas peças. 
Mas, ela só pode colocar uma peça em uma posição que não contenha uma quantidade ímpar de vizinhos com peças do adversário. 
Sabendo de suas habilidades de programação, ela pede sua ajuda para determinar todas as posições em que ela pode colocar uma peça. 
Uma peça é dita vizinha a outra se tiver um lado compartilhado com essa, ou seja, se estiver acima, abaixo ou ao lado dessa peça.
Você nunca pode colocar uma peça na mesma posição da peça do adversário. 
Observação: Para esse exercício você deve implementar no mínimo duas funções, 
sendo uma delas uma função responsável por "marcar" as posições em que podemos colocar uma peça e outra a sua escolha. 
Além disso você deve utilizar alocação dinâmica para a matriz.*/
#include<stdio.h>
#include<stdlib.h>
//Modularizacao das Funcoes.
void jogo(char **tab, int n, int m);
char **entrada(int n,int m);
//Nessa função, busca-se alocar dinamicamente a matriz e entrar com os dados do problema, que seria as peças do tabuleiro.
char **entrada(int n,int m){
    char **entrada;
    entrada = (char **) malloc(n*sizeof(char *));
    for(int i = 0; i<n; i++)
        entrada[i] = (char *) malloc(m*sizeof(char));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            scanf(" %c", &entrada[i][j]);
    }
    return entrada;
}
//A função jogo tem como objetivo, marcar os lugares em que isa pode jogar com um "*".         
void jogo(char **tab, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int cont = 0; //Cont serve para contar a quantidade de "X", adjacentes ao ".".
            //Essa condição serve para verificar um espaço que a peça de isa pode ser colocada.
            if(tab[i][j] == '.'){
            //Nessas 4 primeiras condições, busco verificar se existe o espaço adjacente e se possui um "X", se sim, adiciono 1 ao contador.
                if(j != 0 && tab[i][j-1] == 'X')
                    cont++;
                if(i != 0 && tab[i-1][j] == 'X')
                    cont++;
                if(j != m-1 && tab[i][j+1] == 'X')
                    cont++;
                if(i != n-1 && tab[i+1][j] == 'X')
                    cont++;
                //Isa pode colocar peça quando numero de X vizinhos ao . é par, logo o contador deve ser par para o espaço receber "*".
                if(cont%2 == 0){
                    tab[i][j] = '*';}
            }
        }
    }
} 
//Funcao principal.
int main(){
    //n = quant. linhas e m = quant. colunas.
    int n, m;
    scanf("%d %d", &n, &m);
    char **tab;//Matriz da questão e o tabuleiro do problema.
    tab = entrada(n, m); //Alocação e preenchimento da matriz.
    jogo(tab, n, m);//Verificação de espaços que isa pode jogar.
    //Imprimir os valores atualizados da matriz.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            printf("%c", tab[i][j]);
        printf("\n");
    }
    //Liberação do espaço alocado.
    for(int i = 0; i<n; i++){
        free(tab[i]);
        tab[i] = NULL;
    }
    free(tab);
    tab = NULL;
    return 0;
}

