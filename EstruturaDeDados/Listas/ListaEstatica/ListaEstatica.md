# Lista Estática

A lista estática é um tipo de Estrutura de Dados na qual é implementada utilizando vetores. Possui as seguintes peculiaridades:

- Tamanho fixo na memória
- Boa para consultas rápidas

Para se trabalhar com uma lista estática deve-se saber o tamanho definido daquilo que se queira trabalhar. Ainda é possível definir esse tamanho a partir de um número digitado pelo usuário, veja abaixo como isso é feito:

```C
int tamanho;
printf("Insira o tamanho do seu vetor: ");
scanf("%d", &tamanho);

int *vetor;
vetor = (int *) malloc(sizeof(int) * tamanho);
```

Veja que o código acima é diferente disso:

```C
int tamanho;
printf("Insira o tamanho do seu vetor: ");
scanf("%d", &tamanho);

int vet[tamanho];
```

Esse 2º código irá gerar erro e não será compilado pelo processador. Na 1ª opção criamos um ponteiro `vetor` e alocamos memória suficiente para N tamanhos escolhidos pelo usuário. Dessa forma, podemos trabalhar com o ponteiro normalmente. Abaixo segue um exemplo de preenchimento do vetor:

```C
int tamanho;
printf("Insira o tamanho do seu vetor: ");
scanf("%d", &tamanho);

int *vetor;
vetor = (int *) malloc(sizeof(int) * tamanho);

// Preenchendo o vetor normalmente
for (int i = 0; i < tamanho; i++) {
    printf("Digite um número: ");
    scanf("%d", &vetor[i]);
}
```

**E se caso o usuário querer mudar o tamanho do vetor durante a execução?** Basta realocarmos a memória usada no vetor:

```C
int tamanho;
printf("Insira o tamanho do seu vetor: ");
scanf("%d", &tamanho);

int *vetor;
vetor = (int *) malloc(sizeof(int) * tamanho);

int acrescimo;
printf("Insira outro tamanho de acréscimo para seu vetor: ");
scanf("%d", &acrescimo);

vetor = (int *) realloc(y, sizeof(int) * (tamanho + acrescimo));
```

Lembre-se que, ao finalizar seu programa, deve sempre liberar a memória que foi alocada para a lista:

```C
free(vetor);
```

Em um projeto com múltiplos arquivos em C que trabalhe com listas estáticas é comum ser organizado da seguinte forma:

- **Arquivo `.h`**: Colocamos aqui a estrutura de dados que vamos trabalhar (aluno, números, professores, etc), a estrutura da Lista e os protótipos das funções da Lista.
- **Arquivo `.c`**: Colocamos aqui as implementações das funções do arquivo `.h`.

    **OBS** - Como exemplo vamos utilizar uma lista de números.

Agora daremos início à implementação da Lista Estática e todas as suas funções básicas.

## Criar Lista

Vamos criar uma função responsável por criar a nossa lista de números.

Antes disso precisamos criar a nossa estrutura de lista. Veja abaixo o código da nossa estrutura situado no arquivo `ListaEstatica.h`:

```C
typedef struct {
    // Variável contadora dos números inseridos
    int quantidadeNumeros;
    // Array de números
    int numeros[10];
} Lista;
```

A variável `quantidadeNumeros` irá controlar o fluxo dos números que são inseridos ou excluídos na nossa lista `numeros`. Assim não perdemos a referência da **quantidade real** dos números que estão dentro da lista.

Agora vamos implementar a nossa função de criar a lista:

```C
// Protótipo no arquivo .h
Lista* criarLista();
```

```C
/* Implementação no arquivo .c */

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
```

```C
// Utilização no arquivo principal
Lista *meusNumeros;

meusNumeros = criarLista();
```

### Lista Vazia

Vamos criar uma função que verifica se a lista está vazia. Nossa função irá retornar um valor inteiro caso ele esteja vazia ou não. Para fazer essa verificação basta analisarmos a nossa variável `quantidadeNumeros` presente na nossa estrutura de Lista. Isso pode ser feito da seguinte forma:

```C
// Protótipo no arquivo .h
int estaVazia(Lista *listaNumeros);
```

```C
/* Implementação da função no arquivo .c */

int estaVazia(Lista *listaNumeros) {
    if (listaNumeros -> quantidadeNumeros == 0) return 1;
    return 0;
}
```

```C
// Utilização no arquivo principal
printf("Está vazia? %d", estaVazia(meusNumeros));
```

### Lista Cheia

Da mesma forma que a verificação de lista vazia, vamos fazer a verificação de lista cheia:

```C
// Protótipo no arquivo .h
int estaCheia(Lista *listaNumeros);
```

