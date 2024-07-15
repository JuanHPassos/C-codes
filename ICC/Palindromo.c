/*Voce recebe uma cadeia de N caracteres e seu dever e dizer se existe um anagrama tal que essa
cadeia de caracteres seja um palındromo.
Conceitos que podem ser uteis:
Um anagrama de uma palavra e formado por uma reorganizando os caracteres presentes nessa.
Uma palavra e considerada palındromo se lida nos dois sentidos e a mesma. Por exemplo:
”anna” e um palındromo, ja ”aabc” nao e um palındromo.
Input
Na primeira linha sera dado um inteiro N que representa a quantidade de caracteres a serem lidos.
Na proxima linha serao dados N caracteres.
1 ≤ N ≤ 105
Os caracteres dados sao todos minusculos.*/

#include <stdio.h>
int main(){
    /*n = numero de letras da palavra, freq = numero da quatidade de letras(Ex: espaco 0 do vetor representa a quantidade de a)
    cont = conta quantas frequencias impares existem na palavra(obs:util quando a palavra tem tamanho impar), v = palavra*/
    int n, freq[26] = {0}, cont = 0;
    char v[100010];
    scanf("%d", &n);
    //Ler a palavra.
    scanf("%s", v);
    //Conta a frequencia das letras.
    for(int i = 0; i<n; i++)
        freq[v[i]-'a']++;
    //Se a palavra for par.
    if(n%2 == 0){
        //Verifico se existe frequencia impar, caso exista, nao eh palindromo.
        for(int i = 0; i<26; i++)
            if(freq[i]%2 == 1){
                printf("Nao\n");
                return 0;}}
    //Se a palavra for impar.
    else 
        //Verifico as frequencias, deve haver apenas uma frequencia impar, assim que chegar em 2, nao eh palindromo.
        for(int i = 0; i<26; i++)
            if(freq[i]%2 == 1){
                cont++;
                if(cont == 2){
                    printf("Nao\n");
                    return 0;
                }
            }
    //Se o programa chegou ate aqui, eh porque passsou pelas verificacoes anteriores, entao e palindromo.
    printf("Sim\n");
    return 0;
}