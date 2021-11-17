/****************************************************************************
 *    ex13.c   VERSION 2019.2                                               *
 *    indica numeros primos                                                 *
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

int main(void)
{
    int n, i, resultado = 0; 
    
    printf("digite um numero e diremos se eh primo ou nao:");
    scanf("%d",&n);
    
    for(i = 2; i<= n/2; i++)
    {
    	if(n % i == 0)
    	{
    		resultado++;
    		break;
		}
	}
	
	if(resultado == 0)
		printf("%d eh um primo \n ", n);
	else
		printf("%d NAO eh um primo...Que triste :c  \n ", n);

    return EXIT_SUCCESS;
}


