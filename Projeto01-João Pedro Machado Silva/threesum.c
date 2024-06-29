#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

// declaracao de variaveis globais que guardao a quantidade de operacoes em cada metodo
int qtdOperacoes3SumFB=0;
int qtdOperacoes3SumMelhorado=0;

/* treeSumForcaBruta(): Calcula e apresenta as triplas encontradas no array, tal que (a+b+c = 0),
    com complexidade T(n) ∊ O(n³)*/
void treeSumForcaBruta(int A[], int n) {
    // variável para contar a quantidade de triplas encontradas
    int contTriplas = 0;

    // for que vai do primeiro ao penultimo elemento
    for (int i = 0; i < n - 2; i++) {
        // for que vai do i+1 elemento ao penultimo elemento
        for (int j = i + 1; j < n - 1; j++) {
            // for que vai do j+1 elemento ao ultimo elemento
            for (int k = j + 1; k < n; k++) {
                qtdOperacoes3SumFB++;// Incrementa o contador de operações a cada tripla verificada
                // Verifica se a soma dos três elementos é igual a zero
                if (A[i] + A[j] + A[k] == 0) {
                    contTriplas++;// Incrementa o contador de triplas encontradas
                    // Imprime a tripla encontrada
                    printf("%d Tripla Encontrada: [%d, %d, %d]\n", contTriplas, A[i], A[j], A[k]);
                }
            }
        }
    }

    // imprime o valor total de triplas encontradas
    printf("Total Triplas Encontradas pela Forca Bruta: %d\n", contTriplas);
}

/* treeSumMelhorado(): Calcula e apresenta as triplas encontradas no array, tal que (a+b+c = 0),
    com complexidade T(n) ∊ O(n²)*/
void treeSumMelhorado(int A[], int n) {
    // variável para contar a quantidade de triplas encontradas
    int contTriplas = 0;

    // Ordena o array e imprime o mesmo ordenado
    MergeSortRecursivo(A, 0, n-1, n);
    ImprimeArray(A, "Array Ord.   []", n);

    // Itera sobre cada elemento como o primeiro da tripla
    for (int i = 0; i < n - 2; i++) {
        // Itera sobre cada elemento subsequente como o segundo da tripla
        for (int j = i + 1; j < n - 1; j++) {
            qtdOperacoes3SumMelhorado++; // soma 1 ao contador de operacoes
            int x = -(A[i] + A[j]); // calcula o valor a ser encontrado
            int k = BuscaBinaria(x, A, j + 1, n - 1); // chama a busca binaria para encontrar e retornar o indice do elemento
            if (k != -1) { // testa se foi ou nao encontrado o elemento
                contTriplas++;
                printf("\n%d Tripla Encontrada: [%d, %d, %d]", contTriplas, A[i], A[j], A[k]);
            }
        }
    }
}

/* BuscaBinaria(): metodo para achar o valor no array utilizando a recursividade
    com complexidade T(n) ∊ O(n²)*/
int BuscaBinaria (int x, int A[], int inicio, int fim) {
    // Verifica se o início é menor ou igual ao fim
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        // Verifica se o elemento está no meio
        if (A[meio] == x) {
            return meio;
        }

        // Se o elemento está na metade esquerda do array
        if (A[meio] > x)
            BuscaBinaria(x, A, inicio, meio - 1);

        // Se o elemento está na metade direita do array
        else
            BuscaBinaria(x, A, meio + 1, fim);
    } else {
        return -1;
    }
}

/* MergeSortRecursivo(): Metodo de ordenacao por intercalacao de elementos inteiros de array 
    com complexidade T(n) = n * lgn*/
void MergeSortRecursivo(int A[], int inicio, int fim, int n) {
    int meio;
    
    if(inicio < fim){
        meio = (inicio + fim) / 2;
        MergeSortRecursivo(A, inicio, meio, n);
        MergeSortRecursivo(A, meio+1, fim, n);
        IntercalaSemSentinela(A, inicio, meio, fim, n);
    }
}

/* IntercalaSemSentinela(): metodo auiliar do mergeSort para intercalar dois segmentos de arrays ja ordenados invertendo a segunda parte do array
   T(n) = n */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n) {
    int i, j;
    int *arrayB;

    arrayB = (int*) malloc( (fim+1) * sizeof(int) );

    //Copia da primeira metade do array - em ordem
    for(i=inicio; i<=meio; i++) {
        
        arrayB[i] = A[i];
    }

    //Copia da segunda metade do array - invertendo a ordem
    for(j=meio+1; j<=fim; j++) {
        arrayB[fim+meio+1-j] = A[j];
    }

    i = inicio;
    j = fim;

    for(int k=inicio; k<=fim; k++) {
        qtdOperacoes3SumMelhorado++;
        if(arrayB[i] <= arrayB[j]) {
            A[k] = arrayB[i];
            i++;
        } else {
            A[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);
}

/* ImprimeArray(): Imprime os n elementos inteiros de um array */
void ImprimeArray(int A[], char Msg[], int n) {
    printf("\n %s = ", Msg);

    for (int i=0; i<n; i++) {
        printf(" %d", A[i]);
    }
}

/* ImprimeQtdOperacoes(): Imprime a quantidade de operações relaizadas em cada um dos métodos*/
void ImprimeQtdOperacoes() {
    printf("\nQuantidade de Operacoes - 3SUM - Forca Bruta: %d", qtdOperacoes3SumFB);
    printf("\nQuantidade de Operacoes - 3SUM - Melhorado: %d\n", qtdOperacoes3SumMelhorado);
}
