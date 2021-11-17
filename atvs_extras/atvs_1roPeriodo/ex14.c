/* ************************************************************************ *
 *    ex14.c, VERSION 2019.2                                                *
 *    jogo do PIM                                                           *
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
#include <string.h>

#define SBUFF 80

int pim(int n);

int main (void)
{
    
    int v;
    int p=0;
    char si[SBUFF];

    printf("jogo do pim, comece a contar. \n");
    printf("diga PIM nos multipols de 3 ou 5\n");
    
    while(++p)
    {
    
        fgets(si, SBUFF, stdin);
        v=atoi(si);

        if(pim(p) != (!v != p))  
            break;

    }
    printf("voce perdeu\n");
    
    return EXIT_SUCCESS;
}

int pim(int n)
{
    if(!(n%3) || !(n%5))
        return 1;

    return 0;
}
