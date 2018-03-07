/**
 * Descripción: Contiene la implementacion de las funciones asociadas a object
 *
 * @file object.c
 * @author Miguel Manzano
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "object.h"

/* Estructura _Object con campos id y name */

struct _Object {
  Id id;
  char name[WORD_SIZE + 1];
};


/*Funcion: object_create */
/*Creamos un objeto mediante un puntero (newObject) que apunta a id (parametro introducido de tipo long) */

Object* object_create(Id id) {

  	Object *newObject = NULL;

 	if (id == NO_ID)
   	return NULL;

  	newObject = (Object *) calloc(1,sizeof(Object));

  	if (newObject == NULL) {
    	return NULL;
  	}
  
	newObject->id = id;

  	newObject->name[0] = '\0';

  	return newObject;
}

/*Función: object_destroy*/
/*Libera la memoria dinamica reservada para el objeto del paramentro introducido, devolviendo un OK (1) */

STATUS object_destroy(Object* object) {
  	if (!object) {
    	return ERROR;
  	}

  	free(object);

  	return OK;
}

/*Función: object_set_name*/
/*Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion */

STATUS object_set_name(Object* object, char* name) {
  	if (!object || !name) {
    	return ERROR;
  	}

  	if (!strcpy(object->name, name)) {
    	return ERROR;
  	}

  	return OK;
}

/*Función: object_get_name */
/*Devuelve el valor name del objeto introducido por parametro */

const char * object_get_name(Object* object) {
  	if (!object) {
    	return NULL;
  	}
  
	return object->name;
}

/*Función: object_get_id */
/*Devuelve el valor id del objeto introducido por parametro */

Id object_get_id(Object* object) {
  	if (!object) {
    	return NO_ID;
  	}
  
	return object->id;
}

/*Funcion: object_print */
/*Imprime el contenido de objeto */

STATUS object_print(Object* object) {

  	if (!object) {
    	return ERROR;
  	}
  
	/*Imprime el valor de id y el nombre introducidos*/
  
	fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
  
  	return OK;
}


