/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Juan Martin
 * @version 1.0
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "graphic_engine.h"

struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback;
};


/*Funcion: graphic_engine_create*/

Graphic_engine *graphic_engine_create(){
  	static Graphic_engine *ge = NULL;

  	if (ge)
    	return ge;

  	screen_init();
  	ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

	/*Pinta los distintos campos del tablero */

	  ge->map      = screen_area_init( 1, 1, 48, 13);
  	ge->descript = screen_area_init(50, 1, 29, 13);
  	ge->banner   = screen_area_init(28,15, 23,  1);
  	ge->help     = screen_area_init( 1,16, 78,  2);
  	ge->feedback = screen_area_init( 1,19, 78,  3);

  	return ge;
}

/*Funcion: graphic_engine_destroy*/

void graphic_engine_destroy(Graphic_engine *ge){
  	if (!ge)
    	return;

  	screen_area_destroy(ge->map);
  	screen_area_destroy(ge->descript);
  	screen_area_destroy(ge->banner);
  	screen_area_destroy(ge->help);
  	screen_area_destroy(ge->feedback);

  	screen_destroy();
  	free(ge);
}

/*Funcion graphic_engine_paint_game */

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){

	Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID, player_loc = NO_ID, id_east = NO_ID, id_west = NO_ID;

  	Space* space_act = NULL;
  	char obj='\0';
  	char str[255];
  	T_Command last_cmd = UNKNOWN;
  	extern char *cmd_to_str[];

  	/* Paint in the map area */

	screen_area_clear(ge->map);

	if ((id_act = game_get_player_location(game)) != NO_ID){ 
    	space_act = game_get_space(game, id_act);
    	id_back = space_get_north(space_act);
    	id_next = space_get_south(space_act);
		  id_east = space_get_east(space_act);
		  id_west = space_get_west(space_act);


    	if (game_get_object_location(game) == id_back)
      	obj='*';
    	else
      	obj=' ';

    	if ( id_back != NO_ID ) {
      	sprintf(str, "                  |         %2d| ",(int) id_back);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |     %c     |   ",obj);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  +-----------+");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                        ^");
      	screen_area_puts(ge->map, str);
   	 }


    	if(game_get_object_location(game) == id_act)
      	obj='*';
    	else
      	obj=' ';

    	if(id_act != NO_ID && id_east == NO_ID && id_west == NO_ID) {
      	sprintf(str, "                  +-----------+   ");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  | 8D      %2d|  ",(int) id_act);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |     %c     |  ",obj);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  +-----------+   ");
      	screen_area_puts(ge->map, str);
   	  }

	if(id_act != NO_ID && id_east != NO_ID && id_west == NO_ID){
	      sprintf(str, "                  +-----------+    ");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  | 8D      %2d| > ",(int) id_act);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |     %c     |   ",obj);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  +-----------+    ");
      	screen_area_puts(ge->map, str);
   	  }

	if(id_act != NO_ID && id_east != NO_ID && id_west != NO_ID){
	sprintf(str, "                  +-----------+    ");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                < | 8D      %2d| > ",(int) id_act);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |     %c     |   ",obj);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  +-----------+    ");
      	screen_area_puts(ge->map, str);
   	  }

	if(id_act != NO_ID && id_east == NO_ID && id_west != NO_ID){
	      sprintf(str, "                  +-----------+    ");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                < | 8D      %2d|   ",(int) id_act);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |     %c     |   ",obj);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  +-----------+    ");
      	screen_area_puts(ge->map, str);
   	  }


    	if (game_get_object_location(game) == id_next)
      	obj='*';
    	else
      	obj=' ';

    	if(id_next != NO_ID) {
      	sprintf(str, "                        v");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  +-----------+");
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |         %2d|",(int) id_next);
      	screen_area_puts(ge->map, str);
      	sprintf(str, "                  |     %c     |",obj);
      	screen_area_puts(ge->map, str);
   	 }



	}

	/* Paint the in the description area */

	screen_area_clear(ge->descript);
	if ((obj_loc = game_get_object_location(game)) != NO_ID){

	sprintf(str, "  Object location:%d", (int)obj_loc);
	screen_area_puts(ge->descript, str);

	}

	if ((player_loc = game_get_player_location(game)) != NO_ID){

	sprintf(str, "  Player location:%d", (int)player_loc);
	screen_area_puts(ge->descript, str);
	}

	if (( die_getnumber(game->die)) <= 6 || ( die_getnumber(game->die)) > 0 ){

	sprintf(str, "  Die value:%d", die_getnumber(game->die));
	screen_area_puts(ge->descript, str);
	}


  	/* Paint the in the banner area */

	screen_area_puts(ge->banner, " The game of the Goose ");

	/* Paint the in the help area */

  	screen_area_clear(ge->help);
  	sprintf(str, " The commands you can use are:");
  	screen_area_puts(ge->help, str);
  	sprintf(str, "     following or f, previous or p, quit or q, take or t, drop or d, east or e, west or w, roll or r");
  	screen_area_puts(ge->help, str);

  	/* Paint the in the feedback area */

  	last_cmd = game_get_last_command(game);
  	sprintf(str, " %s", cmd_to_str[last_cmd-NO_CMD]);
  	screen_area_puts(ge->feedback, str);

 	 /* Dump to the terminal */
  	screen_paint();
  	printf("prompt:> ");
}
