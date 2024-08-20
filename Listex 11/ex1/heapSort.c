#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaHeap(int Vet[], int Max);
void Heap(int L, int R, int Vet[]);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Heap Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Heap Sort
    OrdenaHeap(array, n);
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

/*  OrdenaHeap(): Função que Ordena o array Vet[Max] aplicando o Método da
    Família de Classificação por Seleção chamado de Heap Sort. */
void OrdenaHeap(int Vet[], int Max) {
    int L;
    int R;
    int x;

    L = (Max/2) + 1;
    R = Max - 1;

    while(L > 0){
        L--;
        Heap(L, R, Vet);
    }

    while(R > 0){
        x = Vet[0];
        Vet[0] = Vet[R];
        Vet[R] = x;
        R--;
        Heap(L, R, Vet);
    }
}

/*  Heap(): Função Auxiliar a Função OrdenaHeap, que ajuda a Ordenar o array
    Vet[Max] aplicando o Método da Família de Classificação por Seleção
    chamado de Heap Sort*/
void Heap(int L, int R, int Vet[]){
    int i; 
    int j;
    int x;

    i = L;
    j = 2 * L;
    x = Vet[L];

    if((j < R) && (Vet[j] < Vet[j+1])){
        j++;
    }

    while((j <= R) && (x < Vet[j])){
        Vet[i] = Vet[j];
        i = j;
        j = 2 * j;

        if((j < R) && (Vet[j] < Vet[j+1])){
            j++;
        }
    }
    Vet[i] = x;
}