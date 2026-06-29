#include <stdio.h>
#include <stdlib.h>

#define MAX 5


typedef struct {
    int itens[MAX];
    int topo;
} PilhaEstatica;

/*
    Inicializa a pilha.

    O topo começa em -1 porque a pilha está vazia.
    Como os índices do vetor começam em 0, o valor -1 indica
    que ainda não existe nenhum elemento inserido.
*/
void inicializaPilha(PilhaEstatica *p) {
    p->topo = -1;
}

/*
    Verifica se a pilha está vazia.

    Retorna 1 se estiver vazia.
    Retorna 0 caso contrário.
*/
int pilhaVazia(PilhaEstatica *p) {
    return p->topo == -1;
}

/*
    Verifica se a pilha está cheia.

    A pilha estará cheia quando o topo chegar
    ao último índice do vetor.
*/
int pilhaCheia(PilhaEstatica *p) {
    return p->topo == MAX - 1;
}

/*
    Operação PUSH.

    Insere um novo elemento no topo da pilha.
    Antes de inserir, verifica se ainda há espaço no vetor.
*/
void push(PilhaEstatica *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Stack Overflow. Capacidade maxima atingida.\n");
        return;
    }

    p->topo++;
    p->itens[p->topo] = valor;

    printf("Valor %d empilhado com sucesso.\n", valor);
}

/*
    Operação POP.

    Remove e retorna o elemento do topo da pilha.
    Antes de remover, verifica se a pilha não está vazia.
*/
int pop(PilhaEstatica *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Stack Underflow. A pilha esta vazia.\n");
        exit(1);
    }

    int valor = p->itens[p->topo];
    p->topo--;

    return valor;
}

/*
    Consulta o elemento do topo sem removê-lo.
*/
int consultarTopo(PilhaEstatica *p) {
    if (pilhaVazia(p)) {
        printf("A pilha esta vazia.\n");
        exit(1);
    }

    return p->itens[p->topo];
}

/*
    Imprime os elementos da pilha.

    A impressão começa pelo topo, pois o topo é o primeiro
    elemento a ser removido.
*/
void imprimirPilha(PilhaEstatica *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Pilha do topo para a base: ");

    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }

    printf("\n");
}

int main(void) {
    PilhaEstatica pilha;

    inicializaPilha(&pilha);

    printf("Inserindo elementos na pilha:\n");
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    push(&pilha, 40);
    push(&pilha, 50);

    printf("\nTentando inserir com a pilha cheia:\n");
    push(&pilha, 60);

    printf("\nEstado atual da pilha:\n");
    imprimirPilha(&pilha);

    printf("\nElemento no topo: %d\n", consultarTopo(&pilha));

    printf("\nRemovendo elementos da pilha:\n");
    printf("Valor removido: %d\n", pop(&pilha));
    printf("Valor removido: %d\n", pop(&pilha));

    printf("\nEstado da pilha apos remocoes:\n");
    imprimirPilha(&pilha);

    printf("\nRemovendo os elementos restantes:\n");
    printf("Valor removido: %d\n", pop(&pilha));
    printf("Valor removido: %d\n", pop(&pilha));
    printf("Valor removido: %d\n", pop(&pilha));

    printf("\nEstado final da pilha:\n");
    imprimirPilha(&pilha);

    /*
        Se quiser testar Stack Underflow, descomente a linha abaixo.
        Ela tentará remover um elemento de uma pilha vazia.
    */
    // pop(&pilha);

    return 0;
}