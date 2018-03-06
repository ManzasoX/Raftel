/** 
 * Descripción: Define las funciones y estructuras utilizadas para set
 * 
 * @file set.h
 * @author Juan Martín y Miguel Manzano
 * @version 1.1 
 * @date 25-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#ifndef SET_H
#define SET_H

typedef struct _Conjunto Conjunto;

/* Name: conjunto_create
 * @brief Creacion de conjuntos
 * @param no recibe ningun parametro 
 * @return Conjunto*
*/

Conjunto* conjunto_create();

/* Name: conjunto_destroy
 * @brief Elimina el conjunto
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return void
*/

void conjunto_destroy(Conjunto *c);

/* Name: conjunto_add
 * @brief Añade un elemento al conjunto devolviendo un OK o ERROR si hay fallos
 * @param Conjunto * : direccion de un tipo Conjunto
 * @param Id: valor del nuevo elemento del conjunto 
 * @return Status
*/

Status conjunto_add(Conjunto *c, Id n);

/* Name: conjunto_delete
 * @brief Elimina un valor del conjunto, devolviendo un OK o ERROR si hay fallos
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return Status
*/

Status conjunto_delete(Conjunto *c);

/* Name: conjunto_print
 * @brief Imprime el conjunto
 * @param Conjunto* : direccion de un tipo Conjunto
 * @param FILE *: direccion de un tipo FILE
 * @return Conjunto*
*/

int conjunto_print(File *f, Conjunto *c);


#endif
