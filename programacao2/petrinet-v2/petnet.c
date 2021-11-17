/***************************************************************************
 *   petnet.c                                 Version 20201010.001127      *
 *                                                                         *
 *   Petri Net Simulator                                                   *
 *                                                                         *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 *                                                                         *
 *   Copyright (C) 2020         by Gardenia Georgia Barbosa De Siqueira    *
 *                                 Leandro Dantas Lima                     *
 *                                 Everton Da Silva Paiva                  *
 *                                 Davi Pereira Rio                        *
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
 *   Webpage: gttp://ww.beco.cc                                            *
 *   Phone: +55 (81) 97903-2929                                            *
 *                                                                         *
 *   Everton Da Silva Paiva                                                *
 *   Email: evertonpaiva01@gmail.com                                       *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 995251102                                             *
 *                                                                         *
 *   Lucas Silva Borges                                                    *
 *   Email: borgeslucas940@gmail.com                                       *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 99300-1169                                            *
 *                                                                         *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */

/**
 * @file petnet.c
 * @ingroup GroupUnique
 * @brief Petri Net Simulator
 * @details This program really do a nice job as a petrinet for terminal
 * @version 20160806.231815
 * @date 2016-08-06
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
 */
/* ---------------------------------------------------------------------- */
/* includes */

#include "petnet.h" /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main function
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
 *    $./petnet -h
 * @endcode
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160806.231815
 * @date 2016-08-06
 */

int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhV")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    petnet_init(); /* initialization function */

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details initializes someoperations
 */

void petnet_init(void)
{

    IFDEBUG("petnet_init()");

    int num_sort[AMOSTRAS];
    int cont_t[qtdTransicoesFORDisparo + 1];
    float perc_t[qtdTransicoesFORDisparo+1];
    bool trans_dispara[qtdTransicoesFORDisparo+1];
    /* initialization: */

    inputUsuario();
    
    gera_separaCOLt();
    gera_transicaoHabilitada(qtdTransicoes); /* qtdElementos = qtdTransições */
    gera_colunaSeparadaPRE();
    gera_colunaSeparadaPOST();
    gera_disparaTRANS(qtdTransicoes);
    
    while(contadorLoopDoJogo)
    {
 
        zera_separaCOLt();
        zera_transicaoHabilitada(qtdTransicoes);
        zera_colunaSeparadaPRE();
        zera_colunaSeparadaPOST();
        zera_disparaTRANS(qtdTransicoes);
        habilita_transicao();
       
        escolha_trans(cont_t, perc_t, num_sort,trans_dispara); /* definir qual transição deve disparar */
        print_transicaoHabilitada(qtdTransicoes);
        
        print_disparaTRANS(qtdTransicoes);
        muda_qtdTokens();
        print_Tokens(qtdLugares);
        printf("\n **************************************************************************** \n ");
        sleep(3);
        
    }
    printf("\nNao ha mais disparos. Fim da rede. \n\n");
    liberaMemoria();
} 

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief  faz as perguntas iniciais ao usuario.
 * @details faz perguntas e chama algumas funcoes
 * @param [out] void
 * @param [in] void
 * @author Gardenia Georgia
 */

void inputUsuario(void)
{
    printf("\n ******************************************************************** ");
    printf("\n ************************    IMPUTSUSUARIO    ***********************\n");
    printf(" ******************************************************************** \n\n");

    printf(" Quantos Lugares P, existem? ");
    scanf("%d", &qtdLugares);
    printf(" Quantas transicoes T, existem? ");
    scanf("%d",&qtdTransicoes);
   
    //Inputs:
    input_Tokens(); 
    input_ConjuntoPRE(qtdLugares, qtdTransicoes);
    input_ConjuntoPOST(qtdLugares, qtdTransicoes);

    //Prints:
    print_Tokens(qtdLugares);
    print_ConjuntoPRE(qtdLugares, qtdTransicoes);
    print_ConjuntoPOST(qtdLugares, qtdTransicoes);
}

/* ---------------------------------------------------------------------- */

/**
 * @brief coleta os dados de entrada referente aos tokens dos lugares
 * @details gera vetor com quantidade de tokens
 * @param [out] void
 * @param [in] void
 * @author Gardenia Georgia, Lucas Silva Borges
 */

