#include <stdio.h>

int main() {
    printf("--- Introducao a Ponteiros ---\n");
    
    int a = 5;
    // O ponteiro 'p' recebe o endereco de memoria da variavel 'a'
    int *p = &a; 

    printf("Valor inicial de 'a': %d\n", a);
    
    // O modificador de formato %p e usado para imprimir enderecos de memoria (hexadecimal)
    printf("Endereco de 'a' na memoria: %p\n", (void*)&a);
    printf("Valor guardado no ponteiro 'p': %p\n", (void*)p);
    
    printf("\nAlterando o valor via ponteiro...\n");
    // O operador * acede ao conteudo daquele endereco
    *p = 20; 
    
    printf("Novo valor de 'a': %d\n", a);
    printf("Valor lido atraves do ponteiro (*p): %d\n", *p);

    return 0;
}