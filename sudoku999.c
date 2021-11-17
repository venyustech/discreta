/***************************************************************************
 *   sudoku999.c                           Version 1.5.20201101.224751     *
 *                                                                         *
 *   Sudoku Solver                                                         *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 *                                                                         *
 *                                 Leandro Dantas Lima                     *
 *                                 Davi Pereira Rio                        *
 *                                 Heitor Jose Andrade De Oliveira         *
 *                                 Gardenia Georgia Barbosa De Siqueira    *
 *                                 Everton Da Silva Paiva                  *
 *                                                                         *
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
 *                                                                         *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 *                                                                         *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Webpage: http://beco.poli.br/ldls3                                    *
 *   Phone: +55 (81) 98861-9469                                            * 
 *                                                                         * 
 *   Davi Pereira Rio                                                      *
 *   Email: davi.pereira.rio@gmail.com                                     *
 *   Webpage: http://beco.poli.br/dprs3                                    *
 *   Phone: +55 (81) 99688-7696                                            *
 *                                                                         *
 *   Heitor Jose Andrade De Oliveira                                       *
 *   Email: heitora7x@gmail.com                                            *
 *   Webpage: http://beco.poli.br/hjados3                                  *
 *   Phone: +55 (81) 99486-0338                                            *
 *                                                                         *
 *   Gardenia Georgia Barbosa De Siqueira                                  *
 *   Email: rabbit.robotica@gmail.com                                      *
 *   Webpage: http://beco.poli.br/ggbdss3                                  *
 *   Phone: +55 (81) 99785-0393                                            *
 *                                                                         *
 *   Everton Da Siva Paiva                                                 *
 *   Email: evertonpaiva01@gmail.com                                       *
 *   Webpage: http://beco.poli.br/edsps3                                   *
 *   Phone: +55 (81) 99525-1102                                            *
 *                                                                         *  
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file sudoku999.c
 * @ingroup GroupUnique
 * @brief sudoku solve
 * @details solve sudoku based on some rules
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
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
 */

/*
 * Instrucoes para compilar:
 *   $gcc sudoku999.c -o sudoku999.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv sudoku999.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include "sudoku999.h" /* To be created for this template if needed */


/* ---------------------------------------------------------------------- */
/* globals */
int testeRapido[9][9][9] = {0};

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funtion main
 * @details This is the main function
 *
 * @param[in] void ?????????
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./sudoku999 -h
 * @endcode
 *
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
int main(void)
{
    int z; /* flag indicativa de deducao com sucesso */
    int sudoku[9][9][9]={{{0}}}; /* todas as 729 possibilidades */

    IFDEBUG("Starting optarg loop...");

    sudoku999_init(sudoku); /* initialization function: set all candidates to true */
    printsudoku(sudoku);
    
    do
    {
        z=0;
        z+=d1(sudoku); //naked single 
        z+=d2(sudoku); // hidden single
        z+=d3(sudoku); // naked pair
        z+=d4(sudoku); // hidden pair 
        z+=d5(sudoku); // pointing candidate 
        z+=d6(sudoku); // claiming candidate 
        z+=d7(sudoku); // x-wing 
  
   } while(z);

    //apaguei???????
    printf(" status: %s\n", statustoa(check(sudoku)));
    printsudoku_debug(sudoku);

    faz_copia_w(sudoku, testeRapido);

    /* backtracking */ 
    if(check(sudoku) > 0)
    {
        printf(" roda backtracking\n");
        z = d8(sudoku);
        printf(" rodou backtracking. Preencheu %d casas.\n", z);
    }

    printf(" status: %s\n", statustoa(check(sudoku)));
    printsudoku(sudoku);


    return check(sudoku);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 *
 * @author Ruben Carlo Benante, Gardenia Georgia, Leandro Dantas Lima
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void sudoku999_init(int sudoku[9][9][9])
{
    int i, j, k;
    IFDEBUG(" sudoku999_init()");
    
    //seta todos como candidatos:
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            for(k = 0; k < 9; k++)
            {
                sudoku[i][j][k] = 1;
            }
        }
    }
    
    get_sudoku999(sudoku);

    int status = check(sudoku);
    printf(" statusi eh: %s\n", statustoa(status));

    return;
}
/****************************************************************************
 * Mostra o status do sudoku                                                *
 ****************************************************************************/                                                        
/* ---------------------------------------------------------------------- */
/**??????????????????
 * @ingroup GroupUnique
 * @brief  cria cadeira de caractere dizendo qual status do jogo.             
 *
 * @param[in] status recebe valor do status do jogo.
 *
 * @return 0 se invalido     
 * @return -1 se completo
 * @return 1-89 se incompleto
 *
 * @author Everton Da Silva Paiva
 *
 */

char* statustoa(int status)
{        
    switch (status)
    {
        case 0:
            return "invalido";
        case -1:
            return "completo";
        default:
            return "incompleto";
    }
}

/* ***********************************************************************
 * le o arquivo de entrada e salva o sudoku na matriz                     *
 * ************************************************************************/
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   le o arquivo de entrada e salva  candidatos na matriz             
 *
 * @param[in] sudoku tabuleiro a ser preenchido
 *
 * @return void       
 *
 * @author Gardenia Georgia Barbosa De Siqueira
 *
 */???????????????

