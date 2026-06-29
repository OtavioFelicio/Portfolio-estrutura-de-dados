#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
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
    Insere um elemento no final da lista circular.
*/
Lista* insere_final(Lista* l, int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novo->info = valor;

    /*
        Caso 1: lista vazia.
        O novo nó aponta para ele mesmo,
        pois ele é o primeiro e também o último.
    */
    if (l == NULL) {
        novo->prox = novo;
        return novo;
    }

    /*
        Caso 2: lista já possui elementos.
        Precisamos encontrar o último nó.
        Na lista circular, o último nó é aquele cujo próximo aponta para o início.
    */
    Lista* p = l;

    while (p->prox != l) {
        p = p->prox;
    }

    /*
        Agora p está no último nó.
        O último passa a apontar para o novo nó.
        O novo nó aponta para o início da lista.
    */
    p->prox = novo;
    novo->prox = l;

    return l;
}

/*
    Imprime a lista circular.

    Como a lista circular não termina em NULL,
    usamos do...while para imprimir pelo menos uma vez
    e parar quando voltarmos ao início.
*/
void imprime(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Lista* p = l;

    do {
        printf("%d -> ", p->info);
        p = p->prox;
    } while (p != l);

    printf("(volta ao inicio)\n");
}

/*
    Busca um valor dentro da lista circular.

    Retorna o endereço do nó encontrado.
    Caso não encontre, retorna NULL.
*/
Lista* busca(Lista* l, int valor) {
    if (l == NULL) {
        return NULL;
    }

    Lista* p = l;

    do {
        if (p->info == valor) {
            return p;
        }

        p = p->prox;
    } while (p != l);

    return NULL;
}

/*
    Libera toda a memória usada pela lista circular.
*/
void libera(Lista* l) {
    if (l == NULL) {
        return;
    }

    Lista* p = l->prox;

    while (p != l) {
        Lista* temp = p->prox;
        free(p);
        p = temp;
    }

    free(l);
}

int main(void) {
    Lista* lista = inicializa();

    lista = insere_final(lista, 10);
    lista = insere_final(lista, 20);
    lista = insere_final(lista, 30);
    lista = insere_final(lista, 40);

    printf("Lista circular:\n");
    imprime(lista);

    int valor_procurado = 30;

    Lista* encontrado = busca(lista, valor_procurado);

    if (encontrado != NULL) {
        printf("\nValor %d encontrado na lista.\n", valor_procurado);
    } else {
        printf("\nValor %d nao encontrado na lista.\n", valor_procurado);
    }

    libera(lista);

    return 0;
}