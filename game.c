/**
 * Descripción: It implements the game interface and all the associated callbacks
 *
 * @file game.c
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "player.h"
#include "object.h"
#include "GameReader.h"
#include "types.h"
#include "die.h"
#include "set.h"

#define N_CALLBACK 10   /*cantidad de comandos que se definen, hay que aumentar el numero cuando se implementen los nuevos comandos*/
#define ID_object 0
#define ID_die 0
#define ID_player 0
#define obj1 0

/* Define the function type for the callbacks */

typedef void (*callback_fn)(Game* game);

/* List of callbacks for each command in the game */  /*los callbacks hacen las acciones de los comandos*/

  void game_callback_unknown(Game* game);
  void game_callback_quit(Game* game);
  void game_callback_following(Game* game);
  void game_callback_previous(Game* game);
  void game_callback_take(Game* game);
  void game_callback_drop(Game* game);
  void game_callback_east(Game* game);
  void game_callback_west(Game* game);
  void game_callback_roll(Game* game);

/*asigna un numero a cada callback como si fuese una enumeracion para luego utilizar esos numeros para hacer llamadas a estos callbacks */

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_quit,
  game_callback_following,
  game_callback_previous,
  game_callback_take,
  game_callback_drop,
  game_callback_east,
  game_callback_west,
  game_callback_roll};

/*Funciones privadas */

STATUS game_add_space(Game* game, Space* space);

Id game_get_space_id_at(Game* game, int position);

/*Modifica la localizacion del jugador */

STATUS game_set_player_location(Game* game, Id id);

/*Modifica la localizacion del objeto */

STATUS game_set_object_location(Game* game, Id id);

/*Funcion: game_create */
/*recibe un puntero a un Game y lo inicializa, es decir pone todos los elementos de la estructura a NULL o en su estado negativo */

STATUS game_create(Game* game) {

	int i;

  	for (i = 0; i < MAX_SPACES; i++) {
   	  game->spaces[i] = 0;
      space_set_object(game->spaces[i], NO_ID);
  	}

	game->player = player_create(1);
	game->objects[obj1] = object_create(1);
	game->die = ID_die;

  	game_set_player_location(game, NO_ID);
  	game_set_object_location(game, NO_ID);
  	game->last_cmd = NO_CMD;
	  game->die = die_create();
	  die_roll(game->die);

  	return OK;
}

/*Funcion: game_create_from_file */
/* Esta funcion llama a 4 funciones, comprueba si las dos primeras dan error e inicializa las dos segundas a 0 */

STATUS game_create_from_file(Game* game, char* filename) {

  	if (game_create(game) == ERROR)
    	return ERROR;

  	if (GameReader_load_spaces(game, filename) == ERROR)
    	return ERROR;



  	game_set_player_location(game, game_get_space_id_at(game, 0));
  	game_set_object_location(game, game_get_space_id_at(game, 0));

  	return OK;
}

/*Funcion: game_destroy */
/* esta funcion llama a otra que libera la memoria ocupada por los las estructuras que definen el espacio */

STATUS game_destroy(Game* game) {
  	int i = 0;

  	for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    	space_destroy(game->spaces[i]);
  	}

	die_destroy(game->die);

  for(i=0; i>TAMSET; i++){
    game->objects[i] = NULL;
    object_destroy(game->objects[i]);
    free(game->objects[i]);
  }




	player_destroy(game->player);



  	return OK;
}

/*Funcion privada: game_add_space */
/* Añade un valor a spaces */

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  	if (!space) {
    	return ERROR;
  	}

  	while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    	i++;
  	}

  	if (i >= MAX_SPACES) {
    	return ERROR;
  	}

  	game->spaces[i] = space;

  	return OK;
}

/*Funcion privada: game_get_space_id_at */
/* Obtiene la id del espacio segun la posicion introducida */

