/*
 * informes.h
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Cliente.h"
#include "Pedido.h"

int imprimirClientes(Ecliente* list, int len, Epedido* listP, int lenP);

int imprimirPedidosPendentes(Epedido* list, int lenP, Ecliente* listC, int lenC);

int imprimirPedidosProcesados(Epedido* list, int lenP, Ecliente* listC, int lenC);

int cantidadPedidosPorLocalidad(Epedido* listP, int lenP, Ecliente* listC, int lenC);

int clienteConMasPendientes(Ecliente* list, int len, Epedido* listP, int lenP);
int clienteConMasCompletados(Ecliente* list, int len, Epedido* listP, int lenP);
int clienteConMasPedidos(Ecliente* list, int len, Epedido* listP, int lenP);
#endif /* INFORMES_H_ */
