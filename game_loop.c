/**
 * Descripción: It defines the game loop
 *
 * @file game_loop.c
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"

/*Esta es la funcion principal del juego */

int main(int argc, char *argv[]){
   	Game game;
   	T_Command command = NO_CMD;
  	Graphic_engine *gengine;

  	if (argc < 2){
     	fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); /*Imprime esta frase en el caso de que no se 
      	introduzca mas de un argumento en la ejecucion */
      	return 1;
   	}
  	 
	if (game_create_from_file(&game, argv[1]) == ERROR){
      	fprintf(stderr, "Error while initializing game.\n"); /*Imprime esta frase si el fichero data introducido no es correcto */
      	return 1;
   	}

	if ((gengine = graphic_engine_create()) == NULL){
	fprintf(stderr, "Error while initializing graphic engine.\n"); /*Imprime esta frase si se producen fallos en el graphic engine */
	game_destroy(&game);
	return 1;
	}

	while ( (command != QUIT) && !game_is_over(&game) ){
	graphic_engine_paint_game(gengine, &game); /*Si no hay errores se ejecuta el programa */
	command = get_user_input();
	game_update(&game, command);
	} 

	game_destroy(&game);
	graphic_engine_destroy(gengine);
	return 0;
}
