/* SIMULADOR DE RECURSIVIDADE 

Exemplo prático de como simular uma recursão utilizando uma pilha.
No exemplo foi utilizado uma função de cálculo de fatorial de um número. */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proxNo;
} No;

No* push(No *minhaPilha, int numero) {
    No *novo = (No *) malloc(sizeof(No));
    
    if (!novo) {
        puts("Sem memória suficiente! Encerrando...");
        exit(1);
    } else {
        novo -> dado = numero;
        novo -> proxNo = minhaPilha;
        return novo;
    }
}

No* pop(No **minhaPilha) {
    No *aux;
    aux = *minhaPilha;
    *minhaPilha = aux -> proxNo;
    return aux;
}

int fatorial(int numero) {
    No *remover, *pilhaDeRecursao = NULL;

    while (numero > 1) {
        pilhaDeRecursao = push(pilhaDeRecursao, numero);
        numero--;
    }

    while (pilhaDeRecursao) {
        remover = pop(&pilhaDeRecursao);
        numero = numero * remover -> dado;
        free(remover);
    }

    return numero;
}

int main() {
    printf("%d\n", fatorial(5));
    return 0;
}