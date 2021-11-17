 /****************************************************************************
 *   ex22.c      VERSION 2019.2                                             *
 *                                                                          *
 *    maquina de troco                                                      *
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

int main (void)
{
    float f = 0;
	int cedulas100=0,cedulas50=0,cedulas20=0,cedulas10=0,cedulas5=0,cedulas2=0;

    int moedade1real=0,moedas25=0,moedas10=0,moedas5=0,moedas1=0;

    printf("Quanto de troco deseja receber? ");
    scanf("%f",&f);

    while(f >= 100) {
        f -=  100;
        cedulas100++;
    }

    while(f >= 50) {
        f -= 50;
        cedulas50++;
    }

    while(f >= 20) {
        f -= 20;
        cedulas20++;
    }

    while(f >= 10) {
        f -= 10;
        cedulas10++;
    }
    while(f >= 5) {
        f -= 5;
        cedulas5++;
    }
    while(f >= 2) {
        f -= 2;
        cedulas2++;
    }
    while(f >= 1) {
        f -= 1;
        moedade1real++;
    }
    while(f >= 0.25) {
        f -= 0.25;
        moedas25++;
    }
    while(f >= 0.10) {
        f -= 0.10;
        moedas10++;
    }
    while(f >= 0.05) {
        f -= 0.05;
        moedas5++;
    }
    while(f >= 0.01) {
        f -= 0.01;
        moedas1++;
    }

    printf("Seu troco: \n%d cedulas de 100\n%d cedulas de 50\n%d cedulas de 20\n%d cedulas de 10\n%d cedulas de 5\n%d cedulas de 2\n\n%d moeda e 1 real \n\n%d  moedas de 25 \n\n%d moedas de 10\n\n%d moedas de 5\n\n%d moedas de 1 Obrigado volte sempre!\n",cedulas100,cedulas50,cedulas20,cedulas10,cedulas5,cedulas2,moedade1real,moedas25,moedas10,moedas5,moedas1);

	return EXIT_SUCCESS;
}
