#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int frente;
    int fim;
} Fila;

/*
    Inicializa a fila.

    frente = 0 indica o início da fila.
    fim = -1 indica que a fila começa vazia.
*/
void inicializar(Fila *f) {
    f->frente = 0;
    f->fim = -1;
}

/*
    Verifica se a fila está vazia.

    Retorna 1 se estiver vazia.
    Retorna 0 se não estiver vazia.
*/
int filaVazia(Fila *f) {
    return f->fim < f->frente;
}

/*
    Verifica se a fila está cheia.

    Como o vetor tem tamanho fixo, a fila estará cheia
    quando fim chegar ao último índice do vetor.
*/
int filaCheia(Fila *f) {
    return f->fim == MAX - 1;
}

/*
    Insere um elemento no final da fila.
*/
void enqueue(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }

    f->fim++;
    f->dados[f->fim] = valor;

    printf("Valor %d inserido na fila.\n", valor);
}

/*
    Remove o primeiro elemento da fila.

    Como a fila segue FIFO, a remoção acontece na frente.
*/
int dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    int valorRemovido = f->dados[f->frente];
    f->frente++;

    /*
        Se depois da remoção a fila ficar vazia,
        reinicializamos os índices.
    */
    if (filaVazia(f)) {
        inicializar(f);
    }

    return valorRemovido;
}

/*
    Consulta o primeiro elemento da fila sem removê-lo.
*/
int consultarFrente(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    return f->dados[f->frente];
}

/*
    Mostra todos os elementos válidos da fila.
*/
void mostrar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");

    for (int i = f->frente; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }

    printf("\n");
}

int main(void) {
    Fila fila;

    inicializar(&fila);

    printf("Inserindo elementos na fila:\n");
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    enqueue(&fila, 40);
    enqueue(&fila, 50);

    printf("\nEstado atual da fila:\n");
    mostrar(&fila);

    printf("\nConsultando o primeiro elemento:\n");
    printf("Frente da fila: %d\n", consultarFrente(&fila));

    printf("\nRemovendo elementos:\n");
    printf("Elemento removido: %d\n", dequeue(&fila));
    printf("Elemento removido: %d\n", dequeue(&fila));

    printf("\nEstado da fila apos remocoes:\n");
    mostrar(&fila);

    printf("\nConsultando novamente a frente:\n");
    printf("Frente da fila: %d\n", consultarFrente(&fila));

    return 0;
}