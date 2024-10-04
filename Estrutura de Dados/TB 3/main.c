#include <stdio.h>
#include "cidades.h"

int main() {
    const char *nomeArquivo = "entrada.txt";
    
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        printf("Erro ao ler o arquivo ou restricoes nao atendidas.\n");
        return 1;
    }
    
    printf("Comprimento da estrada: %d\n", estrada->T);
    printf("Numero de cidades: %d\n", estrada->N);
    for (int i = 0; i < estrada->N; i++) {
        printf("Cidade: %s, Posicao: %d\n", estrada->C[i].Nome, estrada->C[i].Posicao);
    }
    
    double menorVizinhanca = calcularMenorVizinhanca(nomeArquivo);
    printf("Menor vizinhanca: %.2f\n", menorVizinhanca);
    
    char *cidadeMenor = cidadeMenorVizinhanca(nomeArquivo);
    if (cidadeMenor != NULL) {
        printf("Cidade com menor vizinhanca: %s\n", cidadeMenor);
        free(cidadeMenor);
    }
    
    free(estrada->C);
    free(estrada);

    return 0;
}
