/****************************************************************************
 *   ex22.c      VERSION 2019.2                                             *
 *                                                                          *
 *    random walk                                                           *
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
#include <unistd.h>
#include <time.h>  

#define SBUFF 256 

int main (void)
{	
    srand(time(NULL)+getpid());

    int i=0, x, y, passos=0, posicao; /* coords x e y */
    float media=0.0;
    while(i<=10000)
    {
        x=0; y=0; 
        while((x<=10&&x>=-10)&&(y<=10&&y>=-10))
        {  
            posicao = 1+rand()%4;
            passos++;
            switch(posicao)
            {
                case 1:
                    x++;
                break;

                case 2: 
                    x--;
                break;

                case 3:
                    y++;
                break;

                case 4:
                    y--;
                break;
            } 
        }
        i++;
     }
    media =passos/10000;
    printf("media %f",media);
    return EXIT_SUCCESS;    
}
