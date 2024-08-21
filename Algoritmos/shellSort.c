#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
int power(int base, int exp);
void imprimeArray(int arrayA[], int n, char msg[]);
void shellSort(int arrayA[], int Inc, int SegCorrente, int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente
    int Inc;
    int np;

    printf("Algoritmo Shell Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Shell Sort
    np = 2;
    for(int i = np; i >= 0; i--){
        Inc = power(2, i);
        for(int SegCorrente = 0; SegCorrente < Inc; SegCorrente++){
            shellSort(array, Inc, SegCorrente, n);
        }
    }
    imprimeArray(array, n, "Vetor Ord.   []");

    return 0;
}

/* power(): funcao para calcular potencias*/
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}


/* imprimeArray(): Imprime os n elementos inteiros de um array */
void imprimeArray(int arrayA[], int n, char msg[]) {
    printf("\n %s = ", msg);

    for (int i=0; i<n; i++) {
        printf(" %d", arrayA[i]);
    }
}

/*  shellSort(): metodo para ordenacao de arrays de numeros inteiros
    o dividindo em segmentos e os combinando ordenando para uma menor troca no final*/
void shellSort(int arrayA[], int Inc, int SegCorrente, int n){
    int j;
    int i;
    int x;
    int k;

    for(i = (SegCorrente+Inc); i < n; i += Inc){
        k = SegCorrente;
        j = i - Inc;
        x = arrayA[i];

        printf(" - %d", arrayA[x]);

        while((j >= SegCorrente) && (k == SegCorrente)){
            if(x < arrayA[j]){
                arrayA[j+Inc] = arrayA[j];
                j -= Inc;
            } else {
                k = j + Inc;
            }
        }
    arrayA[k] = x;

    // imprimindo cada passo da ordenacao
    imprimeArray(arrayA, n, "Vetor Desord.[]");
    }
}