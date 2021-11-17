/***************************************************************************
 *   upecman.c                                Version 20191106.231545      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2019         by Dayvson Morais Chagas                   *
 *                                 Gardenia Georgia Barbosa de Siqueira    *
 *                                 Jefferson Queiroz Da Costa              *
 *                                 Joao Gustavo Cavalcanti Beltrao Da Silva*
 *                                 Leandro Dantas Lima                     *
 *                                 Thulio Nascimento Da Silva              *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
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
 *                                                                         *
 *   Dayvson Morais Chagas                                                 *
 *   Email: dayvsmorais@gmail.com                                          *
 *   Phone: +55 (81)98500-2281                                             *
 *                                                                         *
 *   Gardenia Georgia Barbosa De Siqueira                                  *
 *   Email: rabbit.robotica@gmail.com                                      *
 *   Webpage: http://beco.poli.br/rabbit.robotica@gmail.com                *
 *   Phone: +55 (81) 99785-0393                                            *
 *                                                                         *
 *   Jefferson Queiroz Da Costa                                            *
 *   Email: jeffersonadven7@gmail.com                                      *
 *   Webpage: http://beco.poli.br/jeffersonadven7@gmail.com                *
 *   Phone: +55 (87) 99951-1215                                            *
 *                                                                         *
 *   Joao Gustavo Cavalcanti Beltrao Da Silva                              *
 *   Email: joaogustavocavalcante@gmail.com                                *
 *   Webpage: http://beco.poli.br/joaogustavocavalcante@gmail.com          *
 *   Phone: +55 (81) 98187-3486                                            *
 *                                                                         *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Phone: +55 (81) 98861-9469                                            *
 *                                                                         *
 *   Thulio Nascimento Da Silva                                            *
 *   Email: thulionascimento1@gmail.com                                    *
 *   Phone: +55 (81) 99757-3181                                            *
 *                                                                         *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a pacman game for terminal
 * @version 20160529.013231
 * @date 2016-05-29
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h>  /* Time and date functions */
#include <locale.h>  /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Main function
 * @details will start the program
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./upecman -h
 * @endcode
 *
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
int main(int argc, char *argv[])
{
    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    t_game g; /* the game */
    int impr; /* Ultima tecla digitada */
    int imprA; /* Nova tecla digitada */
    clock_t time_inicial = 0, time_final;

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");

    g = upecman_init();

    printlab(g);

    refresh();

    if(print_read(g,0))
    {
        endwin();
        return EXIT_SUCCESS;
    }

    impr = 0;
    clear();
    refresh();

    printlab(g);

    while(1) /* loop do jogo: coloque seu movimento de fantasma aqui */
    {
        time_final = clock();

        /* Entrada do usuario */
        imprA = getch(); 
        /* So muda a techa se tiver precionado uma nova */
        if(imprA != ERR) 
            impr = imprA;

        g = general_moviment(g, impr); /*funcao de movimentacao geral de todos os personagens*/

        if(print_endgame(g))
            break;

        else if((g.pacman.life < 0) || (g.pacman.eaten == 0))  /*game over caso toas as vidas do pacman acabe */
        {
            g = upecman_init(); /* assim que o jogo acabar reta para a posicao inicial*/
            clear();
            printlab(g);
            refresh();
        }
        refresh();
        usleep(500);

        /* Atualiza tempo do jogo a cada 1 segundo */
        if((time_final - time_inicial) >= 1000)
        {
            time_inicial = clock();
            time_final = clock();
            g.time++;

        }
    }

    endwin();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details will start the initial position of the elements on the program
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */
    g.pacman.eaten = 188; /* 188 dots and pills on the map */
    g.pacman.cereja = 1;
    g.time = 0;
    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f)
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
        g.ghost[f].time = 0;
        g.ghost[f].steps = 0;
    }

    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */
    curs_set(0);

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */
    init_pair(7, COLOR_BLUE, COLOR_BLUE); /* Walls paint */
    init_pair(8, COLOR_WHITE, COLOR_BLACK); 
    init_pair(10,COLOR_WHITE, COLOR_BLUE);

    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details This function will print the labirinth and ghosts initial position
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void printlab(t_game g)
{
    IFDEBUG("printlab()");

    int y, x, f;

    for(y = 0; y < LABL; y++)
    {
        for(x = 0; x < 20; x++)
        {
            if(g.lab[y][x] != 'H')
                mvprintw(y,x,"%c",g.lab[y][x]);
            if(g.lab[y][x] == 'H')
                mvchgat(y,x,1,A_BOLD,7,NULL); 
            else 
                mvchgat(y,x,1,A_BOLD,6,NULL); 
        }
    }

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
        mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);

    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);

    refresh();
}


/* ---------------------------------------------------------------------- */
/*                    Movimento do PACMAN                                 */
/* ---------------------------------------------------------------------- */

t_game pacman_move(t_game g, int impr)
{
    curs_set(0);

    mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@"); /* Imprime posicao do pacman */
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL); /* pinta posicao do pacman */
    refresh();

