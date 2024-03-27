#include <stdio.h>

// Assinaturas dos métodos
void imprime05num(int n);
int somaNumIntervalo(int m, int n);
long fatorial(int n);
void torreHanoi(int n, int origem, int destino, int auxiliar);
int fibonacci(int n);

int main(){
    printf("Imprimindo 05 numeros inteiros por recursividade: ");
    imprime05num(0);
    
    printf("\n\nSomando valores de um intervalo ao outro com recursividade: ");
    printf("%d", somaNumIntervalo(0, 5));

    printf("\n\nCalculando o fatorial de um numero com recursividade: ");
    printf("%ld", fatorial(5));

    printf("\n\nResolvendo a Torre de Hanoi por recursividade: ");
    torreHanoi(3, 1, 3, 2);

    printf("\n\nResolvendo Fibonacci por recursividade: ");
    printf("%d", fibonacci(5));
    printf("\nOBS: A função iterativa(T(n) linear) é melhor que a recursiva(T(n) exponencial) ");

    return 0;
}

// imprime05num(): método para imprimir 5 numeros inteiros em sequencia com recursividade
void imprime05num(int n){
    if(n < 5){
        printf("%d", n);
        imprime05num(n+1);
    }
}

// somaNumInterevalo(): metodo para somar os numeros de um intervalo ao outro usando recursividade
int somaNumIntervalo(int m, int n){
    if(m == n){
        return m;
    } else {
        return m + somaNumIntervalo(m + 1, n);
    }
}

// fatorial(): metodo para somar o fatorial de um numero com recursividade. T(n) = a + (n-1)b
long fatorial(int n){
    if(n <= 1){
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}

// torreHanoi(): metodo para resolver a torre de Hanoi, mostrando cada movimento a fazer.
void torreHanoi(int n, int origem, int destino, int auxiliar){
    if(n > 0){
        torreHanoi(n-1, origem, auxiliar, destino);
        printf("\nMover disco da torre %d para a torre %d", origem, destino);
        torreHanoi(n-1, auxiliar, destino, origem);
    }
}

// fibonacci(): metodo que retorna o valor do fibonacci por recursividade(Não é a melhor opção)
int fibonacci(int n){
    if(n < 2){
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


