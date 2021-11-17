/***************************************************************************
 *   Copyright (C) 2005, 2015 by Dr.Beco                                   *
 *   rcb@beco.cc                                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
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
 ***************************************************************************/

/* Template para programa basico Allegro
 * que salva uma imagem em arquivo
 *
 * Para compilar use:
 *     $gcc salvalle.c -o salvalle.x -Wall `allegro-config --cflags --libs`
 */


/* Definicoes de algumas cores */

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))

#define IMAGENAME "teste.bmp" /* nome do arquivo de imagem */

#include <stdio.h>
#include <allegro.h>

int main(void)
{
  BITMAP *buff;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Create a buffer for smooth animation.
  buff = create_bitmap(320,240);
  if(buff == NULL)
  {
    printf("Could not create buffer!\n");
    exit(EXIT_FAILURE);
  }

  circle(buff, 160, 120, 100, CORAMARELO);
  textprintf_ex(buff, font, 50, 50, CORVERDE, CORPRETO, "Teste do circulo.");

  save_bitmap(IMAGENAME, buff, pal);
  destroy_bitmap(buff);
  allegro_exit();
  
  printf("Imagem %s salva com sucesso!\n", IMAGENAME);

  return EXIT_SUCCESS;
}
END_OF_MAIN()

