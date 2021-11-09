# Lista Dinâmica

Uma estrutura de dados do tipo Lista, é uma estrutura de dados mais genérica e por isso não possui muitas restrições. Podemos inserir elementos tanto no início, no meio (de forma ordenada ou não) ou no final, bem como excluir um desses elementos dessas 3 formas. Existem 3 tipos de Listas: As **Listas Encadeadas**, **Duplamente Encadeadas** e as **Listas Circulares**. Veremos a seguir como implementar esses tipos de lista:

## Lista Encadeada

Em uma lista encadeada temos, na composição do nó da lista, o elemento com que o programa irá trabalhar e um ponteiro para o próximo nó.

_Para fins didáticos, foi utilizado uma lista de números inteiros._

```C
typedef struct no {
    int dado;
    struct no *proximo;
} No;
```

### Inserir no Início

```C
void inserirInicio(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> prox = *lista;
        *lista = novo;
    } else {
        puts("Sem memória suficiente!");
    }
}
```

### Inserir no Final

```C
void inserirFinal(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> prox = NULL;

        if (*lista) {
            No *aux = *lista;

            while (aux -> prox)
                aux = aux -> prox;
            aux -> prox = novo;
        } else {
            *lista = novo;
        }
    } else {
        puts("Sem memória suficiente!");
    }
}
```

### Inserir Ordenado

```C
void inserirOrdenado(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;

        if (*lista) {
            if (novo -> dado < (*lista) -> dado) { // O elemento inserido é o 1º menor elemento da lista
                novo -> prox = *lista;
                *lista = novo;
            } else { // Procuramos onde colocar o elemento
                No *aux = *lista;

                while (aux -> prox && novo -> dado > aux -> prox -> dado)
                    aux = aux -> prox;
                novo -> prox = aux -> prox;
                aux -> prox = novo;
            }
        } else {
            novo -> prox = NULL;
            *lista = novo;
        }
    } else {
        puts("Sem memória suficiente!");
    }
}
```

### Remover a partir de um elemento

```C
No* removerElemento(No **lista, int numero) {
    No *excluir = NULL;

    if (*lista) {
        if ((*lista) -> dado == numero) { // Remove o 1º elemento
            excluir = *lista;
            *lista = excluir -> prox;
        } else { // Procura o elemento a ser excluído
            No *aux = *lista;

            while (aux -> prox && aux -> prox -> dado != numero)
                aux = aux -> prox;
            if (aux -> prox) { // Achou o elemento
                excluir = aux -> prox;
                aux -> prox = excluir -> prox;
            }
        }
    }

    return excluir;
}
```

### Buscar Elemento na Lista

```C
No* buscarElemento(No **lista, int numero) {
    No *busca = NULL, *aux = *lista;

    while (aux && aux -> dado != numero)
        aux = aux -> prox;
    
    if (aux)
        busca = aux;

    return busca;
}
```

### Imprimir Lista

```C
void imprimir(No *lista) {
    while (lista) {
        printf("%d ", lista -> dado);
        lista = lista -> proximo;
    }
}
```

## Lista Duplamente Encadeada

Em uma lista duplamente encadeada, na estrutura de nó, temos o tipo de dado no qual o programa irá trabalhar, um ponteiro para o próximo nó e **um ponteiro para o nó anterior**:

```C
typedef struct no {
    int dado;
    struct no *proximo;
    struct no *anterior;
} No;
```

### Inserir Início

```C
void inserirInicio(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> ant = NULL;
        novo -> prox = *lista;
        *lista = novo;
    } else {
        puts("Sem memória suficiente!");
    }
}
```

### Inserir Final

```C
void inserirFinal(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        if (*lista) {
            No *aux = *lista;
            
            while (aux -> prox)
                aux = aux -> prox;
            novo -> ant = aux;
            aux -> prox = novo;
            novo -> prox = NULL;
        } else {
            novo -> prox = *lista;
            novo -> ant = NULL;
            *lista = novo;
        }
    } else {
        puts("Sem memória suficiente!");
    }
}
```

### Inserir com Ordenação

```C
void inserirOrdenado(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        if (*lista) {
            if (novo -> dado < (*lista) -> dado) {
                novo -> prox = *lista;
                (*lista) -> ant = novo;
                *lista = novo;
            } else {
                No *aux = *lista;

                while (aux -> prox && aux -> prox -> dado < novo -> dado)
                    aux = aux -> prox;
                novo -> prox = aux -> prox;
                if (aux -> prox)
                    aux -> prox -> ant = novo;
                novo -> ant = aux;
                aux -> prox = novo;
            }
        } else {
            novo -> prox = NULL;
            novo -> ant = NULL;
            *lista = novo;
        }
    } else {
        puts("Sem memória suficiente!");
    }
}
```

### Remover Elemento

```C
No* excluirElemento(No **lista, int numero) {
    No *excluir = NULL;

    if (*lista) {
        if ((*lista) -> dado == numero) {
            excluir = (*lista) -> dado;
            *lista = excluir -> prox;
            if (*lista)
                (*lista) -> ant = NULL;
        } else {
            No *aux = *lista;

            while (aux -> prox && aux -> prox -> dado != numero)
                aux = aux -> prox;
            if (aux -> prox) {
                excluir = aux -> prox;
                aux -> prox = excluir -> prox;
                if (aux -> prox)
                    aux -> prox -> ant = aux;
            }
        }
    }

    return excluir;
}
```

### Buscar Elemento

```C
No* buscarElemento(No **lista, int numero) {
    No *busca = NULL;

    if (*lista) {
        No *aux = *lista;

        while (aux -> prox && aux -> prox -> dado != numero)
            aux = aux -> prox;
        if (aux -> prox)
            busca = aux -> prox;
    }

    return busca;
}
```

## Lista Circular

Uma lista circular caracteriza-se da seguinte forma: no último elemento da lista, o ponteiro para o próximo elemento irá apontar para o ínicio da lista. Dessa forma temos uma lista circular. É necessário ter cuidado ao realizar qualquer operação nessa lista para não cair em um loop infinito.
