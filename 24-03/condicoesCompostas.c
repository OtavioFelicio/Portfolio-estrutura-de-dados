#include <stdio.h>

int main() {
    float nota;

    printf("--- Sistema de Notas ---\n");
    printf("Digite a nota do aluno (0.0 a 10.0): ");
    scanf("%f", &nota);

    // Verificacao em cascata
    if (nota >= 7.0) {
        printf("Status: Aprovado\n");
    } else if (nota >= 5.0) {
        printf("Status: Recuperacao\n");
    } else {
        printf("Status: Reprovado\n");
    }

    return 0;
}