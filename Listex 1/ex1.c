#include <stdio.h>
#include <stdlib.h>

int maxElemento(int array[], int n, int *operacoes){
    int max = array[0];

    for(int i = 1; i < n; i++){
        (*operacoes)++;
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

int main(){

    int n;
    int operacoes = 0;

    // Adquirindo o tamanho do array
    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &n);

    int array[n];
    // preenchendo o array
    for(int i = 0; i < n; i++){
        printf("\nDigite o valor para a posicao %d do Array: ", i+1);
        scanf("%d", &array[i]);
    }

    int max = maxElemento(array, n, &operacoes);

    printf("O maior elemento do Array eh: %d (Num. Operacoes = %d)", max, operacoes);
    
    return 0;

}