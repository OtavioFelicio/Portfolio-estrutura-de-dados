#include <stdio.h>

// Struct interna
typedef struct {
    char rua[50];
    int numero;
} Endereco;

// Struct externa contendo a struct interna
typedef struct {
    char nome[50];
    int idade;
    Endereco end; // Aninhamento
} Pessoa;

// Funcao que recebe um PONTEIRO para Pessoa
// Isso permite alterar os dados na memoria original
void alterarIdadeENumero(Pessoa *p) {
    // Como 'p' e um ponteiro, usamos o operador -> em vez do ponto (.)
    p->idade = 30;
    p->end.numero = 999;
}

int main() {
    Pessoa pessoa1;
    
    printf("--- Teste de Structs Aninhadas e Ponteiros ---\n");

    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", pessoa1.nome);
    
    printf("Digite a idade: ");
    scanf("%d", &pessoa1.idade);
    
    printf("Digite a rua: ");
    scanf(" %[^\n]", pessoa1.end.rua);
    
    printf("Digite o numero da porta: ");
    scanf("%d", &pessoa1.end.numero);

    printf("\n[Antes da Funcao]\nIdade: %d | Numero: %d\n", pessoa1.idade, pessoa1.end.numero);

    // Passamos o endereco de memoria da pessoa1
    alterarIdadeENumero(&pessoa1);

    printf("\n[Depois da Funcao (Valores Alterados)]\nIdade: %d | Numero: %d\n", pessoa1.idade, pessoa1.end.numero);

    return 0;
}