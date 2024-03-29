#include <stdio.h>

// Assinaturas dos métodos
long expDois(int n);

int main(){
    int n; // armazena o numero fornecido pelo usuario

    // solicita, recebe e atribui o numero a n
    printf("Digite o número que voce deseja elevar o 2: ");
    scanf("%d", &n);

    // chama o metodo exponencial de 2 e printa o resultado
    printf("\n2 elevado a %d é: %ld\n", n, expDois(n));

    return 0;
}

// expDois(int n): metodo para calcular 2 elevado a n recursivamente
long expDois(int n){
    if (n == 0){
        return 1;
    } else {
        return 2 * expDois(n - 1);
    }
}