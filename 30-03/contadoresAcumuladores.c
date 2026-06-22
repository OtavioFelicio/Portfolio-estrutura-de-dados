#include <stdio.h>

int main() {
    // Acumuladores devem SEMPRE ser inicializados com 0
    // para nao somar com "lixo" de memoria.
    int soma = 0; 

    printf("--- Acumulador (Soma de 1 a 10) ---\n");
    
    for (int i = 1; i <= 10; i++) {
        // A variavel 'soma' acumula o valor dela mesma + o valor de 'i'
        soma += i; // Forma contraida de: soma = soma + i;
    }
    
    printf("O valor total acumulado e: %d\n", soma);

    return 0;
}