#include <stdio.h>

int main() {
    int idade;

    printf("--- Verificador de Faixa Etaria ---\n");
    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    // Uso do operador && (AND) para verificar um intervalo
    if (idade >= 18 && idade <= 65) {
        printf("Acesso concedido: Voce esta dentro da faixa permitida (18-65 anos).\n");
    } else {
        // Uso do operador || (OR) apenas como exemplo demonstrativo
        if (idade < 18 || idade > 65) {
            printf("Acesso negado: Voce esta fora da faixa etaria exigida.\n");
        }
    }

    return 0;
}