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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"

/* Estructura _Player con campos id, name, objeto, space */

struct _Player {
  Id id;
  char name[WORD_SIZE + 1];
  Id object;
  Id space;
};

/*Funcion: player_create */
/*Creamos un espacio mediante un puntero (newPlayer) que apunta a id (parametro introducido de tipo long) */

Player* player_create(Id id) {

  	Player *newPlayer = NULL;

  	if (id == NO_ID)
    	return NULL;

  	newPlayer = (Player *) malloc(sizeof (Player));

  	if (newPlayer == NULL) {
    	return NULL;
  	}
  
	newPlayer->id = id;

  	newPlayer->name[0] = '\0';
  	newPlayer->object = NO_ID;
  	newPlayer ->space = NO_ID;

  	return newPlayer;
}

/*Funcion: player_destroy */
/*Libera la memoria dinamica reservada para el jugador del paramentro introducido, devolviendo un OK (1) */

STATUS player_destroy(Player* player) {
  	if (!player) {
    	return ERROR;
  	}

  	free(player);
  	player = NULL;

  	return OK;
}

/*Funcion: player_set_name */
/*Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion */

STATUS player_set_name(Player* player, char* name) {
  	
	if (!player || !player) {
    	return ERROR;
  	}

  	if (!strcpy(player->name, name)) {
    	return ERROR;
  	}

  	return OK;
}

/*Funcion: player_set_object */
/*Esta funcion permite modificar el objecto introducido por parametro, devolviendo un OK tras la modificacion */

STATUS player_set_object(Player* player, Id id) {
  
	if (!player || id == NO_ID) {
    	return ERROR;
  	}
  
	player->object = id;
  	return OK;
}

/*Funcion player_set_space */
/*Esta funcion permite modificar el espacio introducido por parametro, devolviendo un OK tras la modificacion */

STATUS player_set_space(Player* player, Id id) {
  
	if (!player || id == NO_ID) {
    	return ERROR;
  	}
  
	player->space = id;
  	return OK;
}

/*Función: player_get_name */
/*Devuelve el valor name del jugador introducido por parametro */

const char * player_get_name(Player* player) {
  
	if (!player) {
    	return NULL;
  	}
  
	return player->name;
}

/*Funcion: player_get_id */
/*Devuelve el valor id del jugador introducido por parametro */

Id player_get_id(Player* player) {
  	
	if (!player) {
    	return NO_ID;
  	}
  
	return player->id;
}

/*Función: player_get_object */
/*Devuelve el valor object del jugador introducido por parametro */

Id player_get_object(Player* player) {
  
	if (!player) {
    	return NO_ID;
  	}
  
	return player->object;
}

/*Función: player_get_space */
/*Devuelve el valor espacio del jugador introducido por parametro */

Id player_get_space(Player* player) {
  
	if (!player) {
    	return NO_ID;
  	}

  	return player->space;
}

/*Función: player_print*/
/*Imprime la información introducida por el usuario */

STATUS player_print(Player* player) {

  	if (!player) {
    	return ERROR;
  	}
  
	/*Imprime el valor de id y el nombre introducidos*/
  
	fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  	/*Imprime player's object siempre y cuando el jugador tenga un objeto, usa la función player_get_object*/ 
  
	if (player_get_object(player)) {
    	fprintf(stdout, "---> Player's object.\n");
  	} else {
    	fprintf(stdout, "---> The player has no object.\n");
  	}
  
	/*Imprime player's space siempre y cuando el jugador tenga un objeto, usa la función player_get_space*/
  
	if (player_get_space(player)) {
    	fprintf(stdout, "---> Player's space.\n");
  	} else {
    	fprintf(stdout, "---> The player has no space.\n");
  	}

  	return OK;
}

