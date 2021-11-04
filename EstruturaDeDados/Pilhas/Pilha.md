# Pilhas

Uma estrutura de dados do tipo Pilha, como o próprio nome já diz, representa uma pilha de dados. _Exemplo: Uma pilha de livros, de pratos..._

Só é possível realizarmos 2 operações em uma pilha, as operações de **empilhar** (push) e **desempilhar** (pop). O foco de operações em uma pilha é no topo dela, ou seja, quando quisermos inserir ou excluir um elemento da pilha, fazemos isso do topo dela.

_Exemplo Prático: Quando vamos pegar um livro que está no meio da nossa pilha de livros, retiramos um a um os livros que estão no topo até chegarmos no livro que desejamos pegar._

As pilhas também são conhecidas pela sua nomenclatura: **LIFO**, que é uma abreviação para o termo _Last-in-First-out_ (**Último que entra, primeiro que sai**). Essa nomenclatura nada mais é do que um resumo de como trabalhamos com uma pilha.

Como as pilhas são umas estruturas de dados dinâmicas, utilizaremos o conceito de ponteiros e nós. Como a referência de operações em uma pilha é sempre no topo, teremos um ponteiro que irá guardar a referência de topo da pilha e a partir dele iremos realizar as operações de _push_ e _pop_ com os nós dentro da pilha.

Agora veremos a seguir a implementação da estrutura de dados do tipo Pilha em C. Para facilitar a compreensão, utilizei uma Pilha de números inteiros:

## Implementação da Pilha

Primeiro nós criaremos a nossa estrutura do tipo **Nó**, que guardará o tipo de dado que vamos trabalhar na pilha e também um ponteiro que apontará para um próximo elemento da mesma estrutura do tipo Nó. Isso ficará dessa forma:

```C
typedef struct no {
    // Tipo de dado que vamos guardar no Nó
    int dado;
    // Ponteiro que aponta para uma mesma estrutura do tipo Nó
    struct no *proxNo;
} No;
```

Na função principal do nosso programa, criaremos a nossa pilha. Que será do tipo Nó (uma pilha que guarda nós), e é um ponteiro que aponta inicialmente para `NULL` (a pilha começa vazia). Isso pode ser feito da seguinte forma:

```C
No *minhaPilha = NULL;
```

Note que o ponteiro `minhaPilha` guarda sempre a referência para o topo da pilha, que é onde nós devemos trabalhar.

## Empilhar elemento (push)

Para empilharmos um elemento na nossa pilha devemos seguir os seguintes passos:

1. Criar um nó que guardará os dados do nosso novo elemento
2. Fazer com que o **próximo nó** do nosso novo elemento aponte para o elemento que está no topo da pilha.
3. Mudar a referência de **topo da pilha** para ser no novo nó que inserimos dentro da pilha.

Isso pode ser feito da seguinte forma:

```C
void empilhar(No *topoDaPilha) {
    // 1. Criando o novo Nó que vai ser empilhado
    No *novoElemento = (No *) malloc(sizeof(No));
    
    if (novoElemento != NULL) {
        novoElemento -> dado = lerNumero();
        // 2. Linkando o nosso novo elemento com o antigo topo da pilha
        novoElemento -> proxNo = topoDaPilha;
        return novoElemento;
    } else puts("Sem memória suficiente. Nó não foi criado!");
}

// Empilhando no programa Principal
int main() {
    No *minhaPilha = NULL;

    /* 3. O retorno do novoElemento, agora linkado na pilha, 
    será a nova referência de topo para nossa pilha */
    minhaPilha = empilhar(minhaPilha);

    return 0;
}
```

## Desempilhar elemento (pop)

Para desempilhar um elemento da pilha, devemos seguir as instruções abaixo:

1. Criar um nó auxiliar para receber o elemento que está no topo da pilha.
2. Mudar a referência de topo da pilha para o próximo nó que está logo abaixo do topo.
3. Excluir o elemento que estava no topo.

Isso pode ser feito da seguinte forma:

```C
/* A função recebe um ponteiro para ponteiro para podermos modificar
a variável da nossa Pilha (que está na função main) e também o conteúdo
da nossa pilha (que é uma estrutura do tipo Nó que armazena um ponteiro). */

No* desempilhar(No **topoDaPilha) {
    if (*topoDaPilha != NULL) {
        // Passo 1
        No *aux = *topoDaPilha;
        // Passo 2
        *topoDaPilha = aux -> proxNo;
        // Retornando o elemento que vai ser removido
        return aux;

    } 
    
    return NULL;
}

// Desempilhando no programa Principal
int main() {
    No *minhaPilha = NULL;
    No *remover;

    minhaPilha = empilhar(minhaPilha);

    remover = desempilhar(&minhaPilha);
    if (remover != NULL)
        free(remover);
    else
        puts("A pilha está vazia!");

    return 0;
}
```

## Imprimir pilha

Para imprimir os elementos que estão na pilha devemos simplesmente utilizar um laço de repetição até o último elemento da pilha:

```C
void imprimirPilha(No *topoDaPilha) {
    puts("------------ PILHA ----------");
    while (topoDaPilha != NULL) {
        // Imprimindo o elemento
        printf("\t %d\n", topoDaPilha -> dado);

        // Passando para o proximo elemento da pilha
        topoDaPilha = topoDaPilha -> proxNo;
    }
    puts("------------ FIM DA PILHA ----------");
}
```

Pronto! Agora você já tem uma base de como trabalhar com pilhas. Navegando pelo diretório você pode encontrar o arquivo `.c` com a estrutura de dados implementada, outras formas de se trabalhar com esse mesmo tipo de estrutura e exemplos práticos. **Obrigado por ler até aqui!** 😄
