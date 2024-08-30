## Busca Binária

### Encontrar elemento no vetor:
A busca binária ajuda a encontrar um elemento em um vetor (funciona apenas em um vetor ordenado). Tal algoritmo consiste em "chutar" um valor no meio do vetor. Caso ele seja maior que o elemento buscado, sabe-se que o elemento que se quer está para a "esquerda" do vetor (dado **x**, número escolhido, se **x <= v[j]**, então **x <= v[j+i]**, sendo **i** um número natural). O mesmo argumento vale para o caso de o número ser maior, porém deve-se olhar agora os valores da direita.

#### Exemplo:
- **x = 9**
- Vetor: `1 2 3 4 5 6 7 8 9 10`
- **e** = início, **d** = final

Passo a passo:
1. **meio** = 5 → vetor[posição: (e + d) / 2]
2. **x** é maior que 5, logo analisa-se: `6 7 8 9 10`
3. **meio** = 8 → **x > 8**
4. Analisando: `9 10`
5. **meio** = 9, valor encontrado.

Nota-se que tal algoritmo é muito eficiente para **n** muito grandes, tendo em vista que a cada iteração o tamanho cai pela metade.

### Implementação Iterativa:

```c
// Esta função recebe um inteiro x
// e um vetor crescente v[0..n-1]
// e devolve um índice j em 0..n 
// tal que v[j-1] < x <= v[j].

int buscaBinaria (int x, int n, int v[]) { 
   int e = -1, d = n; // atenção!
   while (e < d - 1) {  
      int m = (e + d) / 2;
      if (v[m] < x) e = m;
      else d = m; 
   }
   return d;
}
```
A complexidade do algoritmo é **O(log n)**, pois a cada iteração o tamanho do vetor cai pela metade. Logo, teremos aproximadamente **n / 2^k**, e quando **k** fica menor que **log n**, nota-se que o resultado é menor que 1, encerrando a execução do algoritmo. Portanto, **log n** é o limite superior dessa função.

## Implementação Recursiva
```c
// Recebe um vetor crescente v[e+1..d-1] e
// um inteiro x tal que v[e] < x <= v[d] e
// devolve um índice j em e+1..d tal que
// v[j-1] < x <= v[j].
//A palavra-chave static está aí apenas para indicar que a função bb tem caráter auxiliar, e não deve ser invocada diretamente pelo usuário do algoritmo de busca binária.
//x = valor, e = esquerda, d = direita e v = vetor.
static int 
bb (int x, int e, int d, int v[]) {
   //Se só tiver dois elementos, retorna o maior.
   if (e == d-1) return d;  
   
   else {
      //pega o meio
      int m = (e + d)/2;
      //Se o numero procurado, for maior que o meio, reduz se o vetor a metade superior
      if (v[m] < x)  
         return bb (x, m, d, v);
      else //Caso contrario, a metade superior.
         return bb (x, e, m, v); 
   } 
}

```
## Descobrindo a Complexidade

Note que o vetor terá **n** elementos, que serão divididos por 2, **k** vezes. Porém, tal operação ocorrerá até o vetor ter tamanho 1. Dessa forma:

n/2^k = 1, logo, 2^k = n.
log 2^k = log n (base 2)
k = log n.
