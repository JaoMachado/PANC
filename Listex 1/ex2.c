#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ehPrimo(int num, int *operacoes){
    for(int i = 2; i < num/2; i++){
        if(num % i == 0){
            return 0;
        }
        (*operacoes)++;
    }
    return 1;
}

int main(){
    int operacoes = 1;
    srand((unsigned)time(NULL));
    int num = rand() % 101;
    

    int result = ehPrimo(num, &operacoes);

    if(result == 0){
        printf("Numero inteiro gerado automaticamente (1-100): %d\n", num);
        printf("O numero %d NAO eh Primo (Num. Operacoes = %d)", num, operacoes);
    } else {
        printf("Numero inteiro gerado automaticamente (1-100): %d\n", num);
        printf("O numero %d eh Primo (Num. Operacoes = %d)", num, operacoes);
    }
}