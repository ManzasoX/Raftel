/**
 * Descripción: Contiene la implementacion de las funciones asociadas a space
 *
 * @file space.c
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
#include "space.h"

/*Estructura _Space que contiene un campo id, un campo nombre, campos para las direcciones (norte,sur,este,oeste) y un campo objeto */

struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  Id object;   /*antes era bool, ahora Id porque si no hay objeto tiene NO_ID*/
};

/*Funcion: space_create */
/*Creamos un espacio mediante un puntero (newSpace) que apunta a id (parametro introducido de tipo long) */

Space* space_create(Id id) {

  	Space *newSpace = NULL;

  	if (!id)
    	return NULL;

  	newSpace = (Space *) calloc(1,sizeof (Space));

  	if (newSpace == NULL) {
    	return NULL;
  	}
  
	newSpace->id = id;

  	newSpace->name[0] = '\0';

  	newSpace->north = NO_ID;
  	newSpace->south = NO_ID;
  	newSpace->east = NO_ID;
  	newSpace->west = NO_ID;

 	newSpace->object = FALSE;

  	return newSpace;
}

/*Función: space_destroy*/
/*Libera la memoria dinamica reservada para el espacio del paramentro introducido, devolviendo un OK (1) */

STATUS space_destroy(Space* space) {
 
 	if (!space) {
    	return ERROR;
  	}

  	free(space);
  	space = NULL;

  	return OK;
}

/*Función: space_set_name*/
/*Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion */

STATUS space_set_name(Space* space, char* name) {
  
	if (!space || !name) {
    	return ERROR;
  	}

  
	if (!strcpy(space->name, name)) {
    	return ERROR;
  	}

  	return OK;
}

/*Función: space_set_north */
/*Esta funcion permite modificar la direccion norte a la introducida mediante el parametro id, devolviendo un OK tras la modificacion */

STATUS space_set_north(Space* space, Id id) {
  
	if (!space || id == NO_ID) {
    	return ERROR;
  	}
  
	space->north = id;
  	return OK;
}

/*Función: space_set_south */
/*Esta funcion permite modificar la direccion sur a la introducida mediante el parametro id, devolviendo un OK tras la modificacion */

STATUS space_set_south(Space* space, Id id) {
  
	if (!space || id == NO_ID) {
    	return ERROR;
  	}
  
	space->south = id;
  	return OK;
}

/*Función: space_set_east */
/*Esta funcion permite modificar la direccion este a la introducida mediante el parametro id, devolviendo un OK tras la modificacion */

STATUS space_set_east(Space* space, Id id) {
  	if (!space || id == NO_ID) {
    	return ERROR;
  	}
  
	space->east = id;
  	return OK;
}

/*Función: space_set_west */
/* Esta funcion permite modificar la direccion oeste a la introducida mediante el parametro id, devolviendo un OK tras la modificacion */

STATUS space_set_west(Space* space, Id id) {
  
	if (!space || id == NO_ID) {
    	return ERROR;
  	}
  
	space->west = id;
  	return OK;
}

/*Función: space_set_object */
/*Esta funcion permite modificar el valor object por el valor introducido mediante el parametro value (tipo BOOL) , devolviendo OK */

STATUS space_set_object(Space* space, Id value) {
  
	if (!space) {
    	return ERROR;
  	}
  
	space->object = value;
  	return OK;
}

/*Función: space_get_name */
/*Esta funcion permite modificar el nombre introducido por parametro, devolviendo un OK tras la modificacion*/

const char * space_get_name(Space* space) {
  
	if (!space) {
    	return NULL;
  	}
  
	return space->name;
}

/*Función: space_get_id */
/*Devuelve el valor id del espacio introducido por parametro */

Id space_get_id(Space* space) {
  
	if (!space) {
    	return NO_ID;
  	}
  
	return space->id;
}

/*Función: space_get_north */
/*Devuelve el valor de direccion norte del espacio introducido por parametro */ 

Id space_get_north(Space* space) {
  	
	if (!space) {
    	return NO_ID;
  	}
  
	return space->north;
}

/*Función: space_get_south */
/*Devuelve el valor de direccion sur del espacio introducido por parametro */ 

Id space_get_south(Space* space) {
  
	if (!space) {
    	return NO_ID;
  	}
  
	return space->south;
}

/*Función: space_get_east */
/*Devuelve el valor de direccion este del espacio introducido por parametro */ 

Id space_get_east(Space* space) {
  
	if (!space) {
    	return NO_ID;
  	}
  	
	return space->east;
}

/*Función: space_get_west */
/*Devuelve el valor de direccion oeste del espacio introducido por parametro */ 

Id space_get_west(Space* space) {
  
	if (!space) {
    	return NO_ID;
  	}
  
	return space->west;
}

/*Función: space_get_object */
/*Devuelve el valor object del espacio introducido por parametro */

Id space_get_object(Space* space) {
  
	if (!space) {
    	return FALSE;
  	}
  
	return space->object;
}

/*Función: space_print */
/*Imprime la información introducida por el usuario */

STATUS space_print(Space* space) {
  
	Id idaux = NO_ID;

  	if (!space) {
    	return ERROR;
  	}
 
	/*Imprime el valor de id y el nombre introducidos*/
  
	fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /*Imprime el valor norte introducido, de no ser correcto o no introducirlo escribe No north link.*/
  
	idaux = space_get_north(space);
  	if (NO_ID != idaux) {
    	fprintf(stdout, "---> North link: %ld.\n", idaux);
  	} else {
    	fprintf(stdout, "---> No north link.\n");
  	}
  
/*Imprime el valor sur introducido, de no ser correcto o no introducirlo escribe No south link.*/
  
	idaux = space_get_south(space);
  	if (NO_ID != idaux) {
    	fprintf(stdout, "---> South link: %ld.\n", idaux);
  	} else {
    	fprintf(stdout, "---> No south link.\n");
  	}

  /*Imprime el valor este introducido, de no ser correcto o no introducirlo escribe No east link.*/
  
	idaux = space_get_east(space);
  	if (NO_ID != idaux) {
    	fprintf(stdout, "---> East link: %ld.\n", idaux);
  	} else {
    	fprintf(stdout, "---> No east link.\n");
  	}

  /*Imprime el valor oeste introducido, de no ser correcto o no introducirlo escribe No west link.*/
  
	idaux = space_get_west(space);
  	if (NO_ID != idaux) {
    	fprintf(stdout, "---> West link: %ld.\n", idaux);
  	} else {
    	fprintf(stdout, "---> No west link.\n");
  	}

  /*Imprime Object in the space siempre y cuando haya un obejto mediante la función space_get_object*/
  
	if (space_get_object(space)) {
    	fprintf(stdout, "---> Object in the space.\n");
  	} else {
    	fprintf(stdout, "---> No object in the space.\n");
  	}

  	return OK;
}

