#include <stdio.h>

// Assinaturas dos métodos
int comb(int n, int k);

int main(){
    int k; // armazena o numero de pessoas por grupo
    int n; // armazena o numero de pessoas

    // solicita, recebe e atribui o numero a k
    printf("Entre com o valor de grupos distintos (k): ");
    scanf("%d", &k);

    // solicita, recebe e atribui o numero a n
    printf("\nEntre com o valor de pessoas (n): ");
    scanf("%d", &n);

    // chama o metodo comb e printa o resultado
    printf("\nA quantidade de combinacoes C(n, k) = C(%d, %d) = %d\n\n", n, k, comb(n, k));

    return 0;
}

// comb(): Metodo que retorna quantos grupos de k pessoas são possiveis com n pessoas
int comb(int n, int k){
    if(k == 1){
        return n;
    } else if(k == n){
        return 1;
    } else if(1 < k && k < n){
        int resultado = comb(n-1, k-1);
        return resultado + comb(n-1, k);
    }
}