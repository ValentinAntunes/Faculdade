#include <stdio.h>
#include <math.h>

int main() {
    int MESES;
    double APORTE, txJUROS, MONTANTE;

    scanf("%d", &MESES);

    scanf("%lf", &APORTE);

    scanf("%lf", &txJUROS);

    for (int i = 1; i <= MESES; i++) {
        MONTANTE = APORTE * (1 + txJUROS) * ((pow(1 + txJUROS, i) - 1) / txJUROS);

        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, MONTANTE);
    }

    return 0;
}
