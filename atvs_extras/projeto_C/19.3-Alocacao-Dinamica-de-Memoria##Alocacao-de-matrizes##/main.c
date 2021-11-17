#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, j, linhas, colunas;
    int **matriz;

    printf(" digite a quantidade de linhas");
    scanf("%d", &linhas);
    
    printf(" digite a quantidade de colunas");
    scanf("%d", &colunas);

    //alocando linhas :
    matriz = (int **) malloc(linhas * sizeof(int *));
          //casting^^ //funcao malloc >>
    
    //alocacolunas:
    for( i = 0; i < linhas; i++)
        matriz[i] = (int *) malloc(colunas * sizeof (int));
    
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
    for(i=0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);

    return EXIT_SUCCESS;

}
