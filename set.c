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
#include "set.h"
#include "types.h"
#include "stdlib.h"

#define TAMSET 200

struct _Conjunto {

Id identificadores[TAMSET];

int num;
};

/*Funcion conjunto_create */

Conjunto* conjunto_create()
{

Conjunto *c;
int i;

c = (Conjunto*) malloc (sizeof(Conjunto));

if (c==NULL) return NULL;

for (i=0;i<TAMSET;i++) 
 c->identificadores[i]=0; /*inicializamos a 0 todos los valores del campo identificadores de c*/

 c->num= 0; /*inicializamos a 0 el campo numero de c*/

return c;
}

/*Funcion conjunto_destroy */

void conjunto_destroy(Conjunto *c)
{
 int i;

 if (c==NULL) return;

 for (i=0; i<TAMSET; i++)
 free(c->identificadores[i]); /*libera (destruye) cada dato del valor identificadores de c */

 free(c);
}

/*Funcion conjunto_add */

Status conjunto_add(Conjunto *c, Id n)
{
 
 if (c==NULL) return ERROR;

 c->identificadores[c->num] = n; /*Realiza una copia del identificador que esta en el campo num de c */

 c->num++;

 return OK;
}

/*Funcion conjunto_delete */

Status conjunto_delete(Conjunto *c)
{
 
 if (c==NULL) return ERROR;

 c->num--; /* Ignora la primera posicion, asignando asi el valor de la segunda posicion del campo num */

 c->identificadores[c->num] = 0;  /*Aigna el valor 0 a la nueva posicion */

 return OK;
}

/*Funcion set_print */

int set_print(File *f, Conjunto *c)
{
 int i;

 if ((f==NULL) || (c==NULL)) return -1;

 for (i=0; i<p->num; i++)
 fprintf (f, "%d", p->identificadores[i]);

 return OK;
}
