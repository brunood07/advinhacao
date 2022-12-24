#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	printf("    /\\                                                        /\\      \n");
	printf("   |  |                                                      |  |      \n");
	printf("  /----\\                                                    /----\\   \n");
	printf(" [______]                                                  [______]    \n");
	printf("  |    |         _____                        _____         |    |     \n");
	printf("  |[]  |        [     ]                      [     ]        |  []|     \n");
	printf("  |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |     \n");
	printf("  |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |     \n");
	printf("  |             |     |/'    ____..____    '\\|     |             |    \n");
	printf("   \\  []        |     |    /'    ||    '\\    |     |        []  /    \n");
	printf("    |      []   |     |   |o     ||     o|   |     |  []       |       \n");
	printf("    |           |  _  |   |     _||_     |   |  _  |           |       \n");
	printf("    |   []      | (_) |   |    (_||_)    |   | (_) |       []  |       \n");
	printf("    |           |     |   |     (||)     |   |     |           |       \n");
	printf("    |           |     |   |      ||      |   |     |           |       \n"); 
	printf("  /''           |     |   |o     ||     o|   |     |           ''\\    \n"); 
	printf(" [_____________[_______]--'------''------'--[_______]_____________]    \n");

	printf("*******************************************************************\n");
	printf("************** Bem-vindo ao nosso jogo de advinhacao **************\n");
	printf("*******************************************************************\n");

	int segundos = time(0);
	srand(segundos);

	int numerogrande = rand();
	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;

	int acertou = 0;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Facil, (2) Medio, (3) Dificil\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numerodetentativas;
	switch(nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		case 2: 
			numerodetentativas = 10;
			break;
		default: 
			numerodetentativas = 5;
			break;
	}

	for(int i = 1; i <= numerodetentativas; i++) {
		printf("Tentative %d\n", tentativas);
		printf("Qual e o seu chute? ");

		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		if (chute < 0) {
			printf("Voce nao pode chutar numeros negativos\n");

			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;

		if(acertou) {
			break;
		} else if (maior) {
			printf("Seu chute foi maior que o numero secreto\n");
		} else {
			printf("Seu chute foi menor que o numero secreto\n");
		}

		tentativas++;

		double pontosperdidos = (chute - numerosecreto) / (double)2;
		pontos = pontos - abs(pontosperdidos);
	}
	
	if (acertou) {
		printf("		                           .''.          \n");
		printf("       .''.      .        *''*    :_\\/_:     .          \n");
		printf("      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\:  .'.:.'.     \n");
		printf("  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=-     \n");
		printf(" :_\\/_:'.:::.    ' *''*    * '.\'/.' _\\(/_'.':'.'      \n");
		printf(" : /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  *     \n");
		printf("  '..'  ':::'     * /\\ *     .'/.\'.   '                \n");
		printf("      *            *..*         :                        \n");
		printf("       *                                                 \n");
		printf("        *                                                \n");
		printf("Parabens! Voce acertou!\n");	
		printf("Voce acertou em %d tentativas\n", tentativas);
		printf("Total de pontos: %.2f\n", pontos);
	} else {
		printf("(-_-)\n");
		printf("Voce perdeu! Tente de novo\n");
	}

	printf("Fim de jogo!\n");

	return 0;
}
