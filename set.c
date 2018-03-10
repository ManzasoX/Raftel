/**
 * Descripción: Define las funciones y estructuras utilizadas para set
 *
 * @file set.c
 * @author Juan Martín y Miguel Manzano
 * @version 1.1
 * @date 25-02-2018
 * @copyright GNU Public License
 * Comments:
 */

#include <stdio.h>
#include <stdlib.h>

#include "set.h"
#include "types.h"


struct _Conjunto {

Id identificadores[TAMSET];

int num;
};

/*Funcion conjunto_create */

Conjunto* conjunto_create()
{

Conjunto *c;
int i;

c = (Conjunto*) calloc (1,sizeof(Conjunto));

if (c==NULL) return NULL;


for (i=0;i<TAMSET;i++){
  c->identificadores[i] = NO_ID; /*inicializamos a 0 todos los valores del campo identificadores de c*/
}
 c->num= 0; /*inicializamos a 0 el campo numero de c*/

return c;
}

/*Funcion conjunto_destroy */

void conjunto_destroy(Conjunto *c)
{
 if (!c) return;

 /*for(i=0; i<TAMSET;i++){
   c->identificadores[i]=NO_ID;
 }*/

 free(c);
}

/*Funcion conjunto_add */

STATUS conjunto_add(Conjunto *c, Id n)
{

 if (c==NULL) return ERROR;

 c->identificadores[c->num] = n; /*guarda en el conjunto la id pasada */
 c->num++;

 return OK;
}

/*Funcion conjunto_delete */

Id conjunto_delete(Conjunto *c)
{
  Id aux;

 if (c==NULL) return NO_ID;

 c->num--;

 aux = c->identificadores[c->num];

 c->identificadores[c->num] = NO_ID;  /*Asigna el valor 0 a la nueva posicion */

 return aux;
}

/*Funcion set_print */

int set_print(FILE *f, Conjunto *c)
{
 int i;

 if ((f==NULL) || (c==NULL)) return -1;

 for (i=0; i<(c->num); i++)
 fprintf (f, "%ld", c->identificadores[i]);

 return OK;
}

/* Name: set_get_id
 * @brief devuelve la id del objeto de un conjunto
 * @param el conjunto y la posicion del objeto en el conjunto
 * @return la id  del objeto pedido
*/
Id set_get_id(Conjunto *c, int posicion)
{
  Id id_aux;

  id_aux = c->identificadores[posicion];

  return id_aux;
}

/* Name: conjunto_isEmpty
 * @brief Comprueba si el conjunto esta vacia, devolviendo TRUE si está vacio o FALSE si no lo esta
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return BOOL
*/

BOOL Conjunto_isEmpty(const Conjunto *c)
{
  if (c == NULL)
    return FALSE;

  if(c->num == 0)
    return TRUE;
  else
    return FALSE;
}

/* Name: conjunto_isFull
 * @brief Comprueba si el conjunto esta lleno, devolviendo TRUE si está vacio o FALSE si no lo esta
 * @param Conjunto* : direccion de un tipo Conjunto
 * @return BOOL
*/

BOOL Conjunto_isFull(const Conjunto *c)
{
  if (c == NULL)
    return FALSE;

  if (c->num == (TAMSET+1))
    return TRUE;
  else
    return FALSE;
}