Id game_get_space_id_at(Game* game, int position) {

  	if (position < 0 || position >= MAX_SPACES) {
   	return NO_ID;
  	}

  	return space_get_id(game->spaces[position]);
}

/*Funcion: game_get_space */
/* Con la id pasada como parametro busca y devuelve un puntero al elemento space al que le corresponde la id */
Space* game_get_space(Game* game, Id id){
  int i = 0;

  	if (!id) {
    	return NULL;
  	}

  	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    	if (id == space_get_id(game->spaces[i])){
      	return game->spaces[i];
   	 }
  	}

  	return NULL;
}

/*Funcion privada: game_set_player_location */
/*Modifica la localizacion del jugador */

STATUS game_set_player_location(Game* game, Id id) {

  	if (!id) {
    	return ERROR;
  	}

  	player_set_space(game->player, id);

	return OK;
}

/*Funcion privada: game_set_object_location */
/*Modifica la localizacion del objeto */

STATUS game_set_object_location(Game* game, Id id) {

  	int i;

  	if (!id) {
    	return ERROR;
  	}

  	for(i=0; i < MAX_SPACES; i++){   /*Recorre todas las casillas buscando la que coresponda con la id del argumento*/

     	if(id == (space_get_id(game->spaces[i]))){
       	space_set_object(game->spaces[i], object_get_id(game->objects[obj1]));  /*cuando se encuentre la id se asigna el objeto*/
       	return OK;
     	}
  	}
  	return ERROR;
}

/*Funcion: game_get_player_location */
/* devuelve la localización del jugador almacenada en la estructura game */

Id game_get_player_location(Game* game) {
  	return player_get_space(game->player);
}

/*Funcion: game_get_object_location*/
/* devuelve la localización del objeto almacenada en la estructura game */

Id game_get_object_location(Game* game) {
	int i,j;
	Id objID;

  	if(!game)
	return NO_ID;

/*guardamos la id del objeto a localizar*/
	objID = object_get_id(game->objects[obj1]);
	for(i=0; i< MAX_SPACES; i++)
  {
    for(j=0; j<TAMSET; j++){
		    if(objID == (set_get_id(space_get_object(game->spaces[i]), j)))
        {
		        return (space_get_id(game->spaces[i]));
        }
    }
	}

  return NO_ID;
}

/*Funcion: game_update */
/* iguala last_cmd a cmd de forma que asi segun el numero de cmd llama a su correspondiente callback*/

STATUS game_update(Game* game, T_Command cmd) {

	game->last_cmd = cmd;
  	(*game_callback_fn_list[cmd])(game);

	return OK;
}

/*Funcion: game_get_last_command */
/*devuelve el ultimo comando utilizado, almacenado en last_cmd de la estructura game*/

T_Command game_get_last_command(Game* game){

	return game->last_cmd;
}

/*Funcion: game_print_data */
/* imprime en la pantalla los datos del espacio, el objeto y el jugador */

void game_print_data(Game* game) {

	int i = 0;

 	 printf("\n\n-------------\n\n");

  	printf("=> Spaces: \n");
  	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    	space_print(game->spaces[i]);
  	}

  	printf("=> Object location: %d\n", (int) game_get_object_location(game));
  	printf("=> Player location: %d\n", (int) player_get_space(game->player));
  	printf("prompt:> ");
}

/*Funcion: game_is_over */

BOOL game_is_over(Game* game) {

	return FALSE;
}

/*Callbacks implementation for each action */

void game_callback_unknown(Game* game) {
}

void game_callback_quit(Game* game) {
}

/*Funcion privada: game_callback_following */
/* Permite utilizar el comando following para avanzar por el tablero */

void game_callback_following(Game* game) {
  	int i = 0;
  	Id current_id = NO_ID;
  	Id space_id = NO_ID;

 	space_id = game_get_player_location(game);
  	if (space_id == NO_ID) {
   	return;
  	}

 	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    	current_id = space_get_id(game->spaces[i]);

	if (current_id == space_id) {
      	current_id = space_get_south(game->spaces[i]);

	if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      	}
      	return;
    	}
  	}
}

