# Caderno de Notas do VIM

## Dicas:

* Aceita sintaxe markdown (md)
* Para salvar e sair, :x
* Para ir para janela da esquerda: C-w h
* Para ir para janela da direita: C-w l
* Este arquivo se encontra na sua pasta de configuração do Vim
* Fique à vontade para apagar e escrever neste arquivo como quiser, inclusive apagar estas dicas se desejar.

## Notas:


https://gist.github.com/giucortes/2a50ac91bbe49b20339b0de80b0831fd
#include <stdio.h>
#include <conio.h>

main() {

//Definição de variaveis
int i, j, linhaA, colunaA, linhaB, colunaB, x;

//Entrada de dados
printf("\n Informe a quntidade de linhas da matriz A : ");
scanf("%d",&linhaA);
printf("\n Informe a quantidade de colunas da matriz A : ");
scanf("%d",&colunaA);
printf("\n Informe a quntidade de linhas da matriz B : ");
scanf("%d",&linhaB);
printf("\n Informe a quantidade de colunas da matriz B : ");
scanf("%d",&colunaB);

float matrizA[linhaA][colunaA], matrizB[linhaB][colunaB], matrizC[linhaA][colunaB], aux = 0;

if(colunaA == linhaB) {

	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaA; j++) {
			printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da Matriz A: ", i+1, 167, j+1, 167);
			scanf("%f", &matrizA[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < linhaB; i++) {        
		for(j = 0; j < colunaB; j++) {
			printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da 2%c Matriz B: ", i+1, 167, j+1, 167, 167);
			scanf("%f", &matrizB[i][j]);
		}
		printf("\n");
	}

	// Imprime as matrizes definidas
	printf("---------------------------- 1 - Matriz Gerada ---------------------------------\n\n");

	for(i = 0; i < linhaA; i++) {        
		for(j = 0; j < colunaA; j++) {
			printf("%6.f", matrizA[i][j]);
		}
		printf("\n\n");
	}

	printf("---------------------------- 2 - Matriz Gerada ---------------------------------\n\n");
	for(i = 0; i < linhaB; i++) {
		for(j = 0; j < colunaB; j++) {
			printf("%6.f", matrizB[i][j]); 
		}
		printf("\n\n");
	}

	printf("---------------------------- 3 - Matriz Gerada ---------------------------------\n\n");

	//Processamento e saida em tela  =  PRODUTO DAS MATRIZES
	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			
			matrizC[i][j] = 0;
			for(x = 0; x < linhaB; x++) {
				aux +=  matrizA[i][x] * matrizB[x][j];
			}

			matrizC[i][j] = aux;
			aux = 0;
		}
	}
	
	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			printf("%6.f", matrizC[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");
} else {
	printf("\n\n Nao ha com multiplicar as matrizes dadas ");
}

}//cabooooo

Darling in the Franxx
