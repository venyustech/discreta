 /**************************************************************************
 *   projecteuler.h                           Version 20190325.143836      *
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

#ifndef _PROJECTEULER_H
#define _PROJECTEULER_H

/* ---------------------------------------------------------------------- */
/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <gmp.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include <error.h>
#include <errno.h>
#include <stdarg.h>

/* ---------------------------------------------------------------------- */
/* typedefs */
typedef unsigned long ulong;
typedef unsigned int uint;

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20190325.111846" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */
#define SAFEMEM 1000 /* a thousand integers in cache maximum */
#define ONEMINUTE 60 /* wait 60 seconds before warning */

/* static long mfor_val, mfor_inc; */ /* mfor (middle for) support variables */
/* static uint mfor_loop; */ /* mfor (middle for) break loop flag */
/* #define mfor(min, max) \
    for(mfor_val=((ulong)(((double)((max)+(min))/2.0)+0.5)), mfor_inc=0, mfor_loop=1;\
        mfor_val>(min) && mfor_val<(max) && mfor_loop;\
        mfor_inc=(mfor_loop?(-1*sinal(mfor_inc)*(abs(mfor_inc)+1)):0), mfor_val+=mfor_inc)*/
    
/* ---------------------------------------------------------------------- */
/* globals */
/* char funcname[SBUFF], funcdata[SBUFF]; /1* info to print when interrupted by signal *1/ */

/* ---------------------------------------------------------------------- */
/* prototypes */
void GRABsignals(void);
/* void startfunc(const char *s); */
void LEGOsignals(void);
/* void finishmain(void) __attribute__((always_inline, externally_visible)); */

/* Grab Ctrl-C to show info */
void intsignal(); /* ctrl-c */
void quitsignal(); /* ctrl-\ */
void oneminuterule(); /* one minute rule */

/* external functions */
int ctrlc_printf(char *fmt, ...); /* print only if pressed CTRL-C. Return true if printed. */
int minutes(void); /* return number of minutes */

#endif

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

