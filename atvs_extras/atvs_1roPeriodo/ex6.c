/* ************************************************************************ *
 *    QUADRATIC FUNTION ROOTS,2018 VERSION                                  *
 *    This program will show quadratics funtion roots                       *
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
#include <math.h>

int main(void)
{  
    /*Boas-vindas*/
    printf("bem-vindo ao programa que calcula as raizes de uma equacao do segundo grau:\n");
    /*declarando as variáveis:*/
    float a,b,c,delta,raizdedelta,r1,r2;

    printf("Digite o valor de a:\n");
    scanf("%f",&a);
    if(a==0)
    { 
        printf("Desculpe, a=0 nao eh equação do segundo grau.\n"); 
    }
    else
    {   
        printf("Digite o valor de  b:\n");
        scanf("%f",&b);
        printf("Digite o valor de c:\n");
        scanf("%f",&c);
        /*formula:*/
        delta=(b*b)-(4*a*c);
        raizdedelta = sqrt(delta);
        r1=((-b)+(raizdedelta))/(2*a);
        r2=((-b)-(raizdedelta))/(2*a);
        /*resultado:*/
        printf("As raizes sao: %0.2f, %0.2f",r1,r2);
    }
    return EXIT_SUCCESS;
}
