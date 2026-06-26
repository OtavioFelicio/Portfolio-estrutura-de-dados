#include <stdio.h>

int main() {
    printf("--- Trabalhando com Matrizes (2x2) ---\n");
    
    // Declaracao de uma matriz 2x2 (2 linhas, 2 colunas)
    int matriz[2][2];
    int somaTotal = 0;

    printf("Preencha a matriz:\n");
    
    // Para percorrer uma matriz, usamos laços aninhados (for dentro de for)
    // 'i' controla as LINHAS
    for(int i = 0; i < 2; i++) {
        // 'j' controla as COLUNAS
        for(int j = 0; j < 2; j++) {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
            somaTotal += matriz[i][j];
        }
    }

    printf("\n--- IMPRESSAO VISUAL DA MATRIZ ---\n");
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            // Imprime os valores da mesma linha lado a lado
            printf("[%d] ", matriz[i][j]);
        }
        // Quebra a linha quando terminam as colunas
        printf("\n");
    }

    printf("\nA soma de todos os valores da matriz e: %d\n", somaTotal);

    return 0;
}