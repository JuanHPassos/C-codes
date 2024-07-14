/*Neste fim de semana, ZeMonoY foi ao Cbolao, o maior campeonato nao oficial de League of
Legends do mundo, onde varios jogadores profissionais e streamers competem uns contra os outros
para levantar fundos para causas sociais. A ultima edicao contou com a presenca de aproximadamente
2 mil pessoas, alem de mais de 100 mil visualizacoes simultaneas da transmissao online ao vivo e mais
de 200 mil reais doados para uma ONG que cuida de animais. E claro, Ze, como um bom mono Yasuo,
nao podia perder o evento.
A plateia do Cbolao e dividida em pedacos menores, que se assemelham bastante com uma matriz.
Assim, ao observar a arquibancada, Ze - que estava usando um cosplay do seu personagem favorito do
jogo - decidiu que nao queria se sentar na mesma linha ou na mesma coluna de outros participantes
que tambem estavam de cosplay, ja que assim ele nao chamaria tanta atencao quanto gostaria. Assim,
voce precisa ajudar Ze a encontrar um lugar onde ele possa se sentar. Voce deve fazer um programa
que recebe uma matriz indicando quais lugares estao ocupados por fas sem cosplay, quais estao
ocupados por cosplayers e quais estao vazios. Com essa informacao, imprima um mapa de quais
lugares Ze pode se sentar para chamar a atencao que seu cosplay de Yasuo merece, lembrando que
ele deve se sentar em uma cadeira vazia, e que nao esteja na mesma linha nem na mesma coluna que
outro cosplayer.
A primeira linha da entrada possui a dimensao da matriz a ser lida, com N linhas e M colunas.
• As N linhas seguintes contem M valores, que podem ser ”c” para cosplayer, ”f” para fa sem
cosplay e ”v” para vazio.
• 2 ≤ N ≤ 20 e 2 ≤ M ≤ 20.
• O seu programa devera imprimir uma matriz das mesmas dimensoes da matriz de entrada,
colocando ”o” nos lugares possıveis de Ze sentar e ”x” onde ele nao puder sentar.
• Caso nao haja lugares para Ze sentar, seu programa deve imprimir ”Eh um dia triste para
os mono Yasuo”*/

#include <stdio.h>
int main(){
    //Variavel para guardar linha, coluna e identificar se ha algum lugar disponivel. 
    int m, n, b = 0; 
    scanf("%d %d", &m, &n);
    //Matriz que simboliza o mapa, e "a" é variavel usada para identificar se o acento pode ou nao ser ocupado. 
    char mat[m][n], a;
    //Laco para preencher a matriz.
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++){
            scanf(" %c", &a);
            //Se o lugar tiver um fa, ele nao pode ser ocupado.
            if(a == 'f')
                mat[i][j] = 'x';
            //Se o lugar estiver vazio e for possivel ocupa-lo, entao marca-se um "o".
            else if(a == 'v'){
                if(mat[i][j] != 'x'){
                    mat[i][j] = 'o';
                    //E possivel sentar.    
                    b++;
                }
            }
            //Se houver um cosplayer, nao é possivel ocupar a linha e a coluna do mesmo.
            else if(a == 'c'){
                for(int k = 0; k<n; k++)
                    mat[i][k] = 'x';
                for(int l = 0; l<m; l++)
                    mat[l][j] = 'x';}
        }
    //Caso nao haja lugares.
    if(b == 0)
        printf("Eh um dia triste para os mono Yasuo");
    else
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++)
                printf("%c ", mat[i][j]);
            printf("\n");
         }
        return 0;     
}