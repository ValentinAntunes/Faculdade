#include <stdio.h>

int main(){

    int X;

    printf("Digite um ano igual ou entre 1800 e 2022:\n");
    scanf("%d", &X);

    if(X > 2022){
        printf("Nao houve Jogos Olimpicos de Verao ou Copa do Mundo no ano de %d.\n", X);
    }else if(X % 2 != 0){
        printf("Nao houve Jogos Olimpicos de Verao ou Copa do Mundo no ano de %d.\n", X);
    }else if(X < 1896){
        printf("Nao houve Jogos Olimpicos de Verao ou Copa do Mundo no ano de %d.\n", X);
    }else if(X != 1916 && X != 1940 && X != 1944 && ((X - 1896) %4 == 0)){
        printf("Os Jogos Olimpicos de Verao ocorreram no ano de %d.\n", X);
    }else if(X >= 1930 && X != 1942 && X != 1946 && ((X - 1930) % 4 == 0)){
        printf("A Copa do Mundo de Futebol ocorreu no ano de %d.\n", X);
    }else if(X < 1930 && ((X - 1930) % 4 == 0)){
        printf("Nao houve Jogos Olimpicos de Verao ou Copa do Mundo no ano de %d.\n", X);
    }else if(X == 1916 || X == 1940 || X == 1942 || X == 1944 || X == 1946){
        printf("Nao houve Jogos Olimpicos de Verao ou Copa do Mundo no ano de %d.\n", X);
    }

    /** Nos anos de 1916, 1940, 1942, 1944 e 1946 não houveram Olimpiadas nem Copa do Mundo devido às Guerras.**/

    return 0;
}
