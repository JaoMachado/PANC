#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaBubbleSort(int Vet[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Bubble Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Bubble Sort
    OrdenaBubbleSort(array, n);
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

/*  OrdenaBubbleSort(): Ordena a Sequencia de Numeros pelo Método de Ordenação de
    Permutação das Chaves, também chamado Bubble Sort. Este algoritmo
    empurra o maior valor para sua posição final. */
void OrdenaBubbleSort(int Vet[], int n) {
    int aux;
    int i;
    int j;

    for(j = n - 1; j >= 1; j--){
        for(i = 0; i < j; i++){
            if(Vet[i] > Vet[i+1]){
                aux = Vet[i];
                Vet[i] = Vet[i+1];
                Vet[i+1] = aux;

                // imprimindo cada passo da ordenacao
                imprimeArray(Vet, n, "Vetor Desord.[]");
            }
        }
    }
}