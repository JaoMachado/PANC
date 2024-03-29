#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Metodos
void geraArrayInteiros(int arrayA[], int n);
void imprimeArray(int arrayA[], int n, char msg[]);
int max(int arrayA[], int n);

int main()
{
    //Variaveis Locais 
    int n; // tamanho do array            
    int *array; //Array de Inteiros gerado automaticamente

    //Definindo o Array e alocando espaco de memoria
    printf("Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    //Gerando o Array 
    geraArrayInteiros(array, n);
    imprimeArray(array, n, "Array Gerado");

    // chamando o metodo max e printando o maior valor do array
    printf("\nO maior valor do array é: %d\n", max(array, n));

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

/* max(): metodo para achar o maior valor no array utilizando a recursividade*/
int max(int arrayA[], int n){
    if (n == 1){
        return arrayA[0];
    }

    int max_resto = max(arrayA + 1, n - 1);

    if (arrayA[0] > max_resto){
        return arrayA[0];
    } else {
        return max_resto;
    }
}


