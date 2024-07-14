/*Voce e um gerente de banco e, a fim de conhecer melhor sua carteira de credito, gostaria de realizar
uma captacao de dados do Banco de Dados e imprimir uma lista de todos os clientes junto a outra lista
que mostrara apenas os clientes endividados. Por isso, com os seus conhecimentos sobre computacao,
decide fazer um programa em C para organizar esses dados vindos do banco de dados para futuramente
realizar analises sobre os numeros.
O programa recebera como entrada um numero inteiro (n) correspondente a quantidade de dados
fornecidos e, nas proximas n linhas, uma string nome (que devera ser alocada apenas o tamanho
necessario), um inteiro CPF (que pode ser tratado como char* para ocupar menos espaco), um
inteiro idade, um float saldo e um float credito de cada registro, todos separados por vırgulas pela
formatacao padrao da base de dados. A partir de cada resgistro, obtenha os endividados, printe todos
os registros e, depois, os endividados como no caso teste abaixo.
• Utilize a biblioteca stdlib.h (para alocar) e string.h (para pegar o tamanho das strings).
• Utilize STRUCT para representar as pessoas.
• Em caso de nao ocorrer a presenca de nenhum endividado, deve ser impresso ”Nenhuma pessoa
endividada encontrada.”depois de ”Pessoas endividadas:”.
• 0 ≤ n ≤ 60, 0 ≤ nome ≤ 30, 0 ≤ credito e saldo ≤ 1000.
• Nao esqueca de desalocar a memoria ao final do programa.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct dados{
    char nome[31];//Tamanho max = 30 + '\0'.
    char CPF[12];// Tam. max = 11 + '\0'.
    int idade;
    float saldo;
    float cred;
}pessoas;
/*Funao para a entrada de dados - entrada*/
int entrada(int *n,pessoas **pessoa, int **end){
    int tam = 0;
    scanf("%d", n);//Le a quantidade de pessoa.
    //Aloca dinamicamente a quantidade de pessoas e o tamanho maximo de pessoa endividadas.
    *pessoa = (pessoas*) malloc((*n)*sizeof(pessoas));
    *end = (int*) malloc((*n)*sizeof(int));
    for(int i = 0; i<(*n); i++){
        scanf(" %[^,], %[^,], %d, %f, %f", (*pessoa)[i].nome, (*pessoa)[i].CPF, &(*pessoa)[i].idade, &(*pessoa)[i].saldo, &(*pessoa)[i].cred);
        //A pessoa esta endividade se o cred > saldo.
        if((*pessoa)[i].saldo < (*pessoa)[i].cred){ (*end)[tam] = i; tam++;};
    }
    //Retorna a quantidade de pessoas endividadas.
    return tam;
}


int main(){
    int *end, n, tam;
    pessoas *pessoa;
    tam = entrada(&n, &pessoa, &end);
    for(int i = 0; i<n; i++){
        printf("Dados da pessoa %d:\n", i+1);
        printf("Nome: %s\n", pessoa[i].nome);
        printf("CPF: %s\n", pessoa[i].CPF);
        printf("Idade: %d\n", pessoa[i].idade);
        printf("Saldo: %.2f\n", pessoa[i].saldo);
        printf("Credito: %.2f\n\n", pessoa[i].cred);
    }
    printf("Pessoas endividadas:\n");
    if(tam == 0) printf("Nenhuma pessoa endividada encontrada.");
    else{
        for(int i = 0; i<tam; i++){
            if(i != 0) printf("\n");
            printf("Nome: %s\n", pessoa[end[i]].nome);
            printf("CPF: %s\n", pessoa[end[i]].CPF);
            printf("Divida: %.2f\n",  (pessoa[end[i]].cred-pessoa[end[i]].saldo));
        }
    }
    //Desalocacao de memoria.
    free(pessoa);
    free(end);
    return 0;
}