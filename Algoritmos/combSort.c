#include <stdio.h>
#include <stdlib.h>

//Assinaturas dos Metodos
void imprimeArray(int arrayA[], int n, char msg[]);
void OrdenaCombSort(int Vet[], int n);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *array; //Array de Inteiros gerado automaticamente

    printf("Algoritmo Comb Sort: \n");

    //Definindo o Array e alocando espaco de memoria
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    array = (int*) malloc( n * sizeof(int) );

    // Recebendo o array
    for(int i = 0; i < n; i++){
        printf("Digite o valor para posicao %d do array: ", i);
        scanf("%d", &array[i]);
    }

    //Ordenando o array por Comb Sort
    OrdenaCombSort(array, n);
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

/*  OrdenaCombSort(): Ordena a Sequencia de Numeros pelo Método de Ordenação
    conhecido como CombSort. */
void OrdenaCombSort(int Vet[], int n) {
    double h = n;
    int x;
    int i;
    int Troca;

    do{
        h = h/1.3;

        if((h == 9)||(h == 10)){
            h = 11;
        }
        
        Troca = 0;

        for(i = 0; i < (n - h); i++){
            if(Vet[(int)i] > Vet[(int)(i + h)]){
                x = Vet[i];
                Vet[(int)i] = Vet[(int)(i+h)];
                Vet[(int)(i+h)] = x;
                Troca = 1;
                // imprimindo cada passo da ordenacao
                imprimeArray(Vet, n, "Vetor Desord.[]");
            }
        }
    } while((Troca == 1) || (h >= 1));
}