/* ---------------------------------------------------------------------- */
/* Muda a direcao, se nao for parede, dependendo da tecla pressionada.    */
/* ---------------------------------------------------------------------- */

    if((impr == 'w' || impr == KEY_UP) && (g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != 'H' && g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '-'))
        g.pacman.dir = up;

    else if((impr == 's' || impr == KEY_DOWN) && (g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != 'H' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')) 
        g.pacman.dir = down;

    else if((impr == 'a' || impr == KEY_LEFT) && g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != 'H')
        g.pacman.dir = left;

    else if((impr == 'd' || impr == KEY_RIGHT) && g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != 'H')
        g.pacman.dir = right;

    usleep(100000); /* Desacelerar o jogo */

/* ---------------------------------------------------------------------- */
/* Determina a direcao que quer seguir.                                   */
/* ---------------------------------------------------------------------- */

    if(g.pacman.dir == up || g.pacman.dir == down) /* Qual direcao tem que ir */
    {
        usleep(60000); /* Desacelera o jogo na vertical */
        mvprintw(g.pacman.pos.y, g.pacman.pos.x, " "); /* apaga posicao anterior */
        if(g.lab[g.pacman.pos.y + g.pacman.dir - 1][g.pacman.pos.x] == 'H') /* Se o proximo movimento for uma parede ele para */
            return g;

        g.pacman.pos.y += g.pacman.dir - 1; /* nova posicao baseado na direcao que ele quer ir direita/esquerda */
    }

    if(g.pacman.dir == left || g.pacman.dir == right)
    {
        mvprintw(g.pacman.pos.y, g.pacman.pos.x, " "); /* Apaga posicao do pacman */

        if(g.pacman.pos.y == 10 && g.pacman.pos.x == 19 && g.pacman.dir == right) /* teleporta de lugar se tiver nessa posicao e nessa direcao*/
        {
            g.pacman.pos.y = 10;
            g.pacman.pos.x = 0;
            return g;
        }

        else if(g.pacman.pos.y == 10 && g.pacman.pos.x == 0 && g.pacman.dir == left) /* teleporta de lugar se tiver nessa posicao e nessa direcao*/
        {
            g.pacman.pos.y = 10;
            g.pacman.pos.x = 19;
            return g;
        }
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + g.pacman.dir - 2] == 'H')
            return g;
        g.pacman.pos.x += g.pacman.dir - 2; /* nova posicao baseado na direcao que ele quer ir cima/baixo */
    }

    return g;
}


/* ---------------------------------------------------------------------- */
/* Conta os pontos do jogador/pacman.                                     */
/* ---------------------------------------------------------------------- */

t_game count_score(t_game g)
{
    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '.') /* Se passar por um dot */
    {
        g.pacman.score += 10;
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
        g.pacman.eaten -= 1;
    }

    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == 'o') /* Se passar por um pill */
    {
        if(g.ghost[blinky].mode != dead)
        { 
            g.ghost[blinky].mode = afraid;
            g.ghost[blinky].steps = 1;
            g.ghost[blinky].time = g.time;
        }
        if(g.ghost[inky].mode != dead)
        {
            g.ghost[inky].mode = afraid;
            g.ghost[inky].steps = 1;
            g.ghost[inky].time = g.time;
        }
        if(g.ghost[pinky].mode != dead)
        {
            g.ghost[pinky].mode = afraid;
            g.ghost[pinky].steps = 1;
            g.ghost[pinky].time = g.time;
        }
        if(g.ghost[clyde].mode != dead)
        {
            g.ghost[clyde].mode = afraid;
            g.ghost[clyde].steps = 1;
            g.ghost[clyde].time = g.time;
        }
        g.pacman.score += 50;
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
        g.pacman.eaten -= 1;
    }

    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%')
    {
        g.pacman.score += 500;
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
        g.pacman.cereja++;
        g.pacman.eaten -= 1;
    }


/* ---------------------------------------------------------------------- */
/* Adiciona 750 pontos para cada fantasma morto no modo afraid.           */
/* ---------------------------------------------------------------------- */

    if((g.pacman.pos.x == g.ghost[blinky].pos.x) && (g.pacman.pos.y == g.ghost[blinky].pos.y) && (g.ghost[blinky].mode == afraid))
    {
        g.pacman.score += 750;
        g.ghost[blinky].mode = dead;
    }

    if((g.pacman.pos.x == g.ghost[inky].pos.x) && (g.pacman.pos.y == g.ghost[inky].pos.y) && (g.ghost[inky].mode == afraid))
    {
        g.pacman.score += 750;
        g.ghost[inky].mode = dead;
    }

    if((g.pacman.pos.x == g.ghost[pinky].pos.x) && (g.pacman.pos.y == g.ghost[pinky].pos.y) && (g.ghost[pinky].mode == afraid))
    {
        g.pacman.score += 750;
        g.ghost[pinky].mode = dead;
    }

    if((g.pacman.pos.x == g.ghost[clyde].pos.x) && (g.pacman.pos.y == g.ghost[clyde].pos.y) && (g.ghost[clyde].mode == afraid))
    {
        g.pacman.score += 750;
        g.ghost[clyde].mode = dead;
    }


