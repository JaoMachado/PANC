#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaSelecao(int Vet[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Select Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Ordena Selecao
    OrdenaSelecao(array, n);
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

/*  OrdenaSelecao(): Função que Ordena o array Vet[Max] aplicando o Método da
    Família de Classificação por Seleção chamado de Select Sort. */
void OrdenaSelecao(int Vet[], int n) {
    int i;
    int j;
    int k;
    int x;
    int Comp;

    for(i = 0; i < n; i++){
        Comp = 0;
        k = i;
        x = Vet[i];
        for(j = i + 1; j < n; j++){
            if(Vet[j] < x){
                k = j;
                x = Vet[k];
                Comp = 1;
                // imprimindo cada passo da ordenacao
                imprimeArray(Vet, n, "Vetor Desord.[]");
            }
        }
        if(Comp == 1){
            Vet[k] = Vet[i];
            Vet[i] = x;
        }
    }
}