#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Metodos
void geraArrayInteiros(int arrayA[], int n);
void imprimeArray(int arrayA[], int n, char msg[]);
void mergeSortIterativo(int arrayA[], int n);
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim);
void intercalaComSentinela(int arrayA[], int inicio, int meio, int fim);
void copiaArray(int arrayA[], int arrayB[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *arrayOriginal; //Array de Inteiros gerado automaticamente
    int *arrayTemp;     /*Array temporario para ser utilizado 
                        nas ordenacoes, mantendo integridade
                        dos dados do Array Original */

    printf("Algoritmo Merge Sort sem Sentinela: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    arrayOriginal = (int*) malloc( n * sizeof(int) );
    arrayTemp = (int*) malloc( n * sizeof(int) );

    //Gerando o Array Original
    printf("\nOrdenacao");
    geraArrayInteiros(arrayOriginal, n);
    imprimeArray(arrayOriginal, n, "Array Desord.[]");

    //Ordenando o array por Merge Sort sem Sentinela
    copiaArray(arrayOriginal, arrayTemp, n);
    mergeSortIterativo(arrayTemp, n);
    imprimeArray(arrayTemp, n, "Array Ord.   []");
    printf(" ");
    system("pause");


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

/* mergeSortIterativo(): Metodo de ordenacao por intercalacao de elementos inteiros de array 
                com complexidade T(n) = n * lgn*/
void mergeSortIterativo(int arrayA[], int n) {
    /*  declaracao de variaveis e inicializadas como 1: 
        p-> inicio; 
        b-> blocos a pular; 
        r-> final
    */ 
    int p, r, b = 1;
    while (b < n) {
        // p(inicio) recebe 0
        p = 0;
        while (p + b < n) {
            // r(final) recebe o inicio + 2 * o b, -1
            r = p + 2 * b - 1;
            // se r >= n, quer dizer que o salto de blocos ultrapassa o fim do array e entao r = n-1
            if (r >= n){
                r = n - 1;
            }
            intercalaSemSentinela(arrayA, p, p + b - 1, r);
            imprimeArray(arrayA, n, "Array Ord.   []");
            p = p + 2 *b; 
        }
        b = 2 * b;
    }
}

/* intercalaSemSentinela(): metodo auiliar do mergeSortIterativo para intercalar dois segmentos de arrays ja ordenados invertendo a segunda parte do array
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


