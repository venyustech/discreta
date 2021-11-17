/****************************************************************************
 *    ex19.c       VERSION 2019.2                                           *
 *                                                                          *
 *    aprendendo matematica por repeticao                                   *
 *    Copyright (C) 2019 by Gardenia Georgia Barbosa de Siqueira            *
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
 *    To contact the author, please write to:                               *
 *    Gardenia Georgia Barbosa de Siqueira <gardenia.georgia.b.s@gmail.com> *
 *    Webpage: http://www.upe.com                                           *
 *    Phone: +55 (81) 99785-0393                                            *
 * ************************************************************************ *
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>  
#include <math.h> 
#include <string.h> 

void soma(void);

#define SBUFF 80

int main(void)
{
    srand(time(NULL));

    printf("\nDesafio de operacao de adicao\n");
    soma();
    return EXIT_SUCCESS;
}
void soma(void)
{
    int resultadouser, resultadoparcela, resulterro=0, parcela[2], porcentagem=1, level=1; 
    char in_usuario[SBUFF]; 
    do{
        do{ 
             parcela[0] = rand()%5; 
             parcela[1] = rand()% 6;
             resultadoparcela = parcela[0]+ parcela[1];
            do{
                printf("\n %i%% -------->  %i + %i = ", porcentagem*10, parcela[0], parcela[1]);
                fgets (in_usuario, SBUFF, stdin);
                resultadouser = abs(atoi(in_usuario));
                if(resultadoparcela != resultadouser)
                    resulterro += 1;
			}while(resultadoparcela != resultadouser);
           porcentagem++;
        }while(porcentagem<=10); /* ou seja: 100 por cento*/
    porcentagem=1;
    level++;
    printf("\n%i%% !",10-resulterro>0 ?(10-resulterro)*10:0);
    printf("\nVoce passou! %i \n", level);
    resulterro = 0;
    }while(level<=5);
    return;
}
