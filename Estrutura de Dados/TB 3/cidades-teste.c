#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cidades.h"

// Função auxiliar para comparação de inteiros usada no qsort
int compararCidades(const void *a, const void *b) {
    Cidade *cidadeA = (Cidade *)a;
    Cidade *cidadeB = (Cidade *)b;
    return cidadeA->Posicao - cidadeB->Posicao;
}

Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        return NULL;
    }

    int T, N;
    fscanf(arquivo, "%d", &T);
    fscanf(arquivo, "%d", &N);

    // Verificação de restrições
    if (!(T >= 3 && T <= 1000000 && N >= 2 && N <= 10000)) {
        fclose(arquivo);
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    estrada->T = T;
    estrada->N = N;
    estrada->C = (Cidade *)malloc(N * sizeof(Cidade));

    char linha[512];
    fgets(linha, sizeof(linha), arquivo); // Consumir a linha em branco

    for (int i = 0; i < N; i++) {
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            if (sscanf(linha, "%d %[^\n]", &estrada->C[i].Posicao, estrada->C[i].Nome) != 2) {
                free(estrada->C);
                free(estrada);
                fclose(arquivo);
                return NULL;
            }

            // Verificação adicional das posições
            if (estrada->C[i].Posicao <= 0 || estrada->C[i].Posicao >= T) {
                free(estrada->C);
                free(estrada);
                fclose(arquivo);
                return NULL;
            }

            // Verificar se as posições são únicas
            for (int j = 0; j < i; j++) {
                if (estrada->C[i].Posicao == estrada->C[j].Posicao) {
                    free(estrada->C);
                    free(estrada);
                    fclose(arquivo);
                    return NULL;
                }
            }
        }
    }

    // Ordenar as cidades pela posição para facilitar o cálculo da vizinhança
    qsort(estrada->C, N, sizeof(Cidade), compararCidades);

    fclose(arquivo);
    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return -1; // Indica erro na leitura ou validação das restrições
    }

    double menorVizinhanca = estrada->T;
    double vizinhanca;

    // Calcular a vizinhança inicial (do ponto 0 até a primeira divisa após a primeira cidade)
    if (estrada->N > 1) {
        vizinhanca = (estrada->C[1].Posicao - estrada->C[0].Posicao) / 2.0 + estrada->C[0].Posicao;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    // Calcular vizinhanças entre as cidades
    for (int i = 1; i < estrada->N - 1; i++) {
        vizinhanca = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    // Calcular a vizinhança final (da última divisa antes da última cidade até o ponto T)
    if (estrada->N > 1) {
        vizinhanca = (estrada->C[estrada->N - 1].Posicao - estrada->C[estrada->N - 2].Posicao) / 2.0 + (estrada->T - estrada->C[estrada->N - 1].Posicao);
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    free(estrada->C);
    free(estrada);
    return menorVizinhanca;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return NULL; // Indica erro na leitura ou validação das restrições
    }

    double menorVizinhanca = estrada->T;
    double vizinhanca;
    int cidadeIndex = -1;

    // Calcular a vizinhança inicial (do ponto 0 até a primeira divisa após a primeira cidade)
    if (estrada->N > 1) {
        vizinhanca = (estrada->C[1].Posicao - estrada->C[0].Posicao) / 2.0 + estrada->C[0].Posicao;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeIndex = 0;
        }
    }

    // Calcular vizinhanças entre as cidades
    for (int i = 1; i < estrada->N - 1; i++) {
        vizinhanca = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeIndex = i;
        }
    }

    // Calcular a vizinhança final (da última divisa antes da última cidade até o ponto T)
    if (estrada->N > 1) {
        vizinhanca = (estrada->C[estrada->N - 1].Posicao - estrada->C[estrada->N - 2].Posicao) / 2.0 + (estrada->T - estrada->C[estrada->N - 1].Posicao);
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeIndex = estrada->N - 1;
        }
    }

    if (cidadeIndex != -1) {
        char *nomeCidade = (char *)malloc(256 * sizeof(char));
        strcpy(nomeCidade, estrada->C[cidadeIndex].Nome);
        free(estrada->C);
        free(estrada);
        return nomeCidade;
    }

    free(estrada->C);
    free(estrada);
    return NULL;
}
