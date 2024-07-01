#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define uma estrutura para armazenar o resultado do subarray
typedef struct {
    int left;   // Índice inicial do subarray
    int right;  // Índice final do subarray
    int sum;    // Soma dos elementos do subarray
} Subarray;

// Declaração das funções
Subarray findMaxSubarray(int A[], int inicio, int fim);
Subarray findMaxCrossingSubarray(int A[], int inicio, int meio, int fim);

int main(){
    // Array a ser testado
    int array[] = {20, -7, 12, -5, -22, 15, -4, 7};
    Subarray somaMax;

    // Encontra o subarray com a soma máxima no array inteiro
    somaMax = findMaxSubarray(array, 0, 7);

    // Imprime os resultados
    printf("Soma Máxima: %d\n", somaMax.sum);
    printf("Índice inicial: %d\n", somaMax.left);
    printf("Índice final: %d\n", somaMax.right);
    return 0;
}

/* findMaxSubarray(): Encontra o subarray com a soma máxima no array A[] entre os índices inicio e fim, 
    com complexidade T(n) = O(n lgn)*/
Subarray findMaxSubarray(int A[], int inicio, int fim){
    int meio;
    Subarray esquerda;  // Para armazenar o subarray máximo na metade esquerda
    Subarray direita;  // Para armazenar o subarray máximo na metade direita
    Subarray cruzado;  // Para armazenar o subarray máximo que cruza o meio

    // Caso base: quando o subarray tem apenas um elemento
    if (inicio == fim) {
        Subarray result = {inicio, fim, A[inicio]};
        return result;
    } else {
        meio = (inicio + fim) / 2;  // Encontra o ponto médio

        // Encontra recursivamente o subarray máximo na metade esquerda
        esquerda = findMaxSubarray(A, inicio, meio);

        // Encontra recursivamente o subarray máximo na metade direita
        direita = findMaxSubarray(A, meio + 1, fim);

        // Encontra o subarray máximo que cruza o meio
        cruzado = findMaxCrossingSubarray(A, inicio, meio, fim);

        // Retorna o subarray com a maior soma
        if (esquerda.sum >= direita.sum && esquerda.sum >= cruzado.sum) {
            return esquerda;
        } else if (direita.sum >= esquerda.sum && direita.sum >= cruzado.sum) {
            return direita;
        } else {
            return cruzado;
        }
    }
}

/*findMaxCrossingSubarray():Encontra o subarray máximo que cruza o meio do array A[] entre os índices inicio e fim,
    com complxidade T(n) = O(n)*/ 
Subarray findMaxCrossingSubarray(int A[], int inicio, int meio, int fim) {
    int somaEsquerda = INT_MIN;  // Inicializa a soma máxima da metade esquerda
    int soma = 0;
    int maxEsquerda = meio;

    // Calcula a soma máxima da metade esquerda que cruza o meio
    for (int i = meio; i >= inicio; i--) {
        soma += A[i];
        if (soma > somaEsquerda) {
            somaEsquerda = soma;
            maxEsquerda = i;
        }
    }

    int somaDireita = INT_MIN;  // Inicializa a soma máxima da metade direita
    soma = 0;
    int maxDireita = meio + 1;

    // Calcula a soma máxima da metade direita que cruza o meio
    for (int j = meio + 1; j <= fim; j++) {
        soma += A[j];
        if (soma > somaDireita) {
            somaDireita = soma;
            maxDireita = j;
        }
    }

    // Cria um Subarray para armazenar o resultado
    Subarray result = {maxEsquerda, maxDireita, somaEsquerda + somaDireita};
    return result;
}