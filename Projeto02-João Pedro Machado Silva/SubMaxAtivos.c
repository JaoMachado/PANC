#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATIVOS 100
#define MAX_DIAS 30

// estrutura para armazenar o ativo
typedef struct {
    char nome[20];
    int preco[MAX_DIAS];
    int variacao[MAX_DIAS-1];
} Ativo;

/* calcularVariacao(): Função para calcular a variação diária dos preços de um ativo.
   O cálculo é feito subtraindo o preço do dia anterior do preço do dia atual. */
void calcularVariacao(Ativo *ativo) {
    for (int i = 0; i < MAX_DIAS - 1; i++) {
        ativo->variacao[i] = ativo->preco[i + 1] - ativo->preco[i];
    }
}

/* max(): Função auxiliar que retorna o maior valor entre dois inteiros. */
int max(int a, int b) {
    return (a > b) ? a : b;
}

// estrutura para armazenar o resultado corretamente
typedef struct {
    int soma_maxima;
    int dia_inicio;
    int dia_fim;
} Resultado;

/* segMaxDC(): Função de Divisão e Conquista para encontrar a soma máxima de um subarranjo
   em um array. A função divide o array em duas partes, encontra a soma máxima em cada parte,
   e também encontra a soma máxima que cruza a divisão. */
Resultado segMaxDC(int A[], int p, int d) {
    Resultado res;
    if (p == d) {
        res.soma_maxima = max(0, A[p]);
        res.dia_inicio = res.dia_fim = p;
        return res;
    }
    
    int q = (p + d) / 2;
    
    Resultado maxesq = segMaxDC(A, p, q);
    Resultado maxdir = segMaxDC(A, q + 1, d);
    
    int soma = 0;
    int max2esq = -A[q];
    int esq_inicio = q;
    
    for (int i = q - 1; i >= p; i--) {
        soma += A[i];
        if (soma > max2esq) {
            max2esq = soma;
            esq_inicio = i;
        }
    }
    
    soma = 0;
    int max2dir = -A[q + 1];
    int dir_fim = q + 1;
    
    for (int f = q + 2; f <= d; f++) {
        soma += A[f];
        if (soma > max2dir) {
            max2dir = soma;
            dir_fim = f;
        }
    }
    
    int maxcruz = max2esq + max2dir;
    
    if (maxesq.soma_maxima >= maxdir.soma_maxima && maxesq.soma_maxima >= maxcruz) {
        return maxesq;
    } else if (maxdir.soma_maxima >= maxesq.soma_maxima && maxdir.soma_maxima >= maxcruz) {
        return maxdir;
    } else {
        res.soma_maxima = maxcruz;
        res.dia_inicio = esq_inicio;
        res.dia_fim = dir_fim;
        return res;
    }
}

int main() {
    FILE *file = fopen("ativos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Ativo ativos[MAX_ATIVOS];
    int num_ativos = 0;

    // Leitura do arquivo
    while (fscanf(file, "%[^;];", ativos[num_ativos].nome) != EOF) {
        for (int i = 0; i < MAX_DIAS; i++) {
            fscanf(file, "%d;", &ativos[num_ativos].preco[i]);
        }
        calcularVariacao(&ativos[num_ativos]);
        num_ativos++;
    }

    fclose(file);

    // Processamento dos dados de cada ativo
    for (int i = 0; i < num_ativos; i++) {
        Resultado res = segMaxDC(ativos[i].variacao, 0, MAX_DIAS - 2);
        printf("Ativo: %s\nSoma Máxima: %d\nDia Início: %d, Dia Fim: %d\n\n",
               ativos[i].nome, res.soma_maxima, res.dia_inicio + 1, res.dia_fim + 2);
    }

    return 0;
}