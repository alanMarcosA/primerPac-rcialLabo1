/*
 * Localidad.h
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <string.h>
struct
{
	int id;
	char nombre[51];
	int isEmpty;

}typedef Elocalidad;

int initlocalidad(Elocalidad* list, int len);

int agregarElocalidad(Elocalidad* list, int len, int id,char nombre[]);
#endif /* LOCALIDAD_H_ */
