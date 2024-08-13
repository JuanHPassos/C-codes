# Recursão

Função que recorre a si mesma para continuar sua execução. A função recursiva forma uma pilha das variáveis, parâmetros e o endereço de retorno, e quando a função termina, ela desempilha esses dados da memória, restaurando o estado antes da chamada recursiva.

Nota-se que a função iterativa ocupa menos memória. Porém, há problemas em que a solução recursiva é mais simples de ser implementada e alguns problemas em si, já são recursivos.

## Como usar:
1. **Definir o problema de forma recursiva**, ou seja, em termos dele mesmo.
2. **Definir a condição de término (caso base)**.
3. A cada chamada recursiva, deve-se garantir que se está mais próximo de satisfazer a condição de término.

### Exemplo: Fatorial
1. \( n! = n * (n - 1)! \)
2. Se \( n = 1 \), então \( fat = 1 \).**(Caso base)**
2. Se \( n = 0 \), então \( fat = 1 \).**(Caso base)**
3. `return n * fat(n - 1);`

### Outro exemplo: Fibonacci

Pode ser implementado de forma iterativa ou recursiva; no entanto, a forma iterativa acaba sendo muito mais eficiente, pois essa sequência, na forma recursiva, acaba chamando a mesma função de um \( n \) mais de uma vez. Dessa forma, a complexidade do problema é \( 2^n \). 

Uma solução para esse "problema" recursivo é armazenar em um vetor os valores \( n \) que já foram calculados.

## Recursão de Cauda

É um tipo especial de recursão, no qual não existe processamento a ser feito depois de encerrada a chamada recursiva (aparece no final do código), o que costuma ser mais fácil para implementar a função iterativa.
