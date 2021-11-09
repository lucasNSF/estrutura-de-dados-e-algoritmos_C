#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    int tamanho;
    No *inicio;
} Lista;

void criarLista(Lista *lista) {
    lista -> inicio = NULL;
    lista -> tamanho = 0;
}

void inserirElemento(Lista *lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;

        if (lista -> inicio) {
            if (lista -> inicio -> dado > novo -> dado) {
                novo -> prox = lista -> inicio;
                lista -> inicio = novo;
            } else {
                No *aux = lista -> inicio;
                while (aux -> prox && novo -> dado > aux -> prox -> dado)
                    aux = aux -> prox;
                novo -> prox = aux -> prox;
                aux -> prox = novo;
            }
        } else {
            novo -> prox = NULL;
            lista -> inicio = novo;
        }
        lista -> tamanho++;
    } else {
        puts("Sem memória suficiente!");
    }
}

No* removerElemento(Lista *lista, int numero) {
    No* excluir = NULL;

    if (lista -> inicio) {
        if (lista -> inicio -> dado == numero) {
            excluir = lista -> inicio;
            lista -> inicio = excluir -> prox;
        } else {
            No *aux = lista -> inicio;
            while (aux -> prox && aux -> prox -> dado != numero)
                aux = aux -> prox;
            if (aux -> prox) {
                excluir = aux -> prox;
                aux -> prox = excluir -> prox;
            }
        }
        lista -> tamanho--;
    }

    return excluir;
}

void imprimirLista(Lista lista) {
    No *aux = lista.inicio;
    while (aux) {
        printf("%d ", aux -> dado);
        aux = aux -> prox;
    }
    printf("\nQuantidade de Números = %d.\n", lista.tamanho);
}

No* buscarElemento(Lista *lista, int numero) {
    No *busca = NULL;

    if (lista -> inicio) {
        No *aux = lista -> inicio;
        while (aux && aux -> dado != numero)
            aux = aux -> prox;
        if (aux)
            busca = aux;
    }

    return busca;
}

void lerNumero(int *numero) {
    printf("Digite um número: ");
    scanf("%d", numero);
}

int main() {
    Lista lista;
    No *excluir, *busca;
    int numero, sair = 0, opcao;

    criarLista(&lista);

    while (!sair) {
        do {
            puts("\t---- LISTA ----");
            puts("Escolha uma das opções abaixo:");
            puts("[ 1 ] Inserir Número [ 2 ] Remover Número");
            puts("[ 3 ] Imprimir Lista [ 4 ] Buscar Número");
            puts("[ 5 ] Sair");
            printf("Opção: ");
            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 5) puts("Opção inválida. Tente novamente!");
        } while (opcao < 1 || opcao > 5);

        switch (opcao) {
            case 1:
                lerNumero(&numero);
                inserirElemento(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 2:
                lerNumero(&numero);
                excluir = removerElemento(&lista, numero);
                if (excluir) {
                    puts("Número removido com sucesso!\n");
                    free(excluir);
                } else puts("Número não encontrado!\n");
                break;
            case 3: imprimirLista(lista); break;
            case 4:
                lerNumero(&numero);
                busca = buscarElemento(&lista, numero);
                if (busca) {
                    printf("Número %d encontrado!\n", busca -> dado);
                } else puts("Número não encontrado!\n");
                break;
            default: sair = 1;
        }
    }
    
    return 0;
}