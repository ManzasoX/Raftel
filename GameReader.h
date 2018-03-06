/**
 * Descripción: It defines the game interface
 *
 * @file game.h
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: Falta game_print_screen en el .c
 */

#ifndef __GAMEREADER__
#define __GAMEREADER__

#include "game.h"
#include "command.h"
#include "space.h"

/*Funcion GameReader_load_spaces 
 * @brief Esta funcion se encarga de leer el fichero data que utilizemos para el tablero y analizarlo 
 * para el funcionamiento del programa
 * @param Game*: valor game
 * @param char: valor filename
 * @return: STATUS */

STATUS GameReader_load_spaces(Game* game, char* filename);

#endif