/* ---------------------------------------------------------------------- */
/*       Mensagens de cabecalho - UPECMAN - e de informacoes              */
/* ---------------------------------------------------------------------- */

    mvprintw(2, 25, "UU    UU  PPPPPP  EEEEEE   CCCCC  M       M     A     N     N"); 
    mvprintw(3, 25, "UU    UU  PP   PP EE      CC      M M   M M    A A    N N   N");
    mvprintw(4, 25, "UU    UU  PPPPPP  EEEEE  CC       M  M M  M   AAAAA   N  N  N"); 
    mvprintw(5, 25, "UU    UU  PP      EE      CC      M   M   M  A     A  N   N N"); 
    mvprintw(6, 25, "  UUUU    PP      EEEEEE   CCCCC  M       M A       A N     N"); 

    mvprintw(8, 25, "------------"); 
    mvprintw(9, 25, "score: %d", g.pacman.score);       /* Imprime a pontuacao do pacman */
    mvprintw(10, 25, "------------"); 

    mvprintw(12, 25, "cherry: %d", g.pacman.cereja-1);  /* Imprime o numero de cerejas coletadas */
    mvprintw(19, 25, "remainder: %3d", g.pacman.eaten); /* Imprime o numero de dots e pills remanescentes */
    mvprintw(20, 25, "time: %d", g.time);               /* Imprime o tempo desde o inicio do jogo */

    return g;
}


/* ---------------------------------------------------------------------- */
/* Cria cereja do jogo quando o pacman alcanca 1000 pontos.               */
/* ---------------------------------------------------------------------- */

t_game criacereja(t_game  g)
{
    if((g.pacman.score >= 1000) && (g.pacman.cereja  == 1))
    {
        g.lab[13][10]='%';  /*cria cereja dentro do labirinto*/
        mvprintw(13,10,"%%");
        mvchgat(13,10,1,A_BOLD,1,NULL);
    }
    return g;
}


/* ---------------------------------------------------------------------- */
/* Contador de vidas do pacman.                                           */
/* ---------------------------------------------------------------------- */

t_game pacman_life(t_game g)
{
    /*condicao para pacman perder uma vida*/  
    if((g.pacman.pos.x == g.ghost[blinky].pos.x) && (g.pacman.pos.y == g.ghost[blinky].pos.y) && (g.ghost[blinky].mode != afraid) && (g.ghost[blinky].mode != dead))
    {   g = limpaposfant(g,blinky,0); /*funcao limpa rastro do blinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,pinky,0); /*funcao limpa rastro do pinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,inky,0); /*funcao limpa rastro do inky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,clyde,1); /*funcao limpa rastro do clyde e reseta coordenadas para para inicial*/
        if(g.pacman.life >= 0)
            if(print_read(g,1))
                return g;
    }

    if((g.pacman.pos.x == g.ghost[pinky].pos.x) && (g.pacman.pos.y == g.ghost[pinky].pos.y) && (g.ghost[pinky].mode != afraid) && (g.ghost[pinky].mode != dead))
    {
        g = limpaposfant(g,blinky,0); /*funcao limpa rastro do blinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,pinky,0); /*funcao limpa rastro do pinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,inky,0); /*funcao limpa rastro do inky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,clyde,1); /*funcao limpa rastro do clyde e reseta coordenadas para para inicial*/
        if(g.pacman.life >= 0)
            if(print_read(g,1))
                return g;
    }   

    if((g.pacman.pos.x == g.ghost[inky].pos.x) && (g.pacman.pos.y == g.ghost[inky].pos.y) && (g.ghost[inky].mode != afraid) && (g.ghost[inky].mode != dead))
    {
        g = limpaposfant(g,blinky,0); /*funcao limpa rastro do blinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,pinky,0); /*funcao limpa rastro do pinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,inky,0); /*funcao limpa rastro do inky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,clyde,1); /*funcao limpa rastro do clyde e reseta coordenadas para para inicial*/
        if(g.pacman.life >= 0)
            if(print_read(g,1))
                return g;
    }

    if((g.pacman.pos.x == g.ghost[clyde].pos.x) && (g.pacman.pos.y == g.ghost[clyde].pos.y) && (g.ghost[clyde].mode != afraid) && (g.ghost[clyde].mode != dead))
    {
        g = limpaposfant(g,blinky,0); /*funcao limpa rastro do blinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,pinky,0); /*funcao limpa rastro do pinky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,inky,0); /*funcao limpa rastro do inky e reseta coordenadas para para inicial*/
        g = limpaposfant(g,clyde,1); /*funcao limpa rastro do clyde e reseta coordenadas para para inicial*/
        if(g.pacman.life >= 0)
            if(print_read(g,1))
                return g;
    }

    if(g.pacman.life >=0)
        mvprintw(11, 25, "life: %d", g.pacman.life); /* Imprime a pontuacao */
    else
        mvprintw(11, 25, "life: %d", g.pacman.life+1); /* Imprime a pontuacao */
    return g;
}


/* ---------------------------------------------------------------------- */
/* Imprime mensagem de fim de jogo (game over ou winner)                  */
/* ---------------------------------------------------------------------- */

bool print_endgame(t_game g)
{
    WINDOW *janela3;

    janela3 = newwin(3,14,13,3);

    if(g.pacman.life < 0 || g.pacman.eaten == 0)
    {
        if(g.pacman.life <0)  /* game over caso todas as vidas do pacman acabem */
        { 
            wbkgd(janela3, COLOR_PAIR(1));
            wattron(janela3, A_BOLD); 
            mvwprintw(janela3,1,2,"%s", "GAME  OVER");
            wrefresh(janela3);
        }

        if(g.pacman.eaten == 0) /* Se ja comeu tudo entao acabou o jogo */
        {
            mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
            mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
            wbkgd(janela3, COLOR_PAIR(4));
            wattron(janela3, A_BOLD); 
            mvwprintw(janela3,1,0,"%s", "*** WINNER ***");  
            wrefresh(janela3);
        }

        sleep(2);
        clear();
        printlab(g);
        refresh();
        if(print_read(g,0))
            return 1; 
    }
    return 0;
}


