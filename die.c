/** 
 * Descripción: Define las funciones y estructuras utilizadas para die
 * 
 * @file die.c
 * @author Miguel Manzano
 * @version 1.0
 * @date 1-03-2018
 * @copyright GNU Public License
 * Comments: 
 */

#include <stdio.h>
#include "die.h"
#include "types.h"
#include <stdlib.h>
#include <time.h>

#define MAX_NUMERO 6

/*Estructura _Die que contiene un campo identificador de tipo Id y un campo number de tipo int */

struct _Die {

Id identificador;
int number;
};

/*Funcion die_create */
/*Crea el dado */

Die* die_create(){

	Die* d;
	d = (Die*) calloc (1, sizeof(Die));

	if (d==NULL) return NULL;

	d->identificador = NO_ID;
	d->number = 0;

	return d;
}

/*Funcion die_destroy */
/*Elimina el dado*/

void die_destroy(Die* d){

	if (d==NULL) return;
	
	free(d);
}

/*Funcion die_roll */
/*Realiza una tirada de dado*/

int die_roll(Die* d){

	if (d==NULL) return -1;
	
	srand(time(NULL)); /* Inicializa el generador de numeros aleatorios */
	d->number=rand() % 6 +1; /* Obtencion de numeros aleatorios mediante modulo 6. Le sumamos 1 ya que al ser modulo 6 toma valores entre 0 y 5 */

	if ((d->number < 0) || (d->number > MAX_NUMERO)) return -1;

	return d->number;
}

/*Funcion die_getnumber */
/*Obtiene el valor del campo number de die */

int die_getnumber(Die* d){

	if (d==NULL) return -1;

	return d->number;
}

/*Funcion die_print */
/*Imprime el contenido del dado */

STATUS die_print (FILE *f, Die* d){

	if ((f==NULL) || (d==NULL)) return ERROR;
	fprintf (f, "%d", d->number);

	return OK;
}

