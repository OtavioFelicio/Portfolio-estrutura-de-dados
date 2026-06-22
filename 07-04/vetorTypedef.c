#include <stdio.h>

// Uso do typedef simplifica a criacao de variaveis depois
typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    printf("--- Cadastro da Turma ---\n");
    
    Aluno turma[3]; // Criacao de um vetor para 3 alunos
    int i;

    // Leitura dos dados usando um laco de repeticao
    for(i = 0; i < 3; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        
        printf("Digite o nome: ");
        // Limpa o buffer do teclado antes de ler a proxima string
        scanf(" %[^\n]", turma[i].nome); 
        
        printf("Digite a nota: ");
        scanf("%f", &turma[i].nota);
    }

    // Impressao dos dados iterando sobre o vetor
    printf("\n--- LISTA DE ALUNOS ---\n");
    for(i = 0; i < 3; i++) {
        printf("Aluno %d: %s - Nota: %.2f\n", i + 1, turma[i].nome, turma[i].nota);
    }

    return 0;
}