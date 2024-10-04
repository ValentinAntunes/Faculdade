#include <stdio.h>
#include <stdlib.h>

#define ERRO -1     // Define uma constante chamada ERRO 

float MediaAritmetica (float A, float B, float C);

int main() {
    system("cls");      // Executa o comando 'cls' do DOS
    float a, b, c;
    printf ("Digite tres valores (float): ");
    scanf("%f %f %f", &a, &b, &c);  //%f para float.
    float m = MediaAritmetica(a, b, c);
    printf("A media e %f", m);
}

float MediaAritmetica (float A, float B, float C) {
    float M = A + B + C;
    M = M / 3;
    return(M);
}

