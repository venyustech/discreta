/* ************************************************************************ *
 *    The prime factors of 13195,2018  VERSION                              *
 *                                                                          * 
 *    What is the largest prime factor of the number 600851475143?          *
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
#include<stdlib.h>

#define numero 600851475143

int main(void)
{
    long int N = numero;
    int i = 3;
    int Nprimo = 0;

    while(1)
    {
        while(!(N % i))
        {
            N /= i;
            Nprimo = i;
        }
        if(N == 1)
            break;
        i += 2;
    }
    printf("O maior numero primo de %ld eh %d\n",numero,Nprimo);

    return EXIT_SUCCESS;
}
