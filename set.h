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
#include "types.h"

#define TAMSET 10

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

STATUS conjunto_add(Conjunto *c, Id n);

/* Name: conjunto_delete
 * @brief Elimina un valor del conjunto, devolviendo un OK o ERROR si hay fallos
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return Status
*/

Id conjunto_delete(Conjunto *c);


/* Name: conjunto_print
 * @brief Imprime el conjunto
 * @param Conjunto* : direccion de un tipo Conjunto
 * @param FILE *: direccion de un tipo FILE
 * @return Conjunto*
*/

int set_print(FILE *f, Conjunto *c);


/* Name: set_get_id
 * @brief devuelve la id del objeto de un conjunto
 * @param el conjunto y la posicion del objeto en el conjunto
 * @return la id  del objeto pedido
*/

Id set_get_id(Conjunto *c, int posicion);

/* Name: conjunto_isEmpty
 * @brief Comprueba si el conjunto esta vacia, devolviendo TRUE si está vacio o FALSE si no lo esta
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return BOOL
*/

BOOL Conjunto_isEmpty(const Conjunto *c);

/* Name: conjunto_isFull
 * @brief Comprueba si el conjunto esta lleno, devolviendo TRUE si está vacio o FALSE si no lo esta
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return BOOL
*/

BOOL Conjunto_isFull(const Conjunto *c);

#endif
