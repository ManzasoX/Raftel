/** 
 * Descripción: Define las funciones y estrucutras utilizadas para space 
 * 
 * @file space.h
 * @author Miguel Manzano
 * @version 1.2
 * @date 16-02-2018
 * @copyright GNU Public License
 * Comments: ya estan los comentarios
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/* Name: object_create
 * @brief Creamos un objeto mediante un puntero (newObject) que apunta a id (parametro introducido de tipo long)
 * @param Id: long id 
 * @return Object
*/

Object* object_create(Id id);

/* Name: object_destroy
 * @brief Libera la memoria dinamica reservada para el objeto del paramentro introducido, devolviendo un OK (1)
 * @param Object*: valor object
 * @return STATUS
*/


STATUS object_destroy(Object* object);

/* Name: object_set_name
 * @brief Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion
 * @param Object*: valor object
 * @param char*: valor name
 * @return STATUS
*/

STATUS object_set_name(Object* object, char* name);

/* Name: object_get_name
 * @brief Devuelve el valor name del objeto introducido por parametro
 * @param Object*: valor object
 * @return char
*/

const char * object_get_name(Object* object);

/* Name: object_get_id
 * @brief Devuelve el valor id del objeto introducido por parametro
 * @param Object*: valor objeto
 * @return Id
*/

Id object_get_id(Object* object);

#endif
