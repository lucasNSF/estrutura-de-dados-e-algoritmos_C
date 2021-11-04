/* CALCULADORA USANDO NOTAÇÃO PÓS FIXA

Neste exemplo é criado uma calculadora que resolve expressões
matemáticas utilizando a Notação Pós-Fixa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    float valor;
    struct no *proxNo;
} No;

No* push(No *pilha, float num) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> valor = num;
        novo -> proxNo = pilha;
        return novo;
    }

    return NULL;
}

No* pop(No **pilha) {
    No *aux;

    if (*pilha) {
        aux = *pilha;
        *pilha = aux -> proxNo;
    } else {
        aux = NULL;
    }

    return aux;
}

float operacao(float a, float b, char x) {
    switch (x) {
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
        default: return 0.0;
    }
}

float resolverExpressao(char conta[]) {
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(conta, " ");
    while (pt) {
        if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') {
            n1 = pop(&pilha);
            n2 = pop(&pilha);
            num = operacao(n2 -> valor, n1 -> valor, pt[0]);
            pilha = push(pilha, num);
            free(n1);
            free(n2);
        } else {
            num = strtol(pt, NULL, 10);
            pilha = push(pilha, num);
        }

        pt = strtok(NULL, " ");
    }

    n1 = pop(&pilha);
    num = n1 -> valor;
    free(n1);

    return num;
}

int main() {
    char exp[50] = {"5 3 2 + * 4 / 6 -"};

    printf("Resultado de %s = %.2f\n", exp, resolverExpressao(exp));
    
    return 0;
}