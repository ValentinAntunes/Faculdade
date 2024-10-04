#include <stdio.h>
#include <string.h>

double FP(char NT[50], double F[11]) {//força ponderada, nome time, forças
    double FT = 0;//força time


    double G = F[0];

    double L1 = F[1];//lateral 1
    double L2 = F[4];//lateral em 4°

    double Z1 = F[2];//zagueiro em 2°
    double Z2 = F[3];//zagueiro 3

    double V1 = F[5];
    double V2 = F[6];

    double M1 = F[7];
    double M2 = F[8];

    double A1 = F[9];
    double A2 = F[10];

    FT = (8 * G + 10 * (L1 + L2) + 5 * (Z1 + Z2) + 8 * (V1 + V2) + 11 * (M1 + M2) + 12 * (A1 + A2)) / 100;

    return FT;
}

int main() {
    char NT1[50], NT2[50];
    double FT1[11] = {0};//força time 1
    double FT2[11] = {0};//força time 2
    int TOTALJ = 0;//total de jogadores
    char LINHA[100];//total de 24 linhas, (1 time + 11 jogadores) * 2;

    while (TOTALJ < 24) {//quando atingir 24 linhas, o código é compilado;
        fgets(LINHA, sizeof(LINHA), stdin);
        LINHA[strcspn(LINHA, "\n")] = '\0';
        if (LINHA[0] == '\0') {
            break;
        }

        if (TOTALJ == 0) {
            strcpy(NT1, LINHA);
        } else if (TOTALJ == 12) {
            strcpy(NT2, LINHA);
        } else {
            char NOME[50], POSITION;
            double FORCA;
            sscanf(LINHA, "%[^;];%c;%lf", NOME, &POSITION, &FORCA);

            if (TOTALJ <= 11) {
                FT1[TOTALJ - 1] = FORCA;
            } else {
                FT2[TOTALJ - 12 - 1] = FORCA;
            }
        }

        TOTALJ++;
    }

    double FPT1 = FP(NT1, FT1);//força ponderada T1
    double FPT2 = FP(NT2, FT2);//força ponderada T2

    printf("%s: %.2lf de forca\n", NT1, FPT1);
    printf("%s: %.2lf de forca\n", NT2, FPT2);

    if (FPT1 > FPT2) {
        printf("%s eh mais forte\n", NT1);
    } else if (FPT2 > FPT1) {
        printf("%s eh mais forte\n", NT2);
    }

    return 0;
}
