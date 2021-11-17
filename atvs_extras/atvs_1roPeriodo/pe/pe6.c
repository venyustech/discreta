/* ************************************************************************ *
 *    Sum Square Difference, 2018 VERSION                                   *
 *    Find the difference between the sum of  the first one hundre natural  *
 *    numbers and the square of the sum.                                    *
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
    int quadradoDaSoma = 0, somaDoQuadrado = 0, diferenca;
    int i;

    for(i = 1; i <= 100; i++)
    { 
        quadradoDaSoma += i;
        somaDoQuadrado += i*i;
    }
    quadradoDaSoma *= quadradoDaSoma;
    diferenca = quadradoDaSoma - somaDoQuadrado;

    printf("A diferanca eh: %d\n", diferenca);

    return EXIT_SUCCESS;
}


