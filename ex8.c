/***************************************************************************
 *   ex8.c                                    Version 20201014.202703      *
 *                                                                         *
 *   Listas Lineares                                                       *
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
 * $gcc ex8.c -o ex8.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

typedef struct st_lista{
    int c;
    struct st_lista * prox;
}lista;

lista *buscar(lista *cabeca, int x){
    lista *pl=cabeca;
    while(pl!=NULL)
    {
        if(pl->c==x)
            return pl;
        pl=pl->prox;
    }
    return NULL;
}

void inserir(lista **cabeca, int x){
    lista *pl=*cabeca;
    lista *plant=NULL;
    while(pl!=NULL){
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(lista));
    pl->c=x;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}
void remover(lista **cabeca, lista *r)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    if(r==NULL)
        return;
    while(pl!=NULL && pl!=r)
    {
        plant=pl;
        pl=pl->prox;
    }
    if(pl==NULL)
        return;
    if(plant!=NULL)
        plant->prox=pl->prox;
    else
        *cabeca=pl->prox;
    free(pl);
    return;
}

lista *anterior(lista *cabeca, lista *r)
{
    lista *pl=cabeca, *plant=NULL;
    if(r==NULL)
        return NULL;
    while(pl!=NULL && pl!=r)
    {
        plant=pl;
        pl=pl->prox;
    }
    return plant;
}

void imprimir(lista *cabeca)
{
    lista *pl=cabeca;
    while(pl!=NULL)
    {
        printf("%d->", pl->c);
        pl=pl->prox;
    }
    printf("NULL\n");
}
int main(void)
{
    lista *l1=NULL, *b=NULL, *a=NULL;

    inserir(&l1, 1);
    imprimir(l1);
    inserir(&l1, 2);
    imprimir(l1);
    inserir(&l1, 3);
    imprimir(l1);
    b=buscar(l1, 3);
    if(b!=NULL)
        printf("b->c; %d\n", b->c);
    a=anterior(l1, b);
    if(a!=NULL)
        printf("a->c; %d\n", a->c);
    b=buscar(l1, 1);
    remover(&l1, b);
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

