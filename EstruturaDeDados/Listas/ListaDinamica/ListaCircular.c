#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void criarLista(Lista *lista) {
    lista -> inicio = NULL;
    lista -> fim = NULL;
    lista -> tamanho = 0;
}

void inserirInicio(Lista *lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> prox = lista -> inicio;
        lista -> inicio = novo;
        if (lista -> fim == NULL)
            lista -> fim = novo;
        lista -> fim -> prox = lista -> inicio;
        lista -> tamanho++;
    } else {
        puts("Sem memória suficiente!");
    }
}

void inserirFinal(Lista *lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;

        if (lista -> inicio == NULL) {
            lista -> inicio = novo;
            lista -> fim = novo;
            lista -> fim -> prox = lista -> inicio;
        } else {
            lista -> fim -> prox = novo;
            lista -> fim = novo;
            novo -> prox = lista -> inicio;
        }
        lista -> tamanho++;
    } else {
        puts("Sem memória suficiente!");
    }
}

void inserirOrdenado(Lista *lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;

        if (lista -> inicio == NULL) {
            inserirInicio(lista, numero);
        }
        else if (novo -> dado < lista -> inicio -> dado) {
            inserirInicio(lista, numero);
        }
        else {
            No *aux = lista -> inicio;
            while (aux -> prox != lista -> inicio && novo -> dado > aux -> prox -> dado)
                aux = aux -> prox;
            if (aux -> prox == lista -> inicio)
                inserirFinal(lista, numero);
            else {
                novo -> prox = aux -> prox;
                aux -> prox = novo;
                lista -> tamanho++;
            }
        }
    } else {
        puts("Sem memória suficiente!");
    }
}

No* removerElemento(Lista *lista, int numero) {
    No *excluir = NULL;

    if (lista -> inicio) {
        if (lista -> inicio == lista -> fim && lista -> inicio -> dado == numero) {
            excluir = lista -> inicio;
            lista -> inicio = NULL;
            lista -> fim = NULL;
            lista -> tamanho--;
        }
        else if (lista -> inicio -> dado == numero) {
            excluir = lista -> inicio;
            lista -> inicio = excluir -> prox;
            lista -> fim -> prox = lista -> inicio;
            lista -> tamanho--;
        }
        else {
            No *aux = lista -> inicio;

            while (aux -> prox != lista -> inicio && aux -> prox -> dado != numero)
                aux = aux -> prox;
            if (aux -> prox -> dado == numero) {
                if (lista -> fim == aux -> prox) {
                    excluir = aux -> prox;
                    aux -> prox = excluir -> prox;
                    lista -> fim = aux;
                } else {
                    excluir = aux -> prox;
                    aux -> prox = excluir -> prox;
                }
                lista -> tamanho--;
            }
        }
    }

    return excluir;
}

No* buscar(Lista *lista, int numero) {
    if (lista -> inicio) {
        No *aux = lista -> inicio;
        
        do {
            if (aux -> dado == numero)
                return aux;
            aux = aux -> prox;
        } while (aux != lista -> inicio);
    }

    return NULL;
}

void imprimir(Lista lista) {
    No *aux = lista.inicio;
    if (aux) {
        do {
            printf("%d ", aux -> dado);
            aux = aux -> prox;
        } while (aux != lista.inicio);
    }
    printf("\nTamanho da Lista: %d\n", lista.tamanho);
}

void lerNumero(int *numero) {
    printf("Digite um número: ");
    scanf("%d", numero);
}

int main() {
    Lista lista;
    criarLista(&lista);
    No *excluir, *busca;
    int sair = 0, numero, opcao;

    while (!sair) {
        do {
            puts("\n---- LISTA CIRCULAR ----");
            puts("Escolha uma das opções abaixo:");
            puts("[ 1 ] Inserir no Início [ 2 ] Inserir no Final [ 3 ] Inserir Ordenado");
            puts("[ 4 ] Remover Elemento [ 5 ] Buscar Elemento [ 6 ] Imprimir Lista");
            puts("[ 7 ] Sair");
            printf("Opção: ");
            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 7) puts("Opção inválida. Tente novamente!");
        } while (opcao < 1 || opcao > 7);

        switch (opcao) {
            case 1:
                lerNumero(&numero);
                inserirInicio(&lista, numero);
                puts("Número inserido com sucesso!");
                break;
            case 2:
                lerNumero(&numero);
                inserirFinal(&lista, numero);
                puts("Número inserido com sucesso!");
                break;
            case 3:
                lerNumero(&numero);
                inserirOrdenado(&lista, numero);
                puts("Número inserido com sucesso!");
                break;
            case 4:
                lerNumero(&numero);
                excluir = removerElemento(&lista, numero);
                if (excluir) {
                    puts("Elemento removido com sucesso!");
                    free(excluir);
                } else puts("Elemento não encontrado!");
                break;
            case 5:
                lerNumero(&numero);
                busca = buscar(&lista, numero);
                if (busca)
                    printf("Número %d encontrado!", busca -> dado);
                else
                    puts("Número não encontrado!");
                break;
            case 6: imprimir(lista); break;
            default: sair = 1;
        }
    }
    
    return 0;
}