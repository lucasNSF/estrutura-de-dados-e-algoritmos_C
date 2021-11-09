/* DIVIDIR LISTA 

Dividir uma lista A de números inteiros em 2 listas com
números pares e ímpares.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

void inserirElemento(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> prox = *lista;
        *lista = novo;
    } else {
        puts("Sem memória suficiente!");
    }
}

No* dividirPares(No **lista) {
    No *listaDividida = NULL, *auxLista = *lista;

    while (auxLista) {
        if (auxLista -> dado % 2 == 0)
            inserirElemento(&listaDividida, auxLista -> dado);
        auxLista = auxLista -> prox;
    }

    return listaDividida;
}

No* dividirImpares(No **lista) {
    No *listaDividida = NULL, *auxLista = *lista;

    while (auxLista) {
        if (auxLista -> dado % 2 != 0)
            inserirElemento(&listaDividida, auxLista -> dado);
        auxLista = auxLista -> prox;
    }

    return listaDividida;
}

void imprimir(No *lista) {
    while (lista) {
        printf("%d ", lista -> dado);
        lista = lista -> prox;
    }
    printf("\n");
}

void lerNumero(int *numero) {
    printf("Digite um número: ");
    scanf("%d", numero);
}

int main() {
    No *lista = NULL, *listaPar = NULL, *listaImpar = NULL;
    int numero;

    for (int i = 0; i < 10; i++) {
        lerNumero(&numero);
        inserirElemento(&lista, numero);
    }

    listaPar = dividirPares(&lista);
    listaImpar = dividirImpares(&lista);

    printf("Lista Original: ");
    imprimir(lista);
    printf("Lista Par: ");
    imprimir(listaPar);
    printf("Lista Ímpar: ");
    imprimir(listaImpar);
    
    return 0;
}