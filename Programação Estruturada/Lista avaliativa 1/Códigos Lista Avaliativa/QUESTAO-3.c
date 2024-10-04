#include <stdio.h>

int main(){

    int N, X;

    do{
        printf("Cadastre uma senha de 4 digitos:\n");
        scanf("%d", &N);

        if(N > 9999 || N < 1000){
        printf("senha invalida!\n");
        }

    }while(N > 9999 || N < 1000);

    if(N <= 9999 || N >= 1000){
    printf("senha cadastrada: %d\n", N);
    }

    //printf("Digite a senha cadastrada anteriormente:\n")
    scanf("%d", &X);

    while(X != N){
        printf("senha invalida!\n");
        scanf("%d", &X);
    }

    if(X == N){
        printf("senha valida!\n");
    }

    return 0;
}
