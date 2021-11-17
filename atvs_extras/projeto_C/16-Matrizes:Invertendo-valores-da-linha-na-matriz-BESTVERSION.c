/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2020 by Gardenia Georgia Barbosa De Siqueira              *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Gardenia Georgia Barbosa De Siqueira <rabbit.robotica@gmail.com>  *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 99785-0393                                                  *
 * ************************************************************************ */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


#define MAX 100

void inputSizeMatriz(void);

int main(void)
{
    int i,j,w;
    int NLIN,NCOL;
    float matriz[NLIN][NCOL],aux1;
    float matrizinv[NLIN][NCOL];

    void inputSizeMatriz(void);

    for(i = 0; i < NLIN; i++)
        for(j = 0; j < NCOL; j++)
        {
            printf("\nAgora, digite um numero para matriz[%d]{%d]:",i,j);
            scanf("%f", &aux1);
            matriz[i][j] = aux1;
            getchar();
        }
    printf("A matriz digitada eh:\n");

    for(i = 0; i < NLIN; i++)
    {
        for(j = 0; j < NCOL; j++)
        {
            printf("[%d][%d]= %.2f  ",i,j,matriz[i][j]);
        }
        printf("\n");
    }
 
    //invertendo:

    printf("A matriz com linha inversa  eh:\n");
    for(i = (NLIN-1), w = 0;w < NLIN ; i--, w++)
    {       
        for(j = 0; j < NCOL; j++)
        {
            matrizinv[w][j] = matriz[i][j];
            printf("[%d][%d] = %.2f ",w,j,matrizinv[w][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}


void inputSizeMatriz(void)
{
    int i,j,w,tamL,tamC,aux = 1;
    char inputLinha[MAX]= "",inputColuna[MAX] = "";
    int NLIN,NCOL;
     
    //inserindo numero de colunas valido na matriz:
    while(aux) 
    {
        aux = 0;
        printf("Insira o tamanho da matriz linha coluna:\n");
        scanf("%s %s",inputLinha,inputColuna);
        getchar();

        tamL = strlen(inputLinha);
        tamC = strlen(inputColuna);

        for(i = 0; i < tamL; i++)
        {
            if((!isdigit(inputLinha[i])))
            {
                printf(">>>>Numero invalido, tente novamente.<<<<<\n");
                aux = 1;
                break;
            }
        }
        for(j = 0; j < tamC; j++)
        {
            if((!isdigit(inputColuna[j])))
            {
                printf(">>>Numero invalido, tente novamente.<<<\n");
                aux = 1;
                break;
            }
        }
        printf("voce inseriu matriz[%s][%s]\n",inputLinha,inputColuna);
    }

    NLIN = atoi(inputLinha);
    NCOL = atoi(inputColuna);
    

}
