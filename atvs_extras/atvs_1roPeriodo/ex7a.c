/* **************************************************************************
 *    ex7a.c, VERSION 2019.2                                                *
 *    SORTEIO DA VACA                                                       *
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

#define PR "a vaquinha\n"

int main(void)
{
	int a, b, c;
	a = rand()% 6+1;
	b = rand()% 100;
	c = rand()% 51-50;

	if(a <= 6 && a > 4)
  	{ 
	  	if(b > 40)
      	{
       		if(b < c)
           		printf("Voce ganhou um %s", PR); 
       		else
           		printf("Voce nao ganhou um %s", PR);
      	}
    	else 
    	{  
			if(!c)
           		printf("Voce, ganhou um %s", PR);
        	else
           		printf("Voce, nao ganhou um %s",PR);
    	}   
  	}

	else
	{ 
    	if(a == 6)
        	printf("Voce ganhou um %s", PR);
    	else    
        	printf("voce nao ganhou %s", PR);
 	}	  
	a = rand()% 6+1;
	b = rand()% 100;
	c = rand()% 51-50;

	return EXIT_SUCCESS;

}
