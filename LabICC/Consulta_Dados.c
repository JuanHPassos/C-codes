/*Voce e um hacker e, por motivos tanto sombrios quanto duvidosos, deseja hackear o banco de dados
do mercadinho do Seu Jair. Para isso, voce elaborou um software malicioso que consegue informacoes
exclusivas acerca do banco de dados do mercado. Logo, seu novo objetivo e desenvolver um programa
em C para registrar os dados com alocacao dinamica (para que os dados nao possam ser acessados
pela polıcia em caso de engenharia reversa) e imprimir organizadamente a lista de conteudos para
voce futuramente salva-las num arquivo criptografado.
O programa recebera como entrada um numero inteiro (n) correspondente a quantidade de dados
fornecidos e, nas proximas n linhas, o IP (inteiro que indica a importancia do dado para poder
coagir Seu Jair), o codigo (inteiro que possibilitara saber a quantidade maxima de bytes referente a
informacao) e o conteudo em formato de string sem espacos. A partir de cada codigo, obtenha o
tamanho das respectivas strings - somando seus divisores primos sem repeticao - para uma alocacao
mais eficiente e faca o programa exibir os produtos em ordem decrescente de IP, printando o conteudo
e o codigo.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*Funcao para descobrir o tamanho do conteudo - tamanho*/
int tamanho(int cod){
    //tamanho = soma dos divisores primos sem repeticao de cod.
    int *vet, primo, soma = 0;
    //Vetor que guardara todos os divisores primos.
    vet = (int *) malloc(((int)cod/2)*sizeof(int)+1);
    int tam = 0;
    //Verificar se o numero eh divisor.
    for(int i = 2; i<cod/2; i++){
        primo = 1;
        if(cod%i == 0){
            //Verificar se eh primo.
            for(int j = 0; j<tam; j++){
                if(i%vet[j] == 0){
                    primo = 0;
                    break;
                }
            }
            if(primo == 1){
                //Se for primo, adiciono no vetor.
                vet[tam] = i;
                tam++;
            }
        }
    }
    //Se nao tem divisor, cod eh primo, logo ele e seu proprio divisor e primo.
    if(tam == 0)
        soma = cod;
    //Se tiver, calculo o tamanho a partir da soma dos elementos do vetor.
    else
        for(int i = 0; i < tam; i++)
                soma += vet[i];
    //Desalocacao de memoria.
    free(vet);
    vet = NULL;
    //Tamanho + '\0'.
    return soma+1;
}



int main(){
    int n, ip, tam;//Quant. dados, importancia dado, tamanho do conteudo. 
    int *codigo;//Vetor dos codigos.
    char **conteudo;//Vetor de strings que armazena os conteudos.
    scanf("%d", &n);
    if(n == 0){
        printf("Sem produtos a serem cadastrados");
        return 0;
    }
    //Alocacao dinamica dos vetores.
    codigo = (int *) malloc(n*sizeof(int));
    conteudo = (char **) malloc(n*sizeof(char*));
    for(int i = 0; i<n; i++){
        //O ip simboliza a posicao do vetor em que o codigo e conteudo estara.
        scanf("%d", &ip);
        scanf("%d", &codigo[ip]);
        //Descubre-se o tamanho do conteudo por meio do codigo e do que ele representa.
        tam = tamanho(codigo[ip]);
        //Aloca-se dinamicamente o espaco necessario para o seu armazenamento.
        conteudo[ip] = (char *) malloc(tam*sizeof(char));
        scanf("%s", conteudo[ip]);
    }
    //Imprimi-se as informacoes de acordo com a sua importancia(maior -> menor).
    for(int i = n-1; i>= 0; i--){
        printf("%s", conteudo[i]);
        printf(" %d\n", codigo[i]);
    }
    //Desalocacao da memoria.
    free(codigo);
    codigo = NULL;
    for(int i = 0; i<n; i++)
        free(conteudo[i]);
    free(conteudo);
    return 0;
}


