#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

void inqueue(No **fila, int num) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = num;
        novo -> prox = NULL;

        if (*fila) {
            No *aux = *fila;
            
            if (novo -> dado > 59) { // Critério de Prioridade
                if ((*fila) -> dado > 59) {
                    while (aux -> prox && aux -> prox -> dado > 59)
                        aux = aux -> prox;
                    novo -> prox = aux -> prox;
                    aux -> prox = novo;
                } else {
                    novo -> prox = *fila;
                    *fila = novo;
                }
            } else {
                while (aux -> prox)
                    aux = aux -> prox;
                aux -> prox = novo;
            }
        } else {
            *fila = novo;
        }
    } else { puts("Sem memória suficiente!"); }
}

No* dequeue(No **fila) {
    No *aux = NULL;

    if (*fila) {
        aux = *fila;
        *fila = aux -> prox;
    }

    return aux;
}

void imprimir(No *fila) {
    while (fila) {
        printf("%d - ", fila -> dado);
        fila = fila -> prox;
    }
}

int main() {
    No *fila = NULL, *excluir;
    int opcao, saida = 0, numero;

    while (!saida) {
        do {
            puts("Escolha uma das opções para manipular a Fila: ");
            puts("[ 1 ] Inserir na fila [ 2 ] Retirar da Fila [ 3 ] Imprimir Fila");
            puts("[ 0 ] Sair");
            printf("Opção: ");
            scanf("%d", &opcao);
            
            if (opcao < 0 || opcao > 3) puts("Opção inválida. Tente Novamente!");
        } while (opcao < 0 || opcao > 3);

        switch (opcao) {
            case 1:
                printf("Digite um número para inserir na fila: ");
                scanf("%d", &numero);
                inqueue(&fila, numero); 
                puts("Número inserido com sucesso!");
                break;
            case 2:
                excluir = dequeue(&fila);
                free(excluir);
                puts("Elemento excluído com sucesso!");
                break;
            case 3: imprimir(fila); break;
            default: saida = 1;
        }
    }
    
    return 0;
}