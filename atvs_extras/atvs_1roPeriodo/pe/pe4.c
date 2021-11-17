/* ************************************************************************ *
 *    Largest Palindrome Product, 2018 VERSION                              *
 *                                                                          * 
 *    A palindromic number reads the same both ways. The largest Palindrome *
 *    made from the product of two 2-digit numbers is 9009 = 91 X 99.       *
 *    Finf the largest palindrome made from the the product of two 3-digit  *
 *    numbers.                                                              *
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

#define MIN 100 /*minimo que o numero vai poder estar de acordo com a quantidade de digitos */
#define MAX 999/* maximo de acordo com a quantidade de digitos */

int main (void)
{
    int i,j,k,m; /* nosso numero começara num formato ijkkji*/
    int N; /* Sera o numero que procuramos*/
    int div; /*Sera usado para checar se o N a o que queremos*/
    /*Uso de laco aninhado para a construção do numero N:*/

    for(i = 9; i > 0; i--) /* i nao pode ser 0 senao nao tera um numero ijkkji*/
    {
        for(j = 9; j >= 0; j--)
        {
            for(k = 9; k >= 0; k--)
            {
                N = k*1100 +j*10010 + i*100001;

                for (m = MAX; m >= MIN; m--)
                {
                    if(N % m) /* Se nao eh divisivel roda o laco de novo */
                        continue;
                    div = N/m;
                    if (div >= 100 && div <= 999) /* Achamos o que queriamos */
                    {
                        printf("O maior numero eh: %d\n", N);
                        return 0;
                    }
                }
            }
        }
    }
    
    return EXIT_SUCCESS;
}
