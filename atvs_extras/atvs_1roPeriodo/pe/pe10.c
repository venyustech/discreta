/* ************************************************************************ *
 *    Summation primes, VERSION 2019.2                                      *
 *                                                                          * 
 *    Find the sum of all the primes below two million.                     *
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

#define LIMITE 2000000


int main (void)
{
	int i;
 	long long resultado = 2;
 	int ultimoprimo = 2; 
 	int primoachado = 1; /* para criterio de parada */
 	static int vetor[LIMITE] ={0}; /* estatico para nao sobrecarregar e retira o '0' do vetor */

 	for (i = 1; i < LIMITE; i+=2) /* Já retirando os multiplos de 2 */
   		vetor[i] =  i;

 	/* Peneira de erathones: acha o proximo primo e substitui por 0 os seus multiplos */

 	while (primoachado) /* roda ate nao ter mais primos (primosachados=0) */
 	{
  		int j;
  		primoachado = 0;

  		for (i = ultimoprimo+1; i < LIMITE; i++)
  		{
   			if (vetor[i] != 0) /* Se nao eh 0 entao eh primo (peneira de erastones) */ 
   			{
    			ultimoprimo = i; 
    			resultado += i;
    			primoachado = 1;
    			break;
   			}
  		}	
  		if (primoachado) /* Achado o primo, deleta os multiplos: 1= sim, 0=nao> bit-a-bit */
  		{
   			for ( j = 2; j < LIMITE; j++ )
   			{
    			if ( j*ultimoprimo > LIMITE )
     			break;
    			vetor[j*ultimoprimo] = 0;
   			}
  		}
 	}
 	printf("A soma de todos os primos abaixo de  %d eh:  %lld \n\n", LIMITE, resultado);
 	
	return EXIT_SUCCESS;
}
