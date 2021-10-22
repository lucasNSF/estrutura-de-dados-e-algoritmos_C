#ifndef __LISTAESTATICA_H_
#define __LISTAESTATICA_H_

typedef struct {
    int quantidadeNumeros;
    int numeros[10];
} Lista;

Lista* criarLista();
int estaVazia(Lista *listaNumeros);
int estaCheia(Lista *listaNumeros);

void inserirInicio(Lista *listaNumeros, int numero);
void inserirOrdenado(Lista *listaNumeros, int numero);
void inserirFinal(Lista *listaNumeros, int numero);

int buscarNumero(Lista *listaNumeros, int numero);

void excluirFinal(Lista *listaNumeros);
void excluirInicio(Lista *listaNumeros);
void excluirQualquer(Lista *listaNumeros, int numero);

#endif // __LISTAESTATICA_H_