#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

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

No* buscarElemento(No **lista, int numero) {
    No *busca = NULL, *aux = *lista;

    while (aux && aux -> dado != numero)
        aux = aux -> prox;
    
    if (aux)
        busca = aux;

    return busca;
}

void imprimirLista(No *lista) {
    printf("Lista: ");
    while (lista) {
        printf("%d ", lista -> dado);
        lista = lista -> prox;
    }
    printf("\n");
}

int main() {
    No *lista = NULL, *excluir, *busca;
    int saida = 0, opcao, numero;

    while (!saida) {
        do {
            puts("\t----- LISTA -----");
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
                printf("Digite um número: ");
                scanf("%d", &numero);
                inserirInicio(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite um número: ");
                scanf("%d", &numero);
                inserirFinal(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 3:
                printf("Digite um número: ");
                scanf("%d", &numero);
                inserirOrdenado(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 4:
                printf("Digite um número: ");
                scanf("%d", &numero);
                excluir = removerElemento(&lista, numero);
                if (excluir) {
                    puts("Número removido com sucesso!\n");
                    free(excluir);
                } break;
            case 5:
                printf("Digite um número: ");
                scanf("%d", &numero);
                busca = buscarElemento(&lista, numero);
                if (busca) 
                    printf("Número %d encontrado!\n", busca -> dado);
                break;
            case 6: imprimirLista(lista); break;
            default: saida = 1;
        }
    }
    
    return 0;
}