```C
/* Implementação no arquivo .c */

int estaCheia(Lista *listaNumeros) {
    if (listaNumeros -> quantidadeNumeros == 10) return 1;
    return 0;
}
```

```C
// Utilização no arquivo principal
printf("Está Cheia? %d", estaCheia(meusNumeros));
```

Note que, na implementação da função, a comparação com o número `10` se refere ao tamanho fixo da lista.

### Inserir Número na Lista

Vamos criar uma função que insere um número qualquer na lista. Existem 3 formas de se inserir um número na lista:

- Inserir no Início
- Inserir no Meio
- Inserir no Final

Para ambos os casos não podemos esquecer de sempre incrementar a variável `quantidadeNumeros` da nossa estrutura de lista. Vejamos os 3 modos de inserção na lista:

#### 1. **Inserção no Final**

Para inserirmos no final da lista é bastante simples. Basta utilizarmos a variável `quantidadeNumeros` como indíce da lista. Assim sempre adicionaremos o número no final da lista:

```C
// Protótipo no arquivo .h
void inserirFinal(Lista *listaNumeros, int numero);
```

```C
/* Implementação no arquivo .c */

void inserirFinal(Lista *listaNumeros, int numero) {
    if (estaCheia(listaNumeros)) {
        puts("A lista já está cheia!");
    } else {
        listaNumeros -> numeros[listaNumeros -> quantidadeNumeros] = numero;
        listaNumeros -> quantidadeNumeros++;
        puts("Número inserido!");
    }
}
```

```C
// Utilização no arquivo principal
inserirFinal(meusNumeros, 5);
```

#### 2. **Inserção no Início**

Para inserirmos um número no início, deslocaremos todos os números presentes na lista uma posição a mais. Depois disso, inserimos o número:

```C
// Protótipo no arquivo .h
void inserirInicio(Lista *listaNumeros, int numero);
```

```C
/* Implementação no arquivo.c */

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
```

```C
// Utilização no arquivo principal
inserirInicio(meusNumeros, 50);
```

#### 3. **Inserir Ordenado**

Podemos inserir também um elemento de forma ordenada na lista, isso facilita consultas futuras utilizando o algoritmo de Busca Binária:

```C
// Protótipo no arquivo .h
void inserirOrdenado(Lista *listaNumeros, int numero);
```

```C
/* Implementação no arquivo .c */

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
```

```C
// Utilização no arquivo principal
inserirOrdenado(meusNumeros, -4);
```

### Consulta na Lista

Realizar uma consulta na lista também é bastante trivial. Caso a lista já esteja ordenada, então podemos aplicar o algoritmo de Busca Binária para melhor otimização; caso contrário, executamos uma busca sequencial:

```C
// Protótipo no arquivo .h
int buscarNumero(Lista *listaNumeros, int numero);
```

```C
/* Implementação no arquivo .c */

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
```

```C
// Utilização no arquivo principal
printf("Achou? %d", buscarNumero(meusNumeros, 10));
```

### Excluir Número da Lista

Assim como nos métodos de inserção, podemos excluir um número da lista das seguintes formas:

- Excluir no Início
- Excluir no Meio
- Excluir no Final

Lembrando que não é possível excluir um elemento da lista caso ela esteja vazia. Vejamos agora as implementações dos 3 casos de exclusão:

#### 1. **Excluir no Final**

```C
// Protótipo no arquivo .h
void excluirFinal(Lista *listaNumeros);
```

```C
/* Implementação no arquivo .c */

void excluirFinal(Lista *listaNumeros) {
    if (estaVazia(listaNumeros)) {
        puts("A lista está vazia!");
    } else {
        listaNumeros -> quantidadeNumeros--;
        puts("Número excluído!");
    }
}
```

```C
// Utilização no arquivo principal
excluirFinal(meusNumeros);
```

#### 2. **Excluir no Início**

```C
// Protótipo no arquivo .h
void excluirInicio(Lista *listaNumeros);
```

```C
/* Implementação no arquivo .c */

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
```

```C
// Utilização no arquivo principal
excluirInicio(meusNumeros);
```

#### 3. **Excluir um Número Qualquer**

Para excluir um número da lista em uma posição qualquer, primeiro devemos identificar seu índice e, em seguida, removê-lo:

```C
// Protótipo no arquivo .h
void excluirQualquer(Lista *listaNumeros, int numero);
```

```C
/* Implementação no arquivo .c */

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
```

```C
// Utilização na função principal
excluirQualquer(meusNumeros, 25);
```

Pronto! Agora você já sabe implementar uma lista estática e pode baixar agora o arquivo de código para editar livremente como quiser! **Obrigado por ler até aqui!** 😄
