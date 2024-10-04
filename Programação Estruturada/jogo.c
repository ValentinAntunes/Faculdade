#include <stdio.h>
#include <locale.h>

/*#define NUMERO_DE_TENTATIVAS 3 */

int main() {
    
    setlocale(LC_ALL, "Portuguese_Brazil");

    int numeroSecreto = 24;
    int chute;
    int ganhou = 0;
    int tentativas = 1;
    
    printf("**********\n");
    printf("* Bem vindo ao jogo de chute *\n");
    printf("**********\n");
    printf("\n");


    while (ganhou == 0) {

        printf("* Tentativa %d! *", tentativas);
        printf("\n\n");

        printf("Olá, escolha um chute 1 á 50, e veja se acerte!\n");
        printf("Digite seu chute:");
        scanf("%d", &chute);
        printf("\n\n");

        if(chute < 0) {
            printf("Você não pode chutar números negativos, tente novamente!\n");
            continue;
        }

        printf("Esse foi seu chute %d", chute);
        printf("\n\n");

        int acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;

        if(acertou) {
            printf("Parabéns, você acertou o número secreto!\n");
            //break;
            ganhou = 1;
            
        } 
        
       else if(maior) {
            printf("Muito alto seu chute, diminua um pouco!\n");
            } 
       else {
            printf("O número que você chutou e muito baixo, chute mais alto!\n");
        }
        tentativas++;
    }

    
    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas", tentativas-1);
}