void input_Tokens()//preciso que gere uma matriz
{
    int i, MAXLIN = qtdLugares;
    
    printf("\n ******************************************************************** ");
    printf("\n ***********************     Input TOKENS     ***********************\n");
    printf(" ******************************************************************** \n\n");
   
    //alloca matriz:
    qtdTokens = malloc(MAXLIN *sizeof(int));
    for(i = 0; i < MAXLIN; i++)
    {
        qtdTokens[i] = 0;
        printf(" L[%d]= [%d], \n",i, qtdTokens[i]);
    }
      
    //preenche:
    for(i = 0; i < MAXLIN; i++)
    {
        printf("\n Digite quantos tokens iniciais existem em L%d: ",i);
        scanf("%d", &qtdTokens[i]);
        printf("\n depois L[%d]= [%d],\n ",i, qtdTokens[i]);
    }
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao imprime na tela a quantidade de tokens
 * @details imprime na tela *qtdTokens
 * @param [out] void
 * @param [in] void
 * @author Gardenia Georgia
 */


void print_Tokens(int MAXLIN)
{
    int i;

    printf("\n -------------------------------------------------------------------- ");
    printf("\n ----------------------- Quantidade de TOKENS -----------------------\n");
    printf(" -------------------------------------------------------------------- \n\n");
    for(i = 0; i < MAXLIN; i++)
        printf(" L%d[%d], \n",i, qtdTokens[i]);
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao gera conjunto PRE onde se receber 1, existe.
 * @details gera matriz **conjuntoPRE
 * @param [in] MAXCOL qtdTransicoes
 * @param [in] MAXLIN qtdLugares
 * @author Gardenia Georgia
 */

           
void input_ConjuntoPRE(int MAXLIN, int MAXCOL)
{ 
    int i,j;
    int qtdTransicoesPRE, TransicaoOn;
  
    printf("\n\n ******************************************************************** ");
    printf("\n ************************ Input Conjunto PRET ***********************\n");
    printf(" ******************************************************************** \n");
    //Aloca memoria:
    conjuntoPRE = malloc(MAXLIN*sizeof(int*));
    for(i = 0; i< MAXLIN; i++)
        conjuntoPRE[i] = malloc (MAXCOL *sizeof(int));
   
    //Zera matriz:
    for(i = 0; i< MAXLIN; i++)
        for(j = 0; j < MAXCOL; j++)
            conjuntoPRE[i][j] = 0;

    // Grava posição onde existe transição:
    for( i = 0; i < MAXLIN; i++)
    {
        printf("\n Quantos arcos LT, L%d estah correlacionado: ", i);
        scanf("%d", &qtdTransicoesPRE);
        for(j = 0; j < qtdTransicoesPRE; j++)
        {
            printf("\n  - Digite o numero das transições de L%dTx, talque PRET(L%d,Tx), separando por <ENTER>: ",i,i);
            scanf("%d", &TransicaoOn);
            conjuntoPRE[i][TransicaoOn] = 1;
        }
    }
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao imprime conjunto PRE.
 * @details imprime matriz **conjuntoPRE
 * @param [in] MAXCOL qtdTransicoes
 * @param [in] MAXLIN qtdLugares
 * @author Gardenia Georgia
 */



void print_ConjuntoPRE(int MAXLIN, int MAXCOL)
{
    int i,j;

    printf("\n -------------------------------------------------------------------- ");
    printf("\n --------------------------- Conjunto PRE ---------------------------\n");
    printf(" -------------------------------------------------------------------- \n\n");
    for(i = 0; i < MAXLIN; i++)
    {
        for(j = 0; j < MAXCOL; j++)
            printf(" %d  ",conjuntoPRE[i][j]);
        printf("\n");
    }
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao gera conjunto POST onde se receber 1, existe.
 * @details gera matriz **conjuntoPOST
 * @param [in] MAXCOL qtdTransicoes
 * @param [in] MAXLIN qtdLugares
 * @author Gardenia Georgia
 */

void input_ConjuntoPOST(int MAXLIN, int MAXCOL)
{
    int i, j; 
    int qtdTransicoesPOST, TransicaoOn;
    
    printf("\n\n ******************************************************************** ");
    printf("\n ************************ Input Conjunto POST ***********************\n");
    printf(" ******************************************************************** \n");
    
    //Aloca memória:
    conjuntoPOST = malloc(MAXLIN *sizeof(int*));
    for(i = 0; i < MAXLIN; i++)
        conjuntoPOST[i] = malloc(MAXCOL *sizeof(int));
    
    //Zera matriz:
    for(i = 0; i< MAXLIN; i++)
        for(j = 0; j < MAXCOL; j++)
            conjuntoPOST[i][j] = 0;

    // Grava posição onde existe transição:
    for(i = 0; i < MAXLIN; i++)
    {
        printf("\n Quantos arcos TL, L%d estah correlacionado: ", i);
        scanf("%d", &qtdTransicoesPOST);
        for(j = 0; j < qtdTransicoesPOST; j++)
        {
            printf("\n  - Digite o numero x das transições de TxL%d, talque POST(Tx,L%d), separando por <ENTER>: ",i,i);
            scanf("%d", &TransicaoOn);
            conjuntoPOST[i][TransicaoOn] = 1;
        }
    }
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao imprime conjunto POST onde se receber 1, existe.
 * @details imprime matriz **conjuntoPOST
 * @param [in] MAXCOL qtdTransicoes
 * @param [in] MAXLIN qtdLugares
 * @author Gardenia Georgia
 */


void print_ConjuntoPOST(int MAXLIN, int MAXCOL)
{
    int i,j;

    printf("\n -------------------------------------------------------------------- ");
    printf("\n --------------------------- Conjunto POST --------------------------\n");
    printf(" -------------------------------------------------------------------- \n\n");
    for(i = 0; i < MAXLIN; i++)
    {
        for(j = 0; j < MAXCOL; j++)
            printf(" %d  ",conjuntoPOST[i][j]);
        printf("\n");
    }
}
                     
/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Funcoes abaixo gera, zera e habilita separaCOLt
 * @details As funcoes abaixos irao gerar, zerar e habilitar, global separaCOLt
 * que ira servir para multiplicacao de matriz. Separara qual coluna t tera
 * analises.
 * @param [in] void
 * @param [out] void
 * @author Gardenia Georgia
 */


void gera_separaCOLt()
{
    int MAXLIN = qtdTransicoes;
    //Aloca memória:
    separaCOLt = malloc(MAXLIN *sizeof(int*));
}
void zera_separaCOLt()
{
    int i, MAXLIN = qtdTransicoes;
    for(i = 0; i < MAXLIN; i++)
        separaCOLt[i] = 0;
}
                                 
void habilita_separaCOLt(int ntransicao)
{
    separaCOLt[ntransicao] = 1;
}
                      
/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief As funcoes abaixos irao gerar, zerar e imprimir vetor habilitaTransicao
 * @details funcoes fazem configuracoes iniciis onde habilitaTransicao eh um 
 * vetor onde cada posicao vai registrar qual tx esta habilitado
 * @param [in] qtdElementos = qtdTransicoes
 * @param [out] void
 * @author Gardenia Georgia
 */


void gera_transicaoHabilitada(int qtdElementos)
{
    transicaoHabilitada = malloc(qtdElementos *sizeof(int*));
}
void zera_transicaoHabilitada(int qtdElementos)
{
    int i; 
    for(i = 0; i < qtdElementos; i++)
        transicaoHabilitada[i] = 0; 
}
void print_transicaoHabilitada(int qtdElementos)
{
    int i;

    printf("\n -------------------------------------------------------------------- ");
    printf("\n ------------------------ Transicoes Habilitadas --------------------\n");
    printf(" -------------------------------------------------------------------- \n\n");
    for(i = 0; i < qtdElementos; i++)
        printf(" T%d = %d\n", i, transicaoHabilitada[i]);
}
                       
/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief As funcoes abaixos irao gerar, zerar e habilitar vetor colunaSeparadaPRE
 * @details funcoes abaixo separam a coluna de conjuntoPRE que sao de tx, usando 
 * a multilicacao de conjuntoPRE x separaCOLt
 * @param [in] void
 * @param [out] void
 * @author Gardenia Georgia
 */

void gera_colunaSeparadaPRE()
{
    int MAXLIN = qtdLugares;
    colunaSeparadaPRE = malloc(MAXLIN *sizeof(int*));
}

void zera_colunaSeparadaPRE()
{
    int MAXLIN = qtdLugares;
    int i;
    //zera matriz:
    for(i = 0; i < MAXLIN; i++)
        colunaSeparadaPRE[i] = 0;   
}
void habilita_colunaSeparadaPRE(int TransicaoDeAnalise)
{    
    int i, j, aux = 0;
    
    zera_separaCOLt();
    zera_colunaSeparadaPRE();
    habilita_separaCOLt(TransicaoDeAnalise);

    for( i = 0; i < qtdLugares; i++)
    {
        colunaSeparadaPRE[i] = 0;
        for(j = 0; j < qtdTransicoes; j++)
            aux += (conjuntoPRE[i][j] * separaCOLt[j]);
        colunaSeparadaPRE[i] = aux;
        aux = 0;
    }
}

void print_colunaSeparadaPRE()
{
    int i;
    printf("\n ******************************************************************** ");
    printf("\n ************************ Coluna Separada PRE ***********************\n");
    printf(" ******************************************************************** \n\n");

    for(i = 0; i < qtdLugares; i++)
        printf(" L[%d] = %d\n", i, colunaSeparadaPRE[i]);
}
                        
/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Salva vetr transicaobilitada[i] onde existe habilitacao
 * @details funcoes salva transicaoHabiitada[i], onde i = 1 significa que 
 * transicao Ti esta habilitada
 * @param [in] void
 * @param [out] void
 * @author Gardenia Georgia
 */

void habilita_transicao(void)
{
    int i, j, aux = 0;
    int contaPeso = 0, contaToken = 0;
    
    for(i = 0; i < qtdTransicoes; i++)
    {
         habilita_colunaSeparadaPRE(i);
         for(j = 0; j < qtdLugares; j++)
         {
            if((colunaSeparadaPRE[j]) != 0)
            {
                contaPeso += colunaSeparadaPRE[j];
                contaToken += qtdTokens[j];
            }
         }
         if(contaToken >= contaPeso)
            (transicaoHabilitada[i]) = 1; 
        contaPeso = 0;
        contaToken = 0;
    }
    for(i = 0; i < qtdTransicoes; i++)
        if((transicaoHabilitada[i]) != 0)
            aux += 1;
    qtdTransicoesFORDisparo = aux;
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Funcoes abaixo gera, zera e imprime disparaTRANS
 * @details gera, zera e imprime disparaTRANS com transicoes para disparo
 * @param [in] qtdElementos = qtdTransicoes
 * @param [out] void
 * @author Gardenia Georgia
 */


void gera_disparaTRANS(int qtdElementos)
{
    disparaTRANS = malloc(qtdElementos *sizeof(int*));
}
void zera_disparaTRANS(int qtdElementos)
{
    int i; 
    for(i = 0; i < qtdElementos; i++)
        disparaTRANS[i] = 0; 
}
void print_disparaTRANS(int qtdElementos)
{
    int i;

    printf("\n -------------------------------------------------------------------- ");
    printf("\n ------------------------ Transicoes para disparo -------------------\n");
    printf(" -------------------------------------------------------------------- \n\n");
    for(i = 0; i < qtdElementos; i++)
        printf(" T%d = %d\n", i, disparaTRANS[i]);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Gerar numeros aleatorios utilizados na escolha das transicoes t0 a tn.
 * @details Prints help information (usually called by opt -h)
 *
 * @param [in] num_sort vetor que contem todos os numeros sorteados;
 * @param [in] quant_num quantidade de numeros que a funcao vai gerar aleatoriamente;
 * @param [in] max_trans numero de transicoes definidas.
 *
 * @return Void
 *
 * @author Leandro Dantas Lima
 * @version 20201010.001127
 * @date 2020-10-05
 *
 */

void gerar_aleatorios(int num_sort[], int quant_num, int max_trans)
{
    srand(time(NULL) + getpid());

    int i, v;
    if(max_trans != 0)
        for(i = 0; i < quant_num; i++)
        {
            v = rand() % max_trans + 1;
            num_sort[i] = v;
        }
    if(max_trans == 0)
        for(i = 0; i < quant_num; i++)
            num_sort[i] = 0;
       
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Define qual transicao pode disparar de acordo com a probabilidade definida.
 * @details Prints help information (usually called by opt -h)
 *
 * @param [in] cont_t contador de frequencia das transicoes;                      
 * @param [in] perc_t vetor que contem os percentuais de cada transicao;                   
 * @param [in] num_sort vetor que contem todos os numeros sorteados;
 * @param [in] trans_dispara ponteiro para a transicao habilitada que pode disparar.
 *
 * @return Void
 *
 * @author Leandro Dantas Lima e Gardenia Georgia
 * @version 20201010.001127
 * @date 2020-10-05
 *
 */

void escolha_trans(int *cont_t, float *perc_t, int *num_sort, bool *trans_dispara)
{
    int i, j, cont = 1;

    gerar_aleatorios(num_sort, AMOSTRAS, qtdTransicoesFORDisparo);
    
    if(qtdTransicoesFORDisparo != 0)
    {
        for(j = 1; j <= qtdTransicoesFORDisparo; j++)
        {
            cont_t[j] = 0;
            for(i = 0; i < AMOSTRAS; i++)
                if(num_sort[i] == j)
                    cont_t[j]++;
        }
    
        for(j = 1; j <= qtdTransicoesFORDisparo; j++)
        {
            perc_t[j] = 0;
            perc_t[j] = (float) 100*cont_t[j]/AMOSTRAS;
        }
    }
    printf("\n -------------------------------------------------------------------- ");
    printf("\n ------------------------ Prioridade de disparo ---------------------\n");
    printf(" -------------------------------------------------------------------- \n");

    for(i = 0; i < qtdTransicoes; i++){
        if((transicaoHabilitada[i])!= 0)    
            for(j = 1; j <= qtdTransicoesFORDisparo; j++)
            {
                if( j == cont)
                {
                    if(perc_t[j] >= 110/qtdTransicoesFORDisparo)
                    {
                        printf("\n t%d ## PODE DISPARAR ##", j);
                        disparaTRANS[i] = 1;
                        trans_dispara[j]=true;
                        cont++;
                        break;
                    }
                    else
                    {
                        printf("\n t%d nao pode disparar", j);
                        trans_dispara[j] = false;
                        cont++;
                        break;

                    }
                }
            }
    }
    if(qtdTransicoesFORDisparo == 0)
    {
        printf("#Nao existe mais disparos");
        contadorLoopDoJogo = 0;
    }
    printf("\n");
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief As funcoes abaixos irao gerar, zerar e habilitar vetor colunaSeparadaPRE
 * @details funcoes abaixo separam a coluna de conjuntoPOST que sao de tx, usando 
 * a multilicacao de conjuntoPOST x separaCOLt
 * @param [in] void
 * @param [out] void
 * @author Gardenia Georgia
 */


void gera_colunaSeparadaPOST()
{
    int MAXLIN = qtdLugares;
    colunaSeparadaPOST = malloc(MAXLIN *sizeof(int*));
}

void zera_colunaSeparadaPOST()
{
    int MAXLIN = qtdLugares;
    int i;
    //zera matriz:
    for(i = 0; i < MAXLIN; i++)
        colunaSeparadaPOST[i] = 0;   
}
void habilita_colunaSeparadaPOST(int TransicaoDeAnalise)
{    
    int i, j, aux = 0;
    
    zera_separaCOLt();
    zera_colunaSeparadaPOST();
    habilita_separaCOLt(TransicaoDeAnalise);

    for( i = 0; i < qtdLugares; i++)
    {
        colunaSeparadaPOST[i] = 0;
        for(j = 0; j < qtdTransicoes; j++)
            aux += (conjuntoPOST[i][j] * separaCOLt[j]);
        colunaSeparadaPOST[i] = aux;
        aux = 0;
    }
}

void print_colunaSeparadaPOST()
{
    int i;
    printf("\n ******************************************************************** ");
    printf("\n ************************ Coluna Separada POST **********************\n");
    printf(" ******************************************************************** \n\n");

    for(i = 0; i < qtdLugares; i++)
        printf(" L[%d] = %d\n", i, colunaSeparadaPOST[i]);
}

/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao muda a quantidade de tokens
 * @details Muda a quantidade de tokens de acordo com qual transicao 
 * disparou.
 * @param [in] void
 * @param [out] void
 * @author Gardenia Georgia
 */

void muda_qtdTokens()
{
    int i,j;
    for(i = 0; i < qtdTransicoes; i++)
    {
        if(disparaTRANS[i] != 0)
        {
            habilita_colunaSeparadaPRE(i);
            habilita_colunaSeparadaPOST(i);
            for(j = 0; j < qtdLugares; j++)
                qtdTokens[j] = qtdTokens[j] - colunaSeparadaPRE[j] + colunaSeparadaPOST[j];
        }
    }
}
/* ---------------------------------------------------------------------- */
                                        
/**
 * @ingroup GroupUnique
 * @brief Essa funcao libara memorias alocadas
 * @details Libera memorias alocadas dinamicamente.
 * @param [in] void
 * @param [out] void
 * @author Gardenia Georgia
 */
void liberaMemoria (void)
{
    int i;
    for(i = 0; i < qtdLugares; i++)
    {
        free(conjuntoPOST[i]);
        free(conjuntoPRE[i]);
    }
    free(conjuntoPRE);
    free(qtdTokens);
    free(separaCOLt);
    free(colunaSeparadaPRE);
    free(colunaSeparadaPOST);
    free(transicaoHabilitada);
    free(disparaTRANS);
}



/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160806.231815
 * @date 2016-08-06
 *
 */

void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "petnet", "Petri Net Simulator");
    printf("\nUsage: %s [-h|-v]\n", "petnet");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
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
 * @version 20160806.231815
 * @date 2016-08-06
 *
 */

void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "petrinet", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}


/* ---------------------------------------------------------------------------- */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160714.153029           */
             
