#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaQuickSortRecursivo(int Vet[], int inicio, int fim);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Quick Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Quick Sort
    OrdenaQuickSortRecursivo(array, 0, n-1);
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

/*  OrdenaQuickSortRecursivo(): Ordena, de forma recursiva, a Sequencia de Numeros
    pelo Método de Ordenação por Partição e Troca
    conhecido como QuickSort. */
void OrdenaQuickSortRecursivo(int Vet[], int inicio, int fim) {
    int pivo;
    int aux;
    int i;
    int j;
    int meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = Vet[meio];

    do{
        while(Vet[i] < pivo){
            i = i + 1;
        }
        while(Vet[j] > pivo){
            j = j - 1;
        }

        if(i <= j){
            aux = Vet[i];
            Vet[i] = Vet[j];
            Vet[j] = aux;
            i += 1;
            j -= 1;
        }
    } while(j > i);

    if(inicio < j){
        OrdenaQuickSortRecursivo(Vet, inicio, j);
    }
    if(i < fim){
        OrdenaQuickSortRecursivo(Vet, i, fim);
    }
}