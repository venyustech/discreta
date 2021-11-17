/***************************************************************************
 *   libgeo.c                                 Version 20201014.163238      *
 *                                                                         *
 *   library                                                               *
 *   Copyright (C) 2020         by Gardenia Georgia Barbosa De Siqueira    *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Gardenia Georgia Barbosa De Siqueira                                  *
 *   Email: rabbit.robotica@gmail.com                                      *
 *   Webpage: http://beco.poli.br/rabbit.robotica@gmail.com                *
 *   Phone: (81) 99785-0393                                                *
 ***************************************************************************/
/*
 * Instrucoes para compilar:
 * $gcc libgeo.c -o libgeo.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */
#include "libgeo.h"

int main(void)
{
    
    return EXIT_SUCCESS;
}

int quadrado(int x)
{
    return x*x;
}
int cubo(int x)
{
    return x*x*x;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

