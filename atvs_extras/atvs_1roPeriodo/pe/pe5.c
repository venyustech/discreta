/* ************************************************************************ *
 *    Smallest Multiple, 2018 VERSION                                       *
 *                                                                          *
 *    2510 is the smallest number that can be divided by each of the num-   *
 *    bers from 1 to 10 without any remainder.                              *
 *    What is the smallest positive number that is evenly divisible by all  *
 *    of numbers 1 to 20                                                    *
 *                                                                          *
 *    Copyright (C) 2018 by Gardenia Georgia Barbosa de Siqueira            *
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
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int termino = 0;
    unsigned int resultado = 0;
    
    /* temos que olhar todos os multiplos de 2520 que sao diviiveis pelos numeros de 11 a 20: */

    while (!(termino))
    {
        termino = 1;
        resultado += 2520;

        for(i = 11; i <= 20; i++)
        {
            if(resultado % i)
            { termino = 0;
                break;
            }
        }
    }
    
    printf("O menor numero divisivel por todos numeros de 1 ate 20, eh: %d\n",resultado);

    return EXIT_SUCCESS;
}
