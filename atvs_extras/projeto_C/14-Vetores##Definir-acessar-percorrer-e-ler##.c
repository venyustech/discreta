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
 
#define TAM 11
#define Ntabuada 5
int main(void)
{
    int vetor[TAM],i;

    printf("\nTabuada de %d", Ntabuada);
    
    /*Passando os valores do vetor:(tabuada)*/
    for(i = 0; i < TAM; i++)
    {
        (vetor[i] = (i * Ntabuada));
    /*Imprimindo vetor em um laco de repeticao:*/
        printf("\n5 x %d = %d", i, vetor[i]);
    }
    //Lendo valores do vetor pelo usuario
    for(i = 0; i < TAM; i++)
    {
        printf("\n\nlENDO valores para um vetor. Digite valor %d:", i);
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < TAM; i++)
    {
        printf("\nvalor digitado para vetor[%d] = %d\n", i, vetor[i]);
    }

    return EXIT_SUCCESS;
}

//exercicio: crie um algoritmo que leia um tamanho de um vetor e preencha cada posicao com um valor e depois calcula a media. 
