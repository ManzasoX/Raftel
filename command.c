/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author Miguel Manzano
 * @version 1.1
 * @date 11-02-2018 
 * @copyright GNU Public License
 * Comments: 
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30
#define N_CMD 10

/*Definición de punteros a cadenas de caracteres con una longitud de 10 caracteres*/

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Quit", "Following", "Previous", "Take", "Drop", "East", "West", "Roll"}; /*añadir los nuevos comandos aquí*/
char *short_cmd_to_str[N_CMD] = {"","","q","f","p","t","d", "e", "w", "r"}; /*comandos a utilizar para movernos por el tablero */

/*Funcion: get_user_input */
/*Función que devuelve un comando del tipo T_Command, enumerado anteriormente.*/

T_Command get_user_input(){  

  	T_Command cmd = NO_CMD;
  	char input[CMD_LENGHT] = "";
  	int i=UNKNOWN - NO_CMD + 1;
  
  	if (scanf("%s", input) > 0){    
  	cmd = UNKNOWN;
       	while(cmd == UNKNOWN && i < N_CMD){
	    	if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input,cmd_to_str[i])){
			cmd = i + NO_CMD;
	    	}

	    	else{
		i++;
	    	}
      	   }
  	}
  	return cmd;
}
