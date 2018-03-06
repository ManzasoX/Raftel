/**
 * Descripción: modulo encargado de la carga de espacios
 *
 * @file game_reader.c
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: en curso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "command.h"
#include "space.h"

/*Funcion GameReader_load_spaces */
/*Esta funcion se encarga de leer el fichero data que utilizemos para el tablero y analizarlo 
para el funcionamiento del programa*/

STATUS GameReader_load_spaces(Game* game, char* filename) {
  	FILE* file = NULL;
  	char line[WORD_SIZE] = "";
  	char name[WORD_SIZE] = "";
  	char* toks = NULL;
  	Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  	Space* space = NULL;
  	STATUS status = OK;
  
  	if (!filename) {
    	return ERROR;
  	}
  
  	file = fopen(filename, "r");
  	if (file == NULL) {
    	return ERROR;
 	}
  	
  	while (fgets(line, WORD_SIZE, file)) {
    	if (strncmp("#s:", line, 3) == 0) {
      	toks = strtok(line + 3, "|");
      	id = atol(toks);
      	toks = strtok(NULL, "|");
      	strcpy(name, toks);
      	toks = strtok(NULL, "|");
      	north = atol(toks);
     	toks = strtok(NULL, "|");
      	east = atol(toks);
      	toks = strtok(NULL, "|");
      	south = atol(toks);
     	toks = strtok(NULL, "|");
      	west = atol(toks);

#ifdef DEBUG 

      	printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);

#endif
      	space = space_create(id);
      	if (space != NULL) {
	space_set_name(space, name);
	space_set_north(space, north);
	space_set_east(space, east);
	space_set_south(space, south);
	space_set_west(space, west);
	game_add_space(game, space);
      	}
   	}
  	}
  
  	if (ferror(file)) {
    	status = ERROR;
  	}
  
  	fclose(file);
  
  	return status;
}

