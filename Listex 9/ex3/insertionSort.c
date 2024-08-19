#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void insertionSort(int arrayA[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Insertion Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Insertion Sort
    insertionSort(array, n);
    imprimeArray(array, n, "Vetor Ord.   []");

    return 0;
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
        imprimeArray(arrayA, n, "Vetor Desord.[]");
    }
}