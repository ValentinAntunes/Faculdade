#include <stdio.h>
#include <stdlib.h>

char f(int X);

int main() {
    char T1 = f(4);     // A resposta é B
    char T2 = f(4.8);   // A resposta também é B
    char T3 = f('A');   // O resultado não está no domínio
    char T4 = f('B' - 63);
    printf("Resposta: %c\n", T4);
}

char f (int X) {
    if (X == 1) return('C');
    else if(X == 2) return ('D');
    else if(X == 3) return ('E');
    else if(X == 4) return ('B');
    else if(X == 5) return ('E');
    else {
        printf("O valor indicado nao pertence ao dominio.\n");
        exit(0);
    }
}