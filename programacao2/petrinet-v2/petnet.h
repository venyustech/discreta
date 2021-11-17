/***************************************************************************
 *   petnet.h                                 Version 20201010.000622      *
 *                                                                         *
 *   Petri Net Simulator - header file                                     *
 *                                                                         *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 *                                                                         *
 *   Copyright (C) 2020         by Gardenia Georgia Barbosa De Siqueira    *
 *                                 Leandro Dantas Lima                     *
 *                                 Davi Pereira Rio                        *
 *                                 Everton Da Silva Paiva                  *
 *                                 Raquel Gomes da Silva                   *
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
 *   To contact the authors, please write to:                              *
 *                                                                         *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 *                                                                         *
 *   Gardenia Georgia Barbosa De Siqueira                                  *
 *   Email: rabbit.robotica@gmail.com                                      *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 99785-0393                                            *
 *                                                                         *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Webpage: http://beco.poli.br/leandroautocontrole@gmail.com            *
 *   Phone: +55 (81) 98861-9469                                            *
 *                                                                         *
 *   Davi Pereira Rio                                                      *
 *   Email: davi.pereira.rio@gmail.com                                     *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 97903-2929                                            *
 *                                                                         *
 *   Everton Da Silva Paiva                                                *
 *   Email: evertonpaiva01@gmail.com                                       *
 *   Webpage: hhtp://www.beco.cc                                           *
 *   Phone: +55 (81) 995251102                                             *
 *                                                                         *  
 *   Raquel Gomes da Silva                                                 *
 *   Email: raquelgomesnz@gmail.com                                        *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 988270877                                             *
 *                                                                         *
 *                                                                         *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file petnet.h
 * \ingroup GroupUnique
 * \brief Petri Net Simulator - header file
 * \details This program really do a nice job as a template, and template only!
 * \version 20160806.231942
 * \date 2016-08-06
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _PETRINET_H
#define _PETRINET_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h>  /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h> /* Time and date functions */
#include <unistd.h> /* UNIX standard function */
#include <stdbool.h> /* Defines integer boolean constants true and false */
#include <getopt.h> /* get options from system argc/argv */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160806.231942" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define AMOSTRAS 14

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */
int *qtdTokens = NULL;
int **conjuntoPRE; /* Guarda matriz para construcao do conjunto PRE */
int **conjuntoPOST;/* Guarda matriz para construcao do conjunto POST */
int *separaCOLt;  /* Guarda linha para multiplicaçao que separa coluna T que para verificar habilita_transição */
int *colunaSeparadaPRE; /* Salva valor de coluna tx da matriz ConjuntoPRE */
int *colunaSeparadaPOST; /* Salva valor de coluna tx da matriz ConjuntoPOST */
int *transicaoHabilitada; /* vetor[Tcomponentes] que se estiver 1, tx esta habilitado */
int qtdLugares = 0, qtdTransicoes = 0; /* Guarda valor de acordo com input de Lugares e posicoes pra criacao de matriz */
int qtdTransicoesFORDisparo;
int *disparaTRANS;
int contadorLoopDoJogo = 1;
/* ---------------------------------------------------------------------- */
/* prototypes */
void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void petnet_init(void); /* global initialization function */
void gerar_aleatorios(int num_sort[], int quant_num, int max_trans); /* gerar numeros aleatorios para serem utilizados nas transicoes */
void escolha_trans(int *cont_t, float *perc_t, int *num_sort,bool *trans_dispara); /* definir qual transição deve disparar */
void inputUsuario(void);
void input_Tokens();
void print_Tokens(int MAXLIN);
void input_ConjuntoPRE(int MAXLIN, int MAXCOL);
void input_ConjuntoPOST(int MAXLIN, int MAXCOL);
void print_ConjuntoPRE(int MAXLIN, int MAXCOL);
void print_ConjuntoPOST(int MAXLIN, int MAXCOL);
void gera_separaCOLt();
void zera_separaCOLt();
void habilita_separaCOLt(int ntransicao);
void gera_transicaoHabilitada(int qtdElementos);//qtdElementos = qtdTransições
void zera_transicaoHabilitada(int qtdElementos);
void print_transicaoHabilitada(int qtdElementos);
void gera_colunaSeparadaPRE(); /*gera matriz que fará multiplicação conjuntoPRE x separaCOLt*/
void zera_colunaSeparadaPRE();
void habilita_colunaSeparadaPRE(int TransicaoDeAnalise);
void gera_colunaSeparadaPOST(); /*gera matriz que fará multiplicação conjuntoPRE x separaCOLt*/
void zera_colunaSeparadaPOST();
void habilita_colunaSeparadaPOST(int TransicaoDeAnalise);
void habilita_transicao(void);
void gera_disparaTRANS(int qtdElementos);
void zera_disparaTRANS(int qtdElementos);
void print_disparaTRANS(int qtdElementos);
void inputConjuntoArcos(int **conjunto, int qtdLinha, int qtdColuna, int qtdArcos);
int verif_habilita(int **conjuntoPre, int *tokens, int nLugares, int transicao);
void disparar_trans(int **conjuntoPre, int **conjuntoPost, int *tokens, int nLugares, int transicao);
void muda_qtdTokens();
void liberaMemoria(void);
#endif /* NOT def _PETRINET_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

