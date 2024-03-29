#include <stdio.h>

// Assinaturas dos métodos
int fibonacci(int n);

int main(){
    int n; // armazena o numero fornecido pelo usuario
    
    printf("Digite o numero desejado para calcular o fibonacci: ");
    scanf("%d", &n);
    printf("O fibonacci de %d é %d.\n", n, fibonacci(n));

    return 0;
}

// fibonacci(): metodo que retorna o valor do fibonacci por recursividade(Não é a melhor opção)
int fibonacci(int n){
    if(n < 2){
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
