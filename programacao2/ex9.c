/***************************************************************************
 *   ex9.c                                    Version 20201019.224305      *
 *                                                                         *
 *   Calculadora Polonesa com Pilhas                                       *
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
 * $gcc ex9.c -o ex9.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

/* ---------------------------------------------------------------------- */
/* definitions */

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

/* ---------------------------------------------------------------------- */
/* prototypes */
int getop(char []);
void push(double);
double pop(void);
void ungetch(int);

/* ---------------------------------------------------------------------- */
/* Globals */
int sp = 0;
double val[MAXVAL];
int getch(void);
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("Calculadora polonesa\n\nInsira o valor:\n\n");

    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
           case'-':
                op2 = pop();
                push(pop()- op2);
                break;
           case'/':
                op2 = pop ();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("erro: divisor zero. Recomece.\n");
                break;
            case '\n':
                printf("Resultado: %.8g\n\nDigite a proxima:\n",pop());
                break;
            default:
                printf("error\n\nTente outra vez.%s\n\nRecomece o programa\n",s);
                return 0;
        }
    }
    return 0;
}


void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("\nerror. Pilha cheia %g\n",f);
}
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error. pilha vazia\n");
        return 0;
    }
}

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));
    if(c == '.')
        while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: caracteres em excesso\n");
    else
        buf[bufp++]=c;
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

