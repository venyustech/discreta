/***************************************************************************
 *   upecman.h                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
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
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION
#define VERSION "20160529.013231" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define LABL 23 /**< Number of lines in labyrinth */
#define LABC 21 /**< Number of columns in labyrinth */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

const char labmodel[LABL][LABC] =
{
    /*01234567890123456789*/
    {"HHHHHHHHHHHHHHHHHHHH"},    /* 0*/
    {"H........HH........H"},    /* 1*/
    {"HoHH.HHH.HH.HHH.HHoH"},    /* 2*/
    {"H..................H"},    /* 3*/
    {"H.HH.H.HHHHHH.H.HH.H"},    /* 4*/
    {"H....H...HH...H....H"},    /* 5*/
    {"HHHH.HHH.HH.HHH.HHHH"},    /* 6*/
    {"   H.H...B....H.H   "},    /* 7*/
    {"   H.H.HH--HH.H.H   "},    /* 8*/
    {"HHHH.H.H  P H.H.HHHH"},    /* 9*/
    {"    ...H  I H...    "},    /*10*/
    {"HHHH.H.H  C H.H.HHHH"},    /*11*/
    {"   H.H.HHHHHH.H.H   "},    /*12*/
    {"   H.H........H.H   "},    /*13*/
    {"HHHH.H.HHHHHH.H.HHHH"},    /*14*/
    {"H........HH........H"},    /*15*/
    {"HoHH.HHH.HH.HHH.HHoH"},    /*16*/
    {"H..H.....@......H..H"},    /*17*/
    {"HH.H.H.HHHHHH.H.H.HH"},    /*18*/
    {"H....H...HH...H....H"},    /*19*/
    {"H.HHHHHH.HH.HHHHHH.H"},    /*20*/
    {"H..................H"},    /*21*/
    {"HHHHHHHHHHHHHHHHHHHH"}     /*22*/
};


typedef enum e_ghostmode {chase, scatter, afraid, dead} t_ghostmode;
typedef enum e_direction {up, left, down, right} t_direction;
typedef enum e_ghosts {blinky, pinky, inky, clyde} t_ghosts;

typedef struct st_position
{
    int y; /* line */
    int x; /* column */
} t_pos;

typedef struct st_pacman
{
    t_pos pos; /* current pacman position */
    t_direction dir; /* direction */
    int life; /* how many lifes pacman has */
    int score; /* dot = 10 point; pill = 50 points; ghost = 750 points; cherry = 500 */
    int eaten; /* Count how many dots and pills are left in the map */
    int cereja;
} t_pacman;

typedef struct st_ghost
{
    int time;
    int steps;
    t_pos pos; /* ghost position */
    t_direction dir; /* ghost current direction */
    t_pos starget; /* ghost scatter preferred corner */
    t_ghostmode mode; /* chase, scatter, afraid or dead */
} t_ghost;

typedef struct st_pacdata
{
    int time; /* game run time in seconds */
    char lab[LABL][LABC]; /* the labyrinth map */
    t_pacman pacman; /* pacman data */
    t_ghost ghost[4]; /* ghost[blinky], ghost[pinky], ghost[inky], ghost[clyde] */
} t_game;


/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
t_game upecman_init(void); /* initialize game variables */
void printlab(t_game g); /* print the labyrinth */
t_game pacman_move(t_game g, int impr); /*movimento do pacman*/
t_game count_score(t_game g); /*conta potos do jogo*/
t_game pacman_life(t_game g); /*verifica vidas do pacman*/
t_game blinky_move(t_game g); /*funcao realiza o movimento do blinky*/
t_game inky_move(t_game g); /*funcao realiza o movimento do inky*/ 
t_game pinky_move(t_game g); /*funcao realiza o movimento do pinky*/
t_game clyde_move(t_game g); /*funcao realiza o movimento do clyde*/
t_game criacereja(t_game g); /*funcao gera cereja no labirinto*/
t_game limpaposfant (t_game g, int NomeDoFantasma, bool reset); /*limpa rastro do fantasma selecionado e caso reset TRUE coordenadas default e modo=chase */
t_game movefantasma (t_game g,int NomeDoFantasma, int xalvofant, int yalvofant); /* funcao realiza o */
bool print_endgame(t_game g); /*imprime mensagem de fim de jogo, e retorna se o usuario deseja continar jogando*/
t_game general_moviment(t_game g, int impr); /*funcao chama a movimentacao de todos os personagens*/
t_game change_mode(t_game g); /*funcao realiza alternancia de modos dos fantasmas*/
bool print_read(t_game g, bool aux); /*imprime mensagem inicial*/
t_game mode_dead(t_game g, int ghost); /*funcao para os fantasmas retornarem a area de spawn no modo dead*/

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

