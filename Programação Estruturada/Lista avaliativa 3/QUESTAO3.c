#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int PV(char *placa) { //Validação da placa antiga
    if (strlen(placa) == 8 && placa[3] == '-' &&
        isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) {
        return 1;
    }
    else if (strlen(placa) == 7 && //Validação da placa nova
             isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
             isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6])) {
        return 1;
    }
    return 0;
}

int DSVALIDO(char *DS) { //Validação do dia
    char diasVALIDOS[7][15] = {"DOMINGO", "SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO"};

    for (int i = 0; i < 7; i++) {
        if (strcmp(DS, diasVALIDOS[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char placa[11];
    char DS[15];//dia da semana

    scanf("%s", placa);
    scanf("%s", DS);

    if(!PV(placa) && !DSVALIDO(DS)){
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
        return 0;
    } else if (!DSVALIDO(DS)) {
        printf("Dia da semana invalido\n");
        return 0;
    } else if (!PV(placa)) {
        printf("Placa invalida\n");
        return 0;
    }

    int nFINAL = isdigit(placa[strlen(placa) - 1]) ? (placa[strlen(placa) - 1] - '0') : (placa[strlen(placa) - 2] - '0');
    //nFINAL é o último digito da placa
    strlwr(DS);

    if (strcmp(DS, "domingo") == 0 || strcmp(DS, "sabado") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (strcmp(DS, "segunda-feira") == 0) {
        if (nFINAL == 0 || nFINAL == 1) {
            printf("%s nao pode circular %s\n", placa, DS);
        } else {
            printf("%s pode circular %s\n", placa, DS);
        }
    } else if (strcmp(DS, "terca-feira") == 0) {
        if (nFINAL == 2 || nFINAL == 3) {
            printf("%s nao pode circular %s\n", placa, DS);
        } else {
            printf("%s pode circular %s\n", placa, DS);
        }
    } else if (strcmp(DS, "quarta-feira") == 0) {
        if (nFINAL == 4 || nFINAL == 5) {
            printf("%s nao pode circular %s\n", placa, DS);
        } else {
            printf("%s pode circular %s\n", placa, DS);
        }
    } else if (strcmp(DS, "quinta-feira") == 0) {
        if (nFINAL == 6 || nFINAL == 7) {
            printf("%s nao pode circular %s\n", placa, DS);
        } else {
            printf("%s pode circular %s\n", placa, DS);
        }
    } else if (strcmp(DS, "sexta-feira") == 0) {
        if (nFINAL == 8 || nFINAL == 9) {
            printf("%s nao pode circular %s\n", placa, DS);
        } else {
            printf("%s pode circular %s\n", placa, DS);
        }
    }

    return 0;
}
