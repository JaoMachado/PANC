#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Metodos
void geraArrayInteiros(int arrayA[], int n);
void imprimeArray(int arrayA[], int n, char msg[]);
void mergeSort(int arrayA[], int inicio, int fim);
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim);
void copiaArray(int arrayA[], int arrayB[], int n);
void BuscaBinariaRecursiva(int arrayA[], int inicio, int fim, int x);

int x; // valor a ser procurado

int main()
{
    //Variaveis Locais 
    int n; // tamanho do array            
    int *arrayOriginal; //Array de Inteiros gerado automaticamente
    int *arrayTemp;     /*Array temporario para ser utilizado nas ordenacoes, mantendo integridade
                        dos dados do Array Original */

    //Definindo o Array e alocando espaco de memoria
    printf("Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    arrayOriginal = (int*) malloc( n * sizeof(int) );
    arrayTemp = (int*) malloc( n * sizeof(int) );

    //Gerando o Array Original
    geraArrayInteiros(arrayOriginal, n);

    //Ordenando o array por Merge Sort com Sentinela
    copiaArray(arrayOriginal, arrayTemp, n);
    mergeSort(arrayTemp, 0, n-1);
    imprimeArray(arrayTemp, n, "Array Gerado Ordenado");
    printf(" ");

    // pegando o valor a ser procurado no array ordenado
    printf("\nEntre com o valor inteiro a ser procurado: ");
    scanf("%d", &x);
    BuscaBinariaRecursiva(arrayTemp, 0, n - 1, x);

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
    printf("\n%s = ", msg);

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

/* copiaArray(): Metodo que copia os n elementos do
   arrayA (origem) para o arrayB (destino) */
void copiaArray(int arrayA[], int arrayB[], int n) {
    for (int i=0; i<n; i++) {
        arrayB[i] = arrayA[i];
    }
}

/* BuscaBinariaRecursiva(): metodo para achar o valor no array utilizando a recursividade*/
void BuscaBinariaRecursiva(int arrayA[], int inicio, int fim, int x){
    // Verifica se o início é menor ou igual ao fim
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Verifica se o elemento está no meio
        if (arrayA[meio] == x) {
            printf("\nO valor %d foi encontrado na posição %d do Array!\n", x, meio);
            return;
        }

        // Se o elemento está na metade esquerda do array
        if (arrayA[meio] > x)
            BuscaBinariaRecursiva(arrayA, inicio, meio - 1, x);

        // Se o elemento está na metade direita do array
        else
            BuscaBinariaRecursiva(arrayA, meio + 1, fim, x);
    } else {
        printf("\nO valor %d não foi encontrado no Array!\n", x);
    }
}



