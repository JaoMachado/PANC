#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void mergeSort(int arrayA[], int inicio, int fim);
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Merge Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Merge Sort
    mergeSort(array, 0, n-1);
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

/* mergeSort(): Metodo de ordenacao por intercalacao de elementos inteiros de array 
                com complexidade T(n) = n * lgn*/
void mergeSort(int arrayA[], int inicio, int fim) {
    int meio;
    
    if(inicio < fim){
        meio = (inicio + fim) / 2;
        mergeSort(arrayA, inicio, meio);
        mergeSort(arrayA, meio+1, fim);
        // intercalaSemSentinela(arrayA, inicio, meio, fim);
        intercalaSemSentinela(arrayA, inicio, meio, fim);
    }
}

/* intercalaSemSentinela(): metodo auiliar do mergeSort para intercalar dois segmentos de arrays ja ordenados invertendo a segunda parte do array
   T(n) = n */
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim){
    int i, j;
    int *arrayB;

    arrayB = (int*) malloc( (fim+1) * sizeof(int) );

    //Copia da primeira metade do array - em ordem
    for(i=inicio; i<=meio; i++) {
        arrayB[i] = arrayA[i];
    }

    //Copia da segunda metade do array - invertendo a ordem
    for(j=meio+1; j<=fim; j++) {
        arrayB[fim+meio+1-j] = arrayA[j];
    }

    i = inicio;
    j = fim;

    for(int k=inicio; k<=fim; k++) {
        if(arrayB[i] <= arrayB[j]) {
            arrayA[k] = arrayB[i];
            i++;
        } else {
            arrayA[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);
}