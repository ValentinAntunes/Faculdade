#include <stdio.h>

int main(){

    int A, B;

    scanf("%d", &A);
    scanf("%d", &B);

    if(A > B){
        printf("%d eh maior que %d\n", A, B);
        if(A % B == 0){
            printf("%d eh multiplo de %d\n", A, B);
        }else{
            printf("%d nao eh multiplo de %d\n", A, B);
        }
    }else if(B > A){
        printf("%d eh maior que %d\n", B, A);
        if(B % A == 0){
            printf("%d eh multiplo de %d\n", B, A);
        }else{
            printf("%d nao eh multiplo de %d\n", B, A);
        }
    }else{
        printf("Os valores lidos sao iguais\n");
    }

    return 0;
}
