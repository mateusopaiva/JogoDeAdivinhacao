#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinha��o!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

	int segundos = time(0);
	srand(segundos);
	int numerogrande = rand();

	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;
	int numerodetentativas;
	
	int nivel ;
	printf("Qual o n�vel  de dificuldade?\n");
	printf("(1) F�cil  (2) M�dio  (3) Dif�cil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel );
	while(nivel > 3 || nivel < 0) {
		printf("Escolha o n�vel novamente: ");
		scanf("%d", &nivel);
	}
	switch(nivel){
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default:
			numerodetentativas = 6;
			break;
	}
	
	for(int i = 1; i <= numerodetentativas; i++) {
		printf("\nTentativa %d de %d\n", i, numerodetentativas);
		printf("Qual � o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);
	
		if(chute < 0) {
			printf("Voc� n�o pode chutar n�meros negativos!\n");
			i--;
			continue;
		}
	
		acertou = (chute == numerosecreto);
		int maior = (chute > numerosecreto);
	
		if(acertou) {
			break;
		} 
		else if(maior) {
			printf("Seu chute foi maior que o n�meros secreto!\n");
		} 
		else {
			printf("Seu chute foi menor que o n�meros secreto!\n");
		}
		tentativas++;
		
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}
	
	printf("\nFim de Jogo!\n");
	if(acertou){
		printf("\n\n");
	    printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
		printf("Voc� ganhou!\n");
		printf("Voc� acertou em %d tentativas!\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);
	}
	else {
	printf("O n�mero secreto era: %d\n", numerosecreto);	
	printf("\n\n");
    printf("       \\|/ ____ \\|/    \n");
    printf("        @~/ ,. \\~@      \n");
    printf("       /_( \\__/ )_\\    \n");
    printf("          \\__U_/        \n");
	printf("\n\n");
		printf("Voc� perdeu! Tente de novo!\n");
	}
}
