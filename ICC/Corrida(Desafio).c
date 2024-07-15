/*Maria esta participando de uma corrida de bicicleta que se da em volta do lago Paranoa. O
caminho consiste apenas de secoes retas, direcionadas para norte, sul, leste ou oeste.
Ela comeca no ponto mais ao sul do circuito, inicialmente ela se move para norte e apos isso ela
ira em uma das 4 direcoes (norte, sul, leste ou oeste), nunca retornando para onde veio. Ou seja, se
ela seguiu norte ela nao ira escolher sul como proximo movimento.
Maria ainda e muito nova e se sente insegura em algumas curvas.
Uma curva e considerada perigosa se quando ignorada ela cair imediatamente no lago.
Ajude Maria a se preparar para a competicao e determine quantas curvas perigosas ela tera que fazer.
 Sera dado um valor N que representa a quantidade de pontos do circuito. Abaixo sera apresentado
um exemplo de circuito. Vale destacar que o posicionamento dos pontos sao irrelevantes para a
resolucao do exercıcio portanto nao serao dados na entrada.
A saıda deve ser seguida de uma quebra de linha
*/

#include <stdio.h>
int main(){
    int N, resp;
    scanf("%d", &N);
    /*Nesse problema, percebe-se que para uma volta ser completa, N precisa ser par, pois nao ha movimentos nas diagonais. 
    Alem disso, a primeira volta possivel e com N minimo igual a 4, tendo 0 curvas de risco, apos isso a cada dois pontos novos,
    ocorre 1 curva de risco, pois a personagem nao pode seguir o mesmo caminho, entao ela terar que fazer um desvio(curva de risco), para
    atingir todos os pontos*/
    resp = N/2 - 2;
    printf("%d", resp);
    return 0;
}