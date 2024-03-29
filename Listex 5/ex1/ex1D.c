#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void BuscaBinariaRecursiva(int arrayA[], int inicio, int fim, int x);
void verificaOrdenacao(int arrayA[], int n);

int main()
{
    //Variaveis Locais 
    int n; // tamanho do array            
    int *array; // Array de Inteiros
    int x; // valor a ser procurado

    //Definindo o Array e alocando espaco de memoria
    printf("Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Solicitando e montando o Array Original
    printf("\nAgora voce digitará o valor para cada indice do array, lembre-se que deve ser ORDENADO\n");
    for(int i = 0; i < n; i++){
        printf("Digite o valor para a posição %d do Array: ", i);
        scanf("%d", &array[i]);
    }

    // verificando ordenação do array
    verificaOrdenacao(array, n);

    // imprime array passado
    imprimeArray(array, n, "Array[]");

    // pegando o valor a ser procurado no array ordenado
    printf("\nEntre com o valor inteiro a ser procurado: ");
    scanf("%d", &x);
    BuscaBinariaRecursiva(array, 0, n - 1, x);

    return 0;
}

/* imprimeArray(): Imprime os n elementos inteiros de um array */
void imprimeArray(int arrayA[], int n, char msg[]) {
    printf("\n%s = ", msg);

    for (int i=0; i<n; i++) {
        printf(" %d", arrayA[i]);
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

// verificaOrdenacao(): Verifica se o array está ordenado
void verificaOrdenacao(int arrayA[], int n){
    for (int i = 0; i < n - 1; i++) {
        if (arrayA[i] > arrayA[i + 1]) {
            printf("ARRAY ESTÁ DESORDENADO\n");
            exit(0); 
        }
    }
    printf("ARRAY ESTÁ ORDENADO\n");
}


