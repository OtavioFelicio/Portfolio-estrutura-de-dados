#include <stdio.h>

int main() {
    printf("--- Operacoes com Vetores ---\n");
    
    // Declaracao de um vetor para armazenar 5 numeros inteiros
    int numeros[5];
    int soma = 0;

    printf("Por favor, digite 5 numeros inteiros:\n");
    
    // O laco 'for' e ideal para percorrer vetores. 
    // O indice comeca SEMPRE em 0 e vai ate tamanho-1.
    for(int i = 0; i < 5; i++) {
        printf("Posicao %d: ", i);
        scanf("%d", &numeros[i]);
        
        // Acumula o valor digitado
        soma += numeros[i];
    }

    printf("\n--- RESULTADOS ---\n");
    printf("Os valores guardados foram: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    
    printf("\nA soma total dos elementos e: %d\n", soma);

    return 0;
}