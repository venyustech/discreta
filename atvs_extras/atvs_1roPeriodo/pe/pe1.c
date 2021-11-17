/* ************************************************************************ *
 *    Multiples of 3 and 5, 2018 VERSION                                    *
 *    If we list all the natural numbers below 10 that are multiples of 3   *
 *    or 55, qe get 3,5,6 and 9. The sum of these multiples is 23.          *
 *    Find the sum of all th emultiples of 3 or 5 below 1000                *
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

#define MIN 0
#define MAX 1000

int main(void)
{
    int i;
    int soma = 0;

    for(i=MIN;i<MAX;i++)
        if((0 == i % 3) || (0 == i % 5))
            soma+=i;
    printf("a soma de todos os multiplos de 3 ou 5 do numero%d,ate %d, eh: %d\n",MIN,MAX,soma);
    return EXIT_SUCCESS;
}


