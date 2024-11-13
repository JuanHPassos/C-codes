# Hashing (Tabela de espalhamento)
Acesso direto, mas endereçamento indireto.
- funão de mapeamento h(k) != em geral.
- Resolve uso ineficiente do espaço de armazenamento.

Obs: permite acesso em O(1).

Usada para inserir, remover ou buscar um elemento (1 resultado para uma chave).

**Colisão**: ocorre quando a função hash produz o mesmo endereço para chaves diferentes.
- Chaves com mesmo endereço são ditas sinônimos.

Para identificar as posições do vetor dado um elemento k, são utilizados muitos métodos, para garantir um cenário com pouca memória a ser utilizada e evitar ao máximo colisões.

Dado n elementos em uma tabela de m posições, temos que cada espaço idealmente terá $\frac{n}{m}$. Tal divisão é chamada de fator de carga.

# Tipos de Hashing

**Estático**
Espaço de endereçamento não muda
**Fechado**
- Permite armazenar um conjunto de informações de tamanho limitado(nºchaves = número de elementos)
- Técnicas de rehash para tratamento de colisões
    - Overflow progressivo
    - 2º função hash
**Aberto**
- Permite armazenar um conjunto de informações de tamanho potencialmente ilimitado.
- Encadeamento de elementos para o tratamento de colisões.

**Dinâmico**
- Escopo para endereçamento pode aumentar.

# Técnicas de encontrar colisão

## Rehash

- Sondagem linear
Rehash de h(k) = (h(k) + i) % B, com i = 1...B-1.
Sendo B o tamanho da tabela.

- Sondagem quadrática
 Observa-se que o intervalo entre as sondas aumentará proporcionalmente ao valor do hash. A sondagem quadrática é um método com a ajuda do qual podemos resolver o problema de agrupamento dos valores presente na rehash linear.  Este método também é conhecido como método do quadrado médio. Neste método, procuramos o $i^2$'ésimo slot na i-ésima iteração. Sempre começamos do local do hash original. Se apenas o local estiver ocupado, verificamos os outros slots.

- Duplo hash
Os intervalos entre as sondas são calculados por outra função hash. O hash duplo é uma técnica que reduz o agrupamento de forma otimizada. Nessa técnica, os incrementos para a sequência de sondagem são calculados usando outra função hash. Usa-se outra função hash hash2(x) e procuramos o espaço i*hash2(x) na i-ésima rotação. 

- Lista ligada
Nessa implementação, ao invés de um espaço, usa-se ponteiros para lista. Assim, caso já exista um elemento, não precisasse procurar outro espaço, basta apenas inserir no fim da lista.

Exemplo de boas funções hash:
Divisão:
h(k) = 

Multiplicação:
h(k) = (k*A%1)*m, com A sendo uma constante entre 0 e 1.
(k*A%1) recupera parte fracionária de k*A.

Knutch sugere A = (raiz(5) - 1)/2 = 0,6180...

```c
#include <stdio.h>
#include <stdlib.h>

#define TAM_TABELA 11

typedef struct h {
    int chave;
    int valor;
} hash_t;

hash_t tabela[TAM_TABELA];

int h(int chave) {
    return chave % TAM_TABELA;
}

void inicializar_tabela() {
    for (int i = 0; i < TAM_TABELA; i++) {
        tabela[i].chave = -1;
        tabela[i].valor = -1;
    }
}

void inserir(int chave, int valor) {
    int ind = h(chave);

    for (int i = 0; i < TAM_TABELA; i++) {
        if (tabela[ind].chave == -1) {
            tabela[ind].chave = chave;
            tabela[ind].valor = valor;
            return;
        } else {
            // Overflow progressivo.
            ind = (ind + 1) % TAM_TABELA;
        }
    }
    printf("Tabela de hash está cheia. Não foi possível inserir a chave %d.\n", chave);
}

int busca(int chave) {
    int ind = h(chave);

    for (int i = 0; i < TAM_TABELA; i++) {
        if (tabela[ind].chave == chave) {
            return tabela[ind].valor;
        } else {
            ind = (ind + 1) % TAM_TABELA;
        }
    }
    return -1;  // Chave não encontrada
}

void remover(int chave) {
    int ind = h(chave);

    for (int i = 0; i < TAM_TABELA; i++) {
        if (tabela[ind].chave == chave) {
            tabela[ind].chave = -1;
            tabela[ind].valor = -1;
            return;
        } else {
            ind = (ind + 1) % TAM_TABELA;
        }
    }
    printf("Chave %d não encontrada para remoção.\n", chave);
}

int main() {
    inicializar_tabela();

    inserir(10, 20);
    inserir(21, 30);
    inserir(32, 40);

    int valor = busca(21);
    if (valor != -1) {
        printf("Valor encontrado: %d\n", valor);
    } else {
        printf("Valor não encontrado.\n");
    }

    remover(21);
    valor = busca(21);
    if (valor != -1) {
        printf("Valor encontrado: %d\n", valor);
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
```



