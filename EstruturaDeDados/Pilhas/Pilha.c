#include <stdio.h>
#include <stdlib.h>

// Estrutura que compõe um Nó
typedef struct no {
    int dado;
    struct no *proxNo;
} No;

// Função auxiliar para ler um número inteiro
int lerNumero() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    return numero;
}

// Função empilhar (push) elemento na pilha
No* empilhar(No *topo) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo != NULL) {
        novo -> dado = lerNumero();
        novo -> proxNo = topo;
        return novo;
    } else puts("Sem memória suficiente. Nó não foi criado!");
    return NULL;
}

// Função desempilhar (pop) elemento da pilha
No* desempilhar(No **topo) {
    if (*topo != NULL) {
        No *aux = *topo;
        *topo = aux -> proxNo;
        return aux;
    } else puts("A pilha está vazia!");
    return NULL;
}

// Função que imprime os elementos da pilha
void imprimir(No *pilha) {
    while (pilha != NULL) {
        printf("%d\n", pilha -> dado);
        pilha = pilha -> proxNo;
    }
}

// Função que exclui a pilha
void liberarPilha(No *topo) {
    No *aux;
    while (topo != NULL) {
        aux = topo;
        topo = aux -> proxNo;
        free(aux);
    }
    free(topo);
}

int main() {
    // Criando o ponteiro para o topo da pilha que está vazia
    No *topoDaPilha = NULL, *remover;

    // Menu de Opções interativo para o usuário
    int opcao = 1;
    while (opcao != 0) {
        do {
            puts("\t-=-=-=-= PILHA -=-=-=-=");
            puts("Escolha uma opção:");
            puts("[ 1 ] Empilhar [ 2 ] Desempilhar [ 3 ] Imprimir a Pilha");
            puts("[ 0 ] Sair do Programa");
            
            printf("Opção: ");
            scanf("%d", &opcao);
            if (opcao < 0 || opcao > 3) puts("Opção inválida. Tente novamente!");
        } while (opcao < 0 || opcao > 3);

        switch (opcao) {
            case 1: 
                topoDaPilha = empilhar(topoDaPilha); break;
            case 2: 
                remover = desempilhar(&topoDaPilha);
                if (remover != NULL) {
                    free(remover);
                } else puts("A pilha está vazia");
                break;
            case 3: 
                imprimir(topoDaPilha); break;
            default: liberarPilha(topoDaPilha);
        }
    }
}