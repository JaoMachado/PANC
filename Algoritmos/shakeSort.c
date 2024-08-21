#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaShakeSort(int Vet[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Shake Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Shake Sort
    OrdenaShakeSort(array, n);
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

/*  OrdenaShakeSort(): Ordena a Sequencia de Numeros pelo Método de Ordenação por
    Agitação das Chaves, também chamado Shake Sort.*/
void OrdenaShakeSort(int Vet[], int n) {
    int L = 0;
    int R = n - 1;
    int k = n - 1;
    int j;
    int x;

    do{
        //Caminhando da esquerda para a direira no vetor
        for(j = L; j < R; j++){
            if(Vet[j] > Vet[j+1]){
                x = Vet[j];
                Vet[j] = Vet[j+1];
                Vet[j+1] = x;
                k = j;
                // imprimindo cada passo da ordenacao
                imprimeArray(Vet, n, "Vetor Desord.[]");
            }
        }

        R = k;

        //Caminhando da direita para a esquerda no vetor
        for(j = R; j > R; j--){
            if(Vet[j-1] > Vet[j]){
                x = Vet[j-1];
                Vet[j-1] = Vet[j];
                Vet[j] = x;
                k = j;
                // imprimindo cada passo da ordenacao
                imprimeArray(Vet, n, "Vetor Desord.[]");
            }
        }
        L = k;

    } while(L < R);
}