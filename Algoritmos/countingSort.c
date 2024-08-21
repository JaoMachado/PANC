#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void countingSort(int array[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Counting Sort: \n");

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
    countingSort(array, n);
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

/*  countingSort(): Ordena o array através de um método não-comparativo.*/
void countingSort(int array[], int n) {
    int i;
    int max = array[0];
    int min = array[0];

    // Encontrando o valor máximo e mínimo no array
    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    int range = max - min + 1;
    int *count = (int *)malloc(range * sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Inicializa o array de contagem com 0
    for (i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Contagem das ocorrências de cada elemento
    for (i = 0; i < n; i++) {
        count[array[i] - min]++;
    }

    // Atualizando o array de contagem para armazenar posições
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Construindo o array de saída
    for (i = n - 1; i >= 0; i--) {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    // Copiando o array de saída para o array original
    for (i = 0; i < n; i++) {
        array[i] = output[i];
    }

    // Liberando memória alocada
    free(count);
    free(output);
}