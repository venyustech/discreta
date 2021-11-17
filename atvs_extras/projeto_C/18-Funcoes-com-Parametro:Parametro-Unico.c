/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2020 by Gardenia Georgia Barbosa De Siqueira              *
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
 *  To contact the author, please write to:                                 *
 *  Name: Gardenia Georgia Barbosa De Siqueira <rabbit.robotica@gmail.com>  *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 99785-0393                                                  *
 * ************************************************************************ *
*/

#include<stdio.h>
#include<stdlib.h>

void mostraSucessor(int n);

int retornaAntecessor(int n);

int main(void)
{
    int a;

    printf("Digite valor de a:\n");
    scanf("%d", &a);

    mostraSucessor(a);

    printf("\nO antecessor de %d eh : %d\n", a,retornaAntecessor(a));

    return EXIT_SUCCESS;
}

void mostraSucessor(int n)
{
    printf("\nO sucessor de %d eh : %d\n", n, n + 1);

}

int retornaAntecessor(int n)
{
    return n - 1;
}