/* ---------------------------------------------------------------------- */
/* Movimentacao geral.                                                    */
/* ---------------------------------------------------------------------- */

t_game general_moviment(t_game g, int impr)
{
    g = pacman_move(g, impr); /* funcao que movimenta o pacman */

    /* Verifica se o pacman morreu ou comeu um fantasma logo depois dele mover para evitar que se cruzem */
    g = pacman_life(g); /* verifica se o pacman perdeu vida */
    g = count_score(g);

    g = change_mode(g);

    if(g.ghost[clyde].mode == scatter || g.ghost[clyde].mode == chase) /*clyde se move normalmente no modo chase ou scatter*/
        g = clyde_move(g);

    /* Anda mais lento no modo afraid */
    if(g.ghost[clyde].mode == afraid)
    {

        if(g.ghost[clyde].steps == 2)
        {
            g = clyde_move(g);
            g.ghost[clyde].steps = 0;
        }

        g.ghost[clyde].steps++;
    }

    /* Move tres vezes mais rapido no modo dead */
    if(g.ghost[clyde].mode == dead)
    {
        g = clyde_move(g);
        g = clyde_move(g);
        g = clyde_move(g);
    }
    if(g.ghost[pinky].mode == scatter || g.ghost[pinky].mode == chase) /*pinky se move normalmente no modo chase ou scatter*/
        g = pinky_move(g);

    /* Anda mais lento no modo afraid */
    if(g.ghost[pinky].mode == afraid)
    {

        if(g.ghost[pinky].steps == 2)
        {
            g = pinky_move(g);
            g.ghost[pinky].steps = 0;
        }

        g.ghost[pinky].steps++;
    }

    /* Move tres vezes mais rapido no modo dead */
    if(g.ghost[pinky].mode == dead)
    {
        g = pinky_move(g);
        g = pinky_move(g);
        g = pinky_move(g);
    }

    /* Anda mais rapido no modo chase */
    if(g.ghost[blinky].mode == chase)
    {
        g = blinky_move(g);

        if(g.ghost[blinky].steps == 25)
        {
            g = pacman_life(g); 
            g = blinky_move(g);
            g.ghost[blinky].steps = 0;
        }
    }

    /* Anda mais lento no modo afraid */
    if(g.ghost[blinky].mode == afraid || g.ghost[blinky].mode == dead)
    {

        if(g.ghost[blinky].steps == 2)
        {
            g = blinky_move(g);
            g.ghost[blinky].steps = 0;
        }

        g.ghost[blinky].steps++;
    }

    /* Move tres vezes mais rapido no modo dead */
    if(g.ghost[blinky].mode == dead)
    {
        g = blinky_move(g);
        g = blinky_move(g);
        g = blinky_move(g);
    }

    if(g.ghost[blinky].mode == scatter)
        g = blinky_move(g);

    if(g.ghost[inky].mode == scatter || g.ghost[inky].mode == chase) /*inky se move normalmente no modo chase ou scatter*/
        g = inky_move(g);

    /* Anda mais lento no modo afraid */
    if(g.ghost[inky].mode == afraid)
    {

        if(g.ghost[inky].steps == 2)
        {
            g = inky_move(g);
            g.ghost[inky].steps = 0;
        }

        g.ghost[inky].steps++;
    }

    /* Move tres vezes mais rapido no modo dead */
    if(g.ghost[inky].mode == dead)
    {
        g = inky_move(g);
        g = inky_move(g);
        g = inky_move(g);
    }

    g = criacereja(g);
    g = count_score(g);
    g = pacman_life(g);

    usleep(90000);
    return g;
}


/* ---------------------------------------------------------------------- */
/* Imprime mensagem inicial                                               */
/* ---------------------------------------------------------------------- */

bool print_read(t_game g, bool aux)
{
    int kin=0;
    refresh();
    printlab(g);

    WINDOW *janela;

    janela = newwin(3, 14, 13, 3);

    curs_set(0);
    wrefresh(janela);

    if(aux)
    {
        wbkgd(janela, COLOR_PAIR(6));
        wattron(janela,A_BOLD);
        mvwprintw(janela, 1, 4, "%s","READY!");
        wrefresh(janela);
        sleep(2);
        clear();
        printlab(g);
        refresh();
    }

    if(!aux)
    {
        wbkgd(janela, COLOR_PAIR(6));
        wattron(janela,A_BOLD);
        mvwprintw(janela, 1, 2, "%s","Start?(y/n)");
        wrefresh(janela);

        while(1)
        {
            kin = getch();
            if(kin == 'y' || kin == KEY_LEFT)
                return 0;
            usleep(16667);

            if(kin == 'n' || kin == KEY_RIGHT)
            {
                return 1; 
            }
        }
    }

    return 0;
}


/* ---------------------------------------------------------------------- */
/* Modo de jogo dead.                                                     */
/* ---------------------------------------------------------------------- */

