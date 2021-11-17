#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <new> //para alocar

using namespace std;
int main (void)
{
    int i, j, linhas, colunas;
    int **matriz;

    printf(" digite a quantidade de linhas");
    scanf("%d", &linhas);
    
    printf(" digite a quantidade de colunas");
    scanf("%d", &colunas);

    //alocando linhas :
    matriz = (int **) new int (linhas);
          //casting^^ //funcao malloc >>
    
    //alocacolunas:
    for( i = 0; i < linhas; i++)
        matriz[i] = (int *) new int (colunas);
    
    //preenchendo e imprimindo:
    for( i = 0; i < linhas; i++)
    {
        for( j = 0; j < colunas; j++)
        {
            matriz[i][j] = i+j;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    
    }

    //libera memoria:
    free(matriz);

    return EXIT_SUCCESS;

}
