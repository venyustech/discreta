/* ************************************************************************ *
 *    ex10.c, VERSION 2019.2                                                *
 *    calculo fatorial                                                      *
 *                                                                          *
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

unsigned fatrecursiva( unsigned short n);
unsigned fatinterativa(unsigned short n);

int main (void)
{
    unsigned short n;
    unsigned resinterativa, resrecursiva;
    
    printf("digite um numero para o fatorial: ");
    scanf("%hu", &n);
    
    resinterativa = fatinterativa(n);
    resrecursiva = fatrecursiva(n);

    printf("o fatorial de %hu e igual a: \n %u \n %u \n", n, resinterativa, resrecursiva);

    return EXIT_SUCCESS;
}

unsigned fatinterativa(unsigned short n)
{
    unsigned f = n;
    if(!n)
        return 1;
    while(--n)
        f *=n;
    return f;
} 

unsigned fatrecursiva( unsigned short n)
{
    if(!n)
        return 1;
    return n*fatrecursiva(n-1);
}
