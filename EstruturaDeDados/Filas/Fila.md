# Filas

O conceito de fila é o mesmo do mundo real, logo sua implementação e forma de trabalhar é a mesma. As filas também são conhecidas como estruturas de dados do tipo **FIFO** (_First In First Out_), que nada mais é do que um resumo de como funciona uma fila: o primeiro que entra é o primeiro que sai.

Vejamos as operações e implementações da fila:

## Implementação da Fila

Similar à Pilha, teremos uma estrutura do tipo Nó e a nossa Fila aponta inicialmente para `NULL` (A fila inicia vazia):

```C
/* Implementação de uma fila de Pessoas */

typedef struct {
    char nome[50];
    char sexo;
    int idade;
} Pessoa;

typedef struct no {
    Pessoa p1;
    struct no *proxNo;
} No;

/* Implementação na função Principal */

int main() {
    No *pilha = NULL;
    
    return 0;
}
```

## Inserir na Fila (Inqueue)

Assim como no mundo real, sempre inserimos um novo elemento no final da fila:

```C
void inqueue(No **fila, Pessoa p) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> p1 = p;
        novo -> proxNo = NULL;

        if (*fila) {
            No *aux = *fila;

            while (aux -> proxNo) {
                aux = aux -> proxNo;
            }

            aux -> proxNo = novo;

        } else { *fila = novo; }
    } else { puts("Sem memória suficiente!"); }
}
```

## Remover da Fila (Dequeue)

Para remover um elemento da fila, é similar ao que acontece na estrutura de dados do tipo Pilha:

```C
No* dequeue(No **fila) {
    No *aux;

    if (*fila) {
        aux = *fila;
        *fila = aux -> proxNo;
        return aux;
    } else { aux = NULL; }

    return aux;
}
```

## Imprimir Fila

Devemos percorrer a fila imprimindo seus respectivos elementos:

```C
void imprimirFila(No *fila) {
    int cont = 1;
    
    while (fila) {
        printf("\t ------ %dº PESSOA ------", cont);
        
        printf("Nome: %s\n", fila -> p1.nome);
        printf("Sexo: %c\n", fila -> p1.sexo);
        printf("Idade: %d\n", fila -> p1.idade);

        cont++;
        fila = fila -> proxNo;
    }
}
```

## Fila de Prioridade

Podemos construir também uma fila de prioridade e, a partir de um critério previamente definido, inserimos os elementos de prioridade no início da fila:

```C
typedef struct no {
    int dado;
    struct no *prox;
} No;

void inqueue(No **fila, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> prox = NULL;

        if (*fila) {
            No *aux = *fila;

            if (numero > 59) { // Critério de Prioridade
                if ((*fila) -> dado < 60) {
                    novo -> prox = *fila;
                    *fila = novo;
                } else {
                    while (aux -> prox && aux -> prox -> dado > 59)
                        aux = aux -> prox;
                    aux -> prox = novo;
                    novo -> prox = aux -> prox;
                    aux -> prox = novo;
                }
            } else {
                while (aux -> prox)
                    aux = aux -> prox;
                aux -> prox = novo;
            }
        } else {
            *fila = novo;
        }
    } else {
        puts("Sem memória suficiente!");
    }
}
```

Pronto! Agora você já tem uma base de como trabalhar com filas. Navegando pelo diretório você pode encontrar o arquivo `.c` com a estrutura de dados implementada. **Obrigado por ler até aqui!** 😄
