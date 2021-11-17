/* ************************************************************************ *
 *    Greatest product, VERSION 2009.2                                      *
 *    A Pythagorean triplet is a set of three natural numbers, a < b < c,   *
 *	  for which,                                                            *
 *                                                                          *
 *					a2 + b2 = c2                                            *
 *    For example, 32 + 42 = 9 + 16 = 25 = 52.                              *
 *                                                                          *
 *	  There exists one Pythagorean triplet for which a + b + c = 1000.      *
 *    Find the product abc.                                                 *
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

int main(void)
{
	int a,b,c,aquadrado,bquadrado,cquadrado,soma,produto;
	a=b=c=aquadrado=bquadrado=cquadrado=produto=0;
	soma=1000;
	
	/* maior valor possivel a+b+c =1+499+500: */
	for(a = 1;a <(soma/3);a++)
	{
		for(b = 2; b < (soma/2); b++)
		{
			c = soma - a - b;
			aquadrado = a*a;
			bquadrado = b*b;
			cquadrado = c*c;
			if((aquadrado+bquadrado)==cquadrado)
			{
				produto = a*b*c;
				printf("a: %d\nb: %d\nc: %d\n\t Produto a x b c: %d\n",a,b,c,produto);
			}
		}
	}
	return EXIT_SUCCESS;
}
