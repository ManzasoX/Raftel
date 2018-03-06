/**
 * Descripción: Define algunos tipos de datos mediante estructuras
 *
 * @file types.h
 * @author Miguel Manzano
 * @version 1.1
 * @date 11-02-2018
 * @copyright GNU Public License
 * Comments: 
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

typedef long Id;

/*Al ser una enumeración (siendo BOOL de tipo int)  y no declarar el valor de las variables entonces deducimos que FALSE = 0 y TRUE = 1 */
typedef enum 
 {
  FALSE, TRUE
 } BOOL;

/* ERROR = 0 y OK =1 */
typedef enum 
 {
  ERROR, OK
 } STATUS;

/* N= 0, S = 1, E = 2, W = 3 */
typedef enum 
 {
  N, S, E, W
 } DIRECTION;

#endif
