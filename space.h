/**
 * Descripción: Define las funciones y estrucutras utilizadas para space
 *
 * @file space.h
 * @author Miguel Manzano
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments:
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/* Name: space_create
 * @brief Creamos un espacio mediante un puntero (newSpace) que apunta a id (parametro introducido de tipo long)
 * @param Id: long id
 * @return Space
*/

Space* space_create(Id id);

/* Name: space_destroy
 * @brief Libera la memoria dinamica reservada para el espacio del paramentro introducido, devolviendo un OK (1)
 * @param Space*: valor space
 * @return STATUS
*/

STATUS space_destroy(Space* space);

/* Name: space_get_id
 * @brief Devuelve el valor id del espacio introducido por parametro
 * @param Space*: valor space
 * @return Id
*/

Id space_get_id(Space* space);

/* Name: space_set_name
 * @brief Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion
 * @param Space*: valor space
 * @param char*: valor name
 * @return STATUS
*/

STATUS space_set_name(Space* space, char* name);

/* Name: space_get_name
 * @brief Devuelve el valor name del espacio introducido por parametro
 * @param Space*: valor space
 * @return char
*/

const char* space_get_name(Space* space);

/* Name: space_set_north
 * @brief Esta funcion permite modificar la direccion norte a la introducida mediante el parametro id, devolviendo un OK tras la modificacion
 * @param Space*: valor space
 * @param Id: long id
 * @return STATUS
*/

STATUS space_set_north(Space* space, Id id);

/* Name: space_get_north
 * @brief Devuelve el valor de direccion norte del espacio introducido por parametro
 * @param Space*: valor space
 * @return Id
*/

Id space_get_north(Space* space);

/* Name: space_set_south
 * @brief Esta funcion permite modificar la direccion sur a la introducida mediante el parametro id, devolviendo un OK tras la modificacion
 * @param Space*: valor space
 * @param Id: long id
 * @return STATUS
*/

STATUS space_set_south(Space* space, Id id);

/* Name: space_get_south
 * @brief Devuelve el valor de direccion sur del espacio introducido por parametro
 * @param Space*: valor space
 * @return Id
*/

Id space_get_south(Space* space);

/* Name: space_set_east
 * @brief Esta funcion permite modificar la direccion este a la introducida mediante el parametro id, devolviendo un OK tras la modificacion
 * @param Space*: valor space
 * @param Id: long id
 * @return STATUS
*/

STATUS space_set_east(Space* space, Id id);

/* Name: space_get_east
 * @brief Devuelve el valor de direccion este del espacio introducido por parametro
 * @param Space*: valor space
 * @return Id
*/

Id space_get_east(Space* space);

/* Name: space_set_west
 * @brief Esta funcion permite modificar la direccion oeste a la introducida mediante el parametro id, devolviendo un OK tras la modificacion
 * @param Space*: valor space
 * @param Id: long id
 * @return STATUS
*/

STATUS space_set_west(Space* space, Id id);

/* Name: space_get_west
 * @brief Devuelve el valor de direccion oeste del espacio introducido por parametro
 * @param Space*: valor space
 * @return Id
*/

Id space_get_west(Space* space);

/* Name: space_set_object
 * @brief Esta funcion permite modificar el valor object por el valor introducido mediante el parametro value (tipo BOOL) , devolviendo un OK tras la modificacion
 * @param Space*: valor space
 * @param BOOL: value
 * @return STATUS
*/

STATUS space_set_object(Space* space, Id value);

/* Name: space_get_object
 * @brief Devuelve el valor object del espacio introducido por parametro
 * @param Space*: valor space
 * @return BOOL
*/

Conjunto* space_get_object(Space* space);

/* Name: space_print
 * @brief Imprime la información introducida por el usuario
 * @param Space*: valor space
 * @return STATUS
*/

STATUS space_print(Space* space);

#endif
