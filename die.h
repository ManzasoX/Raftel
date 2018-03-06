/** 
 * Descripción: Define las funciones y estructuras utilizadas para die
 * 
 * @file die.h
 * @author Miguel Manzano
 * @version 1.0 
 * @date 1-03-2018
 * @copyright GNU Public License
 * Comments: 
 */

#include "types.h"

#ifndef DIE_H
#define DIE_H

typedef struct _Die Die;

/* Name: die_create
 * @brief Crea el dado
 * @param no recibe ningun parametro 
 * @return Die*
*/

Die* die_create();

/* Name: die_destroy
 * @brief Elimina el dado
 * @param Die* : direccion de un tipo die
 * @return void
*/

void die_destroy(Die* d);

/* Name: die_roll
 * @brief Realiza una tirada de dado
 * @param Die* : direccion de un tipo die
 * @return int
*/

int die_roll(Die* d);

/* Name: die_getnumber
 * @brief Obtiene el valor del campo number de die
 * @param Die*: direccion de un tipo die
 * @return int
*/

int die_getnumber(Die* d);

/* Name: die_getnumber
 * @brief Imprime el contenido del dado
 * @param FILE*: direccion de un fichero tipo file
 * @param Die*: direccion de un tipo die
 * @return int
*/

STATUS die_print (FILE *f, Die* d);



#endif