/*Funcion privada: game_callback_previous*/
/* Permite utilizar el comando previous para retroceder en el tablero */

void game_callback_previous(Game* game) {
 	 int i = 0;
 	 Id current_id = NO_ID;
 	 Id space_id = NO_ID;

  	space_id = game_get_player_location(game);

  	if (NO_ID == space_id) {
    	return;
  	}

  	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    	current_id = space_get_id(game->spaces[i]);
    	if (current_id == space_id) {
      	current_id = space_get_north(game->spaces[i]);
      	if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      	}
     	 return;
   	 }
 	 }
}

/*Funcion privada: game_callback_take*/
/* Permite utilizar el comando take para coger un objeto de una casilla del tablero */

void game_callback_take(Game* game) {

  	Id spaceId = NO_ID;
  	Id objectLocId = NO_ID;
  	int aux, i;
    aux = 0;

  	spaceId = game_get_player_location(game);  /*ID del espacio donde está el jugador*/
  	objectLocId = game_get_object_location(game); /*ID del espacio donde está el objeto*/
  	if (NO_ID == spaceId) {
   	return;
 	 }

  	if (spaceId == objectLocId)/*jugador y objeto en la misma casilla*/
    {
	     for (i = 0; game->spaces[i] != NULL; i++)/*recorre game->spaces[]*/
       {
          if (spaceId == space_get_id(game->spaces[i]))/*busca la posición en game->space[] de la casilla donde se encuentra el jugador*/
   			  aux = i;/*game->space donde está el jugador*/
       }

       set_delete_id(space_get_object(game->spaces[aux]), object_get_id(game->objects[0]));

	     player_set_object(game->player, object_get_id(game->objects[0]));
	   }
    return;
 }

/*Funcion privada: game_callback_drop*/
/* Permite utilizar el comando drop para soltar un objeto en una casilla del tablero */

void game_callback_drop(Game* game) {
  	Id spaceId = NO_ID;
	Id objectId = NO_ID;
	int aux, i;

  	spaceId = game_get_player_location(game);

	if (NO_ID == spaceId) {
    	return;
  	}

	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
   	if (spaceId == space_get_id(game->spaces[i]))
   	aux = i;
  	}

	objectId = player_get_object(game->player);
	player_set_object(game->player, NO_ID);
	space_set_object(game->spaces[aux], objectId);

	return;
}

/*Funcion privada: game_callback_east */
/* Permite utilizar el comando east para desplazarse a casillas especiales por el tablero */

void game_callback_east(Game* game) {
  	int i = 0;
  	Id current_id = NO_ID;
  	Id space_id = NO_ID;

  	space_id = game_get_player_location(game);
  	if (space_id == NO_ID) {
    	return;
  	}

  	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    	current_id = space_get_id(game->spaces[i]);
    	if (current_id == space_id) {
      	current_id = space_get_east(game->spaces[i]);
      	if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      	}
      	return;
    	}
  	}
}

/*Funcion privada: game_callback_west*/
/* Permite utilizar el comando west para desplazarse a casillas especiales por el tablero */

void game_callback_west(Game* game) {
  	int i = 0;
  	Id current_id = NO_ID;
  	Id space_id = NO_ID;

  	space_id = game_get_player_location(game);

  	if (NO_ID == space_id) {
    	return;
  	}

  	for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    	current_id = space_get_id(game->spaces[i]);

	if (current_id == space_id) {
      	current_id = space_get_west(game->spaces[i]);

	if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      	}
      	return;

    	}
  	}
}

/*Funcion privada: game_callback_roll*/
/* Permite utilizar el comando roll para lanzar el dado */

void game_callback_roll(Game* game){

	die_roll(game->die);

}
