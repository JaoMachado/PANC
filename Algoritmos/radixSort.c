#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaRadixSort(int Vet[], int Max);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Radix Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Radix Sort
    OrdenaRadixSort(array, n);
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

/*  OrdenaRadixSort(): Funcao que ordena o vetor pelo método radix sort. */
void OrdenaRadixSort(int Vet[], int Max){
    int i;
    int b[Max];
    int m = 0;
    int exp = 1;

    for(i = 0; i < Max; i++){
        if(Vet[i] > m){
            m = Vet[i];
        }
    }

    while((m/exp) > 0){
        int bucket[10] = {0};

        for(i = 0; i < Max; i++){
            bucket[Vet[i]/(exp%10)]++;
        }

        for(i = 1; i < 10; i++){
            bucket[i] += bucket[i - 1];
        }

        for(i = Max - 1; i >= 0; i--){
            b[--bucket[Vet[i]/(exp%10)]] = Vet[i];
        }

        for(i = 0; i < Max; i++){
            Vet[i] = b[i];
        }

        exp *= 10;
    }
}