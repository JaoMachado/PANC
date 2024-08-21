#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaBubbleSortMelhorado(int Vet[], int n);

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
    OrdenaBubbleSortMelhorado(array, n);
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

/*  OrdenaBubbleSortMelhorado(): Ordena a Sequencia de Numeros pelo Método de Ordenação de
    Permutação das Chaves, também chamado Bubble Sort,
    mas termina a execução quando nenhuma troca é realizada
    após uma passada pelo vetor. */
void OrdenaBubbleSortMelhorado(int Vet[], int n) {
    int aux;
    int i;
    int j;
    int troca;

    troca = 1; //A variável "troca" será a verificação da troca em cada passada

    for(j = n - 1; (j >= 1) && (troca == 1); j--){
        troca = 0; //Se o valor continuar 0 na próxima passada quer dizer que não houve troca e a função é encerrada.
        for(i = 0; i < j; i++){
            if(Vet[i] > Vet[i+1]){
                aux = Vet[i];
                Vet[i] = Vet[i+1];
                Vet[i+1] = aux;
                troca=1; //Se houve troca, "troca" recebe 1 para continuar rodando.

                // imprimindo cada passo da ordenacao
                imprimeArray(Vet, n, "Vetor Desord.[]");
            }
        }
    }
}