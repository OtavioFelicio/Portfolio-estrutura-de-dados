#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura
typedef struct lista {
int info;
struct lista* prox;
} Lista;

// Funcao auxiliar para inserir no fim (para facilitar os testes)
Lista* insere_fim(Lista* l, int v) {
Lista* novo = (Lista*)malloc(sizeof(Lista));
novo->info = v;
novo->prox = NULL;

if (l == NULL) return novo;

Lista* p = l;
while (p->prox != NULL) {
    p = p->prox;
}
p->prox = novo;
return l;


}

// Funcao auxiliar para imprimir
void imprime(Lista* l) {
Lista* p;
for (p = l; p != NULL; p = p->prox) {
printf("[ %d ] -> ", p->info);
}
printf("NULL\n");
}

Lista* remove_por_posicao(Lista* l, int pos) {
// Caso especial: Lista vazia
if (l == NULL) return NULL;

Lista* atual = l;
Lista* anterior = NULL;
int contador = 0;

// Caso especial: Remover a primeira posicao (indice 0)
if (pos == 0) {
    l = atual->prox;
    free(atual);
    return l;
}

// Percorre a lista ate chegar a posicao desejada
while (atual != NULL && contador < pos) {
    anterior = atual;
    atual = atual->prox;
    contador++;
}

// Se o 'atual' chegou a NULL, a posicao informada nao existe
if (atual == NULL) {
    printf("Erro: Posicao %d invalida ou fora dos limites.\n", pos);
    return l;
}

// A magica acontece aqui: o anterior "pula" o no atual
anterior->prox = atual->prox;

// Liberta a memoria do no que ficou isolado
free(atual);

return l;


}

int main() {
printf("--- Teste Pratico: Grupo 7 ---\n\n");

// 1. Criar uma lista de exemplo
Lista* minhaLista = NULL;
minhaLista = insere_fim(minhaLista, 10); // Posicao 0
minhaLista = insere_fim(minhaLista, 20); // Posicao 1 (MEIO - alvo da remocao)
minhaLista = insere_fim(minhaLista, 30); // Posicao 2

printf("Antes da remocao:\n");
imprime(minhaLista);

// 2. Demonstrar a remocao funcionando (Remover a posicao 1)
printf("\nRemovendo o elemento da posicao 1 (valor 20)...\n");
minhaLista = remove_por_posicao(minhaLista, 1);

// 3. Resultado final
printf("\nDepois da remocao:\n");
imprime(minhaLista);

return 0;


}