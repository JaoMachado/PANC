#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATIVOS 100
#define MAX_DIAS 30

// Estrutura para armazenar o ativo
typedef struct {
    char nome[20];
    int preco[MAX_DIAS];
    int variacao[MAX_DIAS-1];
} Ativo;

// Estrutura para armazenar o resultado corretamente
typedef struct {
    int soma_maxima;
    int dia_inicio;
    int dia_fim;
} Resultado;

// Declaração das Funções
void calcularVariacao(Ativo *ativo);
int max(int a, int b);
Resultado segMaxDC(int A[], int p, int d);

int main() {
    // Abertura do arquivo
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
        printf("Ativo: %s \nSoma Máxima: %d \nDia Início: %d, Dia Fim: %d\n\n",
               ativos[i].nome, res.soma_maxima, res.dia_inicio + 1, res.dia_fim + 1);
    }

    return 0;
}

/* calcularVariacao(): Função para calcular a variação diária dos preços de um ativo.
   O cálculo é feito subtraindo o preço do dia anterior do preço do dia atual. */
void calcularVariacao(Ativo *ativo) {
    for (int i = 0; i < MAX_DIAS - 1; i++) {
        ativo->variacao[i] = ativo->preco[i + 1] - ativo->preco[i];
    }
}

// max(): Função auxiliar que retorna o maior valor entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

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
    
    int soma_esq = 0, max2esq = -1000000, esq_inicio = q;
    for (int i = q; i >= p; i--) {
        soma_esq += A[i];
        if (soma_esq > max2esq) {
            max2esq = soma_esq;
            esq_inicio = i;
        }
    }
    
    int soma_dir = 0, max2dir = -1000000, dir_fim = q + 1;
    for (int i = q + 1; i <= d; i++) {
        soma_dir += A[i];
        if (soma_dir > max2dir) {
            max2dir = soma_dir;
            dir_fim = i;
        }
    }
    
    int maxcruz = max2esq + max2dir;
    
    /* Condição para que retorne o "maxesq" ou "maxdir" quando não tiver terminado e retorne
    o resultado com os dias quando terminado. Substitui a linha 
    "devolva max(maxesq, maxcruz, maxdir)" na intenção de facilitar e retornar na estrutura
    Resultado*/ 
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