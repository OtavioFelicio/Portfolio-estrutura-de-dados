#include <stdio.h>
#include <stdlib.h>


/* Definição do nó da pilha */
typedef struct no {
    int info;
    struct no* prox;
} No;

/* Estrutura principal da pilha */
typedef struct {
    No* topo;
} PilhaDinamica;

/*
    Inicializa a pilha dinâmica.

    O topo começa apontando para NULL,
    indicando que a pilha está vazia.
*/
PilhaDinamica* inicializaPilhaDinamica() {
    PilhaDinamica* p = (PilhaDinamica*) malloc(sizeof(PilhaDinamica));

    if (p == NULL) {
        printf("Erro ao alocar memoria para a pilha.\n");
        exit(1);
    }

    p->topo = NULL;

    return p;
}

/*
    Verifica se a pilha está vazia.

    Retorna 1 se estiver vazia.
    Retorna 0 caso contrário.
*/
int pilhaVazia(PilhaDinamica* p) {
    return p->topo == NULL;
}

/*
    Operação PUSH.

    Insere um novo elemento no topo da pilha.
    Como a pilha é dinâmica, um novo nó é criado com malloc.
*/
void pushDinamico(PilhaDinamica* p, int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria para o novo no.\n");
        exit(1);
    }

    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;

    printf("Valor %d empilhado com sucesso.\n", valor);
}

/*
    Operação POP.

    Remove o elemento do topo da pilha e retorna seu valor.
    Como a pilha segue LIFO, o último valor inserido será removido primeiro.
*/
int popDinamico(PilhaDinamica* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Stack Underflow. A pilha esta vazia.\n");
        exit(1);
    }

    No* noRemovido = p->topo;
    int valor = noRemovido->info;

    p->topo = noRemovido->prox;

    free(noRemovido);

    return valor;
}

/*
    Consulta o elemento do topo sem removê-lo.
*/
int consultarTopo(PilhaDinamica* p) {
    if (pilhaVazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    }

    return p->topo->info;
}

/*
    Imprime os elementos da pilha.

    A impressão começa pelo topo, pois ele é o primeiro elemento acessível.
*/
void imprimirPilha(PilhaDinamica* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    No* atual = p->topo;

    printf("Pilha do topo para a base: ");

    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }

    printf("\n");
}

/*
    Libera todos os nós da pilha.

    Essa função evita vazamento de memória.
*/
void liberarPilha(PilhaDinamica* p) {
    No* atual = p->topo;

    while (atual != NULL) {
        No* temp = atual->prox;
        free(atual);
        atual = temp;
    }

    free(p);
}

int main(void) {
    PilhaDinamica* pilha = inicializaPilhaDinamica();

    printf("Inserindo elementos na pilha:\n");
    pushDinamico(pilha, 10);
    pushDinamico(pilha, 20);
    pushDinamico(pilha, 30);
    pushDinamico(pilha, 40);

    printf("\nEstado atual da pilha:\n");
    imprimirPilha(pilha);

    printf("\nElemento no topo: %d\n", consultarTopo(pilha));

    printf("\nRemovendo elementos da pilha:\n");
    printf("Valor removido: %d\n", popDinamico(pilha));
    printf("Valor removido: %d\n", popDinamico(pilha));

    printf("\nEstado da pilha apos remocoes:\n");
    imprimirPilha(pilha);

    printf("\nInserindo novo elemento:\n");
    pushDinamico(pilha, 50);

    printf("\nEstado final da pilha:\n");
    imprimirPilha(pilha);

    liberarPilha(pilha);

    return 0;
}