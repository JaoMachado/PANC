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
        int a = 0;
        int b = 1;
        int prox;

        if(n == 0){
            return 0;
        } else {
            for(int i = 2; i <= n; i++){
                prox = a + b;
                a = b;
                b = prox;
            }
        }
        return b;
    }
}
