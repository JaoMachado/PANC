#include <stdio.h>

// Assinaturas dos métodos
long fatorial(int n);

int main(){
    int n; // armazena o numero fornecido pelo usuario

    // solicita, recebe e atribui o numero a n
    printf("Digite o número que voce deseja calcular o fatorial: ");
    scanf("%d", &n);

    // chama o metodo fatorial e printa o resultado
    printf("\nO fatorial de %d é: %ld\n", n, fatorial(n));

    return 0;
}

// fatorial(): metodo para somar o fatorial de um numero com recursividade. T(n) = a + (n-1)b
long fatorial(int n){
    long fat = 1;
    for(int i = 1; i <= n; i++){
           fat *= i;
    }
    return fat;
}