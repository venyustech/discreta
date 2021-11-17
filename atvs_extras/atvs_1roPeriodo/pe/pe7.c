/* ************************************************************************ *
 *    10001st prime, VERSION                                                *
 *    By listing the firs six prime numbers: 2,3,5,7,11, and 13, we can see *
 *    that the 6th prime is 13.                                             *
 *    What is the 10001st prime number?                                     *
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

#define MAX 500000
#define AlvoPrincipal 10001

int main(void)
{
    unsigned int primo[MAX];
    int ultimoEncontrado= 1;
    int primoEncontrado = 1;
    int j,i;

    for(i = 0; i < MAX; i++)
        primo[i] = i;
    
    while(primoEncontrado <= AlvoPrincipal)
    {
        for(i = 1; i <= MAX; i++)
        {
            if( primo[ultimoEncontrado+i] != 0)
            {   
                ultimoEncontrado = ultimoEncontrado + i;
                break;
            }
        }
        
        /* Eliminar todos os multiplos desse primo: */
    
        for(j = 2; j < MAX; j++)
        {
            if(ultimoEncontrado*j > MAX)
                break;
            primo[ultimoEncontrado*j] = 0;
        }

        primoEncontrado++;
    }
    printf("Primo #%d eh %d\n", AlvoPrincipal,ultimoEncontrado);

    return EXIT_SUCCESS;
}
