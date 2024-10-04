#include <stdio.h>

int main(){

    int N1, N2, S, X;

    scanf("%d", &N1);

    if(N1 % 2 == 0){
        printf("%d eh par\n", N1);
    }else{
        printf("%d eh impar\n", N1);
    }

    N2 = N1;

    S = 0;

    while (N2 > 0){
        X =  N2 % 10;
        S = S + X;
        N2 = N2 / 10;
    }

    printf("A soma dos algarismos de %d eh igual a %d\n", N1, S);

    return 0;
}
