#include <stdio.h>

int main(){

    char NIVEL;
    float S, TOTAL;

    scanf("%c", &NIVEL);
    scanf("%f", &S);


    if(NIVEL == 'a'){
        TOTAL = S + (0.05 * S);
    }else if(NIVEL == 'b'){
        TOTAL = S + (0.07 * S);
    }else{
        TOTAL = S + (0.08 * S);
    }

    printf("R$ %0.2f\n", TOTAL);

    return 0;
}
