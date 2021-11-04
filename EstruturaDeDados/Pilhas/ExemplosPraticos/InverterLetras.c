/* INVERTER LETRAS DE UMA STRING

Neste exemplo, dado uma string, o programa deve inverter as letras dessa string
mantendo a ordem das palavras. Exemplo: OLA MUNDO ficará ALO ODNUM.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char letra;
    struct no *proxNo;
} No;

No* push(No *pilha, char elemento) {
    No *novo = (No *) malloc(sizeof(No));
    
    if (novo) {
        novo -> letra = elemento;
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

void inverterLetras(char frase[]) {
    No *pilha = NULL, *excluir;
    int cont = 0;

    while (frase[cont] != '\0') {
        if (frase[cont] == ' ') {
            while (pilha) {
                excluir = pop(&pilha);
                printf("%c", excluir -> letra);
                free(excluir);
            }
            printf("%c", frase[cont]);
        } else {
            pilha = push(pilha, frase[cont]);
        }
        cont++;
    }

    while (pilha) {
        excluir = pop(&pilha);
        printf("%c", excluir -> letra);
        free(excluir);
    }
}

int main() {
    char frase[100];

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);
    
    inverterLetras(frase);

    return 0;
}