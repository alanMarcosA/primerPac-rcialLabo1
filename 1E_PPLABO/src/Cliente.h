/*
 * Cliente.h
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <string.h>
struct
{
	int id;
	char nombreEmpresa[51];
	int cuit;
	char dirreccion[51];
	char localidad[51];
	int isEmpty;
}typedef Ecliente;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Ecliente* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEclientes(Ecliente* list, int len);


/** \brief agregar una empleado al array, devuelve -1 en caso de no poder agregarlo.
 * \param list Ecliente* Pointer to array of employees
 * \param len int Array length
 * \param *next, client data
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int agregarEcliente(Ecliente* list, int len, int id,char nombreEmpresa[], int cuit, char dirreccion[], char localidad[]);

int modificarEcliente(Ecliente* list, int len, int id,char dirreccion[], char localidad[]);

int eliminarEcliente(Ecliente* list, int len, int id);

int findEclienteById(Ecliente* list, int len,int id);
#endif /* CLIENTE_H_ */
