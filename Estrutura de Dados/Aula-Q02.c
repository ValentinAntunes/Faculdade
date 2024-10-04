#include <stdio.h>
#include <stdlib.h>

#define ERRO -1     // Define uma constante chamada ERRO 

int Area (int Lado);

int main() {
    system("cls");      // Executa o comando 'cls' do DOS
    int X = 6.3;
    int Resposta = Area(X);
    if(Resposta != ERRO) 
        printf("A area do quadrado de lado %d e igual a %d. \n", X, Resposta);
    else
        printf("Erro na execucao do programa.\n");
}

int Area (int Lado) {
    if (Lado == 2 || Lado == 3 || Lado == 4 || Lado == 5) return (Lado * Lado);
    else return(ERRO);
}
