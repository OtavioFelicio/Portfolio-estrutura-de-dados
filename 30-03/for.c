#include <stdio.h>

int main() {
    printf("--- Contagem com FOR ---\n");
    
    // O laço for agrupa os 3 pilares na mesma linha:
    // 1. Inicializacao (int i = 1)
    // 2. Condicao (i <= 5)
    // 3. Incremento (i++)
    for (int i = 1; i <= 5; i++) {
        printf("Volta numero: %d\n", i);
    }
    
    return 0;
}