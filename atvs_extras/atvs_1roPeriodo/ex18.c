/****************************************************************************
 *    ex18.c  VERSION 2019.2                                                 *
 *    dado um interio retorna seu valor por extenso.                        *
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
#include <math.h>

int main()
{
    int n, num = 0, digits1,digits,
    U,D,C,M; /* Unidade, Dezena, Centena, Milhar*/

    printf("Digite qualquer numero de ATE 4 digitos: ");
    scanf("%d", &n);
	digits = (int) log10(n) +1;
	printf("\n\n\n numero de digitos: %d \n\n",digits);
	if(digits > 4)
	{
		printf("Numero de digitos invalido");
	}
	else
	{
		M = n / 1000;
		C = ((n - (1000*M))/100);
			D = (((n - (1000 * M))-(100*C))/10);
		U = ( ((n - (1000 * M)) -(100*C)) - (10*D) );
	
		printf(" Unidade de Milhar : %d  \n Unidade de Centena: %d \t\n Unidade de Dezena : %d \t\n Unidade           : %d \n", M,C,D,U);
		printf (" \n\t O nome em extenso eh:\n ");

		if(!(M==0))
		{
			if(M == 9)
				printf(" nove mil ");
			if(M == 8)
				printf(" oito mil ");
			if(M == 7)
				printf(" sete mil ");
			if(M == 6)
				printf(" seis mil ");
			if(M == 5)
				printf(" cinco mil ");
			if(M == 4)
				printf(" quatro mil ");
			if(M == 3)
				printf(" tres mil ");
			if(M == 2)
				printf(" dois mil ");
			if(M == 1)
				printf(" um mil ");				
		}
	    if(!(C==0))
		{
			if(C == 1 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" cento e");
			if(C == 1 && (D== 0) && (U==0 ))
				printf(" e cem ");	
			
			if(C == 2 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" duzentos e");
			if(C == 2 && (D== 0) && (U==0 ))
				printf(" duzentos ");
			
			if(C == 3 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" trezentos e");
			if(C == 3 && (D== 0) && (U==0 ))
				printf(" trezentos ");
		
			if(C == 4 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" quatrocentos e");
			if(C == 4 && (D== 0) && (U==0 ))
				printf(" e quatrocentos ");
		
			if(C == 5 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" quinhentos e");
			if(C == 5 && (D== 0) && (U==0 ))
				printf(" e quinhentos ");
		
			if(C == 6 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" seissentos e");
			if(C == 6 && (D== 0) && (U==0 ))
				printf(" e seissentos ");
		
			if(C == 7 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" setecentos e");
			if(C == 7 && (D== 0) && (U==0 ))
				printf(" e setecentos ");
		
			if(C == 8 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" oitocentos e");
			if(C == 8 && (D== 0) && (U==0 ))
				printf(" e oitocentos ");
		
			if(C == 9 && ( (!(D== 0)) || (!(U==0 ))))
				printf(" novecentos e");
			if(C == 9 && (D== 0) && (U==0 ))
				printf(" e novecentos ");	
		}
		if(!(D==0))
		{
			if(D == 1 && U==0)
				printf(" dez ");
			if(D == 1 && U==1)
				printf(" onze ");
			if(D == 1 && U==2)
				printf(" doze ");
			if(D == 1 && U==3)
				printf(" treze ");
			if(D == 1 && U==4)
				printf(" quatorze ");
			if(D == 1 && U==5)
				printf(" quinze ");
			if(D == 1 && U==6)
				printf(" dezesseis ");
			if(D == 1 && U==7)
				printf(" dezessete ");
			if(D == 1 && U==8)
				printf(" dezoito");
			if(D == 1 && U==9)
				printf(" dezenove");
			if (D == 2)
				printf(" vinte ");
			if (D == 3)
				printf(" trinta ");
			if (D == 4)
				printf(" quarenta ");
			if (D == 5)
				printf(" cinquenta ");
			if (D == 6)
				printf(" sessenta ");
			if (D == 7)
				printf(" setenta ");
			if (D == 8)
				printf(" oitenta ");
			if (D == 9)
				printf(" noventa ");
		}
		if(!(C==0))
		{
			if((U == 1) && (!(D== 1)))
				printf("e um");	
			if((U == 2) && (!(D== 1)))
				printf("e dois");	
			if((U == 3) && (!(D== 1)))
				printf("e tres");	
			if((U == 4) && (!(D== 1)))
				printf("e quatro");	
			if((U == 5) && (!(D== 1)))
				printf("e cinco");	
			if((U == 6) && (!(D== 1)))
				printf("e seis");	
			if((U == 7) && (!(D== 1)))
				printf("e sete");	
			if((U == 8) && (!(D== 1)))
				printf("e oito");	
			if((U == 9) && (!(D== 1)))
				printf("e nove");				
		}
	}
    return 0;
}
