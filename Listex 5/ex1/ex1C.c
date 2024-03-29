#include <stdio.h>

// Assinaturas dos métodos
void torreHanoi(int n, char origem, char destino, char auxiliar);

int main(){
    int n; // armazena a quantidade de discos fornecido pelo usuario

    // solicita, recebe e atribui o numero a n
    printf("Digite a quantidade de discos a ser aplicado a Torre de Hanoi: ");
    scanf("%d", &n);

    // chama o metodo Torre de Hanoi
    torreHanoi(n, 'A', 'C', 'B');

    return 0;
}

// torreHanoi(): metodo para resolver a torre de Hanoi, mostrando cada movimento a fazer.
void torreHanoi(int n, char origem, char destino, char auxiliar){
    if(n > 0){
        torreHanoi(n-1, origem, auxiliar, destino);
        printf("\nMover disco da torre %c para a torre %c", origem, destino);
        torreHanoi(n-1, auxiliar, destino, origem);
    }
}