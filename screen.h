/** 
 * Descripción: Define las funciones y estructuras utilizadas para screen
 * 
 * @file screen.h
 * @author Juan Martin
 * @version 1.1 
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: Falta alguna descripcion de funciones (@brief) 
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/* Name: screen_init
 * @brief Reserva memoria dinamica y rellena el fondo
 * @param no recibe ningun parametro 
 * @return void
*/

void  screen_init();

/* Name: screen_destroy
 * @brief Función que libera la memoria dinamica reservada para screen
 * @param no recibe ningun parametro 
 * @return void
*/

void  screen_destroy();

/* Name: screen_paint
 * @brief Pinta el fondo del tablero
 * @param no recibe ningun parametro 
 * @return void
*/

void  screen_paint();

/* Name: screen_gets
 * @brief 
 * @param char *str 
 * @return void
*/

void  screen_gets(char *str);

/* Name: screen_area_init
 * @brief Inicializa un area mediante el paso de valores por parametros, devolviendo el valor del area
 * @param int x: valor x
 * @param int y: valor y
 * @param int width: valor anchura
 * @param int height: valor altura
 * @return Area
*/


Area* screen_area_init(int x, int y, int width, int height);

/* Name: screen_area_destroy
 * @brief Libera la memoria dinamica reservada para area
 * @param Area *area: valor area 
 * @return void
*/

void  screen_area_destroy(Area* area);

/* Name: screen_area_clear
 * @brief Despeja y resetea la nueva area 
 * @param Area *area: valor area
 * @return void
*/

void  screen_area_clear(Area* area);

/* Name: screen_area_reset_cursor
 * @brief Funcion que reinicia el valor del cursor
 * @param Area *area: valor area
 * @return void
*/

void  screen_area_reset_cursor(Area* area);

/* Name: screen_area_puts
 * @brief 
 * @param Area *area: valor area
 * @param char *str 
 * @return void
*/

void  screen_area_puts(Area* area, char *str);

#endif
