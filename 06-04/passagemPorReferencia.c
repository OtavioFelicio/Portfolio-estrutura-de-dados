#include <stdio.h>

// Funcao que recebe ponteiros (enderecos) em vez de valores simples
void troca(int *a, int *b) {
    // 1. Guarda temporariamente o valor que esta no endereco 'a'
    int temp = *a;
    
    // 2. Coloca o valor do endereco 'b' no endereco 'a'
    *a = *b;
    
    // 3. Coloca o valor temporario no endereco 'b'
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    
    printf("--- Passagem por Referencia (Swap) ---\n");
    printf("Valores iniciais no main -> x = %d, y = %d\n\n", x, y);
    
    // Enviamos os ENDERECOS de x e y para a funcao usando o '&'
    troca(&x, &y);
    
    printf("Valores finais no main -> x = %d, y = %d\n", x, y);
    printf("Sucesso! As variaveis originais foram modificadas.\n");

    return 0;
}