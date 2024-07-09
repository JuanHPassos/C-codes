/*Para nao ficar de recuperacao de calculo, voce decidiu fazer um programa que calcula sua nota
final de calculo e analisa sua situacao na disciplina. Seu programa ira receber a nota da P1 de calculo,
seguido da nota da p2, seguido das notas das 4 listas de exercıcio, a nota final sera calculada como
nfinal=(p1+p2+nlistas)/3 sendo nlistas a media das notas das listas.
Se nfinal for Maior ou igual a 5, vocˆe foi aprovado.
Se nfinal for menor do que 5 e maior ou igual a 3, voce esta de recuperacao.
Caso nfinal seja menos que 3, voce foi reprovado.
Alem disso, caso a nota das listas seja zero, voce sera automaticamente reprovado.
*/

#include <stdio.h>
int main(void){
    float p1, p2, nlistas, nfinal, lista1, lista2, lista3, lista4;
    scanf("%f %f %f %f %f %f", &p1, &p2, &lista1, &lista2, &lista3, &lista4);
    nlistas = (lista1 + lista2 + lista3 + lista4)/4;
    nfinal = (p1 + p2 + nlistas)/3;
    if (nlistas == 0 || nfinal < 3)
        printf("Reprovado");  
    else
        if( nfinal >= 5)
            printf("Aprovado");
        else
            printf("Recuperacao");
    return 0;
}