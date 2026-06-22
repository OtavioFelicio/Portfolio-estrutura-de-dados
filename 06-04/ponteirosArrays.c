#include <stdio.h>

int main() {
    printf("--- Ponteiros e Arrays ---\n");
    
    int arr[3] = {10, 20, 30};
    
    // O nome do array 'arr' funciona como o endereco do primeiro elemento (&arr[0])
    int *p = arr; 

    printf("Acedendo com notacao de Array tradicional:\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    
    printf("\nAcedendo com Aritmetica de Ponteiros:\n");
    // *(p + i) e a forma como o C resolve arr[i] internamente
    printf("*(p + 0) = %d\n", *(p + 0));
    printf("*(p + 1) = %d\n", *(p + 1));
    printf("*(p + 2) = %d\n", *(p + 2));

    return 0;
}