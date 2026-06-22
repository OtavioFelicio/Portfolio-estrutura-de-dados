#include <stdio.h>

int main() {
    int num;

    printf("--- Verificador de Par ou Impar ---\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    // O operador % (modulo) retorna o resto da divisao
    if (num % 2 == 0) {
        printf("O numero %d e PAR.\n", num);
    } else {
        printf("O numero %d e IMPAR.\n", num);
    }

    return 0;
}