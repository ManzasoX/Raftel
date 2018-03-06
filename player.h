/**
 * Descripción: Contiene la implementacion de las funciones asociadas a player
 *
 * @file player.c
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/* Name: player_create
 * @brief Creamos un espacio mediante un puntero (newPlayer) que apunta a id (parametro introducido de tipo long)
 * @param Id: long id 
 * @return Player
*/

Player* player_create(Id id);

/* Name: player_destroy
 * @brief Libera la memoria dinamica reservada para el jugador del paramentro introducido, devolviendo un OK (1)
 * @param Player*: valor player
 * @return STATUS
*/

STATUS player_destroy(Player* player);

/* Name: player_set_name
 * @brief Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion
 * @param Player*: valor player
 * @param char*: valor name
 * @return STATUS
*/

STATUS player_set_name(Player* player, char* name);

/* Name: player_set_object
 * @brief Esta funcion permite modificar el objecto introducido por parametro, devolviendo un OK tras la modificacion
 * @param Player*: valor player
 * @param Id: valor id
 * @return STATUS
*/

STATUS player_set_object(Player* player, Id id);

/* Name: player_set_space
 * @brief Esta funcion permite modificar el espacio introducido por parametro, devolviendo un OK tras la modificacion
 * @param Player*: valor player
 * @param Id: valor id
 * @return STATUS
*/

STATUS player_set_space(Player* player, Id id);

/* Name: player_get_name
 * @brief Devuelve el valor name del jugador introducido por parametro
 * @param Player*: valor player
 * @return char
*/

const char * player_get_name(Player* player);

/* Name: player_get_id
 * @brief Devuelve el valor id del jugador introducido por parametro
 * @param Player*: valor player
 * @return Id
*/

Id player_get_id(Player* player);

/* Name: player_get_object
 * @brief Devuelve el valor object del jugador introducido por parametro
 * @param Player*: valor player
 * @return Id
*/

Id player_get_object(Player* player);

/* Name: player_get_space
 * @brief Devuelve el valor espacio del jugador introducido por parametro
 * @param Player*: valor player
 * @return Id
*/

Id player_get_space(Player* player);

/* Name: player_print
 * @brief Imprime la información introducida por el usuario
 * @param Player*: valor player
 * @return STATUS
*/

STATUS player_print(Player* player);

#endif
