#include <stdio.h>
#include <locale.h>

void exibirMatriz(int matriz[][10], int linhas, int colunas){

    for(int lin = 0; lin < linhas; lin++) {
			for(int col = 0; col < colunas; col++) {
				printf("%d ", matriz[lin][col]);
			}
			printf("\n");
		}

		printf("\n");

}

int main()
{
	//Variáveis.

	int lin, col;
	int x, y, a, b, i;

    //Permite a acentuação dentro do printf.
    
	setlocale(LC_ALL, "Portuguese");
	
	//Pede o número de linhas e colunas da matriz A
	
	printf("Digite o número de linhas da matriz A(entre 1 e 10): ");
	scanf("%d", &x);
	
	printf("Digite o número de colunas da matriz A(entre 1 e 10): ");
	scanf("%d", &y);

	//pede o número de linhas e colunas da matriz B.

	printf("Digite o número de linhas da matriz B(entre 1 e 10): ");
	scanf("%d", &a);
	
	printf("Digite o número de colunas da matriz B(entre 1 e 10): ");
	scanf("%d", &b);

	//Condicional para garantir que os valores de x,y,a,b estejam entre 1 e 10.

	if(x >= 1 && x < 11 && a >= 1 && a < 11 && b >= 1 && b < 11) {

		//Matriz A de acordo com as entradas do usuário.

		int matrizA[10][10];

		//for que pede os valores de cada célula da matriz A.

		for(lin = 0; lin < x; lin++) {
			for(col = 0; col < y; col++) {
				printf("Digite o elemento da posição [%d][%d]", lin, col);
				scanf("%d", &matrizA[lin][col]);
			}
		}

		printf("\n");

		//Matriz B de acordo com as entradas do usuário.

		int matrizB[10][10];

		//for que pede os valores de cada célula da matriz B.

		for(lin = 0; lin < a; lin++) {
			for(col = 0; col < b; col++) {
				printf("Digite o elemento da posição [%d][%d]", lin, col);
				scanf("%d", &matrizB[lin][col]);
			}
		}

		printf("\n");

		//Exibe a matriz A.

		printf("Matriz A:\n\n");

        exibirMatriz(matrizA, x, y);

		//Exibe a matriz B.

		printf("Matriz B:\n\n");

        exibirMatriz(matrizB, a, b);

		//Condicional para garantir a compatibilidade entre as matrizes.

		if(y == a) {
		    
            //Matriz C inicializada com 0.
            
			int matrizC[10][10] = {0};

			//for para realizar a multiplicação da matriz A pela matriz B.

			for(lin = 0; lin < x; lin++) {
				for(col = 0; col < b; col++) {
					for(i = 0; i < a; i++) {
						matrizC[lin][col] += matrizA[lin][i] * matrizB[i][col];
					}
				}
			}

			printf("\n");

			//Exibe a matriz C resultante da multiplicação de A e B.

			printf("Matriz resultante AxB:\n\n");

			exibirMatriz(matrizC, x, b);

			//Caso o número de linhas de A seja diferente do número de colunas de B.

		} else {
			printf("Matrizes incompatíveis!");
		}
		
		//Caso o usuário insira valores inválidos para x,y,a,b.
		
	} else {
	    printf("Digite valores de x,y,a,b entre 1 e 10!");
	}
	return 0;
}