t_game mode_dead(t_game g, int ghost)
{
    if((g.ghost[ghost].pos.y > 9) && (g.ghost[ghost].pos.y < 11) && (g.ghost[ghost].pos.x > 7) && (g.ghost[ghost].pos.x < 12)) /* condicao para entrar do spawn */
    {   g.ghost[ghost].mode = chase;
        g.ghost[ghost].time = g.time;
    }

    switch(ghost)
    {
        case blinky:
            g = movefantasma(g,ghost,9,9);
            break;

        case pinky:
            g = movefantasma(g,ghost,9,9);
            break;

        case inky:
            g = movefantasma(g,ghost,9,9);
            break;

        case clyde:
            g = movefantasma(g,ghost,9,9);
            break;
    }
    return g;
}


/* ---------------------------------------------------------------------- */
/* Limpa rastro dos fantasmas.                                            */
/* ---------------------------------------------------------------------- */

t_game limpaposfant (t_game g, int NomeDoFantasma, bool reset)
{
    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]==' ')
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, " ");

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='.')
    {
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, "."); 
        mvchgat(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, 1, A_BOLD, 6, NULL); 
    }

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='o')
    {
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, "o"); 
        mvchgat(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, 1, A_BOLD, 6, NULL); 
    }

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='-')
    {
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, "-");
        mvchgat(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, 1, A_BOLD, 6, NULL);
    }

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='%')
    {
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, "%"); 
        mvchgat(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, 1, A_BOLD, 6, NULL); 
    }

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]== '~')
    {
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, "~"); 
        mvchgat(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, 1, A_BOLD, 6, NULL); 
    }

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='B')
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, " ");

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='P')
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, " ");

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='I')
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, " ");

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='C')
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, " ");

    if(g.lab[g.ghost[NomeDoFantasma].pos.y][g.ghost[NomeDoFantasma].pos.x]=='@')
        mvprintw(g.ghost[NomeDoFantasma].pos.y, g.ghost[NomeDoFantasma].pos.x, " ");

    if(reset) 
    {
        g.pacman.life -=1; /*pacman perde uma vida*/
        g.pacman.pos.y = 17; /* pacman start position (line) */
        g.pacman.pos.x = 9; /* pacman start position (column) */
        g.ghost[blinky].pos.y = 7; /* blinky start position (line) */
        g.ghost[blinky].pos.x = 9; /* blinky start position (column) */
        g.ghost[blinky].mode = chase; /* blinky volta para o modo chase apos a morte do pacman*/
        g.ghost[blinky].time = g.time; /*zera timer blinky*/
        g.ghost[pinky].pos.y = 9; /* pinky start position (line) */
        g.ghost[pinky].pos.x = 10; /* pinky start position (column) */
        g.ghost[pinky].mode = chase; /* pinky volta para o modo chase apos a morte do pacman*/
        g.ghost[pinky].time = g.time; /*zera timer pinky*/
        g.ghost[inky].pos.y = 10;       /* inky start position (line) */
        g.ghost[inky].pos.x = 10;       /* inky start position (column) */
        g.ghost[inky].mode = chase;     /* inky volta para o modo chase apos a morte do pacman*/
        g.ghost[inky].time = g.time;    /* zera timer inky*/
        g.ghost[clyde].pos.y = 11; /* clyde start position (line) */
        g.ghost[clyde].pos.x = 10; /* clyde start position (column) */
        g.ghost[clyde].mode = chase; /* clyde volta para o modo chase apos a morte do pacman*/
        g.ghost[clyde].time = g.time; /*zera timer clyde*/
    }    
    return g;    
}


/* ---------------------------------------------------------------------- */
/* Movimentos dos fantasmas.                                              */
/* ---------------------------------------------------------------------- */

