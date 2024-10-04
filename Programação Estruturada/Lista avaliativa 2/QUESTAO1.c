#include <stdio.h>

int main() {
    int N[10];
    int TOTAL = 10;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &N[i]);
    }

    while (TOTAL > 1) {
        for (int i = 0; i < TOTAL; i++) {
            if (i == TOTAL - 1) {
                printf("%d\n", N[i]);
            } else {
                printf("%d ", N[i]);
            }
        }

        for (int i = 0; i < TOTAL - 1; i++) {
            N[i] = N[i] + N[i + 1];
        }

        TOTAL--;
    }

    printf("%d\n", N[0]);

    return 0;
}