void get_sudoku999(int sudoku[9][9][9])
{
    int LIN = 0, COL = 0, count = 0;
    int MAX_CHAR_FILE = 89;

    while(count != MAX_CHAR_FILE)
    {
        int cellvalue  = fgetc(stdin) - '0';
        if( COL  < 9)
        {
            if(cellvalue > 0)
            {
                dyes(LIN, COL, cellvalue, sudoku);//seta a posicao do valor fixado(cellvalue) como
                                                 //unico candidato na celula, dyes exclui outros candidatos da celula.
            }        
            COL++; // vai pro poximo caractere.
        }
        else
        {
            LIN ++;//senao, vai pra proxima linha e faz a mesma coisa.
            COL = 0;
            if(cellvalue > 0)
            {
                dyes(LIN, COL, cellvalue, sudoku);
            }
        }
        count ++;
    }
    
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   imprime tabulheiro do sudoku.             
 * @author Gardenia Georgia Barbosa De Siqueira
 */

void printsudoku(int sudoku[9][9][9])
{   
    int LIN,COL, cont = 1;
    printf("\n   abc def ghi\n");
    printf("  +-----------+\n");

    for(LIN = 0; LIN < 9; LIN++)
    {
        if((LIN == 3)||(LIN == 6))
            printf("  |---+---+---|\n");
        for(COL = 0; COL < 9; COL++)
        {
            if(COL == 0)
            {
                printf("%d.|%c",cont,celltoa(sudoku[LIN][COL]));// vai imprimir na tela um ponto se tive mais de 1 candidatos,
                                                                //e o candidatos se apenas 1 candidato
                cont++;
            } 
            else if((COL == 2) || (COL == 5) || COL == 8 )
                printf("%c|",celltoa(sudoku[LIN][COL]));
            else
                printf("%c",celltoa(sudoku[LIN][COL]));
        }
        printf("\n");
    }
    printf("  +---+---+---+\n");

    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief  imprime tabuleiro do sudoku com possiveis candidatos
 * @brief  de cada celula.
 *
 * @author Gardenia Georgia Barbosa De Siqueira
 */

void printsudoku_debug(int sudoku[9][9][9])
{
    int LIN, COL, cont = 1;
    char* cell_str;

    printf("\n        a         b         c         d         e         f         g         h         i\n");
    printf("   +-----------------------------------------------------------------------------------------+\n");

    for(LIN = 0; LIN <  9; LIN++)
    {
        if(LIN ==3 || LIN ==6)
            printf("   |-----------------------------+-----------------------------+-----------------------------|\n");
        for(COL = 0; COL  < 9; COL++)
        {
            cell_str = celltoa_debug(sudoku[LIN][COL]); // devolde a celula com os candidatos e ' ' se nao tiver um candidato.
            
            if(COL ==0)
            {
                printf("%d. |%s:", cont, cell_str);
                cont++;
            }
            else if(COL == 2 || COL == 5 || COL == 8)
            {
                printf("%s|", cell_str);
            }
            else
            {
                printf("%s:", cell_str);
            }
            free(cell_str);
        }
        printf("\n");
    }

    printf("   +-----------------------------------------------------------------------------------------+\n");
    
    return;
}

/* **************************************************************************
 *        Transforma o cunjunto de candidatos em um valor unico
 * **************************************************************************/
/* ---------------------------------------------------------------------- */
/**???????????????
 * @ingroup GroupUnique
 * @brief   transforma o cunjunto de candidatos em um caractere unico 
 * @brief   para imprimir             
 *
 * @param[in] candidatos celula com candidatos para analise.
 *
 * @return candidato se existe unico candidato na celula
 * @return '.' se existe mais de um candidato na celula
 *
 * @author Everton Da Silva Paiva
 */

char celltoa(int candidatos[9]) 
{
    int candidato = unico(candidatos);
    if (candidato == 0) 
    {
        return '.';
    } else
    {
        return candidato + '0';
    }
}

/* ---------------------------------------------------------------------- */
/**???????????????
 * @ingroup GroupUnique
 * @brief   transforma o cunjunto de candidatos em um caractere legivel 
 * @brief   para imprimir             
 *
 * @param[in] candidatos celula com candidatos para analise.
 *
 * @return str com os candidatos que existe na celula
 *
 * @author Everton Da Silva Paiva
 */

char* celltoa_debug(int candidatos[9]) {
    char* str = malloc(10 * sizeof(char));
    for (int i = 0; i < 9; i++) {
        if (candidatos[i]) {
            str[i] = i+1 + '0';
            } else {
                str[i] = ' ';
                }
        }
    str[9] = '\0';
    return str;
}

/* ---------------------------------------------------------------------- */
/**???????????????
 * @ingroup GroupUnique
 * @brief   checa se num eh unico ou nao em uma linha.             
 *
 * @param[in] num numero de teste se eh unico e certa linha
 * @param[in] l   linha para verificar se num eh unico ou nao
 * @param[in] w[9][9][9] tabuleiro do sudoku
 *
 * @return   true se num for unico em l
 * @return  false se num nao for unico em l
 *
 * @author Gardenia Georgia Barbosa De Siqueira
 */


int checa_unicoLinha(int l, int num, int w[9][9][9])
{
    int j;

    for(j = 0; j < 9; j++)
       if(unico(w[l][j]) == num)
           return false;
     return true;
}

/* ---------------------------------------------------------------------- */
/**????????????????
 * @ingroup GroupUnique
 * @brief   checa se num eh unico ou nao em uma coluna.             
 *
 * @param[in] num numero de teste se eh unico e certa coluna
 * @param[in] c coluna para verificar se num eh unico ou nao
 * @param[in] w[9][9][9] tabuleiro do sudoku
 *
 * @return   true se num for unico em l
 * @return  false se num nao for unico em l
 *
 * @author Gardenia Georgia Barbosa De Siqueira
 */

int checa_unicoColuna(int c, int num, int w[9][9][9])
{
    int i;

    for(i = 0; i < 9; i++)
       if(unico(w[i][c]) == num)
           return false;
     return true;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   Checa se um candidato existe ou nao num determinado bloco.             
 *
 * @param[in] l Linha da celula testada.
 * @param[in] c Coluna da celula testada.
 * @param[in] num Candidatos para ocuparem as celulas testadas.
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return False ou True (booleano equivalente na forma de inteiro)
 *
 * @author Leandro Dantas Lima
 * @version 20201018.020303
 * @date 2020-10-23
 */

int checa_unicoBloco(int l, int c, int num, int w[9][9][9])
{
    int i, j, bloco_l, bloco_c;
    
    cbloco(l, c, &bloco_l, &bloco_c);

    for(i = bloco_l; i < (bloco_l + 3); i++)
    {
        for(j = bloco_c; j < (bloco_c + 3); j++)
        {
            if(unico(w[i][j]) == num)
            {
                return false;
            }
        }
    }

    return true;
}

/* ---------------------------------------------------------------------- */
/* retorna verdadeiro (1-9) se a celula tem candidato unico */
/**
 * @ingroup GroupUnique
 * @brief   verifica se uma celula tem candidato unico             
 *
 * @param[in] y celula para verificar
 *
 * @return 0 se nao tem unico candidato.
 * @return 1 se o candidato (1 - 9) unico, caso tenha.
 *
 * @author Everton Da Silva Paiva
 */

int unico(int y[9])
{
  int candidato = 0;
  
  for (int i = 0; i < 9; i++) 
      if (y[i]) 
      {
          if (candidato) return 0;
          candidato = i+1;
      }
  return candidato;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique????????
 * @brief   checa se sudoku esta resolvido, incompleto ou invalido             
 *
 * @param[in] w tabuleiro do sudoku com candidatos na terceira dimencao.
 *
 * @return qtdCelulasVazias -1 se resolvido
 * @return qtdCelulasVazias 0 se invalido
 * @return qtdCelulasVazias 1-81 se ha mais de 1 candidatos nas celulas. Celula nao vazia
 *     
 * @author Everton Da Silva Paiva
 */


int check(int w[9][9][9])
{
    int qtdCelulasVazias = 0;// == 0 se apenas 1 candidato,  -1 
    for (int l = 0; l < 9; l++) 
    {
        for (int c = 0; c < 9; c++) 
        {
            int qtdc = totalcandy(w[l][c]); //recebe quantos candidatos ha em cada celula
            if (qtdc == 0) return 0;
            if (qtdc > 1) qtdCelulasVazias++;
        }
    }
   // printf("qtdCelulas vazias: %d\n", qtdCelulasVazias);
    return qtdCelulasVazias == 0 ? -1 : qtdCelulasVazias;
    
}
?????????????????????????
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   checa quantidade de candidatos em uma celula/vetor.             
 *
 * @param[in] y celula a contar quantos candidatos ha dentro dela.
 *
 * @return qtd quantidade de candidatos na celula      
 *
 * @author Everton Da Silva Paiva
 */

int totalcandy(int y[9]) 
{
    int qtd = 0;
    for (int i = 0; i < 9; i++) 
    {
        qtd += y[i];
    }
    return qtd;
}
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   exclui os candidatos da celula, menos o n dado.           
 *
 * @param[in] n numero para ficar como unico em celula
 * @param[in] l linha onde se encontra a celula de n
 * @param[in] c coluna onde se encontra a celula de n
 *
 * @return z indica que houve alteracao       
 *
 * @author Everton Da Silva Paiva
 *
 */

int dyes(int l, int c, int n, int w[9][9][9]) 
{
    int z = 0;
    if (w[l][c][n-1] == 0) z++;
    else z--; // para compensar o z++ a seguir
    for (int i = 0; i < 9; i++) 
    {
        if (w[l][c][i]) z++;
        w[l][c][i] = 0;
    }
    w[l][c][n-1] = 1;
    return z;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief  Exclui o candidato n dado da cleula.              
 *
 * @param[in] n eh o candidato para remover da celula
 * @param[in] l linha onde queremos excluir n
 * @param[in] c coluna onde queremos excluir n
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return 1 se houver remocao
 * @return 0 se nao houver remocao
 *
 * @author Everton Da Silva Paiva
 */

int dnot(int l, int c, int n, int w[9][9][9]) 
{
    if (w[l][c][n-1]) 
    {
        w[l][c][n-1] = 0;
        return 1;
    }
    return 0;
}
//apagar ??????????????????????????
/* ************************************************************************ 
 * Funcao que copia o candidato
 * ************************************************************************/
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   cria vetor com a celula especifica dada            
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

void copycandy(int w[9][9][9], int l, int c, int y[9]) 
{
        for (int i = 0; i < 9; i++) 
        {
            y[i] = w[l][c][i];
        }
}

/* ************************************************************************ 
 * pega size candidatos de candidatos[9] e coloca em tuple, retorna tuple
 *                                                         Everton
 * ***********************************************************************/
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   devolve vetor com numeros que há ocorrencias, 
 * @brief   quando acaba a ocorrencia, preenche o resto do vetor com -1
 *
 * @param[in] candidatos para verificacao
 * @param[in] size qtd maxima de candidatos possiveis
 *
 * @return tuple[size] com numeros onde ha apenas 1 ocorrencia       
 *
 * @author Everton Da Silva Paiva
 */
//???????????????????????/
int* extract_tuple(int candidatos[9], int size) 
{   //devolte vetor[9] com numeros que há ocorrencia, quando
    // acaba a quantidade de ocorrencias, preenche o resto do vetor com -1
    int* tuple = (int*) malloc(size * sizeof(int));
    int extracted = 0;
    for (int i = 0; i < 9 && extracted < size; i++) 
    {
        if (candidatos[i] == 1) 
        {
            tuple[extracted] = i;
            extracted++;
        }
    }
    while (extracted < size) 
    {
        tuple[extracted++] = -1;
    }
    return tuple;
}

/* ************************************************************************ 
 * Funcao que verifica se o candidato eh o msm
 * ***********************************************************************/
/* ---------------------------------------------------------------------- */
/**apagar????????????????????????????
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int samecandy(int candidatosA[9], int candidatosB[9]) 
{
    return same_tuple(candidatosA, candidatosB, 9);
}

/* ************************************************************************
 * Funcao que verifica se eh a msm tupla
 * ***********************************************************************/
/* ---------------------------------------------------------------------- */
/**//?????????????????????
 * @ingroup GroupUnique
 * @brief   funcao que verifica se eh a mesma tupla             
 *
 * @param[in] tupleA tupla para verificacao
 * @param[in] tupleB tupla para verificacao.
 * @param[in] size tamanho das tuplas pra verificacao.
 *
 * @return 0 se nao sao as mesmas tuplas 
 * @return 1 se sao as mesmas tuplas
 *
 * @author Everton Da Silva Paiva
 */

int same_tuple(int* tupleA, int* tupleB, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (tupleA[i] != tupleB[i]) return 0;
    }
    return 1;
}

/* ************************************************************************ 
 * Funcao que verifica se uma tuplaA eh subtupla de tuplaB
 * ************************************************************************/
/* ---------------------------------------------------------------------- */
/**????????????????????????????????
 * @ingroup GroupUnique
 * @brief   verifica se tuplaA eh subtupla de tupleB             
 *
 * @param[in] tupleA tupla para verificar se é subtupla
 * @param[in] tupleB tupla para verificar se é subtupla
 * @param[in] size tamanho de tupleB
 *
 * @return 0 se nao eh subtupla
 * @return 1 se eh subtupla
 *
 * @author Everton Da Silva Paiva
 */

int sub_tuple(int* tupleA, int* tupleB, int size) 
{
    int i = 0, j = 0;
    while (j < size) 
    {
        if (tupleA[i] == -1) return 1; // entra aqui se tupleA acabou antes de tupleB
        while (tupleA[i] > tupleB[j]) 
        {
            j++;
            if (j >= size) return 0;
        }
        if (tupleA[i++] != tupleB[j]) return 0;
    }
    return 1;
}

/* ************************************************************************
 * Funcao que verifica se o candidato ocorreu
 * ***********************************************************************/
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief usada para saber se coordenada dada eh uma coordenada do candidato dado. 
 * @brief usada para evitar deletar a si mesmo
 *
 * @param[in] candidato candidato para analise.
 * @param[in] coord coordenada para analise.
 *
 * @return 1 se for coordenada de candidato
 * @return 0 se nao for coordenada de candidato
 *
 * @author Everton Da Silva Paiva
 */

int candidato_ocorre(Candidato* candidato, Coordenadas* coord) 
{
    for (int i = 0; i < candidato->count; i++) 
    {
        if (candidato->coords[i].l == coord->l &&
                candidato->coords[i].c == coord->c) 
        {
            return 1;
        }
    }
    return 0;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   cria um candidato novo.             
 *
 * @param[in] size tamanho do candidato.
 *
 * @return cc candidato novo criado      
 *
 * @author Everton Da Silva Paiva
 */

ConjuntoContador* novo_cc(int size) 
{
    ConjuntoContador* cc = malloc(sizeof(ConjuntoContador));
    cc->size = size;
    cc->len = 0;
    cc->max = 0;
    cc->argmax = -1;
    for (int i = 0; i < 9; i++) 
    {
        cc->candidatos[i].tupla = (int*) calloc(size, sizeof(int));
        cc->candidatos[i].count = 0;
    }
    return cc;
}


//Funcao insere candidatos
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   faz com que o ConjuntoContador seja de fato um conjunto.
 * @brief primeiro faz um loop em todos os elementos do conjunto buscando
 * @brief todos os elementos do conjunto. Para manter o conjunto sem
 * @brief elementos repetidos
 *
 * @param[in] cc candidato novo para inserir no ConjuntoContador.
 * @param[in] tuple tupla para inserir no ConjuntoContador.
 * @param[in] l,c coordenadas de analise.
 *
 * @return 0 se ja tiver o elemento em ConjuntoContador
 * @return 1 se nao tinha o elemento em ConjuntoContador
 *
 * @author Everton Da Silva Paiva
 */
//????????????????????
int cc_insere(ConjuntoContador* cc, int* tuple, int l, int c) {
    for (int i = 0; i < cc->len; i++) {
        if (same_tuple(cc->candidatos[i].tupla, tuple, cc->size)) {  //se tupla ja estava presente ele so vai atualizar a entrada
            Coordenadas coord;
            coord.l = l;
            coord.c = c;
            if (candidato_ocorre(&(cc->candidatos[i]), &coord)) {
                return 0;
            }
            int contagem = cc->candidatos[i].count + 1;//incrementa contador para dizer que encontrou mais uma ocorrencia daquela entrada
            cc->candidatos[i].coords[contagem-1] = coord;//salva onde a entrada ocorreu
            cc->candidatos[i].count = contagem;
            if (contagem > cc->max) {
                cc->argmax = i;
                cc->max = contagem;
            }
            return 1;
        }
    }
    if (9 == cc->len) return 0;
    for (int i = 0; i < cc->size; i++) {
        cc->candidatos[cc->len].tupla[i] = tuple[i];
    }
    cc->candidatos[cc->len].coords[0].l = l;
    cc->candidatos[cc->len].coords[0].c = c;
    cc->candidatos[cc->len].count = 1;
    cc->max = 1;
    cc->argmax = 0;
    cc->len++;
    return 1;
}


//Funcao que destroi candidatos
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   Funcao para limpeza de memoria          
 *
 * @param[in] cc conjuntocontador
 *
 * @returnvoid       
 *
 * @author Everton Da Silva Paiva
 *
 */

void destroy_cc(ConjuntoContador* cc) 
{
    for (int i = 0; i < 9; i++) 
    {
        free(cc->candidatos[i].tupla);
    }
    free(cc->candidatos);
    cc = NULL;
}


//Funcao que soma os elementos
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   transforma array para string, somando 1 em cada elemento             
 *
 * @param[in] arr array para analise
 * @param[in] size 
 *
 *
 * @return str string que recebeu valores da array       
 *
 * @author Everton Da Silva Paiva
 *
 */
/???????????????
char* arrtoa(int* arr, int size) 
{
    // array pra string, somando em cada elemento
    if (size < 1) return NULL;
    int strlen = size * 2 * + 2, j = 0;
    char* str = (char*) malloc(strlen * sizeof(char));
    str[j++] = '(';
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == -1) break;
        str[j++] = arr[i]+1 + '0' ;
        if (i != (size-1)) 
        {
            str[j++] = ',';
        }
    }
    str[j++] = ')';
    str[j] = '\0';
    return str;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   troca a por b.             
 *
 * @param[in] a variavel para troca
 * @param[in] b variavel para troca
 *
 * @return void       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

void swap(int* a, int* b) 
{
    int c = *a;
    *a = *b;
    *b = c;
}//????????????????????


//dnot geral no bloco, exceto nas coordenadas contidas em coords_ignore
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   exclui o candidato n dado do bloco.             
 *
 * @param[in] n candidato a excluir do bloco.
 * @param[in] w tabuleiro do jogo.
 * @param[in] ql linha inicial do bloco.
 * @param[in] qc coluna iinicial do bloco.
 *
 * @return z flag que indica se excluiu algum candidato       
 *
 * @author Everton Da Silva Paiva
 */
//?????????????????????????????
int dnot_bloco(int ql, int qc, int n, int w[9][9][9],
        Coordenadas* coords_ignore, int coords_len) {
    int z = 0;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            int ignorar = 0;
            for (int k = 0; k < coords_len; k++) 
            {
                if ((coords_ignore[k].l == ql+i) &&
                        (coords_ignore[k].c == qc+j)) 
                {
                    ignorar = 1;
                    break;
                }
            }
            if (!ignorar)
                z += dnot(ql+i, qc+j, n, w);
        }
    }
    return z;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   Insere todos os candidatos possiveis numa linha ou coluna (struct).
 *
 * @param[in] l Linha, ou coluna, na qual devem ser inseridos os possiveis candidatos.
 * @param[in] direcao Direcao que o laco deve rodar ('l' -> linha, 'c' -> coluna)
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return Conjunto   
 *
 * @author Leandro Dantas Lima
 * @version 20201026.191705
 * @date 2020-10-30
 */

ConjuntoContador* batch_cc_insere(int l, char direcao, int w[9][9][9])
{
    int c, k;
    ConjuntoContador* conjunto = novo_cc(1);

    for(c = 0; c < 9; c++)
    {
        if(direcao == 'c') 
            swap(&l, &c);

        for(k = 0; k < 9; k++)
        {
            if(w[l][c][k])
            {
                int tuple[1];
                tuple[0] = k;
                cc_insere(conjunto, tuple, l, c);
            }
        }

        if(direcao == 'c') 
            swap(&l, &c); /* swap back */
    }
    return conjunto;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Grava todos os candidatos que aparecem exatamente n vezes numa linha/coluna.
 *
 * @param[in] l Linha, ou coluna, varrida (ponteiro para inteiro).
 * @param[in] n Quantidade de ocorrencias de certo candidato (no caso do x-wing --> n=2).
 * @param[in] matches Vetor de coordenadas dos candidatos que ocorrem exatamente n vezes.
 * @param[in] direcao Qual "direcao" o laco esta rodando ('l' -> linha; 'c' -> coluna).
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return Match_len (se encontrou um candidato n vezes) ou -1 (se nao encontrou nenhum)
 *
 * @author Leandro Dantas Lima
 * @version 20201026.191705
 * @date 2020-10-30
 */

int cc_find(int *l, int n, Candidato* matches, char direcao, int w[9][9][9])
{
    int i, j;

    for(; *l < 9; (*l)++)
    {
        int match_len = 0;
        ConjuntoContador* cc = batch_cc_insere(*l, direcao, w);

        for(i = 0; i < cc->len; i++)
        {
            Candidato candidato;
            int count = cc->candidatos[i].count;

            if(count == n)
            {
                candidato.tupla = (int*) malloc(sizeof(int));
                candidato.tupla[0] = cc->candidatos[i].tupla[0];

                for(j = 0; j < count; j++)
                    candidato.coords[j] = cc->candidatos[i].coords[j];
                
                matches[match_len++] = candidato;
            }
        }
        destroy_cc(cc);
        
        if(match_len != 0)
        {
            (*l)++;
            return match_len;
        }
    }
    return -1;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   devolve a coordenada inicial do bloco para uma linha e coluna dada             
 *
 * @param[in] l linha para analise.
 * @param[in] c coluna para analise.
 * @param[in] ql onde salvaremo linha inicial do bloco.
 * @param[in] qc onde salvaremos coluna inicial do bloco
 *
 *
 * @return qc e ql       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int cbloco(int l, int c, int *ql, int *qc) 
{
    *ql = l / 3 * 3;
    *qc = c / 3 * 3;
    return (0 <= *ql) && (*ql < 9) && (0 <= *qc) && (*qc < 9);
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   retorna coordenadas de bum bloco dado            
 *
 * @param[in] n numero do bloco
 * @param[in] ql onde salvaremos linha inicial
 * @param[in] qc onde salvaremos coluna inicial
 *
 * @return void       
 *
 * @author Everton Da Silva Paiva
 */

void bloco(int n, int *ql, int *qc) 
{
    *ql = n / 3 * 3;
    *qc = n % 3 * 3;
}


/* ---------------------------------------------------------------------- */
/* funcoes de deducao de d1 a d8 */


/* ---------------------------------------------------------------------- */
/* naked single : peladao */
/* d1 : naked sigle
 * limpa linha: confronta cada valor ja deduzido com sua linha (horizontal) limpando falsas possibilidades
 *
 * Explicacao:
 *      percorre todas as 9x9 celulas da grade (cada celula contem 9 possibilidades)
 *      Para cada celula que achar que tiver o valor ja determinado (unica possibilidade), 
 *      percorre a horizontal que ela pertence e remove nas outras celulas dessa horizontal 
 *      a possibilidade deste valor que nao pode ser repetido
 */

/* 1- naked single : peladao : 
--> quando as possibilidades de uma celula se reduzem a um unico numero, ele e o valor correto.

   se um numero foi deduzido, remove-se o mesmo como candidato nas outras celulas da mesma linha, coluna ou bloco

algoritmo: fixa celula e gira digito, comparando-o com os grupos (linha, coluna, bloco), ate reduzir suas possibilidades a apenas uma.

 */
int d1(int w[9][9][9])
{ 
    int z=0;
  
    printf("iniciando d1\n");
    z+=d1l(w); // naked single : line 
    z+=d1c(w); // naked single : column 
    z+=d1b(w); // naked single : block 
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden single : peladao escondido */
/* d2: procura um numero que aparece apenas uma vez na linha */
/* Explicacao:
 *      Procura, para cada celula, uma que nao tem valor definido e chame-a de celula com n candidatos.
 *      Percorre a horizontal da celula com n candidatos e remove candidatos que se repetem
 *      Ao final, se restar apenas um candidato na celula fixada inicialmente, este eh o valor
 *      correto da celula.
 * 
 *      Exemplo, o valor 7 para a celula a7. Inicialmente os candidatos sao 1, 3, 6 e 7
 *      Percorrendo a horizontal e removendo os repetidos sobra apenas o 7 como possibilidade
 
       a   b   c   d   e   f   g   h   i
     +===========+===========+===========+
     |1 3:1 3:   |1  :  3:   |   :   : 2 |
  7  |  6:  6:   |   :  6:4 6| 5 :   :   |
     |7  :   :  9|   :   :   |   : 8 :   |
     +-----------+-----------+-----------+
 */

/* 2- hidden single : peladao escondido :
--> mesmo que tenham mais candidatos, se em uma celula tem um valor que nao aparece nas outras da mesma linha, coluna ou bloco, ele eh o solteirao escondido.

 * uma celula com multiplos candidatos eh chamada de solteirao se um dos candidatos so
 * aparece em um local na linha, coluna ou bloco. Ele e a solucao e os outros candidatos podem ser eliminados
 
algoritmo: 
 
 */
int d2(int w[9][9][9])
{
    int z=0;
    printf("iniciando d2\n");
    printf("\n\niniciando d2l\n");
    z+=d2l(w); // hidden single : line 
    z+=d2c(w); // hidden single : column 
    z+=d2b(w); // hidden single : block 
    return z;
}

/* ---------------------------------------------------------------------- */
/* naked pair : dupla pelada */
/* naked pair:
 *
 * para cada conjunto de 2 celulas
 * quando tiverem os mesmo 2 candidatos e apenas eles
 * retira das outras celulas do grupo esses candidatos
 *
 * naked tuple: (todos grupos: linha, coluna e bloco)
 * N>1 celulas exatamente iguais com N candidatos cada
 *
 * >> retira das outras celulas do grupo esses numeros
 *
 * Upgrade: N>1 celulas com APENAS N candidatos em comum
 *
 */

/* 3- naked pair : dupla pelada : 

 * duas celulas com o mesmo par de candidatos e apenas ele, chama-se dupla pelada.
 * os valores do par sao removidos do grupo (bloco, linha ou coluna) em que se encontram
 * sobrando somente a duvida do par
 */

/* Opcional: 3.b- naked triple : tripla pelada : ocorre quando 3 celulas em uma mesma linha, coluna ou bloco contem os
 * apenas os mesmos tres candidatos; ou um subconjunto deles. Todas as aparencias dos 3 candidatos podem ser
 * eliminadas do resto do bloco, linha ou coluna
 */


/* Opcional: 3.c- naked quad : quatro pelados : quatro celulas com os mesmos quatro candidatos ou subconjuntos, em uma mesma
 * linha, coluna ou bloco, implicam que os mesmos candidatos em outras celulas no bloco ou seguindo a linha ou
 * coluna respectiva podem ser eliminados.
 */
int d3(int w[9][9][9])
{
    int z=0;
    printf("iniciando d3\n");
    for (int i = 2; i < 5; i++) {
        z+=d3l_(w,i); // naked pair : line 
        z+=d3c_(w,i); // naked pair : column 
        z+=d3b_(w,i); // naked pair : block
    }
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : dupla escondida */
/*
 * Se X candidatos em um grupo estao apenas em X celulas compartilhadas, pode-se limpar
 * os outros candidatos dessas X celulas, sobrando apenas os candidatos repetidos.
 * Afeta: apenas as celulas da tupla.
 *
 * O par escondido quando limpo se transforma em par pelado
 *
 */

/* 4- hidden pair : dupla escondida
 *
 * quando dois candidatos aparecem em apenas duas celulas, em um grupo (linha, coluna ou bloco)
 * mesmo que estas celulas estejam com mais candidatos
 * os demais podem ser eliminados dessas duas celulas, restando assim uma dupla pelada.
 */
int d4(int w[9][9][9])
{
    int z=0;
    z+=d4l(w); // hidden pair : line 
    z+=d4c(w); // hidden pair : column 
    z+=d4b(w); // hidden pair : block 
    return z;
}

/* ---------------------------------------------------------------------- */
/* pointing candidate : candidato dedo-duro */
/* pointing pair : dedo-duro
 * quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 5- pointing pair : dedo-duro : quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 */
int d5(int w[9][9][9])
{
    int z=0;
    z+=d5l(w); // pointing candidate : line 
    z+=d5c(w); // pointing candidate : column 
    return z;
}

/* ---------------------------------------------------------------------- */
/* claiming candidate : candidato exigente */
/* claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 6- claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 */
int d6(int w[9][9][9])
{
    int z=0;
    z+=d6l(w); // claiming candidate : line 
    z+=d6c(w); // claiming candidate : column 
    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing : cruzamento em x */

/* 7- x-wing : cruzamento : quando um candidato aparece em quatro celulas que formam os cantos de um retangulo ou quadrado,
 * e aparece somente em duas celulas para cada uma das linhas, o candidato pode ser removido das colunas.
 * Idem para o inverso entre colunas e linhas.
 */
int d7(int w[9][9][9])
{
    int z=0;
    z+=d7l(w); // x-wing : line 
    z+=d7c(w); // x-wing : column 
    return z;
}

/* ---------------------------------------------------------------------- */
/* backtracking - retroanalise */
/* 8- Backtraking: algoritmo recursivo que tenta todas possibilidades */
int d8(int w[9][9][9])
{
    int z=0;
    z += tenta8(w, 0, 0); // backtracking recursive 
    return z;
}



/* ---------------------------------------------------------------------- */
/* deducoes divididas por grupo: linha, coluna e bloco */


/* ---------------------------------------------------------------------- *
 * naked single : line                                                    *
 * naked single: confronta cada valor ja deduzido com sua                 *
 *               linha (horizontal)                                       *
 *                                                 -Gardenia Georgia      *
 * ---------------------------------------------------------------------- */
 
int d1l(int w[9][9][9])
{
    int l, c, // indices para rodar o mapa inteiro 
        j, // as colunas a percorrer na linha l a limpar 
        n, // o numero unico na linha l 
        z=0; // retorna verdadeiro se alterou w 
    
    for(l=0; l<9; l++)
    {
        for(c=0; c<9; c++)
        {
            if((n=unico(w[l][c])))// n recebe o candidato unico se houve, 0 se nao houver(nesse caso nao entra no if)
            {
                //se esta aqui tem um naked na linha
                //agora podemos remove esse candidato das outras celulas do bloco
                int mod =0;
                for(j=0; j<9; j++)
                { // todas colunas da linha l
                    if(j ==c)
                        continue;
                    mod+=dnot(l,j,n,w);//exclui o candidato n dado da linha
                }
                z += mod;
                if(mod)
                    printf("d1l: naked single(%d), (%d, %d). valor %d\n",l+1, l+1, c+1, n);
            }
        }
    }
                  
    return z>0;
}

/* ---------------------------------------------------------------------- *
 * naked single : column                                                  * 
 * naked single: confronta cada valor ja deduzido                         *
 *               com sua coluna (vertical)                                *
 *                                                 -Gardenia Georgia      *
 * ---------------------------------------------------------------------- */

int d1c(int w[9][9][9])
{
    int l, c, // indices para rodar o mapa inteiro 
        j, // as colunas a percorrer na linha l a limpar 
        n, // o numero unico na linha l 
        z=0; // retorna verdadeiro se alterou w 
    
    for(c=0; c<9; c++)
    {
        for(l=0; l<9; l++)
        {
            if((n=unico(w[l][c]))) //recebe candidato unico se a celula tive apenas 1 candidato nela.
            {
                //se esta aqui eh porque tem um naked single coluna
                //agora podemos remover esse candidato das outras celulas da coluna
                int mod = 0;
                for(j = 0; j < 9; j++)
                { //todas as linhas da coluna c
                    if( j == l)continue;
                    mod+=dnot(j,c,n,w);//exclui o candidato n dado da coluna
                }
                z += mod;
               if(mod)                      // Nr   Posicao        valor = = 
                    printf("d1c: naked single (%d), (%d, %d). valor %d\n",c+1, l+1, c+1, n);
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- *
 * naked single : block                                                   *
 * naked single: confronta cada valor ja deduzido com seu                 *
 *               quadrado (bloco)                                         *
 *                                                  -Gardenia Georgia     *
 * ---------------------------------------------------------------------- */

int d1b(int w[9][9][9])
{
    int z = 0, l, c, n;
    
    for(int b = 0; b < 9; b++)
    {
        bloco(b, &l, &c);
        for(int i = 0; i < 3; i++)
        {
            //percorrendo linhas do bloco: l+i
            for(int j = 0; j < 3; j++)
            {
                //percorrendo colunas do bloco: c+j
                if((n = unico(w[l+i][c+j])))
                {
                    int mod = 0;
                    //se esta aqui eh porque tenho um naked single nesse bloco
                    //agora podemos remove esse canditado das outras celulas do bloco
                    //inicia remocao tupla desse bloco.
                    for(int ii = 0; ii < 3; ii++)
                    {
                        for(int jj = 0; jj <3; jj++)
                        {
                            //se nao for uma das celulas fixadas...
                            if((ii == i) && (jj == j))
                                continue;
                            mod += dnot(l + ii, c + jj, n, w);
                        }
                    }
                    z += mod;
                    if(mod){
                        printf("d1b: naked single (%d), (%d,%d). valor %d\n", b+1, l+i, c+j+1, n);
                    }
                }
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- *
 * hidden single : linha                                                  *
 * hidden single: procura numa horizontal um numero com apenas uma        *
 *                celula possivel de estar                                *
 *                                              -Gardenia Georgia         *
 * ---------------------------------------------------------------------- */

int d2l(int w[9][9][9])
{   
    int l, c, z=0, n;
    int* hidden_singles;
    for(l = 0; l < 9; l++)
    {
        int candy[9] = {0};// cada posicao de candy salva a quantidade de ocorrencia
                           //de um numero em cada posiçao candy['[i] 0 a 8.
                           //Se for hidden tem 1 ocorrencia apenas.
        for(c = 0; c < 9; c++)
        {
            for(int i = 0; i < 9; i++) 
                candy[i] += w[l][c][i]; // salva a quantidade de ocorrencia de 
                                        //um numero salva nas posiçoes de candy de 0 a 8
        }
        hidden_singles = extract_tuple(candy, 9); // recebe vetor[9] com numeros que ha apenas uma ocorrencia,
                                                  //quando acaba a quantidade de ocorrencias termina de preenches com -1
        for( int i = 0; i < 9; i++)
        {
            n = hidden_singles[i]; // recebe o iro candidato com apenas 1 ocorrencia, 
                                   // recebido em hidden_singles pela extract_tuple
            if(n == -1)
            {  // == - quando extracted_tuple nao achou mais nenhuma ocorrencia, 
               //entao preencheu um resto do vetor com 9, entao para de rodar o laço
                printf("dentro do  break  i = %i,  l = %d\n", i, l);
                break;
            }
            for(c = 0; c < 9; c++)
            {
                // se chegamos aqui, achamos um candidato com apenas 1 ocorrencia na linha
                // podemos remover os outros candidatos que estao nessa cleula:
                if(w[l][c][n])
                {
                    int mod = dyes(l,c,n+1,w); // remove candidatos que estao nessa celula de (n+1)
                    z += mod;
                    if(mod)
                    {
                       printf("d2l: hidden single (%d). valor %d. \n", l+1, n+1);
                    }
                }
            }
        }
        free(hidden_singles);
        hidden_singles = NULL;
    }
    return z>0;
}

/* ---------------------------------------------------------------------- *
 * hidden single : column                                                 *
 * hidden single: procura numa vertical um numero                         * 
 * com apenas uma celula possivel de estar                                *
 *                                                 - Gardenia Georgia     *
 * ---------------------------------------------------------------------- */

int d2c(int w[9][9][9])
{
    int l, c,z = 0,  n; 
    int* hidden_singles;

    for(c = 0; c < 9; c++)
    {
        int candy[9] = {0};
        for(l = 0; l < 9; l++)
        {
            for(int i = 0; i < 9; i++)
            {
                candy[i] += w[l][c][i];
            }
        }
        hidden_singles = extract_tuple(candy, 9);

        for(int i = 0; i < 9; i++)
        {
            n = hidden_singles[i];
            if(n == -1) break;
            for(l = 0; l < 9; l++)
            {
                if(w[l][c][n])
                {
                    int mod = dyes(l, c, n+1, w);
                    z += mod;
                    if(mod)
                    {
                        printf("d2c: hidden single (%d). valor %d. \n", c+1, n+1);
                    }
                }
            }
        }
        free(hidden_singles);
        hidden_singles = NULL;
    }
    return z>0;
}

/* ---------------------------------------------------------------------- * 
 * hidden single : block                                                  *
 * hidden single: procura num bloco um numero com apenas                  *
 *                uma celula possivel de estar                            *
 *                                               -Gardenia Georgia        *
 * ---------------------------------------------------------------------- */

int d2b(int w[9][9][9])
{
    int b, l=0, c=0,z=0,n; 
    int* hidden_singles;
    
    for(b = 0; b < 9; b++)
    {
        int candy[9] = {0};
        bloco(b, &l, &c);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                for(int k = 0; k < 9; k++)
                {
                    candy[k] += w[l+i][c+j][k];
                }
            }
        }
        hidden_singles = extract_tuple(candy,9);
        for(int k = 0; k <9; k++)
        {
            n = hidden_singles[k];
            if(n == -1) break;
            for(int ii = 0; ii < 3; ii++)
            {
                for(int jj = 0; jj < 3; jj++)
                {
                    if(w[l+ii][c+jj][n])
                    {
                        int mod = dyes(l+ii, c+jj, n+1, w);
                        z += mod;
                        if(mod)
                        {
                            printf("d2b: hidden single (%d). valor %d. \n", b +1, n +1);
                        }
                    }
                }
            }
        }
        free(hidden_singles);
        hidden_singles = NULL;
    }
    
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : line */
/* naked tuple (pair/triple/quad): remove candidatos fora do par, no grupo */

/* ************************************************************************  
 *                                Everton                                 *
 * ***********************************************************************/ 
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d3l_(int w[9][9][9], int size) {
    int z = 0;
    ConjuntoContador* conjunto;
    int* tuple;
    for (int l = 0; l < 9; l++) {
        conjunto = novo_cc(size);
        for (int c = 0; c < 9; c++) {
            tuple = extract_tuple(w[l][c], size);
            int tc = totalcandy(w[l][c]);
            if (conjunto->max == size) {
                // naked_tuple encontrada
                Candidato candidato = conjunto->candidatos[conjunto->argmax];
                // tenho uma naked_tuple
                // inicia remocao dessa linha
                for (int cc = 0; cc < 9; cc++) {
                    Coordenadas coord;
                    coord.l = l;
                    coord.c = cc;
                    if (candidato_ocorre(&candidato, &coord)) continue; // eh celula fixada
                    int mod = 0;
                    for (int k = 0; k < size; k++) {
                        mod += dnot(coord.l, coord.c, candidato.tupla[k]+1, w);
                    }
                    z += mod;
                    if (mod) {
                        char* str = arrtoa(candidato.tupla, size);
                        printf("d3l: %d-naked_tuple (%d). valor: %s\n",
                                size, l+1, str);
                        free(str);
                        str = NULL;
                    }
                }
            } else if (tc == size) {
                int inseriu = cc_insere(conjunto, tuple, l, c);
                if (inseriu) {
                    c = -1;
                    free(tuple);
                    tuple = NULL;
                    continue;
                }
            } else if (conjunto->len > 0 && (1 < tc && tc < size)) {
                for (int i = 0; i < conjunto->len; i++) {
                    if (sub_tuple(tuple, conjunto->candidatos[i].tupla, size)) {
                        cc_insere(conjunto, conjunto->candidatos[i].tupla, l, c);
                    }
                }
            }
            free(tuple);
            tuple = NULL;
        }
        destroy_cc(conjunto);
    }
    return z > 0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : column */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d3c_(int w[9][9][9], int size) {
    int z = 0;
    ConjuntoContador* conjunto;
    int* tuple;
    for (int c = 0; c < 9; c++) {
        conjunto = novo_cc(size);
        for (int l = 0; l < 9; l++) {
            tuple = extract_tuple(w[l][c], size);
            int tc = totalcandy(w[l][c]);
            if (conjunto->max == size) {
                // naked_tuple encontrada
                Candidato candidato = conjunto->candidatos[conjunto->argmax];
                // tenho uma naked_tuple
                // inicia remocao dessa coluna
                for (int ll = 0; ll < 9; ll++) {
                    Coordenadas coord;
                    coord.l = ll;
                    coord.c = c;
                    if (candidato_ocorre(&candidato, &coord)) continue; // eh celula fixada
                    int mod = 0;
                    for (int k = 0; k < size; k++) {
                        mod += dnot(coord.l, coord.c, candidato.tupla[k]+1, w);
                    }
                    z+=mod;
                    if (mod) {
                        char* str = arrtoa(candidato.tupla, size);
                        printf("d3c: %d-naked_tuple (%d). valor: %s\n",
                                size, l+1, str);
                        free(str);
                        str = NULL;
                    }
                }
            } else if (tc == size) {
                int inseriu = cc_insere(conjunto, tuple, l, c);
                if (inseriu) {
                    l = -1;
                    free(tuple);
                    tuple = NULL;
                    continue;
                }
            } else if (conjunto->len > 0 && ((1 < tc && tc < size))) {
                for (int i = 0; i < conjunto->len; i++) {
                    if (sub_tuple(tuple, conjunto->candidatos[i].tupla, size)) {
                        cc_insere(conjunto, conjunto->candidatos[i].tupla, l, c);
                    }
                }
            }
            free(tuple);
            tuple = NULL;
        }
        destroy_cc(conjunto);
    }
    return z > 0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : block */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Everton Da Silva Paiva
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d3b_(int w[9][9][9], int size) {
    int z = 0, l, c;
    ConjuntoContador* conjunto;
    int* tuple;
    for (int b = 0; b < 9; b++) {
        bloco(b, &l, &c);
        conjunto = novo_cc(size);
superbreak:
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tuple = extract_tuple(w[l+i][c+j], size);
                int tc = totalcandy(w[l+i][c+j]);
                if (conjunto->max == size) {
                    // naked_tuple encontrada
                    Candidato candidato = conjunto->candidatos[conjunto->argmax];
                    for (int ii = 0; ii < 3; ii++) {
                        for (int jj = 0; jj < 3; jj++) {
                            Coordenadas coord;
                            coord.l = l+ii;
                            coord.c = c+jj;
                            if (candidato_ocorre(&candidato, &coord)) continue; // eh celula fixada
                            int mod = 0;
                            for (int k = 0; k < size; k++) {
                                mod += dnot(coord.l, coord.c, candidato.tupla[k]+1, w);
                            }
                            z += mod;
                            if (mod) {
                                char* str = arrtoa(candidato.tupla, size);
                                printf("d3b: %d-naked_tuple (%d). valor: %s\n",
                                        size, l+1, str);
                                free(str);
                                str = NULL;
                            }
                        }
                    }
                } else if (tc == size) {
                    int inseriu = cc_insere(conjunto, tuple, l+i, c+j);
                    if (inseriu) {
                        i = j = 0;
                        free(tuple);
                        tuple = NULL;
                        goto superbreak;
                    }
                } else if (conjunto->len > 0 && (1 < tc && tc < size)) {
                    for (int k = 0; k < conjunto->len; k++) {
                        if (sub_tuple(tuple, conjunto->candidatos[k].tupla, size)) {
                            cc_insere(conjunto, conjunto->candidatos[k].tupla, l+i, c+j);
                        }
                    }
                }
                free(tuple);
                tuple = NULL;
            }
        }
        destroy_cc(conjunto);
    }
    return z > 0;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : line */
/* hidden pair: remove candidatos na celula do par, limpando-o, tornando-o naked pair */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funcao para encontrar pares ocultos nas linhas.             
 *
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return z>0       
 *
 * @author Davi Pereira Rio
 * @version 20201026.191705
 * @date 2020-11-01
 */

int d4l(int w[9][9][9])
{
    int z = 0, n1, n2;// flag que indica se ocorreu deducao
    int* hidden_pair;
    
    for(int l = 0; l < 9; l++)
    {
        int candy[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        for (int c = 0; c < 9; c++)
        {
            for (int i = 0; i < 9; i++)
            {
                candy[i] += w[l][c][i];
            }
        }
        hidden_pair = extract_tuple(candy, 2);
        n1 = hidden_pair[0];
        n2 = hidden_pair[1];
        free(hidden_pair);
        hidden_pair = NULL;

        if (n1 == -1 || n2 == -1) continue;
        for (int c = 0; c < 9; c++)
        {
            if (w[l][c][n1] && w[l][c][n2])
            {
                for (int cc = c+1; cc < 9; cc++)
                {
                    if (w[l][cc][n1] && w[l][cc][n2])
                    {
                        // dyes -1 porque vai mudar n2 pra 0 e mudamos pra 1 de novo
                       int mod = dyes(l, cc, n1+1, w) -1;
                       mod += dyes(l, c, n1+1, w) -1;
                       z += mod;
                       w[l][c][n2] = 1;
                       w[l][cc][n2] = 1;
                       if (mod) 
                       {
                           printf("d4l: hidden pair(%d). valores (%d, %d).\n", l+1, n1+1, n2+1);
                       }
                    }
                }
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : column */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funcao para encontrar pares ocultos nas colunas.             
 *
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
  *
 * @return z>0       
 *
 * @author Davi Pereira Rio
 * @version 20201026.191705 
 * @date 2020-11-01
 */

int d4c(int w[9][9][9])
{
    int z = 0, n1, n2; // flag que indica se ocorreu deducao 
    int * hidden_pair;

    for(int c = 0; c < 9; c++)
    {
        int candy[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        for (int l = 0; l < 9; l++)
        {
            for (int i = 0; i < 9; i++)
            {
                candy[i] += w[l][c][i];
            }
        }
        hidden_pair = extract_tuple(candy, 2);
        n1 = hidden_pair[0];
        n2 = hidden_pair[1];
        free(hidden_pair);
        hidden_pair = NULL;

        if (n1 == -1 || n2 == -1) continue;
        for (int l = 0; l < 9; l++)
        {
            if (w[l][c][n1] && w[l][c][n2])
            {
                for (int ll = l+1; ll < 9; ll++)
                {
                    if (w[ll][c][n1] && w[ll][c][n2])
                    {
                        // dyes -1 porque vai mudar n2 pra 0 e mudamos pra 1 de novo
                        int mod = dyes(ll, c, n1+1, w) -1;
                        mod += dyes(l, c, n1+1, w) -1;
                        z += mod;
                        w[l][c][n2] = 1;
                        w[ll][c][n2] =1;
                        if (mod)
                        {
                            printf("d4c: hidden pair (%d). valores (%d, %d).\n", c+1, n1+1, n2+1);
                        }
                    }
                }
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : block */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funcao para encontrar pares ocultos nos blocos do sudoku.             
 *
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @author Davi Pereira Rio
 * @version 20201026.191705
 * @date 2020-11-01
 */

int d4b(int w[9][9][9])
{
    int z = 0, n1, n2, l, c;// flag que indica se ocorreu deducao
    int* hidden_pair;

    for(int b = 0; b < 9; b++)
    {
        bloco(b, &l, &c);
        int candy[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 9; k++)
                {
                    candy[k] += w[l+1][c+j][k];
                }
            }
        }
        hidden_pair = extract_tuple(candy, 2);
        n1 = hidden_pair[0];
        n2 = hidden_pair[1];
        free(hidden_pair);
        hidden_pair = NULL;

        if(n1 == -1 || n2 == -1) continue;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(w[l+i][c+j][n1] && w[l+i][c+j][n2])
                {
                    for (int ii = i; ii < 3; j++)
                    {
                        for (int jj = j+1; jj < 3; jj++)
                        {
                            if(w[l+ii][c+jj][n1] && w[l+ii][c+jj][n2])
                            {
                                // dyes - 1 porque vai mudar n2 pra 0 e mudamos para 1 de novo
                                int mod = dyes (l+ii, c+jj, n1+1, w) - 1;
                                mod += dyes (l+i, c+j, n1+1, w) -1;
                                z += mod;
                                w[l+i][c+j][n2] = 1;
                                w[l+ii][c+jj][n2] = 1;
                                if (mod)
                                {
                                    printf("d4b: hidden pair (%d). valores (%d, %d). \n", b+1, n1+1, n2+1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : linha */
/* Econtra condidatos e retiralos das possibilidades*/
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Davi Pereira Rio
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d5l(int w[9][9][9])
{
    int z = 0, l, c; // flag que indica se ocorreu deducao 
    
    for (int b = 0; b < 9; b++)
    {
        bloco(b, &l, &c);
        int candy[9] = {0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 9; k++)
                {
                    candy[k] += w[l+i][c+j][k];
                }
            }
        }
        int threecandy[9] = {0};
        int c3 = 0, c2 = 0;
        int twocandy[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (candy[i] ==2)
            {
                twocandy[c2++] = i;
            } else if (candy[i] == 3)
            {
                threecandy[c3++] = i;
            }
        }
        for (int  i = 0; i < 3; i++)
        {
            for (int k = 0; k < c2 || k < c3; k++)
            {
                int ocorrencias2 = 0, ocorrencias3 = 0;

                for (int j = 0; j < 3; j++)
                {
                    if (k < c2 && w[l+i][c+j][twocandy[k]])
                    {
                        ocorrencias2++;
                    }
                    if (k < c3 && w[l+i][c+j][threecandy[k]])
                    {
                        ocorrencias3++;
                    }
                    if (ocorrencias2 == 2)
                    {
                        int mod = 0;
                        for (int cc = 0; cc < 9; cc++)
                        {
                            if ((c <= cc) && (cc < c+3)) continue;
                            mod += dnot(l+i, cc, twocandy[k]+1, w);
                        }
                        z += mod;
                        if (mod)
                        {
                            printf("d5l: pointing pair (b%d l%d). valor %d\n", b+1, l+i+1, twocandy[k]+1);
                            //printsudoku_debug(w);
                            if (!check(w)) exit(0);
                        }
                    }
                    if (ocorrencias3 == 3)
                    {
                        int mod = 0;
                        for (int cc = 0; cc < 9; cc++)
                        {
                            if ((c <= cc) && (cc < c+3)) continue;
                            mod += dnot(l+i, cc, threecandy[k]+1, w);
                        }
                        z+=mod;
                        if (mod)
                        {
                            printf("d5l: pointing triple (b%d l%d). valor %d\n", b+1, l+i+1, threecandy[k]+1);
                            //printsudoku_debug(w);
                            if (!check(w)) exit(0);
                        }
                    }
                }
            }
        }
    }
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : coluna */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Davi Pereira Rio
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d5c(int w[9][9][9])
{
    int z = 0, l, c; // flag que indica se ocorreu deducao 
    
    for (int b = 0; b < 9; b++)
    {
        bloco(b, &l, &c);
        int candy[9] = {0};
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int k = 0; k < 9; k++)
                {
                    candy[k] += w[l+i][c+j][k];
                }
            }
        }
        int threecandy[9] = {0};
        int c3 = 0, c2 = 0;
        int twocandy[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if(candy[i] == 2)
            {
                twocandy[c2++] = i;
            }
        }
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < c3 || k < c2; k++) {
            int ocorrencias2 = 0, ocorrencias3 = 0;
        
            for (int i = 0; i < 3; i++) 
            {
                if (k < c2 && w[l+i][c+j][twocandy[k]]) 
                {
                    ocorrencias2++;
                }
                if (k < c3 && w[l+i][c+j][threecandy[k]]) 
                {
                    ocorrencias3++;
                }
            }
            if (ocorrencias2 == 2) 
            {
                int mod = 0;
                for (int ll = 0; ll < 9; ll++) 
                {
                    if ((l <= ll) && (ll < l+3)) continue;
            
                    mod += dnot(ll, c+j, twocandy[k]+1, w);
                }
                z+=mod;
                if (mod) 
                {
                    printf("d5c: pointing pair (b%d c%d). valor %d\n", b+1, c+j+1, twocandy[k]+1);
                    //printsudoku_debug(w);
                    if (!check(w)) exit(0);
                }
            }
            if (ocorrencias3 == 3) 
            {
                int mod = 0;
                for (int ll = 0; ll < 9; ll++) 
                {
                    if ((l <= ll) && (ll < l+3)) continue;
            
                    mod += dnot(ll, c+j, threecandy[k]+1, w);
                }
                z+=mod;
                if (mod) 
                {
                    printf("d5c: pointing triple (b%d c%d). valor %d\n", b+1, c+j+1, threecandy[k]+1);
                    //printsudoku_debug(w);
                    if (!check(w)) exit(0);
                }
            }
        }   
    }   
  }
  return z>0;
}

/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : line */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Heitor Jose Andrade De Oliveira
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d6_helper(int w[9][9][9], char direcao)
{
    int z = 0; // flag que indica se ocorreu deducao 
    printf("iniciando d6%c.\n", direcao);
    printsudoku_debug(w);
    for (int l = 0; l < 9; l++)
    {
        ConjuntoContador* conjunto = novo_cc(1);
        for (int c = 0; c < 9; c++)
        {
            if (direcao == 'c') swap(&l, &c);

            for (int k = 0; k < 9; k++)
            {
                if (w[l][c][k])
                {
                    int tuple[1];
                    tuple[0] = k;
                    cc_insere(conjunto, tuple, l, c);
                }
            }
            if (direcao == 'c') swap(&l, &c); //swap back
        }
        // aqui terei o conjunto com a contagem dos candidatos do grupo
        // buscar dentre os candidatos, aqueles que ocorrem 2 ou 3 vezes apenas
        // e cujas entradas pertencem ao mesmo bloco.
        for (int i = 0; i < conjunto->len; i++)
        {
            Candidato candidato = conjunto->candidatos[i];
            int count = candidato.count;
            if (count == 2 || count == 3)
            {
                // candidato ocorre a qtd certa de vezes!
                int ql, qc, ql_original, qc_original;
                // vamos descobrir se ocorrem sempre no mesmo bloco agora
                cbloco(candidato.coords[0].l, candidato.coords[0].c, &ql_original, &qc_original);
                int mesmo_bloco = 1;
                for (int j = 1; j < count; j++)
                {
                    cbloco(candidato.coords[j].l, candidato.coords[j].c, &ql, &qc);
                    if (!(ql == ql_original && qc == qc_original))
                    {
                        // blocos diferentes, ignorar este candidato
                        mesmo_bloco = 0;
                        break;
                    }
                }
                if (!mesmo_bloco) continue; // ignorar este candidato

                // esse candidato satisfaz claiming candidate
                // remover do resto do bloco todo
                int mod = dnot_bloco(ql, qc, candidato.tupla[0]+1, w, candidato.coords, candidato.count);
                z += mod;
                if (mod)
                {
                    printf("d6%c: after claiming candidate (%d). valor %d\n", direcao, l+1, candidato.tupla[0]+1);
                    printsudoku_debug(w);
                }
            }
        }
        destroy_cc(conjunto);
    }
    return z>0;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Heitor Jose Andrade De Oliveira
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */

int d6l(int w[9][9][9])
{
    return d6_helper(w, 'l');
}


/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : column */
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   xxxx.             
 *
 * @param[in] xx1 xxxxxx.
 * @param[in] xx2 xxxxxx.
 * @param[in] xx3 xxxxxx.
 *
 * @param[out] xx xxxxxx.
 *
 * @return Xxx       
 *
 * @author Heitor Jose Andrade De Oliveira
 * @version XXXXXXXX.xxxxxx
 * @date 2020-XX-XX
 */


int d6c(int w[9][9][9])
{
    return d6_helper(w, 'c');
}

/* ---------------------------------------------------------------------- */
/* x-wing */
/**
 * @ingroup GroupUnique
 * @brief   Funcao d7 (x-wing) generalizada para evitar repeticao exaustiva de codigo.
 *
 * @param[in] direcao Qual "direcao" o laco esta rodando ('l' -> linha; 'c' -> coluna).
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return Z       
 *
 * @author Leandro Dantas Lima
 * @version 20201026.191705
 * @date 2020-10-30
 */

int d7_helper(int w[9][9][9], char direcao)
{
    int z = 0; /* flag que indica se ocorreu deducao */
    int l = 0, ll, f, i, j;

    Candidato found1[9], found2[9];

    for(ll = 0; ll < 8; ll++)
    {
        l = ll;
        int len1 = cc_find(&l, 2, found1, direcao, w);
        
        if(len1 == -1)
            return 0;
        while(l < 9)
        {
            int len2 = cc_find(&l, 2, found2, direcao, w);

            if(len2 == -1)
            {
                for(f = 0; f < len1; f++)
                    free(found1[f].tupla);
                
                return 0;
            }

            for(i = 0; i < len1; i++)
            {
                for(j = 0; j < len2; j++)
                {
                    int valor1 = found1[i].tupla[0], valor2 = found2[j].tupla[0];

                    if(valor1 == valor2)
                    {
                        Coordenadas *coord1 = found1[i].coords;
                        Coordenadas *coord2 = found2[j].coords;
                        
                        if(((direcao == 'l') && (coord1[0].c == coord2[0].c &&
                                                coord1[1].c == coord2[1].c)) ||
                        ((direcao == 'c') && ((coord1[0].l == coord2[0].l &&
                                                coord1[1].l == coord2[1].l)))) 
                        {
                            /* x-wing detectado */
                            int mod = 0, lll;
                            
                            for(lll = 0; lll < 9; lll++)
                            {
                                if(((direcao == 'c') && ((lll == coord1[0].c) ||
                                                        (lll == coord2[0].c))) ||
                                ((direcao == 'l') && ((lll == coord1[0].l) ||
                                                        (lll == coord2[0].l))))
                                    continue;
                                
                                if(direcao == 'l')
                                {
                                    mod += dnot(lll, coord1[0].c, valor1+1, w);
                                    mod += dnot(lll, coord1[1].c, valor1+1, w);
                                }
                                else
                                {
                                    mod += dnot(coord1[0].l, lll, valor1+1, w);
                                    mod += dnot(coord1[1].l, lll, valor1+1, w);
                                }
                            }
                            z += mod;
                            if(mod)
                            {
                                printf("d7%c: x-wing (%d, %d), (%d, %d), \n"
                                       "             (%d, %d), (%d, %d)\n"
                                       "     valor: %d\n",
                                       direcao, coord1[0].l+1, coord1[0].c+1,
                                       coord1[1].l+1, coord1[1].c+1, coord2[0].l+1, 
                                       coord2[0].c+1, coord2[1].l+1, coord2[1].c+1,
                                       valor1+1);
                                printf("removi %d candidatos\n", mod);
                                printsudoku_debug(w);
                            }
                        }
                    }
                }
            }
            for(f = 0; f < len2; f++)
                free(found2[f].tupla);      
        }
        for(f = 0; f < len1; f++)
            free(found1[f].tupla);        
    }
    return z > 0;
}


/* ---------------------------------------------------------------------- */
/* x-wing */
/**
 * @ingroup GroupUnique
 * @brief   Equivalente da d7_helper varrendo em linha.
 *
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return d7_helper
 *
 * @author Leandro Dantas Lima
 * @version 20201026.191705
 * @date 2020-10-30
 */

int d7l(int w[9][9][9])
{
    return d7_helper(w, 'l');
}

/* ---------------------------------------------------------------------- */
/* x-wing */
/**
 * @ingroup GroupUnique
 * @brief   Equivalente da d7_helper varrendo em coluna.
 *
 * @param[in] w Matriz 9x9x9 que salva os valores do sudoku durante as operacoes.
 *
 * @return d7_helper
 *
 * @author Leandro Dantas Lima
 * @version 20201026.191705
 * @date 2020-10-30
 */

int d7c(int w[9][9][9])
{
    return d7_helper(w, 'c');
}

/* ---------------------------------------------------------------------- */
/* backtracking */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   Funcao auxiliar para backup da matriz w[9][9][9] no backtracking.  
 *
 * @param[in] w Matriz original 9x9x9 com os valores ANTES dos testes do backtracking.
 * @param[in] w_backup Matriz 9x9x9 com os valores de w num estado antes do teste.
 *
 * @return Void       
 *
 * @author Leandro Dantas Lima
 * @version 20201026.031708
 * @date 2020-10-26
 */

void faz_copia_w(int w[9][9][9], int w_backup[9][9][9])
{
    int i, j, k;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            for(k = 0; k < 9; k++)            
                w_backup[i][j][k] = w[i][j][k];            
        }
    }
    
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief   Funcao para encontrar a solucao por recursividade - backtracking.  
 *
 * @param[in] w Matriz original 9x9x9 com os valores ANTES dos testes do backtracking.
 * @param[in] l Linha da celula avaliada (int)
 * @param[in] c Coluna da celula avaliada (int)                  
 *
 * @return Z       
 *
 * @author Leandro Dantas Lima
 * @version 20201026.191705
 * @date 2020-10-26
 */

int tenta8(int w[9][9][9], int l, int c)
{
    int z = 0; /* flag que indica se ocorreu deducao */
    int i, j, k; /* contadores para rodar os lacos (i -> lin, j -> col, k -> cand) */
    int w_backup[9][9][9] = {0}; /* restaurar a w original caso o teste falhe */
    /* char *hd = "tenta8: backtracking"; */
    
    for(i = l; i < 9; i++)      /* roda as linhas */
    {
        for(j = c; j < 9; j++)  /* roda as colunas */
        {
            if(!unico(w[i][j])) 
            {
                for(k = 1; k < 10; k++) /* roda os candidatos */
                {
                    if(!(checa_unicoLinha(i, k, w) && 
                         checa_unicoColuna(j, k, w) && 
                         checa_unicoBloco(i, j, k, w)))
                    {
                        if(k == 9) /* rodou todos os candidatos e nao conseguiu */
                            return 0;
                        
                        continue;
                    }
                    faz_copia_w(w, w_backup); /* restaura w do estado anterior */
                    z += dyes(i, j, k, w); /* dada uma coord e um num, faz deducao
                                              positiva e elimina possibilidades em w */

                    if(z) /* se a dyes conseguiu modificar */                    
                        z += tenta8(w, l, c);

                    else                    
                        printf(" dyes nao alterou nada\n"); /* debug */
                    
                    /* testar o estado de w para backup */
                    switch(check(w))
                    {
                        case -1:
                            return z;
                        case 0:
                            printf("\n\n\n Nao podia ter acontecido (INVALIDO)! \n\n\n");
                            return z;
                        default:
                            faz_copia_w(w_backup, w);  /* restaura estado anterior */
                    }
                }
            }
        }
    }    
    
    return z;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "sudoku999", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "sudoku999");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
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
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "sudoku999", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
