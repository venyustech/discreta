/* ************************************************************************ *
 *    Imprime em ordem crescente, 2018  VERSION                             *
 *    O programa imprimira em ordem crescente de duas formas: a primeira    *
 *    sera antes de uma chamada recursiva e outra depois de uma chamada     *
 *    recursiva                                                             *
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

#define MAX 10 /* numero maximo a ser imprimido */
#define MIN 1  /* numero minimo a ser imprimido */

void imprime_ida(int min, int max); /* imprime antes da chamada recursiva */
void imprime_volta(int n); /* imprime depois da chamada recursiva */

int main()
{
    imprime_ida(MIN,MAX);
    imprime_volta(MAX);

    return EXIT_SUCCESS;
}


void imprime_ida(int min, int max)
{
    if(min>max)
        return;
    printf("ida -> %d\n",min);
    imprime_ida(min+1,MAX);
}

void imprime_volta(int n)
{
    if(n==0)
        return;
    imprime_volta(n-1);
    printf("volta -> %d\n",n);
}