t_game movefantasma (t_game g, int NomeDoFantasma, int xalvofant, int yalvofant)
{
    int f;
    int xf,yf;
    int disman = 0;
    
    f = NomeDoFantasma;
    xf = g.ghost[f].pos.x;
    yf = g.ghost[f].pos.y;

    disman = abs(xf - xalvofant) + abs(yf - yalvofant);     /* Calculo da distancia de manhattan */

    /* Escolhendo a direçao do fantasma */

    if(((abs(xf - xalvofant) + abs(yf - 1 - yalvofant)) < disman) && (g.lab[yf - 1][xf] != 'H') && (g.ghost[f].dir != down))
        g.ghost[f].dir = up;

    else if(((abs(xf + 1 - xalvofant) + abs(yf - yalvofant)) < disman) && (g.lab[yf][xf + 1] != 'H') && (g.ghost[f].dir != left))
        g.ghost[f].dir = right;

    else if(((abs(xf - 1 - xalvofant) + abs(yf - yalvofant)) < disman) && (g.lab[yf][xf - 1] != 'H') && (g.ghost[f].dir != right))
        g.ghost[f].dir = left;

    else if(((abs(xf - xalvofant) + abs(yf + 1 - yalvofant)) < disman) && (g.lab[yf + 1][xf] != 'H') && (g.ghost[f].dir != up) && ((g.lab[yf + 1][xf] != '-') || (g.ghost[f].mode == dead))) 
        g.ghost[f].dir = down;

    /* escolhe uma casa que nao tenha parede, caso nenhuma o aproxime do pacman */
    else 
    {
        if((g.lab[yf][xf + 1] != 'H') &&(g.ghost[f].dir != left))
            g.ghost[f].dir = right;

        else if((g.lab[yf][xf - 1] != 'H') && (g.ghost[f].dir != right))
            g.ghost[f].dir = left;

        else if((g.lab[yf + 1][xf] != 'H') && (g.ghost[f].dir != up))
            g.ghost[f].dir = down;

        else if((g.lab[yf - 1][xf] != 'H') && (g.ghost[f].dir != down))
            g.ghost[f].dir = up;
    }

    /* Depois de escolher a direçao precisamos registrar a posicao que ele irah : */
    if((g.ghost[f].dir == up) && (g.lab[yf - 1][xf] != 'H'))
        g.ghost[f].pos.y--;

    if((g.ghost[f].dir == down) && (g.lab[yf+1][xf] != 'H') && (g.ghost[f].mode != dead) && (g.lab[yf+1][xf] != '-'))
        g.ghost[f].pos.y++;

    if((g.ghost[f].dir == down) && (g.lab[yf+1][xf] != 'H' && g.ghost[f].mode == dead))
        g.ghost[f].pos.y++;

    if((g.ghost[f].dir == right) && (g.lab[yf] [xf + 1] != 'H')) 
    {
        if(g.ghost[f].pos.y == 10 && g.ghost[f].pos.x == 19) /* Portal que leva para o lado oposto do mapa */
        {
            g.ghost[f].pos.y = 10;
            g.ghost[f].pos.x = 0;
        }

        else
            g.ghost[f].pos.x++;
    }

    if(g.ghost[f].dir == left && g.lab[yf][xf - 1] != 'H')
    {
        if(g.ghost[f].pos.y == 10 && g.ghost[f].pos.x == 0)
        {
            g.ghost[f].pos.y = 10;
            g.ghost[f].pos.x = 19;
        }

        else
            g.ghost[f].pos.x--;
    }

    switch(f)
    {
        case blinky:
        {

        /* imprime a posicao do blinky atual */
            if(g.ghost[blinky].mode == dead)
            {
                mvprintw(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, "~");
                mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 8,NULL);
            }

            else
                mvprintw(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, "B");

            if((g.ghost[blinky].mode == chase) || (g.ghost[blinky].mode == scatter))
                mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1,NULL);

            if(g.ghost[blinky].mode == afraid)
                mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 5,NULL);
            g.ghost[blinky].steps++;
        }

        case pinky:
        {
            /* pinta posicao do pinky */
            if(g.ghost[pinky].mode == dead)
            {
                 mvprintw(g.ghost[pinky].pos.y, g.ghost[pinky].pos.x, "~");
                 mvchgat(g.ghost[pinky].pos.y, g.ghost[pinky].pos.x, 1, A_BOLD, 8,NULL);
            }

            else
                 mvprintw(g.ghost[pinky].pos.y, g.ghost[pinky].pos.x, "P");

            if(g.ghost[pinky].mode == chase)
                mvchgat(g.ghost[pinky].pos.y, g.ghost[pinky].pos.x, 1, A_BOLD, 2,NULL);

            if(g.ghost[pinky].mode == afraid)
                mvchgat(g.ghost[pinky].pos.y, g.ghost[pinky].pos.x, 1, A_BOLD, 5,NULL);
        }

        case inky:
        {
        /* imprime a posicao atual do inky nos diferentes modos */
            if(g.ghost[inky].mode == dead)
            {
                mvprintw(g.ghost[inky].pos.y, g.ghost[inky].pos.x, "~");
                mvchgat(g.ghost[inky].pos.y, g.ghost[inky].pos.x, 1, A_BOLD, 8, NULL);
            }

            else
                mvprintw(g.ghost[inky].pos.y, g.ghost[inky].pos.x, "I");

            if(g.ghost[inky].mode == chase)
                mvchgat(g.ghost[inky].pos.y, g.ghost[inky].pos.x, 1, A_BOLD, 3, NULL);

            if(g.ghost[inky].mode == afraid)
                mvchgat(g.ghost[inky].pos.y, g.ghost[inky].pos.x, 1, A_BOLD, 5, NULL);
        }

        case clyde:
        {
            if(g.ghost[clyde].mode == dead)
            {
                mvprintw(g.ghost[clyde].pos.y, g.ghost[clyde].pos.x, "~");
                mvchgat(g.ghost[clyde].pos.y, g.ghost[clyde].pos.x, 1, A_BOLD, 8,NULL);
            }

            else
                mvprintw(g.ghost[clyde].pos.y, g.ghost[clyde].pos.x, "C");

            if((g.ghost[clyde].mode == chase))
                mvchgat(g.ghost[clyde].pos.y, g.ghost[clyde].pos.x, 1, A_BOLD, 4,NULL);

            if(g.ghost[clyde].mode == afraid)
                mvchgat(g.ghost[clyde].pos.y, g.ghost[clyde].pos.x, 1, A_BOLD, 5, NULL);
        }
    }

    return g;
}


/* ---------------------------------------------------------------------- */
/* Movimento do BLINKY                                                    */
/* ---------------------------------------------------------------------- */

