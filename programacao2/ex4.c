/* *********************************************************************** *
 *    ex4.c, VERSION 2020                                                   *
 *    Função que gera numeros aleatorios                                    *
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
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void gera_Aleatorios(void);

int main(void)
{
    gera_Aleatorios();
    
    return EXIT_SUCCESS;
}

void gera_Aleatorios(void)
{
    srand(time(NULL)+getpid());

    printf("Numero Aleatorio: %d\n", rand()%9999);
}
    
