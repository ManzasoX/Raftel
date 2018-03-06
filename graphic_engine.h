/** 
 * @brief It defines a textual graphic engine
 * 
 * @file graphic_engine.h
 * @author Juan Martin
 * @version 1.0 
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/* Name: graphic_engine_create
 * @brief: crea una variable de tipo graphic_engine, la inicializa a null y a continuacion le asigna valores a todos sus elementos
 * @param: sin parametros
 * @return: Graphic_engine*
*/
Graphic_engine* graphic_engine_create();


/* Name: graphic_engine_destroy
 * @brief: llama a varias funciones para liberar la memoria reservada para el puntero ge
 * @param: Graphic_engine *ge , un puntero a una variable
 * @return: void
*/
void graphic_engine_destroy(Graphic_engine *ge);


/* Name: game_create
 * @brief imprime en pantalla una casilla con * si está el objeto y vacio si no, ademas escribe diferentes datos,
   como el nombre del juego o los comandos que se pueden utilizar
 * @param Game*: sin parametros
 * @return Graphic_engine*
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);


void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
