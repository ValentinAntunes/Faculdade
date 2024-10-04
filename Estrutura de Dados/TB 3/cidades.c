#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cidades.h"

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

    if (!(T >= 3 && T <= 1000000 && N >= 2 && N <= 10000)) {
        fclose(arquivo);
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    estrada->T = T;
    estrada->N = N;
    estrada->C = (Cidade *)malloc(N * sizeof(Cidade));

    char linha[512];
    fgets(linha, sizeof(linha), arquivo);

    for (int i = 0; i < N; i++) {
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            if (sscanf(linha, "%d %[^\n]", &estrada->C[i].Posicao, estrada->C[i].Nome) != 2) {
                free(estrada->C);
                free(estrada);
                fclose(arquivo);
                return NULL;
            }

            if (estrada->C[i].Posicao <= 0 || estrada->C[i].Posicao >= T) {
                free(estrada->C);
                free(estrada);
                fclose(arquivo);
                return NULL;
            }

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

    qsort(estrada->C, N, sizeof(Cidade), compararCidades);

    fclose(arquivo);
    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return -1;
    }

    double menorVizinhanca = estrada->T;
    double vizinhanca;

    if (estrada->N > 1) {
        vizinhanca = (estrada->C[1].Posicao - estrada->C[0].Posicao) / 2.0 + estrada->C[0].Posicao;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    for (int i = 1; i < estrada->N - 1; i++) {
        vizinhanca = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

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
        return NULL;
    }

    double menorVizinhanca = estrada->T;
    double vizinhanca;
    int cidadeIndex = -1;

    if (estrada->N > 1) {
        vizinhanca = (estrada->C[1].Posicao - estrada->C[0].Posicao) / 2.0 + estrada->C[0].Posicao;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeIndex = 0;
        }
    }

    for (int i = 1; i < estrada->N - 1; i++) {
        vizinhanca = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidadeIndex = i;
        }
    }

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