 /**************************************************************************
 *   projecteuler.c                           Version 20190325.143802      *
 *                                                                         *
 *   Project Euler                                                         *
 *   Copyright (C) 2015-2019    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
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
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 **************************************************************************/

/* *** DO NOT CHANGE THIS FILE *** */

#include "projecteuler.h" 

/* ---------------------------------------------------------------------- */
/* globals */
volatile sig_atomic_t oneminute=0;
volatile sig_atomic_t CTRLC=0;
/* char funcname[SBUFF]; */
/*, funcdata[SBUFF];*/
/* info to print when interrupted by signal */

/* ---------------------------------------------------------------------- */
/* grabbing control */
void GRABsignals(void)
{
    signal(SIGINT, intsignal);
    signal(SIGQUIT, quitsignal);
    signal(SIGALRM, oneminuterule);
    alarm(ONEMINUTE); /* alarm in 1 minute */
    /* printf("Project Euler version %s\n", VERSION); */
    printf("Ctrl-C to dump. Ctrl-\\ to abort.\n");
    return;
}

/* ---------------------------------------------------------------------- */
/* give signals back to owner */
/* extern inline void finishmain(void) __attribute__((always_inline, externally_visible)) */
extern inline void LEGOsignals(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGALRM, SIG_DFL);
    return;
}

/* ---------------------------------------------------------------------- */
/* Control-C gives info */
void intsignal()
{
    CTRLC=1;
}

/* ---------------------------------------------------------------------- */
/* Set alarm clock: tThe answer should be ready in just one minute */
void oneminuterule()
{
    oneminute++;
    write(1, "\n ---- One minute rule broken ! ----\n", 37);
    alarm(ONEMINUTE);
    /* raise(SIGQUIT); */
}

/* ---------------------------------------------------------------------- */
/* Control-\ ends all */
void quitsignal()
{                
    LEGOsignals();
    (void)write(2,"\nctrl-\\ pressed!\n", 17);
    abort();
}

/* ---------------------------------------------------------------------- */
/* Print only if Control-c is pressed. Return true if printed */
int ctrlc_printf(char *fmt, ...)
{
    va_list args;
    volatile int i=CTRLC;
   
    CTRLC=0;
    if(i)
    {
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
        sleep(1);
    }
    return i;
}

/* ---------------------------------------------------------------------- */
/* count number of minutes */
int minutes(void)
{
    return (int)oneminute;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */


