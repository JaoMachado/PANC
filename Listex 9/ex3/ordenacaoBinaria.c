#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void ordenacaoBinaria(int arrayA[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Ordenacao Binaria: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Ordenacao Binaria
    ordenacaoBinaria(array, n);
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

/*  ordenacaoBinaria(): metodo para ordenacao de arrays de inteiros
    utilizando a buscaBinaria para determinar o ponto de insercao*/
void ordenacaoBinaria(int arrayA[], int n) {
    int i;
    int j;
    int m;
    int x;
    int L;
    int R;

    for(i = 1; i < n; i++){
        x = arrayA[i];
        
        //Busca do ponto R para inserir o x
        L = 0;
        R = i;

        printf(" - %d", arrayA[R]);

        while(L < R){
            m = (L + R) / 2;
            if(x >= arrayA[m]){
                L = m + 1;
            } else {
                R = m;
            }
        }

        // Fazendo a movimentacao para inserir no ponto R
        for(j = i; j > L; j--){
            arrayA[j] = arrayA[j-1];
        }

        // inserindo x na posicao de R
        arrayA[R] = x;

        // imprimindo cada passo da ordenacao
        imprimeArray(arrayA, n, "Vetor Desord.[]");
    }
}