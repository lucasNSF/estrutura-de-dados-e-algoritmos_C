/* VERIFICAR EXPRESSÃO MATEMÁTICA

Neste exemplo, é utilizado a estrutura de dados Pilha para
verificar se uma expressão matemática está no formato correto,
dos parênteses, colchetes ou chaves. */

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int boolean;

typedef struct no {
    char elemento;
    struct no *proxNo;
} No;

No* push(No *pilha, char caractere) {
    No *novo = (No *) malloc(sizeof(No));
    
    if (novo) {
        novo -> elemento = caractere;
        novo -> proxNo = pilha;
        return novo;
    }

    return NULL;
}

No* pop(No **pilha) {
    if (*pilha) {
        No *aux = *pilha;
        *pilha = aux -> proxNo;
        return aux;
    }
    return NULL;
}

boolean validarExpressao(char expressao[]) {
    No *pilha = NULL, *remover;
    int cont = 0;
    boolean error = false;

    while (expressao[cont] != '\0') {
        if (expressao[cont] == '{' || 
            expressao[cont] == '[' || 
            expressao[cont] == '(') {
            pilha = push(pilha, expressao[cont]);
        } 
        
        else if (expressao[cont] == '}' ||
                expressao[cont] == ']' || 
                expressao[cont] == ')') {
            if (pilha) { error = true; break; }
            remover = pop(&pilha);

            if (remover -> elemento == '(')
                remover -> elemento += 1;
            else
                remover -> elemento += 2;
            
            if (remover -> elemento != expressao[cont]) {
                error = true; break;
            }
        }

        cont++;
    }

    if (pilha) error = true;

    return error;
}

int main() {
    char conta[50];
    boolean verificacao;

    printf("Digite uma expressão matemática: ");
    scanf("%[^\n]", conta);
    
    verificacao = validarExpressao(conta);
    
    printf("Tem erro? %d\n", verificacao);

    return 0;
}