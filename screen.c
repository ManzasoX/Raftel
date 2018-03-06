/**
 * Descripción: Contiene la implementación de las funciones asociadas a screen
 *
 * @file screen.c
 * @author Juan Martin
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 23
#define COLUMNS 80
#define TOTAL_DATA (ROWS * COLUMNS) + 1

#define BG_CHAR '~'
#define FG_CHAR ' '
#define PROMPT " prompt:> "

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x))

/*Estructura _Area con los campos x,y,width,height de tipo int y un campo con puntero a cursor de tipo char */
struct _Area
{
  int x, y, width, height;
  char *cursor;
};

 char *__data;

/* Funciones privadas */

   int  screen_area_cursor_is_out_of_bounds(Area* area);
   void screen_area_scroll_up(Area* area);
   void screen_utils_replaces_special_chars(char* str);

/*Funcion: screen_init */
/* Reserva memoria dinamica y rellena el fondo */

void screen_init(){
  
	screen_destroy(); 
  	__data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  	if (__data)
  	{
    	memset(__data, (int) BG_CHAR, TOTAL_DATA); /*Fill the background*/
    	*(__data + TOTAL_DATA - 1) = '\0';
  	}
 	}

/*Funcion: screen_destroy */
/*Función que libera la memoria dinamica reservada para screen */
 
void screen_destroy(){

  	if (__data)
    	free(__data);
}

/*Funcion: screen_paint */
/*Pinta el fondo del tablero */

void screen_paint(){

  	char *src = NULL;
  	char dest[COLUMNS + 1];
  	int i=0;

  	memset(dest, 0, COLUMNS + 1);
  
  	if (__data)
  	{
    	puts("\033[2J"); /*Clear the terminal*/
    	for (src=__data; src < (__data + TOTAL_DATA - 1); src+=COLUMNS)
   	{
      	memcpy(dest, src, COLUMNS);
      
	/* printf("%s\n", dest); */
      
	for (i=0; i<COLUMNS; i++)
      	{
	if (dest[i] == BG_CHAR)
       	{
	printf("\033[0;34;44m%c\033[0m", dest[i]); /* fg:blue(34);bg:blue(44) */
       	}
         
	else
        {
	printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
	}
      	}
      	printf("\n");
    	}
  	}
 }

/*Funcion: screen_gets */

void screen_gets(char *str){

  	fprintf(stdout, PROMPT);
  	if (fgets(str, COLUMNS, stdin))
    	*(str + strlen(str) - 1) = 0; /* Replaces newline character with '\0' */
}

/*Funcion: screen_area_init */
/*Inicializa un area mediante el paso de valores por parametros, devolviendo el valor del area */

Area* screen_area_init(int x, int y, int width, int height){

  	int i = 0;
  	Area* area = NULL;

  	if ( (area  = (Area*) malloc (sizeof(struct _Area))) )
  	{
    	*area = (struct _Area) {x, y, width, height, ACCESS(__data, x, y)};

    	for (i=0; i < area->height; i++)
      	memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  	}

  	return area;
 }

/*Funcion: scren_area_destroy */
/*Libera la memoria dinamica reservada para area */

void screen_area_destroy(Area* area){
  	if(area)
    	free(area);
}

/*Funcion: screen_area_clear */
/*Despeja y resetea la nueva area */

void screen_area_clear(Area* area){
  	int i = 0;

  	if (area){
    	screen_area_reset_cursor(area);
    
    	for (i=0; i < area->height; i++)
      	memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  	}
}

/*Funcion: screen_area_reset_cursor */
/*Funcion que reinicia el valor del cursor */

void screen_area_reset_cursor(Area* area){
  	if (area)
   	area->cursor = ACCESS(__data, area->x, area->y);
}

/*Funcion: screen_area_puts */

void screen_area_puts(Area* area, char *str){
  
	int len = 0;
  	char *ptr = NULL;

  	if (screen_area_cursor_is_out_of_bounds(area))
    	screen_area_scroll_up(area);
  
  	screen_utils_replaces_special_chars(str);

  	for (ptr = str; ptr < (str + strlen(str)); ptr+=area->width){
    	memset(area->cursor, FG_CHAR, area->width);
    	len = (strlen(ptr) < area->width)? strlen(ptr) : area->width;
    	memcpy(area->cursor, ptr, len);
    	area->cursor += COLUMNS;
  	}
}

/*Funcion privada: screen_area_cursor_is_out_of_bounds */

int screen_area_cursor_is_out_of_bounds(Area* area){
  
	return area->cursor > ACCESS(__data,
			       area->x + area->width,
			       area->y + area->height - 1);
}

/*Funcion: screen_area_scroll_up */

void screen_area_scroll_up(Area* area){
  
	for(area->cursor = ACCESS(__data, area->x, area->y);
      	area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
      	area->cursor += COLUMNS){
    	memcpy(area->cursor, area->cursor+COLUMNS, area->width);
  	}
}

/*Funcion privada: screen_untils_replaces_special_chars */

void screen_utils_replaces_special_chars(char* str){
  
	char *pch = NULL;

  	/* Replaces acutes and tilde with '??' */
  
	while ((pch = strpbrk (str, "ÁÉÍÓÚÑáéíóúñ")))
    	memcpy(pch, "??", 2);
}

