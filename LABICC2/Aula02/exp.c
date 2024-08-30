/* Implemente a exponenciação de duas formas: uma iterativa e outra utilizando o método de
 divisão e conquista (exponenciação rápida). Considere que 𝑛 e 𝑘 são dois inteiros, onde 0 <
 𝑛 <104 e 0 < 𝑘 < 109.
 
Observação

Para evitar overflow, a saída deverá ser composta pelos últimos quatro dígitos do resultado.
Isso pode ser feito aplicando a operação mod (% no C) durante o cálculo. Como a operação mod
é comutativa, recomenda-se aplicá-la em cada etapa do processo.*/

#include<stdio.h>
#include<stdlib.h>
//Note que como o exericio pede apenas os 4 ultimos numeros, so precisamos operar as multiplicações com os quatro primeiros numeros.
//Dividir e conquistar.
int exp(int n,int k){
    //Pegar os primeiros 4 dígitos.
    n = n%10000;
    //Um numero elevado a 1, é ele mesmo.
    if(k == 1){
        return n%10000;
    }
    if(k%2){
        return ((((exp(n, k/2)%10000)*(exp(n, k/2)%10000))%10000)*n);
    }
    else{
        return ((exp(n, k/2)%10000)*(exp(n,k/2)%10000));
    }
}

int main(){
    //n = base, k = expoente.
    int n, k, resposta;
    
    scanf("%d %d", &n, &k);
    
    resposta = exp(n, k);
    
    printf("%d", resposta%10000);
    
    return 0;
}

//Versão iterativa
/* #include<stdio.h>
#include<stdlib.h>

int main(){
    //n = base, k = expoente.
    int n, k, aux = 1;
    //aux 
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i<k; i++){
        aux = aux%10000;
        aux *= n;
    }
    
    aux = aux%10000;
    
    printf("%d", aux);
    
    return 0;
} */
