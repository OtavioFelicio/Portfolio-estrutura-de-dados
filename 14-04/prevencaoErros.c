#include <stdio.h>

int main() {
    printf("--- Analise de Limites de Vetores ---\n");
    
    // Inicializacao direta de um vetor de 3 posicoes
    int numeros[3] = {10, 20, 30};

    printf("Os elementos estao armazenados nos indices 0, 1 e 2.\n");
    
    // GARANTIA DE SEGURANCA: A condicao do laco (i < 3) 
    // impede que o programa tente ler ou escrever memoria invalida.
    for(int i = 0; i < 3; i++) {
        printf("Indice [%d] contem o valor: %d\n", i, numeros[i]);
    }

    // AVISO: Fazer algo como numeros[5] = 100; em C nao da erro de compilacao,
    // mas causa comportamento indefinido (o programa pode crashar).
    printf("\nAtencao: Em C, o programador e responsavel por respeitar os limites do array!\n");

    return 0;
}