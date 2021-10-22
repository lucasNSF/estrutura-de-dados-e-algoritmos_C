#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

// Função responsável por criar a lista de números
Lista* criarLista() {
    // Ponteiro para nossa lista de números
    Lista *listaNumeros;
    // Alocando memória para criar a nossa lista
    listaNumeros = (Lista *) malloc(sizeof(Lista));

    if (listaNumeros == NULL) { // Não alocou a memória
        puts("Erro, sem memória suficiente!");
        exit(1); // Forçando a saída do programa
    } else { // Lista foi criada com sucesso
        listaNumeros -> quantidadeNumeros = 0;
    }
    return listaNumeros;
}

// Função que verifica se a lista está vazia
int estaVazia(Lista *listaNumeros) {
    if (listaNumeros -> quantidadeNumeros == 0) return 1;
    return 0;
}

// Função que verifica se a lista está cheia
int estaCheia(Lista *listaNumeros) {
    if (listaNumeros -> quantidadeNumeros == 10) return 1;
    return 0;
}

// Função que insere um número no final da lista
void inserirFinal(Lista *listaNumeros, int numero) {
    if (estaCheia(listaNumeros)) {
        puts("A lista já está cheia!");
    } else {
        listaNumeros -> numeros[listaNumeros -> quantidadeNumeros] = numero;
        listaNumeros -> quantidadeNumeros++;
        puts("Número inserido!");
    }
}

// Função que insere um número no início da lista
void inserirInicio(Lista *listaNumeros, int numero) {
    if (estaCheia(listaNumeros)) {
        puts("A lista já está cheia!");
    } else {
        for (int i = listaNumeros -> quantidadeNumeros - 1; i >= 0; i--) {
            listaNumeros -> numeros[i + 1] = listaNumeros -> numeros[i];
        }
        listaNumeros -> numeros[0] = numero;
        listaNumeros -> quantidadeNumeros++;
        puts("Número inserido!");
    }
}

// Função que insere um número em ordem crescente na lista
void inserirOrdenado(Lista *listaNumeros, int numero) {
    if (estaCheia(listaNumeros)) {
        puts("A lista já está cheia!");
    } else {
        int i = 0;
        while (i < listaNumeros -> quantidadeNumeros && listaNumeros -> numeros[i] < numero)
            i++;
        for (int k = listaNumeros -> quantidadeNumeros; k >= i; k--) {
            listaNumeros -> numeros[k + 1] = listaNumeros -> numeros[k];
        }
        listaNumeros -> numeros[i] = numero;
        listaNumeros -> quantidadeNumeros++;
        puts("Número inserido!");
    }
}

// Função responsável por buscar um número na lista
int buscarNumero(Lista *listaNumeros, int numero) {
    // Implementando busca sequencial
    for (int i = 0; i < listaNumeros -> quantidadeNumeros; i++) {
        if (listaNumeros -> numeros[i] == numero) {
            puts("Número encontrado!");
            return 1;
        }
    }
    puts("Número não encontrado!");
    return 0;
}

// Função que exclui um número no final da lista
void excluirFinal(Lista *listaNumeros) {
    if (estaVazia(listaNumeros)) {
        puts("A lista está vazia!");
    } else {
        listaNumeros -> quantidadeNumeros--;
        puts("Número excluído!");
    }
}

// Função que exclui um número no ínicio da lista
void excluirInicio(Lista *listaNumeros) {
    if (estaVazia(listaNumeros)) {
        puts("A lista está vazia!");
    } else {
        /* Empurramos o número no início da lista para "fora" dela */
        int aux;
        for (int i = 0; i < listaNumeros -> quantidadeNumeros; i++) {
            aux = listaNumeros -> numeros[i + 1];
            listaNumeros -> numeros[i + 1] = listaNumeros -> numeros[i];
            listaNumeros -> numeros[i] = aux;
        }
        listaNumeros -> quantidadeNumeros--;
        puts("Número excluído!");
    }
}

// Função que exclui um número qualquer da lista
void excluirQualquer(Lista *listaNumeros, int numero) {
    if (estaVazia(listaNumeros)) {
        puts("A lista está vazia!");
    } else {
        int i = 0;
        while (i < listaNumeros -> quantidadeNumeros && listaNumeros -> numeros[i] != numero)
            i++;
        if (i == listaNumeros -> quantidadeNumeros) {
            puts("Número não encontrado!");
        } else {
            int aux;
            for (int k = i; k < listaNumeros -> quantidadeNumeros; k++) {
                aux = listaNumeros -> numeros[k + 1];
                listaNumeros -> numeros[k + 1] = listaNumeros -> numeros[k];
                listaNumeros -> numeros[k] = aux;
            }
            listaNumeros -> quantidadeNumeros--;
            puts("Número excluído!");
        }
    }
}
