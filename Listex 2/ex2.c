#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
int receberIndiceArray(int array[], int n);
int maxMin1(int array[], int n, int max, int min);
int maxMin2(int array[], int n, int max, int min);
int maxMin3(int array[], int n, int max, int min);

// Variaveis globais
int operacoes;

int main(){
    //Variaveis Locais
    int n; //Tamanho do Array
    int *array; //Array de Inteiros 
    int max;
    int min;

    //Definindo o Array e alocando espaco de memoria
    printf("\nEntre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // recebendo array do usuario
    receberIndiceArray(array, n);

    // passando nos algoritmos 
    maxMin1(array, n, max, min);
    maxMin2(array, n, max, min);
    maxMin3(array, n, max, min);
}

/* receberIndiceArray(): Preenche o array com os valores dos indices fornecidos pelo usuario*/
int receberIndiceArray(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do Array: ", i+1);
        scanf("%d", &array[i]);
    }
}

/* int maxMin1(): primeiro algoritmo para encontrar o maior e menor elemento do array*/
int maxMin1(int array[], int n, int max, int min){
    max = array[0];
    min = array[0];
    operacoes = 0;

    for(int i = 1; i < n; i++){
        operacoes++;
        if(array[i] > max){
            max = array[i];
        }
        operacoes++;
        if(array[i] < min){
            min = array[i];
        }
    }
    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)", max, min, operacoes);
}

/* int maxMin2(): Segundo algoritmo para encontrar o maior e menor elemento do array*/
int maxMin2(int array[], int n, int max, int min){
    max = array[0];
    min = array[0];
    operacoes = 0;

    for(int i = 1; i < n; i++){
        operacoes++;
        if(array[i] > max){
            max = array[i];
        } else if(array[i] < min){
            min = array[i];
        }
    }

    printf("\nmaxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)", max, min, operacoes);
}
/* int maxMin3(): TErceiro algoritmo para encontrar o maior e menor elemento do array*/
int maxMin3(int array[], int n, int max, int min){
    operacoes = 0;

    if(n % 2 != 0){
        array[n+1] = array[n];
        n = n + 1;
    }

    max = array[0];
    min = array[1];

    operacoes++;
    if(array[0] < array[1]){
        max = array[1];
        min = array[0];
    }

    for(int i = 2; i < n; i += 2){
        operacoes++;
        if(array[i] > array[i+1]){
            operacoes++;
            if(array[i] > max){
                max = array[i];
            }
            operacoes++;
            if(array[i+1] < min){
                min = array[i+1];
            }
        } else {
            operacoes++;
            if(array[i] < min){
                min = array[i];
            }
            operacoes++;
            if(array[i+1] > max){
                max = array[i+1];
            }
        }
    }

    printf("\nmaxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)", max, min, operacoes);
}