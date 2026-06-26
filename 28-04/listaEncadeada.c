#include <stdio.h>
#include <stdlib.h>

// --- Estrutura Básica ---
typedef struct lista {
int info;
struct lista* prox;
} Lista;

// --- 1. Inicialização ---
Lista* inicializa(void) {
return NULL;
}

// --- 2. Inserção no Início ---
Lista* insere(Lista* l, int i) {
Lista* novo = (Lista*) malloc(sizeof(Lista));

// Boa prática: verificar se a memória foi alocada
if (novo == NULL) {
    printf("Erro: Memoria insuficiente!\n");
    exit(1);
}

novo->info = i;
novo->prox = l;
return novo;


}

// --- 3. Impressão ---
void imprime(Lista* l) {
Lista* p;
printf("Lista atual: ");
for (p = l; p != NULL; p = p->prox) {
printf("%d -> ", p->info);
}
printf("NULL\n");
}

// --- 4. Busca ---
Lista* busca(Lista* l, int v) {
Lista* p;
for (p = l; p != NULL; p = p->prox) {
if (p->info == v) {
return p; // Encontrou: retorna o endereco do no
}
}
return NULL; // Nao encontrou
}

// --- 5. Remoção do Último Nó ---
Lista* remove_ultimo(Lista* l) {
// Caso 1: Lista vazia
if (l == NULL) {
return NULL;
}

// Caso 2: Lista com apenas 1 elemento
if (l->prox == NULL) {
    free(l);
    return NULL;
}

// Caso 3: Lista com mais de 1 elemento (Para no penúltimo)
Lista* p = l;
while (p->prox->prox != NULL) {
    p = p->prox;
}

// Libera a memoria do ultimo no e ajusta o ponteiro do penultimo
free(p->prox);
p->prox = NULL;

return l;


}

// --- 6. Liberação de Memória (Evita Memory Leaks) ---
void libera(Lista* l) {
Lista* p = l;
while (p != NULL) {
Lista* t = p->prox; // Guarda o proximo de forma segura
free(p);            // Destroi o atual
p = t;              // Avanca para o proximo
}
}

// =========================================================
// FUNÇÃO PRINCIPAL PARA TESTES
// =========================================================
int main(void) {
printf("--- Operacoes Completas em Lista Encadeada ---\n\n");

Lista* minhaLista = inicializa();

// Inserindo elementos
printf("Inserindo elementos (10, 20, 30)...\n");
minhaLista = insere(minhaLista, 10);
minhaLista = insere(minhaLista, 20);
minhaLista = insere(minhaLista, 30);
imprime(minhaLista);

// Teste de Busca
printf("\nBuscando o valor 20...\n");
Lista* resultado = busca(minhaLista, 20);
if (resultado != NULL) {
    // Imprime o valor encontrado e o seu endereço de memória
    printf("Valor %d encontrado no endereco: %p\n", resultado->info, (void*)resultado);
} else {
    printf("Valor nao encontrado.\n");
}

// Teste de Remocao do Ultimo
printf("\nRemovendo o ultimo no da lista...\n");
minhaLista = remove_ultimo(minhaLista);
imprime(minhaLista);

// Teste de Limpeza de Memoria
printf("\nLimpando toda a memoria...\n");
libera(minhaLista);
minhaLista = NULL; // Anular o ponteiro é uma boa prática

printf("Memoria libertada com sucesso. Fim do programa.\n");

return 0;


}