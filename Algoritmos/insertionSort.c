#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Metodos
void geraArrayInteiros(int arrayA[], int n);
void imprimeArray(int arrayA[], int n, char msg[]);
void insertionSort(int arrayA[], int n);
void copiaArray(int arrayA[], int arrayB[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *arrayOriginal; //Array de Inteiros gerado automaticamente
    int *arrayTemp;     /*Array temporario para ser utilizado 
                        nas ordenacoes, mantendo integridade
                        dos dados do Array Original */

    printf("Algoritmo Insertion Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    arrayOriginal = (int*) malloc( n * sizeof(int) );
    arrayTemp = (int*) malloc( n * sizeof(int) );

    //Gerando o Array Original
    geraArrayInteiros(arrayOriginal, n);
    imprimeArray(arrayOriginal, n, "Array Original");

    //Ordenando o array por Insertion Sort
    copiaArray(arrayOriginal, arrayTemp, n);
    insertionSort(arrayTemp, n);
    imprimeArray(arrayTemp, n, "Array Ordenado");
    imprimeArray(arrayOriginal, n, "Array Original");

    return 0;
}

/* geraArrayInteiros(): Metodo para gerar n numeros inteiros
   de 0 a 99 e armazenar em um array de inteiros */
void geraArrayInteiros(int arrayA[], int n) {
    int numAleatorio;

    srand( time(NULL) );
    for (int i=0; i<n; i++) {
        numAleatorio = rand() % 100;
        arrayA[i] = numAleatorio;
    }
}

/* imprimeArray(): Imprime os n elementos inteiros de um array */
void imprimeArray(int arrayA[], int n, char msg[]) {
    printf("\n %s = ", msg);

    for (int i=0; i<n; i++) {
        printf(" %d", arrayA[i]);
    }
}

/* insertionSort(): Metodo de ordenacao direta de arrays de
   inteiros com complexidade T(n) = n^2 */
void insertionSort(int arrayA[], int n) {
    int chave;

    for (int j=1; j<n; j++) {
        chave = arrayA[j];
        printf(" - %d", chave);
        int i = j-1;

        while ( (i>=0) & (arrayA[i] > chave ) ) {
            arrayA[i+1] = arrayA[i];
            i--;
        }

        arrayA[i+1] = chave;
        imprimeArray(arrayA, n, "Ordenando");
    }
}

/* copiaArray(): Metodo que copia os n elementos do
   arrayA (origem) para o arrayB (destino) */
void copiaArray(int arrayA[], int arrayB[], int n) {
    for (int i=0; i<n; i++) {
        arrayB[i] = arrayA[i];
    }
}


