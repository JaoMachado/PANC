#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Metodos
void geraArrayInteiros(int arrayA[], int n);
void imprimeArray(int arrayA[], int n, char msg[]);
int procuraValor(int arrayA[], int n, int valorProcura);

int main(){
    int n; //tamanho do array
    int valorProcura; // valor a ser procurado no array
    int *array; //array de inteiros gerados
    int indiceEncontrado; //o indice que foi encontrado o valorProcura

    //Definindo o Array e alocando espaco de memoria
    printf("\nEntre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc(n * sizeof(int));

    // gerando e imprimino o array
    geraArrayInteiros(array, n);
    imprimeArray(array, n, "Array Gerado");

    //Definindo o valor a ser procurado
    printf("\nEntre com o valor inteiro a ser procurado: ");
    scanf("%d", &valorProcura);

    //Procurando o valor e imprimindo a mensagem
    indiceEncontrado = procuraValor(array, n, valorProcura);

    if(indiceEncontrado == -1){
        printf("\nValor nao encontrado no Array!");
    } else {
        printf("\nO Valor %d foi encontrado na posicao %d", valorProcura, indiceEncontrado);
    }
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

/* procuraValor(): Procura o valor nos indices do array e retorna o indice em que foi encontrado*/
int procuraValor(int arrayA[], int n, int valorProcura){
    for(int i = 1; i < n; i++){
        if(arrayA[i-1] == valorProcura){
            return i;
        }
    }
    return -1;
}
