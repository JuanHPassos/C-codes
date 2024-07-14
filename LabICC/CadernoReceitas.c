/*Sua avo Lurdes esta tendo dificuldades de anotar todas as receitas dela no caderno de papel, 
entao voce decide aplicar seus conhecimentos adquiridos na faculdade para ajuda-la nisso. Implemente um programa em C que possua 4 funcionalidades:
1- R para registrar uma nova receita, sendo que a receita possui 6 campos.
A primeira entrada sera uma string que nao passara de 20 caracteres, seguida de 5 inteiros que representam a farinha, ovos, oleo, acucar e chocolate.
2- C seguido de 5 inteiros para cadastrar a compra de ingredientes para seu estoque (seguira a mesma ordem do cadastro da receita).
3- F seguido de um inteiro que representa o numero da receita que sera feita 
(a primeira receita cadastrada é a receita 0, a segunda a receita 1, assim por diante) para fazer a receita caso a quantidade de ingredientes seja suficiente. 
Ao realizar a receita lembre de subtrair a quantidade de ingredientes do estoque. Seu caderno de receitas deve ser alocado dinamicamente. 
Alem disso, se for solicitado uma receita que ainda nao foi cadastrada, o programa deve imprimir "Receita nao encontrada!".
4 - A ultima funcionalidade S serve para sair do programa. 
No final, seu programa deve imprimir a quantidade remanescente de ingredientes e a quantidade de receitas registradas.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Receita e os ingredientes necessarios
typedef struct dona{
    char nome[21];
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int choco;
}receita;
//Estoque com a quantidades de ingredientes disponiveis.
typedef struct ingredientes{
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int choco;
}estoque;
/*Funcao que registra um receita - registra*/
void registra(receita *comida){
    scanf(" %s", comida->nome);
    scanf("%d %d %d %d %d", &comida->farinha, &comida->ovos, &comida->oleo, &comida->acucar, &comida->choco);   
}
/*Funcao que abastece o estoque - compra*/
void compra(estoque *ing){
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    ing->farinha += a;
    ing->ovos += b;
    ing->oleo += c;
    ing->acucar += d;
    ing->choco += e;
}
/*Funcao que faz um comida - fazer*/
void fazer(int tam,receita *comida,estoque *ing){
    int num;
    scanf("%d", &num);
    //Verifica existe essa receita.
    if(num >= tam){ printf("Receita nao encontrada!\n"); return;}
    //Caso exista, verifica o estoque, se nao for possivel fazer, informa o que esta faltando.
    else{
        if(comida[num].farinha > ing->farinha){
            printf("Farinha insuficiente\n"); return;
        }
        if(comida[num].ovos > ing->ovos){
            printf("Ovos insuficientes\n"); return;
        }
        if(comida[num].oleo > ing->oleo){
            printf("Oleo insuficiente\n"); return;
        }
        if(comida[num].acucar > ing->acucar){
            printf("Acucar insuficiente\n"); return;
        }
        if(comida[num].choco > ing->choco){
            printf("Chocolate insuficiente\n"); return;
        }
    }  
    //Caso seja possivel, atualiza o estoque apos os ingredientes serem gastos.
    ing->choco -= comida[num].choco;
    ing->acucar -= comida[num].acucar;
    ing->oleo -= comida[num].oleo;
    ing->ovos -= comida[num].ovos;
    ing->farinha -= comida[num].farinha;
    printf("%s feita com sucesso!\n", comida[num].nome);
}
        
int main(){
    int tam = 0, fim = 0;//tam = quant. de receitas, e fim = controle do while.
    estoque ing;
    char comando;
    receita *comida;
    comida = (receita*) malloc(100*sizeof(receita));//Vetor que guardara as receitas.
    //Enquanto nao for dado o comando S
    while(fim == 0){
        scanf(" %c", &comando);
        //Se o quantidade de receitar chegar em 100, aumenta-se o vetor para caber 200 receitas.
        if(tam == 100){
            comida = (receita*) realloc(comida, 200*sizeof(receita));
        }
        switch (comando){
            case 'R':
                //Registra-se a receita nova.
                registra(&comida[tam]);
                tam++;
                break;
            case 'C':
                //Realiza a compra dos ingredientes
                compra(&ing);
                break;
            case 'F':
                //Realiza uma receita
                fazer(tam, comida, &ing);
                break;
            case 'S':
                fim = 1;
                break;
            //Caso seja informado um codigo que nao esta nas opcoes especificadas pelo problema.
            default:
                printf("Codigo invalido\n");
        }
    }
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", ing.acucar);
    printf("Chocolate: %d\n", ing.choco);
    printf("Farinha: %d\n", ing.farinha);
    printf("Oleo: %d\n", ing.oleo);
    printf("Ovos: %d\n", ing.ovos);
    printf("Receitas cadastradas: %d", tam);
    //Desalocacao de memoria.
    free(comida);
    return 0;
}