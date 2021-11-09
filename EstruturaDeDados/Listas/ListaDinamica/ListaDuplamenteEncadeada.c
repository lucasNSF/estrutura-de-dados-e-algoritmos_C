#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox, *ant;
} No;

void inserirInicio(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        novo -> ant = NULL;
        novo -> prox = *lista;
        *lista = novo;
    } else {
        puts("Sem memória suficiente!");
    }
}

void inserirFinal(No **lista, int numero) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo) {
        novo -> dado = numero;
        if (*lista) {
            No *aux = *lista;
            
            while (aux -> prox)
                aux = aux -> prox;
            novo -> ant = aux;
            aux -> prox = novo;
            novo -> prox = NULL;
        } else {
            novo -> prox = *lista;
            novo -> ant = NULL;
            *lista = novo;
        }
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
                (*lista) -> ant = novo;
                *lista = novo;
            } else {
                No *aux = *lista;

                while (aux -> prox && aux -> prox -> dado < novo -> dado)
                    aux = aux -> prox;
                novo -> prox = aux -> prox;
                if (aux -> prox)
                    aux -> prox -> ant = novo;
                novo -> ant = aux;
                aux -> prox = novo;
            }
        } else {
            novo -> prox = NULL;
            novo -> ant = NULL;
            *lista = novo;
        }
    } else {
        puts("Sem memória suficiente!");
    }
}

No* excluirElemento(No **lista, int numero) {
    No *excluir = NULL;

    if (*lista) {
        if ((*lista) -> dado == numero) {
            excluir = (*lista) -> dado;
            *lista = excluir -> prox;
            if (*lista)
                (*lista) -> ant = NULL;
        } else {
            No *aux = *lista;

            while (aux -> prox && aux -> prox -> dado != numero)
                aux = aux -> prox;
            if (aux -> prox) {
                excluir = aux -> prox;
                aux -> prox = excluir -> prox;
                if (aux -> prox)
                    aux -> prox -> ant = aux;
            }
        }
    }

    return excluir;
}

No* buscarElemento(No **lista, int numero) {
    No *busca = NULL;

    if (*lista) {
        No *aux = *lista;

        while (aux -> prox && aux -> prox -> dado != numero)
            aux = aux -> prox;
        if (aux -> prox)
            busca = aux -> prox;
    }

    return busca;
}

void imprimirLista(No *lista) {
    while(lista) {
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
    No *lista = NULL, *busca, *excluir;
    int sair = 0, numero, opcao;

    while (!sair) {
        do {
            puts("\n\t---- LISTA DUPLAMENTE ENCADEADA ----");
            puts("Escolha uma das opções abaixo:");
            puts("[ 1 ] Inserir no Início [ 2 ] Inserir no Final [ 3 ] Inserir Ordenado");
            puts("[ 4 ] Remover Elemento [ 5 ] Buscar Elemento [ 6 ] Imprimir Lista");
            puts("[ 7 ] Sair");
            printf("Opção: ");
            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 7) puts("Opção inválida. Tente novamente!");
        } while (opcao < 1 || opcao > 7);

        switch (opcao) {
            case 1:
                lerNumero(&numero);
                inserirInicio(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 2:
                lerNumero(&numero);
                inserirFinal(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 3: 
                lerNumero(&numero);
                inserirOrdenado(&lista, numero);
                puts("Número inserido com sucesso!\n");
                break;
            case 4:
                lerNumero(&numero);
                excluir = excluirElemento(&lista, numero);
                if (excluir) {
                    puts("Número removido com sucesso!\n");
                    free(excluir);
                } else puts("Número não encontrado!\n");
                break;
            case 5:
                lerNumero(&numero);
                busca = buscarElemento(&lista, numero);
                if (busca)
                    printf("Número %d encontrado!", busca -> dado);
                else puts("Número não encontrado!\n");
                break;
            case 6: imprimirLista(lista); break;
            default: sair = 1;
        }
    }
    
    return 0;
}