t_game blinky_move(t_game g)
{
    int px, py, bx, by; /* posicao do pacman e do blinky */

    px = g.pacman.pos.x; /* Coordenada x do pacman */
    py = g.pacman.pos.y; /* Coordenada y do pacman */

    bx = g.ghost[blinky].pos.x; /* Coordenada x do blinky */
    by = g.ghost[blinky].pos.y; /* Coordenada y do blinky */

    /* condicao para que o blinky saia de dentro do spawn */
    if((by >= 8) && (by <= 12) && (bx >= 7) && (bx <= 12)) 
    {
        py = 7;
        px = 10;
    }

    if(g.ghost[blinky].mode == afraid  || g.ghost[blinky].mode == scatter) /* se estiver no modo afraid corre para seu lugar favorito */
    {
        py = g.ghost[blinky].starget.y; /* preferred corner (line) */
        px = g.ghost[blinky].starget.x; /* preferred corner (column) */
    }

    /* funcao para mover os fantasmas */

    /* Limpa rastro do fantasma */
    g = limpaposfant(g,blinky,0);

    /* Chama funcao de mover o fantasma */
    if(g.ghost[blinky].mode == dead)
        g = mode_dead(g,blinky);

    else
        g = movefantasma(g,blinky,px,py);

    /* g.ghost[blinky].steps++; */
    return g;

}


/* ---------------------------------------------------------------------- */
/*                            Movimentos do INKY                          */
/* ---------------------------------------------------------------------- */

t_game inky_move(t_game g)
{
    int ix, iy;                                     /* Posicao do fantasma inky */
    int xblinky, yblinky;                           /* Posicao do fantasma blinky */
    int xpinky, ypinky;                             /* Posicao do fantasma pinky */
    int xalvoinky, yalvoinky;                       /* Alvo do inky */
    int xintermediario = 0, yintermediario = 0;     /* Ponto intermediario entre inky e blinky 2 casas a frente do pacman */

    ix = g.ghost[inky].pos.x;  
    iy = g.ghost[inky].pos.y;  

    xblinky = g.ghost[blinky].pos.x;  
    yblinky = g.ghost[blinky].pos.y;  

    xpinky = g.ghost[pinky].pos.x;  
    ypinky = g.ghost[pinky].pos.y;  

    /* Escolhendo o ponto intermediario entre o inky e o blinky que fica 2 casas a frente do pacman */
    switch(g.pacman.dir)
    {

        case up:
            {
                xintermediario = g.pacman.pos.x;   
                yintermediario = g.pacman.pos.y-2;  /* pacman andando para cima, inky 2 casas abaixo dele */
                break;
            }

        case down:
            {
                xintermediario = g.pacman.pos.x;   
                yintermediario = g.pacman.pos.y+2;  /* pacman andando para baixo, inky 2 casas acima dele */
                break;
            }

        case right:
            {
                xintermediario = g.pacman.pos.x+2;  /* pacman andando para a direita, inky 2 casas a direita dele */
                yintermediario = g.pacman.pos.y;  
                break;
            }

        case left:
            {
                xintermediario = g.pacman.pos.x-2;  /* pacman andando para a esquerda, inky 2 casas a esquerda dele */
                yintermediario = g.pacman.pos.y;  
                break;
            }
    }

    /* Se estiver no modo afraid ou scatter deve procurar seu canto favorito */
    if(g.ghost[inky].mode == afraid || g.ghost[inky].mode == scatter) 
    {
        xalvoinky = g.ghost[inky].starget.x;    /* coluna preferida do inky */
        yalvoinky = g.ghost[inky].starget.y;    /* linha preferida do inky */
    }

    /* Caso contrario, reorienta seu alvo */
    xalvoinky = 2 * xintermediario - xblinky;
    yalvoinky = 2 * yintermediario + yblinky;

    /* Condicao para o Inky sair do spawn */
    if((iy >= 8) && (iy <= 12) && (ix >= 7) && (ix <= 12)&& g.pacman.eaten <168) 
        if(!((xpinky > 7) && (xpinky < 12) && (ypinky > 8) && (ypinky < 12)))
        {
            yalvoinky = 7;
            xalvoinky = 10; 
        }

    g = limpaposfant(g,inky,0);     /* limpa possiveis rastors do fantasma inky no mapa */

    /* Se estiver no modo dead */
    if(g.ghost[inky].mode == dead)
        g = mode_dead(g,inky);  /* faz o inky voltar ao spawn */

    else
        g =  movefantasma(g, inky, xalvoinky, yalvoinky);

    return g;
}


/* ---------------------------------------------------------------------- */
/*                          Movimentação do CLYDE                         */
/* ---------------------------------------------------------------------- */

