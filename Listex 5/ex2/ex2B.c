#include <stdio.h>

// Assinaturas dos métodos
int mdc(int a, int b);

int main(){
    int a; // armazena o primeiro numero fornecido pelo usuario
    int b; // armazena o segundo numero fornecido pelo usuario

    // solicita, recebe e atribui o numero a n
    printf("Digite o primeiro número que voce deseja calcular o maximo divisor comum: ");
    scanf("%d", &a);
    printf("Digite o segundo número que voce deseja calcular o maximo divisor comum: ");
    scanf("%d", &b);

    // chama o metodo mdc e printa o resultado
    printf("\nO maximo divisor comum de %d e %d é: %d\n", a, b, mdc(a, b));

    return 0;
}

// mdc(): Função recursiva para calcular o MDC usando o algoritmo de Euclides
int mdc(int a, int b) {
    if (b == 0){
        return a;
    } else {
        return mdc(b, a % b);
    }
}