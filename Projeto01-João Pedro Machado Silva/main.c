#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"
#include "threesum.c"

/* Vari�veis Globais */
int *A;

int main()
{
    // Variavel que armazena no tamanho do array
    int n;
    
    printf("\n ---Projeto 01 - 3SUM--- \n");

    // Adquire o tamanho do array e instancia o tamanho no array "A"
    printf("\n Definir o tamanho do Array: ");
    scanf("%d", &n);
    A = (int*) malloc (n * sizeof(int));
    
    // preenche o array e o imprime o mesmo
    for(int i=0; i<n; i++) {
        printf(" Entre com o %d elemento do Array: ", i+1);
        scanf("%d", &A[i]);
    }

    ImprimeArray(A, "Array Infor.   []", n);

    // Apresenta a solução através da versão de força bruta do 3SUM
    printf("\n\n ---3SUM - Forca Bruta:--- \n\n");
    treeSumForcaBruta(A, n);

    // Apresenta a solução através da versão melhorada do 3SUM
    printf("\n ---3SUM - Melhorado:--- \n");
    treeSumMelhorado(A, n);

    // Imprime quantidade de operações necessárias em cada uma das versões do 3SUM
    ImprimeQtdOperacoes();

    return 0;
}

