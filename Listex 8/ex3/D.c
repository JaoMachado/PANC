#include <stdio.h>
#include <stdlib.h>

//Declaração das funções
long long karatsuba(int u, int v, int n);

int main(){
    // Números grandes para multiplicar
    long long u = 99998888;
    long long v = 77776666;
    
    // Chama a função de multiplicação de Karatsuba e armazena o resultado
    long long result = karatsuba(u, v, 8);
    
    // Exibe o resultado da multiplicação
    printf("Resultado: %lld\n", result);

    return 0;
}

/* karatsuba(): Algoritmo para calcular a multiplicacao de numeros inteiros muito grandes,
    com complexidade T(n) = O(n^1.585)*/
long long karatsuba(int u, int v, int n){

    // Caso base: se o número de dígitos é 3 ou menos, realiza a multiplicação direta
    if (n <= 3) {
        return u * v;
    }

    // Calcula o ponto de divisão dos números
    int m = n / 2;

    // Calcula as potências de 10 necessárias para dividir os números
    long long dezElevM = 1;
    for (int i = 0; i < m; i++) {
        dezElevM *= 10;
    }
    long long doisDezElevM = dezElevM * dezElevM;

    // Divide os números u e v em partes
    long long p = u / dezElevM;  // Parte alta de u
    long long q = u % dezElevM;  // Parte baixa de u
    long long r = v / dezElevM;  // Parte alta de v
    long long s = v % dezElevM;  // Parte baixa de v

    // Calcula os produtos intermediários usando recursão
    long long pr = karatsuba(p, r, m);             // Multiplicação das partes altas
    long long qs = karatsuba(q, s, m);             // Multiplicação das partes baixas
    long long y = karatsuba(p + q, r + s, m + 1);  // Multiplicação das somas das partes

    // Combina os resultados intermediários para obter o produto final
    return pr * doisDezElevM + (y - pr - qs) * dezElevM + qs;
}