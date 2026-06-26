#include <stdio.h>
#include <stdlib.h> // Necessario para usar o malloc

// Definicao da estrutura do no (Lista)
typedef struct lista {
    int info;
    struct lista* prox; // Ponteiro para o proximo elemento
} Lista;

// Funcao para inicializar a lista como vazia
Lista* inicializa(void) {
    return NULL;
}

// Funcao para inserir um novo elemento no inicio da lista
Lista* insere(Lista* l, int i) {
    // 1. Aloca espaco na memoria para o novo no
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    
    // 2. Insere a informacao
    novo->info = i;
    
    // 3. O 'proximo' deste novo no sera a lista antiga
    novo->prox = l;
    
    // 4. Retorna o novo no, que agora e a "cabeca" (head) da lista
    return novo;
}

// Funcao para percorrer e imprimir a lista
void imprime(Lista* l) {
    Lista* p; // Ponteiro auxiliar para nao perder o inicio da lista
    
    printf("\nLista criada: ");
    // Comeca no inicio (l); enquanto nao for NULL; avanca para o proximo
    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
}

int main(void) {
    printf("--- Teste de Lista Encadeada ---\n");
    
    // 1. Inicializa a lista
    Lista* l = inicializa();
    int valor;
    int i;

    // 2. Laco para inserir 5 valores iterativamente
    for (i = 0; i < 5; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &valor);
        
        // IMPORTANTE: E obrigatorio capturar o retorno da funcao insere,
        // senao perdemos a referencia para o novo inicio da lista.
        l = insere(l, valor);
    }

    // 3. Mostra o resultado final
    imprime(l);

    return 0;
}