#include <stdio.h>
#include <string.h>

// Definicao da estrutura
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    printf("--- Registo de Aluno ---\n");
    
    struct Aluno a1; // Declaracao da variavel do tipo struct Aluno

    printf("Digite o nome: ");
    // %[^\n] le a string ate o utilizador pressionar Enter (aceita espacos)
    scanf("%[^\n]", a1.nome);
    
    printf("Digite a idade: ");
    scanf("%d", &a1.idade);
    
    printf("Digite a nota: ");
    scanf("%f", &a1.nota);

    printf("\n--- DADOS INFORMADOS ---\n");
    // Acesso aos campos com o operador ponto (.)
    printf("Nome: %s\n", a1.nome);
    printf("Idade: %d\n", a1.idade);
    printf("Nota: %.2f\n", a1.nota);

    return 0;
}