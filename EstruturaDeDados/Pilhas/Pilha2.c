#include <stdio.h>
#include <stdlib.h>

int lerNumero();

// Estrutura que compõe um nó
typedef struct no {
    int dado;
    struct no *proxNo;
} No;

// Estrutura que compõe a pilha
typedef struct {
    No *topo;
} Pilha;

// Função responsável por criar a pilha
void criarPilha(Pilha *minhaPilha) {
    minhaPilha -> topo = NULL;
}

// Função empilhar elemento (push)
void empilhar(Pilha *minhaPilha) {
    No *novoNo = (No *) malloc(sizeof(No));

    if (novoNo != NULL) {
        novoNo -> dado = lerNumero();
        novoNo -> proxNo = minhaPilha -> topo;
        minhaPilha -> topo = novoNo;
    } else {
        puts("Sem memória suficiente!");
    }
}

// Função desempilhar elemento (pop)
No* desempilhar(Pilha *minhaPilha) {
    if (minhaPilha -> topo != NULL) {
        No *aux;
        aux = minhaPilha -> topo;
        minhaPilha -> topo = aux -> proxNo;
        return aux;
    } else {
        puts("A pilha está vazia!");
    }
    return NULL;
}

// Função que imprime os elementos da pilha
void imprimir(Pilha *minhaPilha) {
    No *aux = minhaPilha -> topo;
    puts("----------- PILHA ----------");
    while (aux != NULL) {
        printf("%d\n", aux -> dado);
        aux = aux -> proxNo;
    }
    puts("-----------FIM DA PILHA ----------");
}

// Função auxiliar para ler um número inteiro
int lerNumero() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    return numero;
}

int main() {
    Pilha pilhaNumeros;
    No *remover;

    criarPilha(&pilhaNumeros);

    int escolha = 0, opcao;
    while (escolha == 0) {
        do {
            puts("Escolha uma das opções:");
            puts("[ 1 ] Empilhar [ 2 ] Desempilhar [ 3 ] Imprimir Pilha");
            puts("[ 0 ] Sair do Programa");

            printf("Opção: ");
            scanf("%d", &opcao);
            if (opcao < 0 || opcao > 3) puts("Opção inválida. Tente novamente!");
        } while (opcao < 0 || opcao > 3);

        switch (opcao) {
            case 1: empilhar(&pilhaNumeros); break;
            case 2: 
                remover = desempilhar(&pilhaNumeros);
                if (remover != NULL)
                    free(remover);
                else puts("A pilha está vazia!");
                break;
            case 3: imprimir(&pilhaNumeros); break;
            default: escolha = 1;
        }
    }
}