t_game clyde_move(t_game g)
{
    int px, py, cx, cy; /* posicao do pacman e do clyde */
    int xalvoclyde, yalvoclyde;
    px = g.pacman.pos.x;   /* Coordenada x do pacman */
    py = g.pacman.pos.y;   /* Coordenada y do pacman */
    cx = g.ghost[clyde].pos.x;  /* Coordenada x do clyde */
    cy = g.ghost[clyde].pos.y;  /* Coordenada y do clyde */

    if((g.ghost[clyde].mode == afraid) || (g.ghost[clyde].mode == scatter)) /*Ao estar no modo afraid, o fatasma vai para sua zona preferida*/
    {
        xalvoclyde = g.ghost[clyde].starget.x; /*Coordenada x preferido do Clyde*/
        yalvoclyde = g.ghost[clyde].starget.y; /*Coordenada y preferida do Clyde*/
    }

    xalvoclyde = px; /* xalvo recebe o valor de x do pac-man*/  
    yalvoclyde = py; /* yalvo recebe o valor de y do pac-man*/

    if(((abs(px - cx) < 9) && (abs(py - cy) < 9))) /* Se a ditancia entre o clyde e o pac-man for menor ou igual a oito, o clyde vai para regiao favorita*/
    {
        xalvoclyde = 0;
        yalvoclyde = 22;
    }
    else
        if(((abs(px - cx) > 8) && (abs(py - cy) > 8))) /* Se a distancia entre o clyde e o pac-man for maior que oito, o clyde persegue o pac-man*/
        {
            xalvoclyde = px;
            yalvoclyde = py;    
        }
 
    if((cy >= 8) && (cy <= 12) && (cx >= 7) && (cx <= 12) && (g.pacman.eaten < 148)) /* Se a coordenada do clyde estiver dentro das coordenadas da caneta*/
    {                                                                                /* monstro e o do pac-man tiver comido menos que 148 pontos, */                           
        yalvoclyde = 7;                                                              /* o y alvo do clyde sera 7 e */
        xalvoclyde = 10;                                                             /* o x alvo do clyde sera 10.*/
    }                                                                                /* Isso ocorre para que ele saiba o momento de sair da caneta*/

    g = limpaposfant(g,clyde,0); /* funcao limpa os rastros de todos os fantasmas e reseta coordenadas para inicial*/

    if (g.ghost[clyde].mode == dead ) /* Se o fantasma estiver no modo morto,*/
        g = mode_dead(g,clyde);       /* ele atribuira os dados a variavel g atraves da funcao responsavel por esse modo.*/
    else                              /* Caso esse if falhe, ele atribuira os valores da funcao movefantasma para variavel g*/   
        g = movefantasma(g,clyde,xalvoclyde,yalvoclyde); /* A qual sera utilizada para continuidade do laco do jogo*/

    return g; 
} 
 
 
/* ---------------------------------------------------------------------- */
/*                    Movimentos do fantasma PINKY                        */
/* ---------------------------------------------------------------------- */

t_game pinky_move(t_game g)
{
    int px = 0, py = 0, pix, piy; /* posicao do pacman e do pinky */

    /* Escolhe quatro casas a frente do pacman como alvo */
    if((g.pacman.dir == right) || (g.pacman.dir == left))
    {
        px = g.pacman.pos.x + (g.pacman.dir - 2)*4; /* Coordenada x do pacman - 4*/
        py = g.pacman.pos.y; /* Coordenada y do pacman */
    }

    if(g.pacman.dir == up)
    {
        px = g.pacman.pos.x-4;
        py = g.pacman.pos.y-4;
    }

    if(g.pacman.dir == down)
    {
        px = g.pacman.pos.x; /* Coordenada x do pacman */
        py = g.pacman.pos.y + (g.pacman.dir - 1)*4; /* Coordenada y do pacman - 4 */
    }

    if(g.ghost[pinky].mode == afraid  || g.ghost[pinky].mode == scatter) /* se estiver no modo afraid corre para seu lugar favorito */
    {
        py = g.ghost[pinky].starget.y; /* preferred corner (line) */
        px = g.ghost[pinky].starget.x; /* preferred corner (column) */
    }

    pix = g.ghost[pinky].pos.x; /* Coordenada x do pinky */
    piy = g.ghost[pinky].pos.y; /* Coordenada y do pinky */

    if((piy >= 8) && (piy <= 12) && (pix >= 7) && (pix <= 12)) /* condicao para sair do spawn */
    {
        py = 7;
        px = 10;
    }

    g = limpaposfant(g,pinky,0); /*funcao limpa rastro de todos os fantasmas e retesa coordenadas para para inicial*/

    /* Se estive no modo dead chama uma funcao diferente */
    if(g.ghost[pinky].mode == dead)
        g = mode_dead(g,pinky);
    else
        g = movefantasma(g,pinky,px,py);

    return g;
}


/* ---------------------------------------------------------------------- */
/* Modo de jogo change.                                                   */
/* ---------------------------------------------------------------------- */

t_game change_mode(t_game g)
{
    int f;

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky e clyde */
    {
        /* Troca de modos dos fantasmas */
        if((g.ghost[f].mode == afraid) && ((g.time - g.ghost[f].time) > 5)) /* Se ja passou 5 segundos no modo afraid ele volta para o chase */
        {
            g.ghost[f].mode = chase;
            g.ghost[f].time = g.time;
        }
        /* Apos 20 segundos no modo chase ele muda para o modo scatter */
        if((g.ghost[f].mode == chase) && ((g.time - g.ghost[f].time) > 20))  
        {
            g.ghost[f].mode = scatter;
            g.ghost[f].time = g.time;
        }

        /* Apos 7 segundos no modo scatter ele muda para o modo chase */
        if((g.ghost[f].mode == scatter) && ((g.time - g.ghost[f].time) > 7))  
        {
            g.ghost[f].mode = chase;
            g.ghost[f].time = g.time;
        }
    }      
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
/* ---------------------------------------------------------------------- */
