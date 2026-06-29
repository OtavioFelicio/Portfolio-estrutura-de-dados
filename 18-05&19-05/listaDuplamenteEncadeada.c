#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* ant;
    struct lista* prox;
} Lista;

/*
    Inicializa a lista.
    Uma lista vazia começa apontando para NULL.
*/
Lista* inicializa(void) {
    return NULL;
}

/*
    Cria um novo nó da lista.
*/
Lista* criarNo(int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

/*
    Insere um novo elemento no início da lista.
*/
Lista* inserirInicio(Lista* l, int valor) {
    Lista* novo = criarNo(valor);

    /*
        O novo nó aponta para o antigo primeiro nó.
    */
    novo->prox = l;

    /*
        Se a lista não estiver vazia,
        o antigo primeiro nó aponta para trás,
        ou seja, para o novo nó.
    */
    if (l != NULL) {
        l->ant = novo;
    }

    /*
        O novo nó passa a ser o início da lista.
    */
    return novo;
}

/*
    Insere um novo elemento no final da lista.
*/
Lista* inserirFinal(Lista* l, int valor) {
    Lista* novo = criarNo(valor);

    /*
        Se a lista estiver vazia,
        o novo nó será o primeiro elemento.
    */
    if (l == NULL) {
        return novo;
    }

    /*
        Percorre a lista até encontrar o último nó.
        O último nó é aquele cujo prox aponta para NULL.
    */
    Lista* p = l;

    while (p->prox != NULL) {
        p = p->prox;
    }

    /*
        Liga o antigo último nó ao novo nó.
        Depois, liga o novo nó de volta ao antigo último.
    */
    p->prox = novo;
    novo->ant = p;

    return l;
}

/*
    Imprime a lista do início para o fim.
*/
void imprimir(Lista* l) {
    Lista* p = l;

    printf("Lista em ordem normal: ");

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }

    printf("\n");
}

/*
    Imprime a lista do fim para o início.
*/
void imprimirReverso(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Lista* p = l;

    /*
        Primeiro, vamos até o último nó.
    */
    while (p->prox != NULL) {
        p = p->prox;
    }

    /*
        Depois, voltamos usando o ponteiro ant.
    */
    printf("Lista em ordem reversa: ");

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->ant;
    }

    printf("\n");
}

/*
    Busca um valor na lista.

    Retorna:
    - o endereço do nó encontrado;
    - NULL caso o valor não exista.
*/
Lista* buscar(Lista* l, int valor) {
    Lista* p = l;

    while (p != NULL) {
        if (p->info == valor) {
            return p;
        }

        p = p->prox;
    }

    return NULL;
}

/*
    Libera toda a memória alocada pela lista.
*/
void liberar(Lista* l) {
    Lista* p = l;

    while (p != NULL) {
        Lista* temp = p->prox;
        free(p);
        p = temp;
    }
}

int main(void) {
    Lista* lista = inicializa();

    /*
        Inserindo no início:
        Depois dessas inserções, a lista ficará:
        10 20 30
    */
    lista = inserirInicio(lista, 30);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 10);

    /*
        Inserindo no final:
        A lista ficará:
        10 20 30 40 50
    */
    lista = inserirFinal(lista, 40);
    lista = inserirFinal(lista, 50);

    imprimir(lista);
    imprimirReverso(lista);

    int valorProcurado = 30;

    Lista* resultado = buscar(lista, valorProcurado);

    if (resultado != NULL) {
        printf("Valor %d encontrado na lista.\n", valorProcurado);
    } else {
        printf("Valor %d nao encontrado na lista.\n", valorProcurado);
    }

    liberar(lista);

    return 0;
}