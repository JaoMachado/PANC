#include <stdio.h>
#include <stdlib.h>

// Declaracao das funcoes
void addMatrices(int A[2][2], int B[2][2], int result[2][2]);
void subtractMatrices(int A[2][2], int B[2][2], int result[2][2]);
void strassenMultiplication(int A[2][2], int B[2][2], int C[2][2]);
void printMatrix(int M[2][2]);

int main() {
    // arrays para armazenar as matrizes
    int A[2][2] = {{1, 3}, {7, 5}};
    int B[2][2] = {{6, 8}, {4, 2}};
    int C[2][2]; 

    // Multiplicação das matrizes A e B usando o algoritmo de Strassen
    strassenMultiplication(A, B, C);

    // Impressão da matriz resultante
    printf("Matriz resultante C:\n");
    printMatrix(C);

    return 0;
}

// Função para adicionar duas matrizes 2x2
void addMatrices(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j]; // Soma dos elementos correspondentes
        }
    }
}

// Função para subtrair duas matrizes 2x2
void subtractMatrices(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] - B[i][j]; // Subtração dos elementos correspondentes
        }
    }
}

// Função para multiplicação de matrizes de Strassen para matrizes 2x2
void strassenMultiplication(int A[2][2], int B[2][2], int C[2][2]) {
    // Variáveis para armazenar os produtos intermediários M1 a M7
    int M1, M2, M3, M4, M5, M6, M7;

    // Elementos das matrizes A e B
    int A11 = A[0][0];
    int A12 = A[0][1];
    int A21 = A[1][0];
    int A22 = A[1][1];
    int B11 = B[0][0];
    int B12 = B[0][1];
    int B21 = B[1][0];
    int B22 = B[1][1];

    // Calculando os produtos intermediários M1 a M7
    M1 = (A11 + A22) * (B11 + B22);
    M2 = (A21 + A22) * B11;
    M3 = A11 * (B12 - B22);
    M4 = A22 * (B21 - B11);
    M5 = (A11 + A12) * B22;
    M6 = (A21 - A11) * (B11 + B12);
    M7 = (A12 - A22) * (B21 + B22);

    // Calculando os elementos da matriz resultante C
    C[0][0] = M1 + M4 - M5 + M7; // Elemento C11
    C[0][1] = M3 + M5;           // Elemento C12
    C[1][0] = M2 + M4;           // Elemento C21
    C[1][1] = M1 - M2 + M3 + M6; // Elemento C22
}

// Função para imprimir uma matriz 2x2
void printMatrix(int M[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", M[i][j]); // Imprime cada elemento da matriz
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }
    printf("\n"); // Linha em branco após a matriz
}
