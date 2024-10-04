#include <stdio.h>
#include "calculadora.h"

int main() {
    char expression[MAX];
    char choice;

    do {
        printf("Escreva a operação posfixa: ");
        fgets(expression, MAX, stdin);

        expression[strcspn(expression, "\n")] = 0;

        printf("Resultado: %.2f\n", Posfixa(expression));

        printf("Deseja fazer outra operação? (s/n) : ");
        choice = getchar();
        getchar();
    } while (choice == 's' || choice == 'S');

    return 0;
}