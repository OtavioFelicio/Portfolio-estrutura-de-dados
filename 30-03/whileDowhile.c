#include <stdio.h>

int main() {
    int i = 1;
    
    printf("--- Teste com WHILE ---\n");
    // O while testa a condicao ANTES de executar.
    // Como i (1) e menor ou igual a 5, ele entra no laco.
    while (i <= 5) {
        printf("Valor: %d\n", i);
        i++; // Atualizacao essencial para evitar loop infinito
    }

    printf("\n--- Teste com DO...WHILE ---\n");
    int j = 10;
    // O do...while executa o bloco PRIMEIRO e testa DEPOIS.
    // Ele vai imprimir '10' pelo menos uma vez, mesmo a condicao (j <= 5) sendo falsa.
    do {
        printf("Valor: %d\n", j);
        j++;
    } while (j <= 5);

    return 0;
}