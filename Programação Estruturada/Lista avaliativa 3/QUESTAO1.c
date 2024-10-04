#include <stdio.h>
#include <string.h>

int VR(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int RpD(char *romano) { //romano para decimal
    int RESULT = 0;
    int i;

    for (i = 0; i < strlen(romano); i++) {
        int vATUAL = VR(romano[i]);
        int vPROX = (i + 1 < strlen(romano)) ? VR(romano[i + 1]) : 0;

        if (vATUAL < vPROX) {
            RESULT += vPROX - vATUAL;
            i++;
        } else {
            RESULT += vATUAL;
        }
    }

    return RESULT;
}

void DpB(int decimal, char *binario) { //decimal para binário
    if (decimal == 0) {
        binario[0] = '0';
        binario[1] = '\0';
        return;
    }

    int INDEX = 0;
    while (decimal > 0) {
        binario[INDEX++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    binario[INDEX] = '\0';

    int inicio = 0;
    int END = INDEX - 1;
    while (inicio < END) {
        char temp = binario[inicio];
        binario[inicio] = binario[END];
        binario[END] = temp;
        inicio++;
        END--;
    }
}

int main() {
    char romano[13];
    char binario[32];

    scanf("%s", romano);

    int decimal = RpD(romano);

    DpB(decimal, binario);

    printf("%s na base 2: %s\n", romano, binario);

    printf("%s na base 10: %d\n", romano, decimal);

    printf("%s na base 16: %x\n", romano, decimal);

    return 0;
}
