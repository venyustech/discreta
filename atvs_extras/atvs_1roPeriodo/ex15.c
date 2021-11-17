/****************************************************************************
 *   ex15.c        VERSION 2019.2                                           *
 *                                                                          *
 *    Calculadora basica                                                    *
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
 */

#include <stdio.h> 
#include <stdlib.h> 

 int main(void)
{
    float num1, num2;
    char oper;

    printf("\t\tCalculadora\n\n");

    printf("Operacoes disponiveis\n");
    printf("'+' : soma\n");
    printf("'-' : subtracao\n");
    printf("'*' : multiplicao\n");
    printf("'/' : divisao\n");
    printf("'%%' : resto da divisao\n");
    printf("\nDigite a expressao na forma: numero1 operador numero2\n");
    printf("Exemplos: 1 + 1 ,  2.1 * 3.1\n");
    printf("Para sair digite: 0 0 0\n");
    scanf("%f", &num1);
    scanf(" %c",&oper);
    scanf("%f", &num2);
        
    switch( oper )
    {
        case '+':
            printf("%.2f\n\n", num1 + num2);
            break;
        case '-':
            printf("%.2f\n\n", num1 - num2);
            break;
        case '*':
            printf("%.2f\n\n", num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                printf("%.2f\n\n", num1 / num2);
            else
                printf("Nao existe divisao por 0\n\n");
            break;
        case '%':
            printf("%d\n\n", (int)num1 % (int)num2);
            break;
        default:
            if(num1 != 0 && oper != '0' && num2 != 0)
                printf(" Operador invalido\n\n ");
            else
                printf(" Fechando calculadora!\n ");
    }

	return EXIT_SUCCESS;
	
}
