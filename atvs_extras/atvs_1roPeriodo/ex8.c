/* ************************************************************************ *
 *    ex8.c, VERSION 2019                                                   *
 *    dados tres segmentos de reta, conferir se formam um triangulo         *
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
#include <math.h>

int main (void)
{
    float a, b, c;
    
    printf("Bem-vindo ao programa que te dirah se existe o triangulo qualquer que voce queira \n ");

    printf("\ndigite um valor para o seguimento de reta(a): ");
    scanf("%f", &a);
    printf("\ndigite um valor para o seguimento de reta(b): ");
    scanf("%f", &b);
    printf("\ndigite um valor para o seguimento de reta(c): ");
    scanf("%f", &c);

    if(a<(c+b) && (b<(a+c)) && (c<(a+b)))
		printf("O triangulo existe ");
	else	
		printf("o triangulo nao existe :c ");
    
    return EXIT_SUCCESS;
    
}
