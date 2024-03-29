#include <stdio.h>
// Assinaturas dos métodos
double H(int n);

int main(){
    int n; // armazena o numero fornecido pelo usuario
    
    printf("Digite a posicao desejada da Serie Harmonica: ");
    scanf("%d", &n);
    printf("O valor do %d-esimo numero harmonico é %.5f.\n", n, H(n));
    return 0;
}

// H(): metodo que retorna o valor da posicao n da serie harmonica por recursividade(Não é a melhor opção)
double H(int n){
    if(n <= 1){
        return 1.0;
    } else {
        double hn = H(n-1);
        return hn + (1.0/n);
    }
}
