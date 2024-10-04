#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ERRO -1     // Define uma constante chamada ERRO 

char minusculo ();

int main() {
    system("cls");      // Executa o comando 'cls' do DOS
    char letra = minusculo();
    printf("\n%c", letra);
    return(1);
}

char minusculo() {
    char ch = getche();  // Lê, exclisivamente, apenas 1 caractere
    if((ch >= 'A') && (ch <= 'Z')) return(ch + 32);
    else return(ch);
}

