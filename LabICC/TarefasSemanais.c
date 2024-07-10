/*Voce foi encarregado de desenvolver um programa em C para ajudar um amigo da engenharia
civil a organizar suas atividades ao longo da semana. O programa recebera como entrada um numero
correspondente ao dia da semana (1 - Segunda, 2 - Ter¸ca ... 7 - Domingo) e um valor “booleano”
(bool). Se bool = 0, voce deve indicar as atividades a partir daquele dia (inclusive) ate o final da
semana (domingo). Se bool = 1, imprima apenas a tarefa do dia informado. Caso o dia informado
nao seja valido, imprima ”Dia nao informado”como saıda, independente do pedido requisitado.*/

#include <stdio.h>
int main(){
    int dia_da_semana, bool;
    scanf("%d %d", &dia_da_semana, &bool);
    switch(dia_da_semana){
        case 1:
            printf("Segunda: Aula de computacao\n");
            if(bool==1)
                break;
        case 2:
            printf("Terca: Treino de volei\n");
            if(bool==1)
                break;
        case 3:
            printf("Quarta: Aula de calculo\n");
            if(bool==1)
                break;
        case 4:
            printf("Quinta: Lista de GA\n");
            if(bool==1)
                break;
        case 5:
            printf("Sexta: Festa da Sacim\n");
            if(bool==1)
                break;
        case 6:
            printf("Sabado: Jantar em familia\n");
            if(bool==1)
                break;
        case 7:
            printf("Domingo: Depressao pos final de semana\n");
                break;
        default:
            printf("Dia nao registrado\n");
            break;
        
    }
    return 0;
}
   