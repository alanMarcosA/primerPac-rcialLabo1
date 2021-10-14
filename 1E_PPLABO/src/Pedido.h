/*
 * Pedido.h
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <string.h>
struct
{
	int id;
	int idCliente;
	float kilosTotales;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int stado;
	int isEmpty;
}typedef Epedido;
int initEpedidos(Epedido* list, int len);

/** \brief agregar un pedido, el idEmpleado debe ser validado previamente, devuelve -1 en caso de no poder agregarlo.
 * \param list Ecliente* Pointer to array of employees
 * \param len int Array length
 * \param id int Identificador de pedido
 * \param idCliente int Identificador de cliente, debe ser previamente validado.
 * \param kilosTotales float kilos totales del pedido.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int crearPedido(Epedido* list, int len, int id,int idCliente, float kilosTotales);

int procesarResiduos(Epedido* list, int len, int id,float kilosHDPE,float kilosLDPE, float kilosPP);

/** \brief devuelve la cantidad de pedidos que tiene un cliente en esta PENDING
 * caso contrario devuelve (-1)
 * \param list Ecliente* Pointer to array of employees
 * \param len int Array length
 * \param idCliente int Identificador de cliente, debe ser previamente validado.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or invalid IdCliente] - (x>=0) if Ok
 *
 */
int pedidosPendientesPorIdCli(Epedido* list, int len,int idCliente);
#endif /* PEDIDO_H_ */
