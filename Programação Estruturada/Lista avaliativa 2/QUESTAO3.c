#include <stdio.h>
#include <string.h>

void somaMATRIZ(int A[4][4], int B[4][4], int RESULTADO[4][4]) {//c�lculo de soma
    for (int X = 0; X < 4; X++) {
        for (int Y = 0; Y < 4; Y++) {
            RESULTADO[X][Y] = A[X][Y] + B[X][Y];
        }
    }
}

void subMATRIZ(int A[4][4], int B[4][4], int RESULTADO[4][4]) {//c�lculo de subtra��o
    for (int X = 0; X < 4; X++) {
        for (int Y = 0; Y < 4; Y++) {
            RESULTADO[X][Y] = A[X][Y] - B[X][Y];
        }
    }
}

void multMATRIZ(int A[4][4], int B[4][4], int RESULTADO[4][4]) {//c�lculo de multiplica��o
    for (int X = 0; X < 4; X++) {
        for (int Y = 0; Y < 4; Y++) {
            RESULTADO[X][Y] = 0;
            for (int Z = 0; Z < 4; Z++) {
                RESULTADO[X][Y] += A[X][Z] * B[Z][Y];
            }
        }
    }
}

int main() {
    int matrizA[4][4], matrizB[4][4], RESULTADO[4][4];
    char OP[20];//opera��o

    for (int X = 0; X < 4; X++) {
        for (int Y = 0; Y < 4; Y++) {
            scanf("%d", &matrizA[X][Y]);
        }
    }

    for (int X = 0; X < 4; X++) {
        for (int Y = 0; Y < 4; Y++) {
            scanf("%d", &matrizB[X][Y]);
        }
    }

    scanf("%s", OP);

    if (strcmp(OP, "soma") == 0) { //string de compara��o
        somaMATRIZ(matrizA, matrizB, RESULTADO);
    } else if (strcmp(OP, "sub") == 0) {
        subMATRIZ(matrizA, matrizB, RESULTADO);
    } else if (strcmp(OP, "mult") == 0) {
        multMATRIZ(matrizA, matrizB, RESULTADO);
    }

    for (int X = 0; X < 4; X++) {
        for (int Y = 0; Y < 4; Y++) {
            printf("%4d", RESULTADO[X][Y]);
        }
        printf("\n");
    }

    return 0;
}
