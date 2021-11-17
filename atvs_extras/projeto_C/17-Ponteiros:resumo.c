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
 * ************************************************************************ *
 */

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    // Variaveis armazenam valores:
    int a = 10;

    // Ponteiros armazenam POSICOES DA MEMORIA
    int *ponte;

    //  Ponteiro recebendo a posicao na memoria da variavel b:
    ponte = &a;

    // Imprimindo o valor de uma variavel 
    printf("Valor de a: %d \n", a);
    
    // * pode ser lido como "conteudo apontado por"
    *ponte = 40;

    // Imprimindo o valor de uma variavel 
    printf("Valor de a mudado pelo ponteiro: %d \n", a);

    return EXIT_SUCCESS;
}



