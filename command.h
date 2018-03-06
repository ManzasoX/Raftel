/**
 * @brief: Implementa el puntero
 *
 * @file command.h
 * @author Miguel Manzano
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#ifndef COMMAND_H
#define COMMAND_H

/*Enumeración de los comandos asignandoles el valor desde -1 al 8*/

typedef enum enum_Command {
   NO_CMD = -1, UNKNOWN, QUIT, FOLLOWING, PREVIOUS, TAKE, DROP, EAST, WEST, ROLL} T_Command; 

/*NO_CMD no se introduce ningun comando, UNKNOWN no identifica el comando introducido, 
  QUIT para salir del juego, FOLLOWING para avanzar, 
  PREVIOUS para retroceder, TAKE para coger un objeto, DROP para soltar un objeto, 
  EAST para moverse hacia la derecha en casillas especiales,
  WEST para moverse a la izquierda en casillas especiales
  ROLL para lanzar el dado */


/* Name: get_user_input
 * @brief Función que devuelve un dato del tipo T_Command, enumerado anteriormente.
 * @param no recibe ningun parametro 
 * @return T_Command
*/

T_Command get_user_input(); 

#endif
