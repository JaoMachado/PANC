#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void bucketSort(int array[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Bucket Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array
    bucketSort(array, n);
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

// Função auxiliar para encontrar o valor máximo no array
int findMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Função para ordenar um bucket usando Bubble Sort
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/*  bucketSort(): Função que Ordena o array através do método de dividí-los em baldes */
void bucketSortBucket(int array[], int n) {
    if (n <= 1) return;  // Se o tamanho do bucket for 0 ou 1, não é necessário ordenar

    int max = findMax(array, n);
    int bucketCount = (max / n) + 1;  // Número de buckets
    int **buckets = (int**)malloc(bucketCount * sizeof(int*));
    int *bucketSizes = (int*)calloc(bucketCount, sizeof(int)); // Inicializa com zero

    if (buckets == NULL || bucketSizes == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    // Inicializa os buckets e seus tamanhos
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        if (buckets[i] == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
    }

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] / ((max / bucketCount) + 1);
        if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1; // Evita acesso fora dos limites
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i];
    }

    // Ordena cada bucket individualmente usando Bubble Sort
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            bubbleSort(buckets[i], bucketSizes[i]);
            // Concatena os buckets no array original
            for (int j = 0; j < bucketSizes[i]; j++) {
                array[index++] = buckets[i][j];
            }
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}


// Apenas para chamar o bucketSortBucket
void bucketSort(int array[], int n) {
    bucketSortBucket(array, n);
}