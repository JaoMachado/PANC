#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    
}

int ordenaArray(int array[], int n, int *operacoes){
    int i, chave, j, x;
    for (i = 0; i < n; i++) {
        chave = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
            (*operacoes)++;
        }
        array[j + 1] = chave;
        printf("Array Desord.[] = ");
        printArray(array, n);
        printf("- %d", chave);
        printf("\n");
    }
}

int main(){
    int n;
    int operacoes = 1;

    srand((unsigned)time(NULL));

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++){
        array[i] = rand() % 101;
    }

    ordenaArray(array, n, &operacoes);

    printf("Array Ord.   [] = ");
    printArray(array, n);

    printf("\nNumero de Operacoes para Ordenacao: %d", operacoes);
}