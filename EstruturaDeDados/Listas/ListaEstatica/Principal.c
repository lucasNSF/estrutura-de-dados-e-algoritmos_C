#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

int main() {
    /* Edite aqui da forma que você achar melhor! :3 */

    Lista *meusNumeros;

    meusNumeros = criarLista();
    printf("Está vazia? %d\n", estaVazia(meusNumeros));
    printf("Está cheia? %d\n", estaCheia(meusNumeros));
    
    inserirFinal(meusNumeros, 5);
    inserirInicio(meusNumeros, 50);
    inserirOrdenado(meusNumeros, 15);

    printf("Achou? %d\n", buscarNumero(meusNumeros, 10));

    excluirFinal(meusNumeros);
    excluirInicio(meusNumeros);
    excluirQualquer(meusNumeros, 50);
    
    return 0;
}