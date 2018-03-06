/**
 * Descripción: It defines the game interface
 *
 * @file game.h
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "die.h"

/* Estructura Game con un campo player que recoge la informacion del jugador, un campo object que recoge la informacion del objeto, un campo spaces  y un campo last_cmd de tipo T_command que señala el ultimo comando utilizado */

typedef struct _Game{
  Player *player;
  Object *object;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
  Die* die;
} Game;

/* Name: game_create
 * @brief recibe un puntero a un Game y lo inicializa, es decir pone todos los elementos de la estructura a NULL o en su estado negativo
 * @param Game*: valor game
 * @return STATUS
*/

STATUS game_create(Game* game);

/* Name: game_create_from_file
 * @brief Esta funcion llama a 4 funciones, comprueba si las dos primeras dan error e inicializa las dos segundas a 0
 * @param Game*: valor game
 * @param char*: valor filename
 * @return STATUS
*/

STATUS game_create_from_file(Game* game, char* filename);

/* Name: game_update
 * @brief  iguala last_cmd a cmd
 * @param Game*: valor game
 * @param T_Command: int cmd
 * @return STATUS
*/

STATUS game_update(Game* game, T_Command cmd);

/* Name: game_destroy
 * @brief  esta funcion llama a otra que libera la memoria ocupada por los las estructuras que definen el espacio
 * @param Game*: valor game
 * @return STATUS
*/

STATUS game_destroy(Game* game);

/* Name: game_is_over
 * @brief  devuelve solo dos valores, true o false
 * @param Game*: valor game
 * @return BOOL
*/

BOOL game_is_over(Game* game);

/* Name: game_print_screen
 * @brief Imprime los datos de pantalla
 * @param Game*: valor game
 * @return void
*/

void game_print_screen(Game* game);

/* Name: game_print_data
 * @brief  imprime en la pantalla los datos del espacio, el objeto y el jugador
 * @param Game*: valor game
 * @return void
*/

void game_print_data(Game* game);

/* Name: game_get_space
 * @brief Con la id pasada como parametro busca y devuelve un puntero al elemento space al que le corresponde la id
 * @param Game*: valor game
 * @param Id: long id
 * @return Space
*/

Space* game_get_space(Game* game, Id id);

/* Name: game_get_player_location
 * @brief devuelve la localización del jugador almacenada en la estructura game
 * @param Game*: valor game
 * @return Id
*/

Id  game_get_player_location(Game* game);

/* Name: game_get_object_location
 * @brief devuelve la localización del objeto almacenada en la estructura game
 * @param Game*: valor game
 * @return Id
*/

Id  game_get_object_location(Game* game);

/* Name: game_get_last_command
 * @brief devuelve el ultimo comando utilizado, almacenado en last_cmd de la estructura game
 * @param Game*: valor game
 * @return T_Command
*/

T_Command game_get_last_command(Game* game);

/* Name: game_add_space
 * @brief añade un espacio
 * @param Game*: valor game
 * @param Space* : valor space
 * @return T_Command
*/

STATUS game_add_space(Game* game, Space* space);
#endif
