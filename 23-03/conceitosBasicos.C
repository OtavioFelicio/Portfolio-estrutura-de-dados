#include <stdio.h>

int main() {
    // 1. Variáveis e Tipos Básicos
    printf("--- Variáveis e Tipos Básicos ---\n");
    int idade = 25;
    float notaMedia = 7.5;
    char opcao = 'S';
    
    printf("Idade (int): %d\n", idade);
    printf("Nota Média (float): %.2f\n", notaMedia);
    printf("Opção (char): %c\n\n", opcao);

    // 2. Operadores e a Armadilha da Divisão
    printf("--- Operadores e Divisão ---\n");
    int a = 5;
    int b = 2;
    
    // Divisão Inteira trunca o resultado
    int divisaoInteira = a / b;
    printf("Divisão Inteira (5 / 2): %d\n", divisaoInteira);
    
    // Divisão Real necessita de valores float
    float divisaoReal = 5.0 / 2.0;
    printf("Divisão Real (5.0 / 2.0): %.2f\n", divisaoReal);
    
    // Operadores de incremento e atribuição
    a += 5;
    printf("Atribuição (a += 5): %d\n", a);
    a++;
    printf("Incremento (a++): %d\n\n", a);

    // 3. Entrada e Saída de Dados
    printf("--- Entrada e Saída (I/O) ---\n");
    int idadeUsuario;
    float alturaUsuario;

    printf("Digite sua idade: ");
    // Uso obrigatório do '&' para referenciar o endereço de memória
    scanf("%d", &idadeUsuario);

    printf("Digite sua altura (ex: 1.75): ");
    scanf("%f", &alturaUsuario);

    printf("Dados lidos - Idade: %d, Altura: %.2f\n", idadeUsuario, alturaUsuario);

    return 0;
}