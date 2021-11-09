/* COPIAR LISTAS

Neste exemplo devemos copiar os conteúdos de 2 listas A e B em uma nova lista C.
*/

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

void inserirOrdenado(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;

        if (*lista) {
            if (novo -> dado < (*lista) -> dado) {
                novo -> prox = *lista;
                *lista = novo;
            } else {
                No *aux = *lista;
                while (aux -> prox && aux -> prox -> dado < novo -> dado)
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

void imprimir(No *lista) {
    while (lista) {
        printf("%d ", lista -> dado);
        lista = lista -> prox;
    }
    printf("\n");
}

void copiarLista(No **listaOrigem, No **listaDestino) {
    No *auxOrigem = *listaOrigem;

    while (auxOrigem) {
        inserirOrdenado(listaDestino, auxOrigem -> dado);
        auxOrigem = auxOrigem -> prox;
    }
}

int main() {
    No *listaA = NULL, *listaB = NULL, *listaC = NULL;
    int numero;

    puts("\t---- LISTA A ----");
    for (int i = 0; i < 5; i++) {
        printf("Digite um número: ");
        scanf("%d", &numero);
        inserirInicio(&listaA, numero);
    }

    puts("\t---- LISTA B ----");
    for (int i = 0; i < 5; i++) {
        printf("Digite um número: ");
        scanf("%d", &numero);
        inserirInicio(&listaB, numero);
    }

    copiarLista(&listaA, &listaC);
    copiarLista(&listaB, &listaC);

    printf("Lista A: ");
    imprimir(listaA);
    printf("Lista B: ");
    imprimir(listaB);
    printf("Lista C: ");
    imprimir(listaC);

    return 0;
}